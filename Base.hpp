#pragma once
#include "Exception.hpp"
#include <string>
#include <limits>
 class Base{
 public:
	 virtual std::string& volume() = 0;//объём перевозимого груза
	 virtual std::string& citirs() = 0;//в какие города осуществляет поездки
	 virtual std::string& name() = 0;//наименование/модель
	 virtual ~Base(){}
 };
