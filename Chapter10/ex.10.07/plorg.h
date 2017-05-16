// ex.10.07.plorg.h -- Plorg class declaration
#ifndef PLORG_H_
#define PLORG_H_

namespace PLORG
{
    class Plorg
    {
    private:
        static const int MAX = 19;
        char m_name[MAX];
        int m_ci; // contentment index
    public:
        Plorg(char name[] = "Plorga", int ci = 50);
        void reset_ci(int ci);
        void report();
    }; 
}

#endif