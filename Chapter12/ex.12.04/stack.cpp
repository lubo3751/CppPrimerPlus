// 10.11.stack.cpp -- Stack member functions
#include <iostream>
#include <cstring>
#include "stack.h"
using std::cout;
using std::endl;
Stack::Stack(int n)    // create an empty stack
{
    cout << "Default constructor called\n";    // comment out to make it silent
    size = n;
    pitems = new Item[size];
    top = 0;
}

Stack::Stack(const Stack & st)
{
    cout << "Copy constructor called\n";       // comment out to make it silent
    size = st.size;
    pitems = new Item[size];
    memcpy_s(pitems, size*(sizeof pitems), 
        st.pitems, st.size*(sizeof st.pitems));
    top = st.top;
}

Stack::~Stack()
{
    cout << "Destructor called\n";             // comment out to make it silent
    delete [] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item & item) 
{
    if (top < size)
    {
        pitems[top++] = item;
        cout << item << " pushed to " << this << endl; // comment out to silent
        return true;
    }
    else
    {
        cout << this << " is full\n";          // comment out to make it silent
        return false;
    }
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
    {
        cout << this << " is empty\n";         // comment out to make it silent
        return false; 
    }
}

Stack & Stack::operator=(const Stack & st)
{
    cout << "Assignment operator called\n";    // comment out to make it silent
    if (this == &st)
        return *this;
    delete [] pitems;
    size = st.size;
    pitems = new Item[size];
    memcpy_s(pitems, size*(sizeof pitems), 
        st.pitems, st.size*(sizeof st.pitems));
    top = st.top;
    return *this;
}
