//
// Created by 17129 on 2023/11/7.
//

#ifndef TEXTADV_FOODOBJECT_H
#define TEXTADV_FOODOBJECT_H

#include "GameObject.h"




class FoodObject : public GameObject{
    int energy;      //limited in a range of 1-10
    string type;
public:
    void useObject() override;
    FoodObject(const string* _shortName, const string* _longDescription, const string* _key, int _energy);
    int getEnergy() const;
    string getType() override;
};

#endif //TEXTADV_FOODOBJECT_H