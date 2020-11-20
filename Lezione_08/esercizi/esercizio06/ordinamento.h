#ifndef ordinamento_h
#define ordinamento_h

class ordinamento {
    public:
        ordinamento();
        ~ordinamento();

        bool operator() (int a, int b);
};

#endif
