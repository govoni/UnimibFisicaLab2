#ifndef quadrato_h
#define quadarato_h

#include "forma.h"

class quadrato: public forma {
    public:
        // Costruttore di default
        quadrato();
        // Costruttore con parametro
        quadrato(double lato = 1);
        // Distruttore
        ~quadrato();

        // Cambia lato
        void cambia_lato(double lato);

        // Calcola l'area
        double calcola_area();

        // Calcola l'area - metodo non virtual
        double calcola_area_non_virtual();

    private:
        double m_lato;
};

#endif
