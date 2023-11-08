//
// Created by 17129 on 2023/11/8.
//


#include "FoodObject.h"
#include "State.h"

FoodObject::FoodObject(const string *_shortName, const string *_longDescription, const string *_key, int _energy) :
        GameObject(_shortName, _longDescription, _key), energy(_energy), type("food") {
}


int FoodObject::getEnergy() const {
    if(this->energy>10){
        return 10;
    } else if (this->energy<1){
        return 1;
    } else {
        return this->energy;
    }
}

void FoodObject::useObject() {
    State::strength += FoodObject::getEnergy();
    if (State::strength < 0){
        State::strength = 0;
    } else if(State::strength>100){
        State::strength = 100;
    }
}

string FoodObject::getType() {
    return this->type;
}
