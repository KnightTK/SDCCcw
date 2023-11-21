cmake_minimum_required(VERSION 3.8)
project(textadv)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp RoomState/Room.cpp RoomState/Room.h wordwrap.h wordwrap.cpp RoomState/State.cpp RoomState/State.h strings.h
        Object/GameObject.h
        Object/FoodObject.h
        Object/GameObject.cpp
        Object/FoodObject.cpp)
add_executable(textadv ${SOURCE_FILES})