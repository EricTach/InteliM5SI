#include "hash.h" 
#include <iostream>
using namespace std;

//Contrutor que ativa a Hash e aloca memória
Hash::Hash(int max) {  
  length = 0;
  max_items = max;
  structure = new Cliente[max_items];
}

//Desaloca a memória da estrutura de dados
Hash::~Hash(){
  delete [] structure;
}

//verifica se a tabela hash está cheia
bool Hash::isFull() const {
  return (length == max_items);
}

//verifica o número de itens armazenados na tabela hash
int Hash::getLength() const {
  return length;
}

//Recupera determinado item na tabela caso seja encontrado
//Utiliza "getHash" para encontrar a posição do item que está sendo procurado
void Hash::retrieveItem(Cliente& login, bool& found) {
  int startLoc = getHash(login);
  bool moreToSearch = true; 
  int location = startLoc;
  do {
    //Caso o item seja encontrado, ou não está na posição, para a busca
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

//insere um item na tabela
void Hash::insertItem(Cliente login) {
  int location;
  location = getHash(login);
  while (structure[location].getImei() > 0)
    location = (location + 1) % max_items;
  structure[location] = login;
  length++;
}

//Deleta um item dentro da tabela
//Utiliza a função "getHash" para encontrar a posição do item que deseja ser deletado
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
    structure[location] = Cliente(-2,""); //Coloca o valor de -2 no lugar do item deletado
    length--;
  }
}

//printa a tabela utilizando um loop
void Hash::print() {
  for (int i = 0; i < max_items; i++) {
    cout << i <<":"<< structure[i].getImei()<<", "<<structure[i].getLogin()<<endl;
  }
}

//Utilizado para identificar a posição de um determinado cliente
int Hash::getHash(Cliente login){
  return login.getImei() % max_items; //Obtem o resto da divisão, que é responsável pela criação da tabela hash
}

