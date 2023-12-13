
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
#include <fstream>
#include <sstream>



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

    auto * f1 = FoodObject::addObject(&food1name, &food1desc, &food1key, 7, r1);
    auto * f2 = FoodObject::addObject(&food2name, &food2desc, &food2key, -18, r1);
    auto * f3 = FoodObject::addObject(&food3name, &food3desc, &food3key, 400, r2);

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


void saveGame(string fileName){
    std::ofstream saveFile(fileName);
    if (saveFile.is_open()){
        saveFile << *currentState->getCurrentRoom()->getName() << std::endl;

        saveFile.close();
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
    exit(0);
}


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

        std::stringstream inputCommandStream(commandBuffer);
        string firstWord, secondWord, uselessWord;
        inputCommandStream >> firstWord >> secondWord >> uselessWord;
        if (!uselessWord.empty()){
            wrapOut(&badCommand);
            wrapEndPara();
            continue;
        }


        /* The first word of a command would normally be the verb. The first word is the text before the first
         * space, or if there is no space, the whole string. */
        auto endOfVerb = static_cast<uint8_t>(commandBuffer.find(' '));
        auto endOfSecond = static_cast<uint8_t>(commandBuffer.find(' '));
        bool isSecond = false;

        if (endOfVerb != static_cast<uint8_t>(-1)) {
            endOfSecond = commandBuffer.find(' ', endOfVerb + 1);
            isSecond = true;
        }


        for (auto iter: directionMap) {
            if (firstWord == iter.first) {
                commandOk = true;
                gotoTarget(iter.second);
                if (!secondWord.empty()) {

                    bool isExist = false;
                    for (auto secondOfObject: GameObject::allObjects) {
                        if (secondWord == *secondOfObject->getKey()) {
                            isExist = true;
                            bool searchSuccess = false;

                            for (auto item_room: currentState->getCurrentRoom()->getGameObjects()) {
                                if (secondWord == *item_room->getKey()) {
                                    std::cout << "Find it in the room!" << std::endl;
                                    searchSuccess = true;
                                    break;
                                }
                            }

                            if (!searchSuccess) {
                                for (auto item_inventory: currentState->getInventory()) {
                                    if (secondWord == *item_inventory->getKey()) {
                                        std::cout << "Find it in the inventory!" << std::endl;
                                        searchSuccess = true;
                                        break;
                                    }
                                }
                            }

                            if (!searchSuccess){
                                wrapOut(&inOtherRoom);
                                wrapEndPara();
                                commandBuffer.clear();
                            }
                        }
                    }

                    if (!isExist){
                        wrapOut(&noExist);
                        wrapEndPara();
                        commandBuffer.clear();
                    }

                    break;

                } else {
                    break;
                }
            }
        }




        if (firstWord == "get") {
            commandOk = true;

            if (secondWord.empty()) {
                std::cout << "Please enter the key of the object which you want to get -";
                inputCommand(&commandBuffer);

                inputCommandStream.str("");
                inputCommandStream.clear();

                inputCommandStream << commandBuffer;
                inputCommandStream >> secondWord;
            }

            bool ifExist = false;
            for (auto iter: GameObject::allObjects) {
                if (secondWord == *iter->getKey()) {
                    ifExist = true;
                    bool searchSuccess = false;

                    for (auto item_room: currentState->getCurrentRoom()->getGameObjects()) {
                        if (secondWord == *item_room->getKey()) {
                            currentState->addObject(item_room);
                            currentState->getCurrentRoom()->removeObject(item_room);
                            std::cout << "The object is successfully transferred to the inventory" << std::endl;
                            searchSuccess = true;
                            break;
                        }
                    }

                    if (!searchSuccess) {
                        for (auto item_inventory: currentState->getInventory()) {
                            if (secondWord == *item_inventory->getKey()) {
                                std::cout << "Already in inventory" << std::endl;
                                searchSuccess = true;
                                break;
                            }
                        }
                    }

                    if(!searchSuccess) {
                        wrapOut(&inOtherRoom);
                        wrapEndPara();
                        commandBuffer.clear();
                    }
                }
            }
            if (!ifExist){
                wrapOut(&noExist);
                wrapEndPara();
                commandBuffer.clear();
            }
        }


        if (firstWord == "drop") {
            commandOk = true;
            if (currentState->getInventory().empty()){
                std::cout << "Your inventory is empty." << std::endl;
            } else {

                if (secondWord.empty()) {
                    std::cout << "Please enter the key of the object which you want to drop -";
                    inputCommand(&commandBuffer);

                    inputCommandStream.str("");
                    inputCommandStream.clear();

                    inputCommandStream << commandBuffer;
                    inputCommandStream >> secondWord;
                }

                bool ifExist = false;
                for (auto iter: GameObject::allObjects) {
                    if (secondWord == *iter->getKey()) {
                        ifExist = true;
                        bool searchSuccess = false;

                        for (auto item_room: currentState->getCurrentRoom()->getGameObjects()) {
                            if (secondWord == *item_room->getKey()) {
                                std::cout << "The item is already in the room." << std::endl;
                                searchSuccess = true;
                                break;
                            }
                        }

                        if (!searchSuccess) {
                            for (auto item_inventory: currentState->getInventory()) {
                                if (secondWord == *item_inventory->getKey()) {
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
                            commandBuffer.clear();
                        }
                    }
                }
                if (!ifExist) {
                    wrapOut(&noExist);
                    wrapEndPara();
                    commandBuffer.clear();
                }
            }
        }


        if (firstWord == "inventory" && secondWord.empty()) {
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


        if (firstWord == "examine") {
            commandOk = true;

            if (secondWord.empty()) {
                std::cout << "Please enter the name of the object which you want to examine -";
                inputCommand(&commandBuffer);

                inputCommandStream.str("");
                inputCommandStream.clear();

                inputCommandStream << commandBuffer;
                inputCommandStream >> secondWord;
            }

            bool ifExist = false;
            for (auto iter: GameObject::allObjects) {
                if (secondWord == *iter->getShortName()) {
                    ifExist = true;
                    std::cout << *iter->getLongDescription() << std::endl;
                    break;
                }
            }
            if (!ifExist) {
                wrapOut(&noExist);
                wrapEndPara();
                commandBuffer.clear();
            }
        }


        if (firstWord == "eat") {
            commandOk = true;

            if (currentState->getInventory().empty()) {
                std::cout << "There is nothing in the inventory..." << std::endl;
            } else {
                if (secondWord.empty()) {
                    std::cout << "Please enter the key of the object which you want to eat -";
                    inputCommand(&commandBuffer);

                    inputCommandStream.str("");
                    inputCommandStream.clear();

                    inputCommandStream << commandBuffer;
                    inputCommandStream >> secondWord;
                }

                bool eatSuccess = false;
                for (auto iter: currentState->getInventory()) {
                    if (secondWord == *iter->getKey()) {
                        currentState->eatObject(iter);
                        eatSuccess = true;
                        break;
                    }
                }
                if (!eatSuccess){
                    std::cout << "You don't have this food in your inventory..." << std::endl;
                    commandBuffer.clear();
                }
            }
        }


        if(firstWord == "save"){
            std::cout <<"please enter: ";
            inputCommand(&commandBuffer);
            saveGame(commandBuffer + ".txt");
        }



//        if (commandBuffer.compare(0, endOfVerb, "c") == 0){
//            commandOk = true;
//            std::cout<<"current strength: "<<currentState->getStrength()<<std::endl;
//        }


        /* Quit command */
        if ((firstWord == "quit") || currentState->getStrength()<=0) {
            commandOk = true;
            gameOver = true;
        }

        /* If commandOk hasn't been set, command wasn't understood, display error message */
        if (!commandOk) {
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