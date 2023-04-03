#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"

using namespace std;

class Item;

class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    vector<Item> inventory;
    vector<Item> backpack;
    vector<string> skill;
    int cd;
    int money;
public:
    Player();
    Player(string,int,int,int);
    void addItemtoInventory(Item);
    void addItemtoBackpack(Item);
    void learnSkill(Item);
    void increaseStates(int,int,int);
    void potionusing(int);
    void changeRoom(Room*);
    void changebackpackInventory(int);
    void setSkill(string);
    void setcd(int);
    int attackpotionusing(int);
    void setmoney(int);
    /* Virtual function that you need to complete   */
    /* In Player, this function should show the
       status of player.                            */
    bool triggerEvent(Object*);

    /* Set & Get function*/
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(vector<Item>);
    void setBackpack(vector<Item>);
    void openBackpack();
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    vector<Item> getInventory();
    vector<Item> getBackpack();
    vector<string> getSkill();
    int getcd();
    void decreasecd();
    int getmoney();
    void eraback(int);
};

#endif // PLAYER_H_INCLUDED
