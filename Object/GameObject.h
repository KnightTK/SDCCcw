//
// Created by 17129 on 2023/11/7.
//

#ifndef TEXTADV_GAMEOBJECT_H
#define TEXTADV_GAMEOBJECT_H

#include <string>
#include <forward_list>
#include <list>
#include "../RoomState/Room.h"


using std::string;

class Room;


class GameObject{
private:
    const string* shortName;
    const string* longDescription;
    const string* key;
public:
    virtual bool isFood();

    GameObject(const string* _shortName, const string* _longDescription, const string* _key);

    static std::list<GameObject*> allObjects;

    static GameObject* addObject(const string* _shortName, const string* _longDescription, const string* _key, Room* room);

    const string *getShortName() const;
    const string *getLongDescription() const;
    const string *getKey() const;
};

#endif //TEXTADV_GAMEOBJECT_H