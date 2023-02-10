#include "hash.h" 
#include <iostream>
using namespace std;

//Contrutor que ativa a Hash e aloca memória

Hash::Hash(int max) {  
  length = 0;
  max_items = max;
  structure = new Cliente[max_items];
}

Hash::~Hash(){
  delete [] structure;
}

bool Hash::isFull() const {
  return (length == max_items);
}

int Hash::getLength() const {
  return length;
}

void Hash::retrieveItem(Cliente& login, bool& found) {
  int startLoc = getHash(login);
  bool moreToSearch = true; 
  int location = startLoc;
  do {
    if (structure[location].getImei() == login.getImei() ||
	structure[location].getImei() == -1)
      moreToSearch = false;
    else
      location = (location + 1) % max_items;
  } while (location != startLoc && moreToSearch);
  
  found = (structure[location].getImei() == login.getImei() );   
  if (found) { 
    login = structure[location];
  }
}

void Hash::insertItem(Cliente login) {
  int location;
  location = getHash(login);
  while (structure[location].getImei() > 0)
    location = (location + 1) % max_items;
  structure[location] = login;
  length++;
}

void Hash::deleteItem(Cliente login) {
  int startLoc = getHash(login);
  bool moreToSearch = true; 
  int location = startLoc;
  do {
    if (structure[location].getImei() == login.getImei() ||
	structure[location].getImei() == -1)
      moreToSearch = false;
    else
      location = (location + 1) % max_items;
  } while (location != startLoc && moreToSearch);

  if (structure[location].getImei() == login.getImei()) {       
    structure[location] = Cliente(-2,"");
    length--;
  }
}

void Hash::print() {
  for (int i = 0; i < max_items; i++) {
    cout << i <<":"<< structure[i].getImei()<<", "<<structure[i].getLogin()<<endl;
  }
}

int Hash::getHash(Cliente login){
  return login.getImei() % max_items;
}

