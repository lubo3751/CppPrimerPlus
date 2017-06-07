// stock20.cpp -- augmented version
#include "stock20.h"  // includes <iostream>

// constructors

Stock::Stock()     // default constructor
{
    len = 8;
    company = new char[len];
    strcpy_s(company, len, "no name");
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * co, long n, double pr)
{
    len = std::strlen(co);
    company = new char[len + 1];
    strcpy_s(company, len + 1, co);
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

Stock::Stock(const Stock & s)     // copy constructor
{
    len = s.len;
    company = new char[len + 1];
    strcpy_s(company, len + 1, s.company);
    shares = s.shares;
    share_val = s.share_val;
    total_val = s.total_val;
}

// destructor
Stock::~Stock()
{
    delete [] company;
}

// other methods

void Stock::buy(long num, double price)
{
     if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}

// overloaded operator method
Stock & Stock::operator=(const Stock & s)
{
    if (this == &s)
        return *this;
    delete [] company;
    len = s.len;
    company = new char[len + 1];
    strcpy_s(company, len + 1, s.company);
    shares = s.shares;
    share_val = s.share_val;
    total_val = s.total_val;
    return *this;
}

// overloaded operator friend method
// argument 'Stock s' isn't referece, so it can handle dereferenced pointer
ostream & operator<<(ostream & os, Stock s)
{
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig = 
        os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = os.precision(3);
    
    os << "Company: " << s.company
        << "  Shares: " << s.shares << '\n';
    os << "  Share Price: $" << s.share_val;
    // set format to #.##
    os.precision(2);
    os << "  Total Worth: $" << s.total_val << '\n';

    // restore original format
    os.setf(orig, ios_base::floatfield);
    os.precision(prec);
    
    return os;
}
