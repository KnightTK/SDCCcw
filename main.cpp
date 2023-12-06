
#include <iostream>
#include <iomanip>
#include <memory>
#include <iterator>
#include <vector>
#include <forward_list>
#include "RoomState/Room.h"
#include "wordwrap.h"
#include "RoomState/State.h"
#include "strings.h"
#include "Object/FoodObject.h"
#include <map>
#include <thread>
#include <chrono>
#include <atomic>



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
    auto * r1 = Room::addRoom(&r1name, &r1desc);
    auto * r2 = Room::addRoom(&r2name, &r2desc);

    auto * r4 = Room::addRoom(&r4name, &r4desc);
    auto * r5 = Room::addRoom(&r5name, &r5desc);
    auto * r6 = Room::addRoom(&r6name, &r6desc);
    auto * r7 = Room::addRoom(&r7name, &r7desc);

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

    auto * o1 = GameObject::addObject(&o1name, &o1desc, &o1key, r1);
    auto * o2 = GameObject::addObject(&o2name, &o2desc, &o2key, r1);
    auto * o3 = GameObject::addObject(&o3name, &o3desc, &o3key, r2);

    auto * f1 = FoodObject::addObject(&food1name, &food1desc, &food1key, 2, r1);
    auto * f2 = FoodObject::addObject(&food2name, &food2desc, &food2key, 400, r1);
    auto * f3 = FoodObject::addObject(&food3name, &food3desc, &food3key, -10, r2);

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


void strengthCount(){
    while (true) {
        std::this_thread::sleep_for(std::chrono::minutes (1));
        currentState->setStrength(currentState->getStrength() - 1);
        if (currentState->getStrength() <= 0){
            break;
        }
    }
    std::cout<<"You don't have enough strength. Game over."<<std::endl;
    exit(0);
}



/**
 * The main game loop.
 */
void gameLoop() {
//    std::atomic<int> strength;

    std::thread myThread (strengthCount);
    myThread.detach();

    bool gameOver = false;
    while (!gameOver) {
        /* Ask for a command. */
        bool commandOk = false;
        inputCommand(&commandBuffer);

        /* The first word of a command would normally be the verb. The first word is the text before the first
         * space, or if there is no space, the whole string. */
        auto endOfVerb = static_cast<uint8_t>(commandBuffer.find(' '));


        for (auto iter: directionMap) {
            if (commandBuffer.compare(0, endOfVerb, iter.first) == 0) {
                commandOk = true;
                gotoTarget(iter.second);
                break;
            }
        }



        for (auto iter: GameObject::allObjects) {
            if (commandBuffer.compare(0, endOfVerb, *iter->getKey()) == 0) {
                bool searchSuccess = false;
                commandOk = true;

                for (auto item_room: currentState->getCurrentRoom()->getGameObjects()) {
                    if (commandBuffer.compare(0, endOfVerb, *item_room->getKey()) == 0) {
                        std::cout << "Find it in the room!" << std::endl;
                        searchSuccess = true;
                        break;
                    }
                }

                if (!searchSuccess) {
                    for (auto item_inventory: currentState->getInventory()) {
                        if (commandBuffer.compare(0, endOfVerb, *item_inventory->getKey()) == 0) {
                            std::cout << "Find it in the inventory!" << std::endl;
                            searchSuccess = true;
                            break;
                        }
                    }
                }

                if (!searchSuccess){
                    wrapOut(&inOtherRoom);
                    wrapEndPara();
                }
            }
        }



        if (commandBuffer.compare(0, endOfVerb, "get") == 0) {
            commandOk = true;
            std::cout << "Please enter the key of the object which you want to get -";
            inputCommand(&commandBuffer);
            auto endOfVerb_get = static_cast<uint8_t>(commandBuffer.find(' '));

            bool ifExist = false;
            for (auto iter: GameObject::allObjects) {
                if (commandBuffer.compare(0, endOfVerb_get, *iter->getKey()) == 0) {
                    ifExist = true;
                    bool searchSuccess = false;

                    for (auto item_room: currentState->getCurrentRoom()->getGameObjects()) {
                        if (commandBuffer.compare(0, endOfVerb, *item_room->getKey()) == 0) {
                            currentState->addObject(item_room);
                            currentState->getCurrentRoom()->removeObject(item_room);
                            std::cout << "The object is successfully transferred to the inventory" << std::endl;
                            searchSuccess = true;
                            break;
                        }
                    }

                    if (!searchSuccess) {
                        for (auto item_inventory: currentState->getInventory()) {
                            if (commandBuffer.compare(0, endOfVerb, *item_inventory->getKey()) == 0) {
                                std::cout << "Already in inventory" << std::endl;
                                searchSuccess = true;
                                break;
                            }
                        }
                    }

                    if(!searchSuccess) {
                        wrapOut(&inOtherRoom);
                        wrapEndPara();
                    }
                }
            }
            if (!ifExist){
                wrapOut(&noExist);
                wrapEndPara();
            }
        }


        if (commandBuffer.compare(0, endOfVerb, "drop") == 0) {
            commandOk = true;
            std::cout << "Please enter the key of the object which you want to drop -";
            inputCommand(&commandBuffer);
            auto endOfVerb_drop = static_cast<uint8_t>(commandBuffer.find(' '));

            bool ifExist = false;
            for (auto iter: GameObject::allObjects) {
                if (commandBuffer.compare(0, endOfVerb_drop, *iter->getKey()) == 0) {
                    ifExist = true;
                    bool searchSuccess = false;

                    for (auto item_room: currentState->getCurrentRoom()->getGameObjects()) {
                        if (commandBuffer.compare(0, endOfVerb, *item_room->getKey()) == 0) {
                            std::cout << "The item is already in the room." << std::endl;
                            searchSuccess = true;
                            break;
                        }
                    }

                    if (!searchSuccess) {
                        for (auto item_inventory: currentState->getInventory()) {
                            if (commandBuffer.compare(0, endOfVerb, *item_inventory->getKey()) == 0) {
                                currentState->getCurrentRoom()->addObject(iter);
                                currentState->removeObject(iter);
                                std::cout << "The object is successfully dropped!" << std::endl;
                                searchSuccess = true;
                                break;
                            }
                        }
                    }

                    if (!searchSuccess) {
                        wrapOut(&inOtherRoom);
                        wrapEndPara();
                    }
                }
            }
            if (!ifExist) {
                wrapOut(&noExist);
                wrapEndPara();
            }
        }


        if (commandBuffer.compare(0, endOfVerb, "inventory") == 0) {
            commandOk = true;
            if (currentState->getInventory().empty()) {
                std::cout << "There is nothing in the inventory..." << std::endl;
            } else {
                for (auto iter: currentState->getInventory()) {
                    wrapOut(iter->getShortName());
                    wrapEndPara();
                }
            }
        }


        if (commandBuffer.compare(0, endOfVerb, "examine") == 0) {
            commandOk = true;
            std::cout << "Please enter the name of the object which you want to examine -";
            inputCommand(&commandBuffer);
            auto endOfVerb_examine = static_cast<uint8_t>(commandBuffer.find(' '));

            bool ifExist = false;
            for (auto iter: GameObject::allObjects) {
                if (commandBuffer.compare(0, endOfVerb_examine, *iter->getShortName()) == 0) {
                    std::cout << *iter->getLongDescription() << std::endl;
                    ifExist = true;
                    break;
                }
            }
            if (!ifExist) {
                wrapOut(&noExist);
                wrapEndPara();
            }
        }


        if (commandBuffer.compare(0, endOfVerb, "eat") == 0) {
            commandOk = true;
            if (currentState->getInventory().empty()) {
                std::cout << "There is nothing in the inventory..." << std::endl;
            } else {
                std::cout << "Please enter the key of the object which you want to eat -";
                inputCommand(&commandBuffer);
                auto endOfVerb_eat = static_cast<uint8_t>(commandBuffer.find(' '));

                bool eatSuccess = false;
                for (auto iter: currentState->getInventory()) {
                    if (commandBuffer.compare(0, endOfVerb_eat, *iter->getKey()) == 0) {
                        currentState->eatObject(iter);
                        currentState->removeObject(iter);
                        eatSuccess = true;
                        break;
                    }
                }
                if (!eatSuccess){
                    std::cout << "You don't have this food in your inventory..." << std::endl;
                }
            }
        }



        if (commandBuffer.compare(0, endOfVerb, "c") == 0){
            commandOk = true;
            std::cout<<"current strength: "<<currentState->getStrength()<<std::endl;
        }


        /* Quit command */
        if ((commandBuffer.compare(0, endOfVerb, "quit") == 0) || currentState->getStrength()<=0) {
            commandOk = true;
            gameOver = true;
        }

        /* If commandOk hasn't been set, command wasn't understood, display error message */
        if (!commandOk) {
            wrapOut(&badCommand);
            wrapEndPara();
        }
    }
//    if (gameOver){
//        myThread.detach();
//    }
}


int main() {
    initWordWrap();
    initRooms();
    initState();
    currentState->announceLoc();
    gameLoop();
    return 0;
}