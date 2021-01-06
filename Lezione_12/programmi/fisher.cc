#include "fisher.h"
#include "../../Lezione_09/programmi/statistiche_vector.h"

#include "TLegend.h"

using namespace std ;

void leggiFile (vector<vector<double> > & data, string nome_file)
{
  ifstream input_file ;
  input_file.open (nome_file.c_str (), ios::in) ;

  if (!input_file.is_open ()) exit (1) ;

  double input_x ;
  double input_y ;
  vector<double> v ;
  data.push_back (v) ;
  data.push_back (v) ;
  while (true) 
    {
      input_file >> input_x ;
      input_file >> input_y ;
      if (input_file.eof () == true) break ;
      data.at (0).push_back (input_x) ;
      data.at (1).push_back (input_y) ;
    } 
  input_file.close () ;
  return ;
} 


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


TH2F * riempiIstogramma (const vector<vector<double> > & data, string histo_name, int maxNum)
{
  // preparazione dell'istogramma
  // ---- ---- ---- ---- ---- ---- ----  

  double max_x = *max_element (data.at (0).begin (), data.at (0).end ()) ;
  double min_x = *min_element (data.at (0).begin (), data.at (0).end ()) ;
  double max_y = *max_element (data.at (1).begin (), data.at (1).end ()) ;
  double min_y = *min_element (data.at (1).begin (), data.at (1).end ()) ;

  double sigma_x = sqrt (varianza (data.at (0))) ;
  double sigma_y = sqrt (varianza (data.at (1))) ;

  TH2F * h_vis = new TH2F (
      histo_name.c_str (), 
      "distribuzione 2D",
      3 * (max_x - min_x) / sigma_x, min_x, max_x, 
      3 * (max_y - min_y) / sigma_y, min_y, max_y
    ) ;

  // riempimento dell'istogramma
  // ---- ---- ---- ---- ---- ---- ----  

  for (int i = 0 ; i < data.at (0).size () ; ++i)
    {
      if (maxNum > 0 and i > maxNum) break ;
      h_vis->Fill (data.at (0).at (i), data.at (1).at (i)) ;
    }

  return h_vis ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


matrice determinaCovarianza (const vector<vector<double> > & data)
{

  if (data.size () < 2) exit (1) ;
  // calcolo della matrice delle covarianze
  // ---- ---- ---- ---- ---- ---- ----  

  double V_xx = varianza (data.at (0)) ;
  double V_yy = varianza (data.at (1)) ;
  double M_x = media (data.at (0)) ;
  double M_y = media (data.at (1)) ;

  double V_xy = 0. ;
  for (int i = 0 ; i < data.at (0).size () ; ++i)
    {
      V_xy += (data.at (0).at (i) - M_x) * (data.at (1).at (i) - M_y) ;
    }
  V_xy /= data.at (0).size () ;

  matrice covarianza (2) ;
  covarianza.setCoord (0, 0, V_xx) ;
  covarianza.setCoord (1, 1, V_yy) ;
  covarianza.setCoord (0, 1, V_xy) ;
  covarianza.setCoord (1, 0, V_xy) ;

  return covarianza ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


TH1F * riempiIstogramma (const vector<double> & data, string histo_name, int maxNum)
{
  // preparazione dell'istogramma
  // ---- ---- ---- ---- ---- ---- ----  

  double max_x = *max_element (data.begin (), data.end ()) ;
  double min_x = *min_element (data.begin (), data.end ()) ;

  double sigma_x = sqrt (varianza (data)) ;

  TH1F * h_vis = new TH1F (
      histo_name.c_str (), 
      "distribuzione 1D",
      5 * (max_x - min_x) / sigma_x, min_x, max_x
    ) ;

  // riempimento dell'istogramma
  // ---- ---- ---- ---- ---- ---- ----  

  for (int i = 0 ; i < data.size () ; ++i)
    {
      if (maxNum > 0 and i > maxNum) break ;
      h_vis->Fill (data.at (i)) ;
    }

  return h_vis ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


void plotComparison (TH1F * h_H1, TH1F * h_H0, TCanvas & c1, string nome_file, string asse_x)
{
  double y_max = 0. ;
  if (h_H1->GetBinContent (h_H1->GetMaximumBin ()) > y_max)
    y_max = h_H1->GetBinContent (h_H1->GetMaximumBin ()) ;
  if (h_H0->GetBinContent (h_H0->GetMaximumBin ()) > y_max)
    y_max = h_H0->GetBinContent (h_H0->GetMaximumBin ()) ;

  double x_min = h_H1->GetXaxis ()->GetXmin () ;
  double x_max = h_H1->GetXaxis ()->GetXmax () ;

  if (h_H0->GetXaxis ()->GetXmin () < x_min) x_min = h_H0->GetXaxis ()->GetXmin () ;
  if (h_H0->GetXaxis ()->GetXmax () > x_max) x_max = h_H0->GetXaxis ()->GetXmax () ;

  TH1F * bkg = c1.DrawFrame (x_min, 0, x_max, y_max * 1.1) ;
  bkg->SetXTitle (asse_x.c_str ()) ;

  h_H1->SetLineColor (kRed) ;
  h_H1->SetLineWidth (2) ;
  h_H0->SetLineColor (kBlue) ;
  h_H0->SetLineWidth (2) ;

  h_H1->Draw ("hist same") ;
  h_H0->Draw ("hist same") ;

  TLegend legend (0.5, 0.7, 0.9, 0.9) ;
  legend.AddEntry (h_H1, "H1", "l") ;
  legend.AddEntry (h_H0, "H0", "l") ;
  legend.Draw () ;
  c1.Print (nome_file.c_str (), "png") ;

  delete bkg ;

  return ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


/**
  disegna la curva ROC per una selezione basata sul valore dei vettori in input
  dove la selezione è input < soglia.
   - se maggiore_di == true  allora H0 sta a destra di H1
   - se maggiore_di == false allora H0 sta a sinistra di H1
*/
TGraph disegnaROC (vector<double> v_H_1, vector<double> v_H_0, bool maggiore_di, double forzaMaxA) 
{
  // NB questa operazione modifica l'ordinamento nel campione, 
  //    quindi se l'ordinamento va preservato meglio è fare una copia
  //    dei vector per lavorarci
  sort (v_H_1.begin (), v_H_1.end ()) ;
  sort (v_H_0.begin (), v_H_0.end ()) ;

  // determinazione del massimo e del minimo valore assunti dai due campioni

  double taglio_min = *v_H_1.begin () ;
  if (*v_H_0.begin () < taglio_min) taglio_min = *v_H_0.begin () ;

  double taglio_max = *v_H_1.rbegin () ;
  if (*v_H_0.rbegin () > taglio_max) taglio_max = *v_H_0.rbegin () ;
  if (forzaMaxA > 0) taglio_max = forzaMaxA ;

  // determinazione del passo di scorrimento della selezione

  double risoluzione = 10 * (taglio_max - taglio_min) / v_H_1.size () ;

  // riempimento della curva ROC

  TGraph g_ROC ;

  int contatore_1 = 0 ;
  int contatore_0 = 0 ;
  for (double taglio = taglio_min ; taglio < taglio_max ; taglio += risoluzione)
    {
      // conta il numero di eventi sotto soglia per ogni campione
      // (ricordando che i due campioni sono stati ordinati)
      for ( ; contatore_1 < v_H_1.size () ; ++contatore_1)
        if (v_H_1.at (contatore_1) > taglio) break ;

      for ( ; contatore_0 < v_H_0.size () ; ++contatore_0)
        if (v_H_0.at (contatore_0) > taglio) break ;

      if (maggiore_di)
        g_ROC.SetPoint (g_ROC.GetN (), 
            static_cast<double> (contatore_0) / v_H_0.size (),      // alpha
            1. - static_cast<double> (contatore_1) / v_H_1.size ()  // beta
          ) ;
      else
        g_ROC.SetPoint (g_ROC.GetN (), 
            1. - static_cast<double> (contatore_0) / v_H_0.size (), // alpha
            static_cast<double> (contatore_1) / v_H_1.size ()       // beta
          ) ;
    }

  g_ROC.GetHistogram ()->SetXTitle ("#alpha") ;
  g_ROC.GetHistogram ()->SetYTitle ("#beta") ;
  return g_ROC ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- 


double area (TGraph & graph)
{
  double area = 0. ;
  double x = graph.GetPointX (0) ;
  double y = graph.GetPointY (0) ;

  for (int i = 1 ; i < graph.GetN () ; ++i)
    {
      area += 0.5 * (y + graph.GetPointY (i)) * fabs (graph.GetPointX (i) - x) ;
      x = graph.GetPointX (i) ;
      y = graph.GetPointY (i) ;
    }

  return area ;
}


