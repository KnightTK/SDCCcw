
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
#include <string>


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
    auto * r1 = Room::addRoom(&r1name, &r1desc, 1);
    auto * r2 = Room::addRoom(&r2name, &r2desc, 2);

    auto * r4 = Room::addRoom(&r4name, &r4desc, 4);
    auto * r5 = Room::addRoom(&r5name, &r5desc, 5);
    auto * r6 = Room::addRoom(&r6name, &r6desc, 6);
    auto * r7 = Room::addRoom(&r7name, &r7desc, 7);

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

    auto * o1 = GameObject::addObject(&o1name, &o1desc, &o1key, 1, r1);
    auto * o2 = GameObject::addObject(&o2name, &o2desc, &o2key, 2, r1);
    auto * o3 = GameObject::addObject(&o3name, &o3desc, &o3key, 3, r2);

    auto * f1 = FoodObject::addObject(&food1name, &food1desc, &food1key, 4, 7, r1);
    auto * f2 = FoodObject::addObject(&food2name, &food2desc, &food2key, 5, -18, r1);
    auto * f3 = FoodObject::addObject(&food3name, &food3desc, &food3key, 6, 400, r2);
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



bool isFile(string fileName){
    std::ifstream testIsFile(fileName);
    if (testIsFile.is_open()){
        std::cout << "The file exist." << std::endl;
        testIsFile.close();
        return true;
    } else {
        std::cout << "nooooooooo" << std::endl;
        testIsFile.close();
        return false;
    }
}

void saveGame(string fileName){
    std::vector<std::vector<int>> saveVectorBuffer;
    //currentRoom:
    std::vector<int> currentRoomState = {0, currentState->getCurrentRoom()->getIndex(), 0};
    saveVectorBuffer.push_back(currentRoomState);

    //currentStrength:
    std::vector<int> currentStrengthState = {1, currentState->getStrength(), 0};
    saveVectorBuffer.push_back(currentStrengthState);

    //roomObject:
    for (auto room : Room::rooms){
        if (!room->getGameObjects().empty()){
            for (auto obj : room->getGameObjects()){
                std::vector<int> roomObject = {2, room->getIndex(), obj->getIndex()};
                saveVectorBuffer.push_back(roomObject);
            }
        } else if (room->getGameObjects().empty()){
            std::vector<int> roomObject = {2, room->getIndex(), 0};
            saveVectorBuffer.push_back(roomObject);
        }
    }

    //currentInventory:
    if (!currentState->getInventory().empty()) {
        for (auto obj: currentState->getInventory()) {
            std::vector<int> currentInventory = {3, obj->getIndex(), 0};
            saveVectorBuffer.push_back(currentInventory);
        }
    } else if (currentState->getInventory().empty()){
        std::vector<int> currentInventory = {3, 0, 0};
        saveVectorBuffer.push_back(currentInventory);
    }

    currentState->setStateVector(saveVectorBuffer);

    std::ofstream saveFile(fileName);
    if (saveFile.is_open()){
//        saveFile << currentState->getStateVector() << std::endl;

//        std::copy(currentState->getStateVector().begin()->begin(), currentState->getStateVector().begin()->end(), std::ostreambuf_iterator<char>(saveFile));

        for (auto row : currentState->getStateVector()){
            for (auto value : row){
                saveFile << value << " ";
            }
            saveFile << "\n";
        }

        saveFile.close();
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
    exit(0);
}

void loadGame(string fileName){
    if (isFile(fileName)){
        std::cout << "Are you sure you want to read the current archive?"<<std::endl;
        std::ifstream loadFile(fileName);
        std::vector<std::vector<int>> stateBuffer;
        string eachLine;
        while (getline(loadFile, eachLine)) {
            std::stringstream ss(eachLine);
            std::vector<int> row;
            int action, obj1, obj2;
            ss >> action >> obj1 >> obj2;
            row.push_back(action);
            row.push_back(obj1);
            row.push_back(obj2);
            stateBuffer.push_back(row);
        }
        currentState->setStateVector(stateBuffer);
        loadFile.close();

        //clear all things
        currentState->clearInventory();
        for (auto room : Room::rooms){
            room->clearObject();
        }

        //load all things
        for(auto loadLine : currentState->getStateVector()){
            int action, obj1, obj2;
            action = loadLine[0];
            obj1 = loadLine[1];
            obj2 = loadLine[2];

            switch (action) {
                case 0:
                    for (auto room : Room::rooms){
                        if (room->getIndex() == obj1){
                            currentState->setCurrentRoom(room);
                            break;
                        }
                    }
                    break;
                case 1:
                    currentState->setStrength(obj1);
                    break;
                case 2:
                    if (obj2 == 0){
                        break;
                    } else {
                        for (auto room: Room::rooms) {
                            if (room->getIndex() == obj1) {
                                for (auto obj: GameObject::allObjects) {
                                    if (obj->getIndex() == obj2) {
                                        room->addObject(obj);
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                    }
                    break;
                case 3:
                    if (obj1 == 0){
                        break;
                    } else {
                        for (auto obj : GameObject::allObjects){
                            if (obj->getIndex() == obj1){
                                currentState->addObject(obj);
                                break;
                            }
                        }
                    }
                    break;
                default:
                    std::cout << "The save file is corrupted, please restart the game."<<std::endl;
                    exit(0);
            }
        }
    } else {
        std::cout << "The save file is not exist."<<std::endl;
    }
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
                currentState->announceLoc();
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


        if(firstWord == "save" || firstWord == "load"){
            commandOk = true;
            std::cout <<"please enter: ";
            inputCommand(&commandBuffer);
            if (firstWord == "save") {
                saveGame(commandBuffer + ".txt");
            } else if (firstWord == "load") {
                loadGame(commandBuffer + ".txt");
                commandBuffer.clear();
            }
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