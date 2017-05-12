// ex.10.08.list.h -- List class declaration
#ifndef LIST_H_
#define LIST_H_

// structure for saving bank account
struct Account {
    std::string name;
    double deposit;
    double interest;
};

typedef Account Item;

class List
{
private:
    enum {MAX = 5};
    Item items[MAX];
    int last;
public:
    List();
    bool isempty() const;
    bool isfull() const;
    bool add(const Item & item);
    void visit(void (*pf)(Item &));
};
#endif

void show_menu();
void solicit_choice(char * choice);
void add_interest(Item & it);
void show_account(Item & it);
Account & solicit_info(Account & ac);
