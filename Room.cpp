#include "Room.h"
Room::Room(){}
Room::Room(bool isExit,int index,vector<Object*> objects){
    this -> isExit = isExit;
    this -> index = index;
    this -> objects = objects;
    upRoom = NULL;
    downRoom = NULL;
    leftRoom = NULL;
    rightRoom = NULL;
}
bool Room::popObject(Object* defeat){
    objects.erase(objects.begin());
}
void Room::setUpRoom(Room* add){
    upRoom = add;
}
void Room::setDownRoom(Room* add){
    downRoom = add;
}
void Room::setLeftRoom(Room* add){
    leftRoom = add;
}
void Room::setRightRoom(Room* add){
    rightRoom = add;
}
void Room::setIsExit(bool add){
    isExit = add;
}
void Room::setIndex(int  add){
    index = add;
}
void Room::setObjects(vector<Object*> add){
    objects = add;
}
bool Room::getIsExit(){
    return isExit;
}
int Room::getIndex(){
    return index;
}
vector<Object*> Room::getObjects(){
    return objects;
}
Room* Room::getUpRoom(){
    return upRoom;
}
Room* Room::getDownRoom(){
    return downRoom;
}
Room* Room::getLeftRoom(){
    return leftRoom;
}
Room* Room::getRightRoom(){
    return rightRoom;
}

