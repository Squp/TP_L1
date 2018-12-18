#include "Train.hpp"
/*public*/
  Train::Train(const std::string& _volume, const std::string& _citirs, int _year, const std::string& _name, int _cnt)
	  :_year(_year), _volume(_volume), _citirs(_citirs), _name(_name), _cnt(_cnt){}
  Train::Train(const Train& g):
  _year(g._year), _volume(g._volume), _citirs(g._citirs), _name(g._name), _cnt(g._cnt){}
  Train::~Train(){}
/*геттеры сеттеры*/
  int& Train::cnt(){return _cnt;}
  int& Train::year(){return _year;}
  std::string& Train::volume(){return _volume;}//объём перевозимого груза
  std::string& Train::citirs(){return _citirs;}//в какие города осуществляет поездки
  std::string& Train::name(){return _name;}//наименование/модель

std::istream& operator>>(std::istream& in, Train& g){
   if(!(in >> g._name >> g._citirs >> g._volume >> g._year >> g._cnt)) throw Exception("reading exception");
   return in;
}
std::ostream& operator<<(std::ostream& out, const Train& g){
	out << g._name << '\t' << g._citirs << '\t' << g._volume << '\t' << g._year << '\t' << g._cnt;
	return out;

}
