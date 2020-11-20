#ifndef generatore_h
#define generatore_h

/*
 *  Generatore lineare congruenziale
 */

class generatore {
    public:
        // Costruttore
        generatore(int seed);
        // Distruttore
        ~generatore();

        // Imposta il seed
        void set_seed(int seed);

        // Genera un numero casuale
        virtual double generate();

    protected:
        // Seed
        int m_seed;

        // Costanti per la generazione di numeri casuali
        const long long int A = 214013;
        const long long int C = 2531011;
        const long long int M = 2147483647;

        // Genera un numero casuale nel range tra m_min e m_max
        double rand_range(double min, double max);
};


#endif
