//
// Created by 17129 on 2023/11/7.
//

#ifndef TEXTADV_GAMEOBJECT_H
#define TEXTADV_GAMEOBJECT_H

#include <string>
#include <forward_list>
#include <list>




using std::string;

class GameObject{
    string type;   //Give a type attribute to distinguish object types.
public:
    virtual void useObject();
    GameObject(const string* _shortName, const string* _longDescription, const string* _key);
    const string* shortName;
    const string* longDescription;
    const string* key;
    static std::list<GameObject*> allObjects;
    static void addObject(GameObject* object);
    virtual string getType();
};

#endif //TEXTADV_GAMEOBJECT_H