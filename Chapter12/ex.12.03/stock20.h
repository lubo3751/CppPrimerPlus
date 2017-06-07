// stock20.h -- augmented version
#ifndef STOCK20_H_
#define STOCK20_H_
#include <iostream>
using std::ostream;

class Stock
{
private:
    char * company;
    int len;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
// constructors and destructor
    Stock();                // default constructor
    Stock(const char * co, long n = 0, double pr = 0.0);
    Stock(const Stock & s);   // copy constructor
    ~Stock();
// other methods
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    const Stock & topval(const Stock & s) const;
// overloaded operator method
    Stock & operator=(const Stock & s);
// overloaded operator friend method
    friend ostream & operator<<(ostream & os, Stock s);
};

#endif
