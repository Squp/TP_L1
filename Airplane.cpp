#include "Airplane.hpp"
/*public*/
  Airplane::Airplane(const std::string& _volume, const std::string& _citirs, int _size, const std::string& _name, const std::string& _type)
	  :_volume(_volume), _citirs(_citirs), _size(_size), _name(_name), _type(_type) {}
  Airplane::Airplane(const Airplane& g):
  _volume(g._volume), _citirs(g._citirs), _size(g._size), _name(g._name), _type(g._type){}
  Airplane::~Airplane(){}
/*геттеры сеттеры*/
  std::string& Airplane::type(){return _type;}
  int& Airplane::size(){return _size;}
  std::string& Airplane::volume(){return _volume;}//объём перевозимого груза
  std::string& Airplane::citirs(){return _citirs;}//в какие города осуществляет поездки
  std::string& Airplane::name(){return _name;}//наименование/модель

std::istream& operator>>(std::istream& in, Airplane& g){
   if(!(in >> g._name >> g._citirs >> g._volume >> g._size >> g._type)) throw Exception("reading exception");
   return in;
}
std::ostream& operator<<(std::ostream& out, const Airplane& g){
	out << g._name << '\t' << g._citirs << '\t' << g._volume << '\t' << g._size << '\t' << g._type;
	return out;

}
