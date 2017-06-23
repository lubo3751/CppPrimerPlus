// classic.h -- Cd class and Classic class interface
#ifndef CLASSIC_H_
#define CLASSIC_H_

// base Cd class
class Cd { // represents a CD disk
private:
    char performers[50];
    char label[20];
    int selections; // number of selections
    double playtime; // playing time in minutes
public:
    Cd(char* s1, char* s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd() {}
    virtual void Report() const; // reports all CD data
    Cd & operator=(const Cd & d);
};

// derived Classic class
class Classic : public Cd {
private:
    char primary_work[50];
public:
    Classic(char* pw, char* s1, char* s2, int n, double x);
    Classic(const Classic & d);
    Classic();
    virtual void Report() const; // reports all CD data
    Classic & operator=(const Classic & d);
};

#endif
