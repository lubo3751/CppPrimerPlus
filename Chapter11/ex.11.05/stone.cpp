// stone.cpp -- user-defined conversions
// compile with stonewt.cpp
#include <iostream>
using std::cout;
#include "stonewt.h"
void display(const Stonewt & st, int n);
int main()
{
    Stonewt incognito = 275; // uses constructor to initialize
    Stonewt wolfe(285.7);    // same as Stonewt wolfe = 285.7;
    Stonewt taft(21, 8);

    incognito.stn_mode();
    cout << "The celebrity weighed " << incognito;
    wolfe.stn_mode();
    cout << "The detective weighed " << wolfe;
    taft.lbs_mode();
    cout << "The President weighed " << taft;
    incognito = 276.8;      // uses constructor for conversion
    taft = 325;             // same as taft = Stonewt(325);
    incognito.stn_mode();
    cout << "After dinner, the celebrity weighed " << incognito;
    cout << "After dinner, the President weighed " << taft;
    taft.stn_mode();
    display(taft, 2);
    cout << "The wrestler weighed even more.\n";
    display(422, 2);
    cout << "President was lighter than wrestler of " << Stonewt(422) - taft;
    cout << "Celebrity and president, together weighed " << incognito + taft;
    cout << "Wrestler and his twin weighed " << 2 * Stonewt(422);
    cout << "No stone left unearned\n";
    // std::cin.get();
    return 0;
}

void display(const Stonewt & st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow! " << st;
    }
}