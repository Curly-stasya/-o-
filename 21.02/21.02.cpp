#include <iostream>
#include "Arr.h"
using namespace std;

int main()
{
    Arr shelf;
    shelf.addElement(8);
    shelf.addElement(17);
    shelf.addElement(43);
    shelf.addElement(59);
    shelf.print();
    cout << "------------" << endl;
    cout << shelf.getElement(2) << endl;
    cout << "------------" << endl;
    shelf.removeElement(0);
    shelf.print();
    cout << "------------" << endl;
    shelf.resize(2);
    shelf.print();
}
