// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
class Stonewt
{
public:
    enum Mode {STN, LBS};         // STN for stones, LBS for pounds modes
private:
    enum {Lbs_per_stn = 14};      // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
    Mode mode;                    // STN or LBS
public:
    Stonewt(double lbs);          // constructor for double pounds
    Stonewt(int stn, double lbs); // constructor for stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    void stn_mode();                // set mode to STN
    void lbs_mode();                // set mode to LBS
    Stonewt operator+(const Stonewt & sw) const;
    Stonewt operator-(const Stonewt & sw) const;
    Stonewt operator*(double n) const;
    friend Stonewt operator*(double n, const Stonewt & sw) { return sw * n; }
    friend std::ostream & operator<<(std::ostream & os, const Stonewt & sw);

};
#endif
