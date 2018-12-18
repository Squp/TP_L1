#include "Car.hpp"
/*public*/
  Car::Car(const std::string& _times, const std::string& _volume, const std::string& _citirs, int _year, const std::string& _name, const std::string& _mark)
	  : _times(_times), _volume(_volume), _citirs(_citirs), _year(_year), _name(_name), _mark(_mark) {}
  Car::Car(const Car& g):
  _times(g._times), _volume(g._volume), _citirs(g._citirs), _year(g._year), _name(g._name), _mark(g._mark){}
  Car::~Car(){}
/*геттеры сеттеры*/
  int& Car::year(){return _year;}
  std::string& Car::mark(){return _mark;}
  std::string& Car::times(){return _times;}
  std::string& Car::volume(){return _volume;}//объём перевозимого груза
  std::string& Car::citirs(){return _citirs;}//в какие города осуществляет поездки
  std::string& Car::name(){return _name;}//наименование/модель

std::istream& operator>>(std::istream& in, Car& g){
   if(!(in >> g._times >> g._volume>> g._citirs>> g._year>> g._name>> g._mark)){
	   throw Exception("reading exception");
   }
   return in;
}
std::ostream& operator<<(std::ostream& out, const Car& g){
	out << g._times << '\t' << g._volume << '\t' << g._citirs<< '\t' << g._year<< '\t' << g._name<< '\t' << g._mark;
	return out;

}
