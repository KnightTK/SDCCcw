

#include "State.h"

#include <utility>



/**
 * Current state of the game.
 */

/**
 * Display the description of the room the player is in. */

void State::announceLoc() const {
    this->currentRoom->describe();
}

/**
 * Constructor.
 * @param startRoom Pointer to the room to start in.
 */
State::State(Room *startRoom) : currentRoom(startRoom), strength(100){
    stateVector = {};
};

/**
 * Move to a specified room and print its description.
 * @param target Pointer to the room to move to.
 */
void State::goTo(Room *target) {
    this->currentRoom = target;
    this->announceLoc();
}

/**
 * Return a pointer to the current room.
 * @return Pointer to the current room.
 */
Room* State::getCurrentRoom() const {
    return this->currentRoom;
}

std::list<GameObject*> State::getInventory() {
    return  State::inventory;
}

void State::addObject(GameObject *object) {
    State::inventory.push_back(object);
}

int State::getStrength() const {
    return strength;
}

//void State::addToStrength(State _state, int _strength) {
//    _state.strength += _strength;
//    if(_state.strength > 100){
//        _state.strength = 100;
//    } else if(_state.strength < 0) {
//        _state.strength = 0;
//    }
//}


void State::eatObject(GameObject *object) {
    if(object->isFood()){
        this->strength += ((FoodObject*) object)->getEnergy();
        if(this->strength > 100){
            this->strength = 100;
        } else if (this->strength < 0){
            this->strength = 0;
        }
        this->inventory.remove(object);
        std::cout<<"Successfully eating food, your current strength is: "<<this->getStrength()<<std::endl;
    } else {
        std::cout<<"You can't eat this object. Because it is not a food..."<<std::endl;
    }
}


void State::removeObject(GameObject *object) {
    inventory.remove(object);
}

void State::setStrength(int _strength) {
    State::strength = _strength;
}

void State::addState(std::vector<int> subVector) {
    this->stateVector.push_back(subVector);
}

std::vector<std::vector<int>> State::getStateVector() {
    return this->stateVector;
}

void State::setStateVector(std::vector<std::vector<int>> stateBuffer) {
    this->stateVector = std::move(stateBuffer);
}

void State::setCurrentRoom(Room *room) {
    State::currentRoom = room;
}

void State::clearInventory() {
    this->inventory.clear();
}
