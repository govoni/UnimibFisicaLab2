#ifndef rettangolo_h
#define quadarato_h

#include "forma.h"

class rettangolo: public forma {
    public:
        // Costruttore di default
        rettangolo();
        // Costruttore con parametro
        rettangolo(double lato_1 = 1, double lato_2 = 1);
        // Distruttore
        ~rettangolo();

        // Cambia lato
        void cambia_lato_1(double lato);
        void cambia_lato_2(double lato);

        // Calcola l'area
        double calcola_area();

        // Calcola l'area - metodo non virtual
        double calcola_area_non_virtual();

    private:
        double m_lato_1;
        double m_lato_2;
};

#endif
