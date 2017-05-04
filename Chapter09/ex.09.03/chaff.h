// golf.h -- for main.cpp

const int N = 2;

struct chaff
{
    char dross[20];
    int slag;
};

// function calls set_dross() and set_slag() functions
// and sets elements of *pChaffAr
void set_ptChAr(chaff * pChaffAr);

// function solicits dross from user
// and sets the member of ch to the value entered
void set_dross(chaff & ch, int i);

// function solicits slag from user
// and sets the member of ch to the value entered
void set_slag(chaff & ch, int i);

// function displays contents of *pChaffAr
void show_ptChAr(chaff * pChaffAr);
