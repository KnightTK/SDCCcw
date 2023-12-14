//
// Created by 17129 on 2023/11/7.
//


#include <iostream>
#include "GameObject.h"


std::list<GameObject*> GameObject::allObjects;

GameObject::GameObject(const string* _shortName, const string* _longDescription, const string* _key, const int _index) :
    shortName(_shortName), longDescription(_longDescription), key(_key), index(_index)
{
GameObject::allObjects.push_back(this);
}


GameObject* GameObject::addObject(const string* _shortName, const string* _longDescription, const string* _key, int _index, Room* room) {
    auto * newObject = new GameObject(_shortName, _longDescription, _key, _index);
    room->Room::addObject(newObject);
    return newObject;
}





const string *GameObject::getShortName() const {
    return shortName;
}

const string *GameObject::getLongDescription() const {
    return longDescription;
}

const string *GameObject::getKey() const {
    return key;
}

bool GameObject::isFood() {
    return false;
}

int GameObject::getIndex() const {
    return index;
}


