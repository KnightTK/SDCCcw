
#include <iostream>
#include <iomanip>
#include <memory>
#include <iterator>
#include <vector>
#include <forward_list>
#include "Room.h"
#include "wordwrap.h"
#include "State.h"
#include "strings.h"
#include "FoodObject.h"
#include <map>



using std::string;
using std::unique_ptr;


string commandBuffer;
State *currentState;

/**
 * Print out the command prompt then read a command into the provided string buffer.
 * @param buffer Pointer to the string buffer to use.
 */
void inputCommand(string *buffer) {
    buffer->clear();
    std::cout << "> ";
    std::getline(std::cin, *buffer);
}

/**
 * Sets up the map.
 */
void initRooms() {
    auto * r7 = new Room(&r7name, &r7desc);
    auto * r6 = new Room(&r6name, &r6desc);
    auto * r5 = new Room(&r5name, &r5desc);
    auto * r4 = new Room(&r4name, &r4desc);


    auto * r2 = new Room(&r2name, &r2desc);
    auto * r1 = new Room(&r1name, &r1desc);


    Room room3(&r1name,&r1desc);
    Room* r3=&room3;
    Room::addRoom(r1);
    Room::addRoom(r2);
    Room::addRoom(r3);

    Room::addRoom(r4);
    Room::addRoom(r5);
    Room::addRoom(r6);
    Room::addRoom(r7);

    auto * o1 = new GameObject(&o1name, &o1desc, &o1key);
    auto * o2 = new GameObject(&o2name, &o2desc, &o2key);
    auto * o3 = new GameObject(&o3name, &o3desc, &o3key);
    r1->addObject(o1);
    r1->addObject(o2);
    r2->addObject(o3);

    auto * f1 = new FoodObject(&food1name, &food1desc, &food1key, 500);
    r1->addObject(f1);

    r1->setNorth(r2);
    r2->setSouth(r1);
    r1->setSouth(r5);
    r5->setNorth(r1);
    r1->setWest(r4);
    r4->setEast(r1);
    r1->setEast(r6);
    r6->setWest(r1);
    r6->setEast(r7);
    r7->setWest(r6);

}

/**
 * Sets up the game state.
 */
void initState() {
    currentState = new State(Room::rooms.front());
}




void gotoTarget(int direction){
    Room* targetRoom = currentState->getCurrentRoom()->getDirection(direction);
    if (targetRoom == nullptr){
        wrapOut(&badExit);
        wrapEndPara();
    } else {
        currentState->goTo(targetRoom);
    }
}

std::map<std::string,int> directionMap = {
        {"north", 1},
        {"n", 1},
        {"south", 2},
        {"s", 2},
        {"west", 3},
        {"w", 3},
        {"east", 4},
        {"e", 4},
};







/**
 * The main game loop.
 */
void gameLoop() {
    bool gameOver=false;
    while (!gameOver) {
        /* Ask for a command. */
        bool commandOk = false;
        inputCommand(&commandBuffer);

        /* The first word of a command would normally be the verb. The first word is the text before the first
         * space, or if there is no space, the whole string. */
        auto endOfVerb = static_cast<uint8_t>(commandBuffer.find(' '));


        for (auto  iter : directionMap) {
            if(commandBuffer.compare(0,endOfVerb,iter.first)==0){
                commandOk = true;
                gotoTarget(iter.second);
                break;
            }
        }


        for (auto iter : GameObject::allObjects) {
            if (commandBuffer.compare(0, endOfVerb, *iter->key) == 0){
                commandOk = true;

                for (auto item_room : currentState->getCurrentRoom()->gameObjects){
                    if (commandBuffer.compare(0, endOfVerb, *item_room->key) == 0){
                        std::cout<<"Found it in the room!"<<std::endl;
                        break;
                    }
                }

                for (auto item_inventory : State::getInventory()) {
                    if (commandBuffer.compare(0, endOfVerb, *item_inventory->key) == 0){
                        std::cout<<"Found it in the inventory!"<<std::endl;
                        break;
                    }
                }
            }
        }








        if (commandBuffer.compare(0, endOfVerb, "get") == 0){
            commandOk = true;
            std::cout<<"Please enter the key of the object which you want to get: "<<std::endl;
            inputCommand(&commandBuffer);
            auto endOfVerb = static_cast<uint8_t>(commandBuffer.find(' '));

            for (auto iter : GameObject::allObjects) {
                if (commandBuffer.compare(0, endOfVerb, *iter->key) == 0){

                    for (auto item_room : currentState->getCurrentRoom()->gameObjects){
                        if (commandBuffer.compare(0, endOfVerb, *item_room->key) == 0){
                            currentState->addObject(iter);
                            currentState->getCurrentRoom()->gameObjects.remove(iter);
                            std::cout<<"The object was successfully transferred to the inventory"<<std::endl;
                            goto FLAG;
                        }
                    }

                    for (auto item_inventory : currentState->getInventory()) {
                        if (commandBuffer.compare(0, endOfVerb, *item_inventory->key) == 0){
                            std::cout<<"Already in inventory"<<std::endl;
                            goto FLAG;
                        }
                    }

                    std::cout<<"The object is not in the current room or in inventory, it may be in another room"<<std::endl;
                    goto FLAG;
                }
            }
            std::cout<<"The object does not exist"<<std::endl;
        }


        if (commandBuffer.compare(0, endOfVerb, "drop") == 0){
            commandOk = true;
            std::cout<<"Please enter the key of the object which you want to drop: "<<std::endl;
            inputCommand(&commandBuffer);
            auto endOfVerb = static_cast<uint8_t>(commandBuffer.find(' '));

            for (auto iter : GameObject::allObjects) {
                if (commandBuffer.compare(0, endOfVerb, *iter->key) == 0){

                    for (auto item_room : currentState->getCurrentRoom()->gameObjects){
                        if (commandBuffer.compare(0, endOfVerb, *item_room->key) == 0){
                            std::cout<<"The item is already in the room."<<std::endl;
                            goto FLAG;
                        }
                    }

                    for (auto item_inventory : State::getInventory()) {
                        if (commandBuffer.compare(0, endOfVerb, *item_inventory->key) == 0){
                            currentState->getCurrentRoom()->addObject(iter);
                            State::getInventory().remove(iter);
                            std::cout<<"The object was successfully dropped!"<<std::endl;
                            goto FLAG;
                        }
                    }

                    std::cout<<"The object is not in the current room or in inventory, it may be in another room"<<std::endl;
                    goto FLAG;
                }
            }
            std::cout<<"The object does not exist"<<std::endl;
        }



        if(commandBuffer.compare(0, endOfVerb, "inventory") == 0){
            commandOk = true;
            if (State::getInventory().empty()){
                std::cout<<"There is nothing in the inventory..."<<std::endl;
            } else {
                for (auto iter : State::getInventory()) {
                    wrapOut(iter->shortName);
                    wrapEndPara();
                }
            }
        }


        if(commandBuffer.compare(0, endOfVerb, "examine") == 0) {
            commandOk = true;
            std::cout<<"Please enter the name of the object which you want to examine: "<<std::endl;
            inputCommand(&commandBuffer);
            auto endOfVerb = static_cast<uint8_t>(commandBuffer.find(' '));

            for (auto iter : GameObject::allObjects) {
                if (commandBuffer.compare(0, endOfVerb, *iter->shortName) == 0){
                    std::cout<<*iter->longDescription<<std::endl;
                    goto FLAG;
                }
            }
            std::cout<<"The object does not exist"<<std::endl;
        }

        if (commandBuffer.compare(0, endOfVerb, "eat") == 0){
            commandOk = true;
            if (State::getInventory().empty()){
                std::cout<<"There is nothing in the inventory..."<<std::endl;
            }else{
                std::cout<<"Please enter the key of the object which you want to eat: "<<std::endl;
                inputCommand(&commandBuffer);
                auto endOfVerb = static_cast<uint8_t>(commandBuffer.find(' '));

                for (auto iter : State::getInventory()) {
                    if (commandBuffer.compare(0, endOfVerb, *iter->key) == 0){
                        if (iter->getType().compare("food") == 0){
                            iter->useObject();
                            std::cout<<"Successfully eating food, your current strength is: "<<State::strength<<std::endl;
                            goto FLAG;
                        } else {
                            std::cout<<"You can't eat this object. Because it is not a food..."<<std::endl;
                            goto FLAG;
                        }

                    }
                }
                std::cout<<"You don't have this food in your inventory..."<<std::endl;
            }
        }








        FLAG:










        /* Quit command */
        if ((commandBuffer.compare(0,endOfVerb,"quit") == 0)) {
            commandOk = true;
            gameOver = true;
        }

        /* If commandOk hasn't been set, command wasn't understood, display error message */
        if(!commandOk) {
            wrapOut(&badCommand);
            wrapEndPara();
        }
    }
}


int main() {
    initWordWrap();
    initRooms();
    initState();
    currentState->announceLoc();
    gameLoop();
    return 0;
}