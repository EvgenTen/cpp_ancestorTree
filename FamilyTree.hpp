#include <iostream>
using namespace std::string;

namespace family{
    struct node{
        string name;
        node *father=nullptr;
        node *mather=nullptr;
    };
    struct Tree{
     private:
        node root;
     public:

     Tree(string);
     ~Tree();
     Tree& addFather(string child,string father);
     Tree& addMother(string child,string mother);
     string relation(string);
     string find(string);
     void display();
     Tree& remove(string);

    
    };
}