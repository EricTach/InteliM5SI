#include <iostream>
using namespace std;

class Cliente{
private :
  int         imei;
  std::string login;  
public:  
  Cliente();
  Cliente(int imei, std::string login);
  string getLogin() const;
  int getImei() const;
};