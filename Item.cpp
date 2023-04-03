#include "Item.h"
Item::Item():Object(){}
Item::Item(string name,string tag,int health,int attack,int defense):Object(name,tag){
    this -> health = health;
    this -> attack = attack;
    this -> defense = defense;
}
bool Item::triggerEvent(Object* deal){
    Player* pickup = static_cast<Player*> (deal);
    if(this -> getTag() == "potion"|| this -> getTag() == "key" || this-> getTag() == "attackpotion"){
        cout<<"You put it into your backpack"<<endl;
        pickup->addItemtoBackpack(*this);
        return true;
    }
    else if(this -> getTag() == "weapon" || this -> getTag() == "armor" || this -> getTag() == "shield"){
        int flag = 1;
        vector<Item> players = pickup->getInventory();
        for(auto i : players){
            if(i.getTag() == this -> getTag()){
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            cout<<"You put it into your backpack"<<endl;
            pickup->addItemtoBackpack(*this);
            return true;
        }
        else{
            cout<<"You put on "<<this -> getTag()<<" : "<<this -> getName()<<endl;
            pickup->addItemtoInventory(*this);
            return true;
        }
    }
}
int Item::getHealth(){
    return health;
}
int Item::getAttack(){
    return this -> attack;
}
int Item::getDefense(){
    return this -> defense;
}
void Item::setHealth(int health){
    this -> health = health;
}
void Item::setAttack(int attack){
    this -> attack = attack;
}
void Item::setDefense(int defense){
    this -> defense = defense;
}
