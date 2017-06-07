


Consider the following class declaration:

    class Cow {
        char name[20];
        char * hobby;
        double weight;
    public:
        Cow();
        Cow(const char * nm, const char * ho, double wt);
        Cow(const Cow c&);
        ~Cow();
        Cow & operator=(const Cow & c);
        void ShowCow() const; // display all cow data
    };

Provide the implementation for this class and write a short program that uses all the
member functions.

Sample run:
-----------

![enter image description here](https://image.ibb.co/jtiCha/ex_12_01.png)