// ex.10.03.golf.h -- Golf class declaration
#ifndef GOLF_H_
#define GOLF_H_

const int MAX = 5;

class Golf {
private:
    static const int LEN = 40;
    char fullname[LEN];
    int handicap;
public:
    Golf(char * name = "", int hc = 0); 
    int setgolf();
    void reset_handicap(int hc);
    void showgolf();
};

#endif
