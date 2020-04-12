#include "FamilyTree.hpp"

using namespace std;
using namespace family;

Tree::Tree(string name){
    root.name = name;
}

Tree::~Tree(){

}
Tree& Tree::addFather(string child,string father){
    return *this ;
}
Tree& Tree::addMother(string child,string mother){
    return *this;
}
string Tree::relation(string name){
    return "";
}

string Tree::find(string relat){
    return "";
}
void Tree::display(){

}
Tree& Tree::remove(string){
    return *this;
} 