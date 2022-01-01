#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
using namespace std;


class View
{
  public:
	//showmenu(int&) displays a menu for the user and allows the user to select from
	//predetermined options
    void showMenu(int&);

	//getProduct(string&) gets user input for a product name and stores it in string&
    void getProduct(string&);

	//getQuantity gets user input for a quantity and stores it in int&
    void getQuantity(int&);
};

#endif
