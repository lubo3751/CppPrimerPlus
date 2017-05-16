// ex.10.05.main.cpp
// compile with stack.cpp and helpers.cpp
#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
    using namespace std;
    using namespace STACK;
    Stack st; // create an empty stack
    char ch;
    customer cust;
    double total = 0;
    cout << "Please enter A to add a customer payment,\n"
         << "P to process a CP, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')   
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a': if (st.isfull()) {
                          cout << "stack already full\n\n";
                      } else {
                          strcpy_s(cust.fullname, LEN, get_name());
                          cust.payment = get_payment();
                          st.push(cust);
                      }
                      break;
            case 'P':
            case 'p': if (st.isempty()) {
                          cout << "stack already empty\n\n";
                      } else {
                          st.pop(cust);
                          cout << "Customer " << cust.fullname
                               << " $" << cust.payment << " popped\n";
                          total += cust.payment;
                          cout << "payments total: " << total << "\n\n";
                      }
                      break;
        }
        cout << "Please enter A to add a customer payment,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "\nBye\n\n";
    return 0; 
}

