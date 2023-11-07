
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


    r1->setNorth(r2);
    r1->setSouth(r5);
    r1->setWest(r4);
    r1->setEast(r6);
    r6->setEast(r7);

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

std::map<std::string,int> commandMap = {
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





        for (auto  iter : commandMap) {
            if(commandBuffer.compare(0,endOfVerb,iter.first)==0){
                commandOk = true;
                gotoTarget(iter.second);
            }
        }








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