// classic.cpp -- Cd class and Classic class implementation
#include <iostream>
#include <string>
#include "classic.h"
using std::cout;
using std::endl;

/*
 * base Cd class
 */
Cd::Cd(char* s1, char* s2, int n, double x)
    : selections(n), playtime(x) {
    strcpy_s(performers, 50, s1);
    strcpy_s(label, 20, s2);
}

Cd::Cd(const Cd & d) 
    : selections(d.selections), playtime(d.playtime) {
    strcpy_s(performers, 50, d.performers);
    strcpy_s(label, 20, d.label);
}

Cd::Cd() : selections(0), playtime(0.0) {
    strcpy_s(performers, 50, "null");
    strcpy_s(label, 20, "null");
}

void Cd::Report() const {
    cout << "performers: " << performers << endl;
    cout << "label: " << label << endl;
    cout << "selections: " << selections << endl;
    cout << "playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d) {
    if (this == &d) return *this;
    strcpy_s(performers, 50, d.performers);
    strcpy_s(label, 20, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

/*
 *  derived Classic class
 */
Classic::Classic(char* pw, char* s1, char* s2, int n, double x) 
    : Cd::Cd(s1, s2, n, x) {
    strcpy_s(primary_work, 50, pw);
}

Classic::Classic(const Classic & d) : Cd::Cd(d) {
    strcpy_s(primary_work, 50, d.primary_work);
}

Classic::Classic() : Cd::Cd() {
    strcpy_s(primary_work, 50, "null");
}

void Classic::Report() const {
    Cd::Report();
    cout << "primary work: " << primary_work << endl;
}

Classic & Classic::operator=(const Classic & d) {
    Cd::operator=(d);
    if (this == &d) return *this;
    strcpy_s(primary_work, 50, d.primary_work);
    return *this;
}