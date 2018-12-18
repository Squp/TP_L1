#pragma once
#include "Base.hpp"

class Train: public Base{
protected:
  int _cnt;//количество вагонов
  int _year;//год
  std::string _volume;//объём перевозимого груза
  std::string _citirs;//в какие города осуществляет поездки
  std::string _name;//наименование/модель
public:
  Train(const std::string& _volume = "", const std::string& _citirs = "", int _year = 0, const std::string& _name = "", int _cnt = 0);
  Train(const Train& g);
  virtual ~Train();
  /*геттеры сеттеры*/
  int& cnt();
  int& year();
  std::string& volume();//объём перевозимого груза
  std::string& citirs();//в какие города осуществляет поездки
  std::string& name();//наименование/модель

  friend std::istream& operator>>(std::istream& in, Train& g);
  friend std::ostream& operator<<(std::ostream& out, const Train& g); 
};
