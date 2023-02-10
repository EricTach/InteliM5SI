#include "hash.h"
#include <iostream>

using namespace std;

int main() {
  Hash clientesHash(9); //Determina o tamanho da tabela hash
  
  //caso de teste 1: Colocar novos imeis e logins nas strings
  int imeis[7] = {1345, 31300, 1234,
     49001, 52202, 65606,
     91234}; //Imeis utilizados para testes
  string login[7] = {"Sergiogames@gmail.com", "Raul.arnaldo@imeis.com",  "Rogeriomatut@imeis.com",  "Carloso@imeis.com","Lucas@imeis.com", "Maria@imeis.com", "Samanta@imeis.com"}; //logins utilizados para testes

   //Caso de teste 2: Adicionar as strings na tabela hash, adicionando o login e imei
  for (int i = 0; i < 7; i++) {
    Cliente cliente = Cliente(imeis[i], login[i]);
    clientesHash.insertItem(cliente);
  }

  //Caso de teste 3: Printa a tabela e verfica se a tabela esta configurada corretamente
  clientesHash.print();
  cout << "------------------------------" << endl;

  //Caso de teste 4: Busca determinado cliente dentro da tabela hash (Rogerio)
  Cliente cliente(1234, "");
  bool found = false;
  clientesHash.retrieveItem(cliente, found);
  cout << cliente.getLogin() << " -> " << found << endl;

  cout << "------------------------------" << endl;
  
  //Caso de teste 5: Deleta o cliente escolhido  (Rogerio) da tabela hash
  clientesHash.deleteItem(cliente);
  clientesHash.print();

  //Case de teste 6: Verifica quantos fatores tem dentro da tabela hash e confirma que todos os fatores foram corretamente adicionados
  cout << "------------------------------" << endl;
  cout << "O tamanho da tabela Hash é de : " << clientesHash.getLength() + 1 <<endl;
  cout << "------------------------------" << endl;

  //Finalização
  cout << "Fim" << endl;
}