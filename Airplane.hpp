#pragma once
#include "Base.hpp"

class Airplane: public Base{
protected:
  std::string _volume;//объём перевозимого груза
  std::string _citirs;//в какие города осуществляет поездки
  std::string _name;//наименование/модель
  std::string _type;//тип
  int _size;//габариты
public:
  Airplane(const std::string& _volume = "", const std::string& _citirs = "", int _size = 0, const std::string& _name = "", const std::string& _type = "");
  Airplane(const Airplane& g);
  virtual ~Airplane();
  /*геттеры сеттеры*/
  std::string& type();
  int& size();
  std::string& volume();//объём перевозимого груза
  std::string& citirs();//в какие города осуществляет поездки
  std::string& name();//наименование/модель

  friend std::istream& operator>>(std::istream& in, Airplane& g);
  friend std::ostream& operator<<(std::ostream& out, const Airplane& g); 
};
