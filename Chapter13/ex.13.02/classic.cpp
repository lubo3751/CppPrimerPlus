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
    performers = new char[strlen(s1) + 1];
    strcpy_s(performers, strlen(s1) + 1, s1);
    label = new char[strlen(s2) + 1];
    strcpy_s(label, strlen(s2) + 1, s2);
}

Cd::Cd(const Cd & d) 
    : selections(d.selections), playtime(d.playtime) {
    performers = new char[strlen(d.performers) + 1];
    strcpy_s(performers, strlen(d.performers) + 1, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy_s(label, strlen(d.label) + 1, d.label);
}

Cd::Cd() : selections(0), playtime(0.0) {
    performers = new char[5];
    strcpy_s(performers, 5, "none");
    label = new char[5];
    strcpy_s(label, 5, "none");
}

Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}

void Cd::Report() const {
    cout << "performers: " << performers << endl;
    cout << "label: " << label << endl;
    cout << "selections: " << selections << endl;
    cout << "playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d) {
    if (this == &d) return *this;
    delete [] performers;
    delete [] label;
    performers = new char[strlen(d.performers) + 1];
    strcpy_s(performers, strlen(d.performers) + 1, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy_s(label, strlen(d.label) + 1, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

/*
 *  derived Classic class
 */
Classic::Classic(char* pw, char* s1, char* s2, int n, double x) 
    : Cd::Cd(s1, s2, n, x) {
    primary_work = new char[strlen(pw) + 1];
    strcpy_s(primary_work, strlen(pw) + 1, pw);
}

Classic::Classic(const Classic & d) : Cd::Cd(d) {
    primary_work = new char[strlen(d.primary_work) + 1];
    strcpy_s(primary_work, strlen(d.primary_work) + 1, d.primary_work);
}

Classic::Classic() : Cd::Cd() {
    primary_work = new char[5];
    strcpy_s(primary_work, 5, "none");
}

Classic::~Classic()
{
    delete [] primary_work;
}

void Classic::Report() const {
    Cd::Report();
    cout << "primary work: " << primary_work << endl;
}

Classic & Classic::operator=(const Classic & d) {
    if (this == &d) return *this;
    Cd::operator=(d);
    delete [] primary_work;
    primary_work = new char[strlen(d.primary_work) + 1];
    strcpy_s(primary_work, strlen(d.primary_work) + 1, d.primary_work);
    return *this;
}