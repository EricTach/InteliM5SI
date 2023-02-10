#include "cliente.h"

Cliente::Cliente(){
  this->imei   = -1;
  this->login = "";
};  
Cliente::Cliente(int imei, std::string login){
  this->imei    = imei;
  this->login  = login;
}
string Cliente::getLogin() const {
  return login;
}
int Cliente::getImei() const{
  return imei;
}