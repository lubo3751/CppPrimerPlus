//ex.10.05.helpers.h
#ifndef HELPERS_H_
#define HELPERS_H_

const int LEN = 35;

struct customer {
    char fullname[LEN];
    double payment;
};

char * get_name();
double get_payment();

#endif