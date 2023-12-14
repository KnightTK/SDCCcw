

#ifndef TEXTADV_STATE_H
#define TEXTADV_STATE_H


#include "Room.h"
#include "../Object/FoodObject.h"
#include <iostream>
#include <vector>

class State {
private:
    std::vector<std::vector<int>> stateVector;
    Room *currentRoom;
    std::list<GameObject*> inventory;
    int strength;
public:

    explicit State(Room *startRoom);
    void goTo(Room *target);
    void announceLoc() const;
    Room* getCurrentRoom() const;

    std::list<GameObject*> getInventory();

    int getStrength() const;
    void setStrength(int strength);

    void addObject(GameObject* object);
    void removeObject(GameObject* object);
    void eatObject(GameObject* object);

    void addState(std::vector<int> subVector);
    std::vector<std::vector<int>> getStateVector();
    void setStateVector(std::vector<std::vector<int>> stateBuffer);

    void setCurrentRoom(Room *room);
    void clearInventory();
};


#endif //TEXTADV_STATE_H
