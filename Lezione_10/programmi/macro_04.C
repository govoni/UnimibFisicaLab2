
h_scarti->Rebin (2) ;
h_scarti->SetStats (0) ;
h_scarti->SetFillColor (kOrange + 1) ;
h_scarti->SetLineColor (kGray + 2) ;
Float_t binWidth = h_scarti->GetXaxis ()->GetBinWidth (1) ;

TF1 *chi2 = new TF1 ("chi2", "[0] * ROOT::Math::chisquared_pdf(x,[1])", 0, 25) ;
chi2->SetParameter (0, h_scarti->Integral () * binWidth) ;
chi2->SetParameter (1, 4) ;
chi2->SetLineColor (kGray + 2) ;
chi2->SetLineWidth (10) ;

TCanvas c1 ("c1", "", 800, 800) ;
TH1F * bkg = c1.DrawFrame (0,0,20,600) ;
bkg->GetXaxis ()->SetTitle ("Q^{2}_{min}") ;
bkg->GetYaxis ()->SetTitle ("toy experiments") ;
bkg->Draw () ;
h_scarti->Draw ("hist same") ;
chi2->Draw ("same") ;

