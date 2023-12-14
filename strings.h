

#ifndef TEXTADV_STRINGS_H
#define TEXTADV_STRINGS_H


#include <string>

const std::string r1name = "Room 1";
const std::string r1desc = "You are in room 1. It's really quite boring, but then, it's just for testing really. There are roads in all four directions.";
const std::string r2name = "Blue Room";
const std::string r2desc = "You are in the blue room. You know because it's blue. That's about all though. There's a passage to the south.";
const std::string r4name = "Room 4";
const std::string r4desc = "You are in the room 4. There's a passage to the east.";
const std::string r5name = "Room 5";
const std::string r5desc = "You are in the room 5. There's a passage to the north.";
const std::string r6name = "Room 6";
const std::string r6desc = "You are in the room 6. There's a passage to the west. And there's another road to the east";
const std::string r7name = "Room 7";
const std::string r7desc = "You are in the room 7. There's a passage to the west.";

const std::string o1name = "spanner";
const std::string o1desc = "This is a spanner. What can it do?";
const std::string o1key = "spanner";
const int o1index = 1;
const std::string o2name = "tissue";
const std::string o2desc = "This is a tissue. Maybe it can wipe your tears";
const std::string o2key = "tissue";
const int o2index = 2;
const std::string o3name = "key";
const std::string o3desc = "This is a key. It can be used to open a door";
const std::string o3key = "key";
const int o3index = 3;

const std::string food1name = "apple";
const std::string food1desc = "<Food: Strength+7> This is an apple. It can keep doctor away.";
const std::string food1key = "apple";
const int f1index = 4;
const std::string food2name = "milk";
const std::string food2desc = "<Food: Strength+1> This is a carton of milk. It looks like it has expired";
const std::string food2key = "milk";
const int f2index = 5;
const std::string food3name = "hamburger";
const std::string food3desc = "<Food: Strength+10> This is a hamburger. Wait, why is there a hamburger here?";
const std::string food3key = "hamburger";
const int f3index = 6;

const std::string badExit = "You can't go that way.";
const std::string badCommand = "I don't understand that.";
const std::string inOtherRoom = "The object is not in the current room or in inventory, it may be in another room.";
const std::string noExist = "The object does not exist";


#endif //TEXTADV_STRINGS_H
