#pragma once
#include "Base.hpp"

class Car: public Base{
protected:
  std::string _volume;//объём перевозимого груза
  std::string _citirs;//в какие города осуществляет поездки
  std::string _name;//наименование/модель
  std::string _mark;//марка
  std::string _times;//время для каждого города
  int _year;//год выпуска
public:
  Car(const std::string& _times = "", const std::string& _volume = "", const std::string& _citirs = "", int _year = 0, const std::string& _name = "", const std::string& _mark = "");
  Car(const Car& g);
  virtual ~Car();
  /*геттеры сеттеры*/
  int& year();
  std::string& mark();
  std::string& times();
  std::string& volume();//объём перевозимого груза
  std::string& citirs();//в какие города осуществляет поездки
  std::string& name();//наименование/модель

  friend std::istream& operator>>(std::istream& in, Car& g);
  friend std::ostream& operator<<(std::ostream& out, const Car& g); 
};
