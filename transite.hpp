#pragma once
#include "Keeper.hpp"
#include "Airplane.hpp"
#include "Train.hpp"
#include "Car.hpp"
#include <string>
#include <iostream>
#include "Exception.hpp"

class Transite{//груозопереводчик
protected:
   Keeper<Car> _car;
   Keeper<Airplane> _airplane;
   Keeper<Train> _train;
public:
   Keeper<Car>& car();
   Keeper<Airplane>& airplane();
   Keeper<Train>& train();
};
