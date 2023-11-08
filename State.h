

#ifndef TEXTADV_STATE_H
#define TEXTADV_STATE_H


#include "Room.h"

class State {
    Room *currentRoom;
public:
    static std::list<GameObject*> inventory;
    explicit State(Room *startRoom);
    void goTo(Room *target);
    void announceLoc() const;
    Room* getCurrentRoom() const;
    static std::list<GameObject*> getInventory() ;
    static void addObject(GameObject* object);
    static int strength;
};


#endif //TEXTADV_STATE_H
