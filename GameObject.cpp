//
// Created by 17129 on 2023/11/7.
//


#include <iostream>
#include "GameObject.h"


std::list<GameObject*> GameObject::allObjects;

GameObject::GameObject(const string* _shortName, const string* _longDescription, const string* _key) :
    shortName(_shortName), longDescription(_longDescription), key(_key), type("null")
{
GameObject::allObjects.push_back(this);
}

void GameObject::addObject(GameObject* object){
    GameObject::allObjects.push_back(object);
}

void GameObject::useObject() {
    std::cout<<"no error."<<std::endl;
}

string GameObject::getType() {
    return GameObject::type;
}


