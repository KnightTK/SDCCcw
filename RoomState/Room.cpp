
#include "Room.h"
#include "../wordwrap.h"

/**
 * Stores a static list of all rooms.
 */
std::list<Room*> Room::rooms;

/**
 * Room default constructor.
 * @param _name Room's name.
 * @param _desc Room's description.
 */
Room::Room(const string* _name, const string *_desc, int _index) :
        name(_name), description(_desc), index(_index), north(nullptr), south(nullptr), west(nullptr), east(nullptr) {};

/**
 * Remove destroyed rooms from the static list.
 */
Room::~Room() {
    Room::rooms.remove(this);
}

/**
 * Prints the description of a room (the name and long description)
 */
void Room::describe() const {
    wrapOut(this->name);
    wrapEndPara();
    wrapOut(this->description);
    wrapEndPara();
    for (auto iter: this->gameObjects) {
        wrapOut(iter->getShortName());
        wrapEndPara();
    }
}

/**
 * Statically creates a room and then adds it to the global list.
 * @param _name Name for the new room.
 * @param _desc Description for the new room.
 * @return A pointer to the newly created room.
 */
Room* Room::addRoom(const string* _name, const string *_desc, int _index) {
    auto *newRoom = new Room(_name, _desc, _index);
    Room::rooms.push_back(newRoom);
    return newRoom;
}

/**
 * Adds an existing room to the static list.
 * @param room Pointer to the room to add.
 * @return
 */
void Room::addRoom(Room* room) {
    Room::rooms.push_back(room);
}


void Room::addObject(GameObject *object) {
    gameObjects.push_back(object);
}

/**
 * Gets the north exit of a room.
 * @return The room that is north of this one, or NULL if there is no exit.
 */
Room* Room::getNorth() const {
    return this->north;
}

/**
 * Sets the north exit of a room.
 * @param _north Pointer to the room to be north of this one.
 */
void Room::setNorth(Room* _north) {
    this->north = _north;
}



Room* Room::getSouth() const {
    return this->south;
}
Room* Room::getWest() const {
    return this->west;
}
Room* Room::getEast() const {
    return this->east;
}

Room* Room::getDirection(int direction) const {
    switch (direction) {
        case 1:
            return getNorth();
            break;
        case 2:
            return getSouth();
            break;
        case 3:
            return getWest();
            break;
        case 4:
            return getEast();
            break;
        default:
            return nullptr;
    }
}


void Room::setSouth(Room *_south) {
    this->south = _south;
}
void Room::setWest(Room *_west) {
    this->west = _west;
}
void Room::setEast(Room *_east) {
    this->east = _east;
}

const std::list<GameObject *> Room::getGameObjects() const {
    return gameObjects;
}

void Room::removeObject(GameObject *object) {
    gameObjects.remove(object);
}

const string *Room::getName() const {
    return name;
}

int Room::getIndex() {
    return index;
}

void Room::clearObject() {
    this->gameObjects.clear();
}
