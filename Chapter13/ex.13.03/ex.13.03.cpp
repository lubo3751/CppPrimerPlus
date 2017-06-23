// ex.13.03.cpp  -- abcDMA class, baseDMA class, lacksDMA class, 
//                  and hasDMA class testing
// compile with dma.cpp
#include <iostream>
#include <string>
#include "dma.h"
const int NUMS = 3;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    abcDMA * labels[NUMS];
    string label;
    string color;
    string style;
    int rating;
    char choice;

    for (int i = 0; i < NUMS; ++i)
    {
        cout << "Enter label's name: ";
        getline(cin, label);
        cout << "Enter label's rating: ";
        cin >> rating;
        cout << "Enter 1 for plain label, "
            << "2 for label with color, or 3 for label with style: ";
        while (cin >> choice && (choice != '1' && choice != '2' && choice != '3'))
            cout << "Enter either 1, 2, or 3: ";
        while (cin.get() != '\n')
            continue;
        switch (choice)
        {
        case '1':
            labels[i] = new baseDMA(label.c_str(), rating);
            break;
        case '2':
            cout << "Enter label's color: ";
            getline(cin, color);
            labels[i] = new lacksDMA(color.c_str(), label.c_str(), rating);
            break;
        case '3':
            cout << "Enter label's style: ";
            getline(cin, style);
            labels[i] = new hasDMA(style.c_str(), label.c_str(), rating);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    for (int i = 0; i < NUMS; ++i)
    {
        labels[i]->View();
        cout << endl;
    }

    for (int i = 0; i < NUMS; i++)
    {
        delete labels[i];  // free memory
    }
    cout << "Done.\n";
    /* code to keep window open
    if (!cin)
    cin.clear();
    while (cin.get() != '\n')
    continue;
    */
    return 0;
}
