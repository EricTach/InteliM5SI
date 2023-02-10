#include "cliente.h"

class Hash {
 public:
  Hash(int max_items = 100);
  ~Hash();
  bool isFull() const;
  int getLength() const;
  
  void retrieveItem(Cliente& Cliente, bool& found);   
  void insertItem(Cliente Cliente); 
  void deleteItem(Cliente Cliente);  
  void print();
 private:
  int getHash(Cliente Cliente);
  int   max_items;
  int   length;
  Cliente* structure;
};
