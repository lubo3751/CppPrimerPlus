// ex.13.04 -- Port class and VintagePort class testing
// compile with port.cpp
#include "port.h"

int main()
{
    Port p1;
    p1.Show();
    cout << endl;

    Port p2("Berry Bros. & Rudd", "tawny", 7);
    p2.Show();
    cout << endl;

    Port p3(p2);
    p3.Show();
    cout << endl;

    p1 = p3;
    p1.Show();
    cout << endl;

    (p2 += p1.BottleCount()) -= 3;

    cout << p2 << endl;

    cout << "\n--------------------------\n\n";

    VintagePort vp1;
    vp1.Show();
    cout << endl;

    VintagePort vp2("Croft", 3, "Quinta da Roeda", 1983);
    vp2.Show();
    cout << endl;

    VintagePort vp3(vp2);
    vp3.Show();
    cout << endl;

    vp1 = vp3;
    vp1.Show();
    cout << endl;

    (vp2 += vp1.BottleCount()) -= 2;
    cout << vp2 << endl << endl;

    return 0;
}