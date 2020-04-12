#include <iostream>
#include <string>
#pragma once
using namespace std;


namespace family{
    struct node{
        string name;
        node* father=nullptr;
        node* mather=nullptr;
    };
    class Tree{
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