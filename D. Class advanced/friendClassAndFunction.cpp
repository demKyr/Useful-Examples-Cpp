// A friendly class is a class that is given access to the private and protected members of another class.
// A friend function is a function that is given access to the private and protected members of a class.

#include <iostream>
using namespace std;

class GFG {
private:
    int private_variable;
protected:
    int protected_variable;
public:
    GFG()
    {
        private_variable = 10;
        protected_variable = 99;
    }
    friend class FriendClass; // friend class declaration
    friend void friendFunction(GFG& obj); // friend function declaration
    friend std::ostream& operator << (std::ostream&, GFG&); // friend function declaration
};

// Class FriendClass is declared as a friend inside class GFG so it can access the private members of class GFG
class FriendClass {
public:
    void display(GFG& t)
    {
        cout << t.private_variable << " " << t.protected_variable << endl;
    }
};

// function friendFunction is declared as a friend of class GFG so it can access the private members of class GFG
void friendFunction(GFG& obj)
{
    cout << obj.private_variable << " " << obj.protected_variable << endl;
}

// overloaded << operator to print GFG object
ostream& operator << (ostream& s, GFG& obj)
{
    s << obj.private_variable << " " << obj.protected_variable << endl;
    return s;
}


int main()
{
    GFG g;
    FriendClass friendClassInstance;
    friendClassInstance.display(g); // prints 10 99
    friendFunction(g); // prints 10 99
    cout << g; // prints 10 99
    return 0;
}