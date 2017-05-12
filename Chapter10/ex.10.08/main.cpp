// ex.10.08.main.cpp -- using the List class
// compile with list.cpp
#include <iostream>
#include "list.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    List list;
    Account account;

    show_menu();
    char choice;
    solicit_choice(&choice);
    while (choice != 'Q' && choice != 'q') 
    {
        switch(choice) 
        {
            case 'a':
            case 'A': if (list.isfull())
                          cout << "Maximum number of accounts reached.\n\n";
                      else {
                          account = solicit_info(account);
                          list.add(account);
                      }
                      break;
            case 'b':
            case 'B': if (list.isempty())
                          cout << "No account created.\n\n";
                      else {
                          list.visit(add_interest);
                          cout << "Interest added.\n\n";
                      }
                      break;
            case 'c':
            case 'C': if (list.isempty())
                          cout << "No account created.\n\n";
                      else {
                          list.visit(show_account);
                          cout << endl;
                      }
                      break;
            default : cout << "That's not a choice.\n";
                      show_menu();
                      cin.get(choice).get();
                      continue;
        }
        show_menu();
        solicit_choice(&choice);
    }
    cout << "Bye!\n\n";
    return 0;
}


