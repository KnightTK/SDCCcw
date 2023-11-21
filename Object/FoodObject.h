//
// Created by 17129 on 2023/11/7.
//

#ifndef TEXTADV_FOODOBJECT_H
#define TEXTADV_FOODOBJECT_H

#include "GameObject.h"




class FoodObject : public GameObject{
private:
    int energy;      //limited in a range of 1-10
public:
    FoodObject(const string* _shortName, const string* _longDescription, const string* _key, int _energy);
    int getEnergy() const;
    static FoodObject* addObject(const std::string *_shortName, const std::string *_longDescription, const std::string *_key, int _energy, Room *room);

};

#endif //TEXTADV_FOODOBJECT_H