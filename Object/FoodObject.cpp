//
// Created by 17129 on 2023/11/8.
//


#include "FoodObject.h"
#include "../RoomState/State.h"

FoodObject::FoodObject(const string *_shortName, const string *_longDescription, const string *_key, int _energy) :
        GameObject(_shortName, _longDescription, _key), energy(_energy) {
}


int FoodObject::getEnergy() const {
    if(this->energy>10){
        return 10;
    } else if (this->energy<0){
        return 1;
    } else {
        return this->energy;
    }
}


FoodObject* FoodObject::addObject(const std::string *_shortName, const std::string *_longDescription, const std::string *_key, int _energy, Room *room) {
    auto * newFood = new FoodObject(_shortName, _longDescription, _key, _energy);
    room->addObject(newFood);
    return newFood;
}

