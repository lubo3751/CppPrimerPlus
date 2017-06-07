// main.cpp -- exercise 4 chapter 12 of C++ Primer Plus
#include <iostream>
#include "stack.h"
int main()
{
    using std::cout;
    using std::endl;
    Stack s1(3);
    cout << "s1(3) created at " << &s1 << endl;
    s1.push(111);
    Stack s2(s1);
    cout << "s2(s1) created at " << &s2 << endl;
    s2.push(222);
    Stack s3;
    cout << "s3 created at " << &s3 << endl;
    s3 = s2;
    cout << "s2 assigned to s3\n";
    s3.push(333);
    s3.push(444);
    unsigned long item;
    s3.pop(item);
    cout << item << " popped from " << &s3 << endl;
    s3.pop(item);
    cout << item << " popped from " << &s3 << endl;
    s3.pop(item);
    cout << item << " popped from " << &s3 << endl;
    s3.pop(item);
    return 0; 
}
