#include <iostream>
using namespace std;
#include <string>

#include "View.h"

void View::showMenu(int& choice)
{
  int numOptions = 5;

  cout << endl;
  cout << "Which test would you like to run?"<< endl;
  cout << "  (1) Receive product" << endl;
  cout << "  (2) Fill order" << endl;
  cout << "  (3) Print store locations" << endl;
  cout << "  (4) Print warehouse locations" << endl;
  cout << "  (5) Print products" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::getProduct(string& product){
  cout<<"Which product? ";
  cin >> product;
  cout << endl;
}

void View::getQuantity(int& q){
  cout<<"What quantity? ";
  cin >> q;
  cout << endl;
}




