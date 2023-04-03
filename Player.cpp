#include "Player.h"
Player::Player():GameCharacter(){}
Player::Player(string name,int health,int attack,int defense):GameCharacter(name,"Player",health,attack,defense){
}
void Player::addItemtoInventory(Item puton){
    increaseStates(puton.getHealth(),puton.getAttack(),puton.getDefense());
    inventory.push_back(puton);
}
void Player::addItemtoBackpack(Item putin){
    backpack.push_back(putin);
}
void Player::learnSkill(Item learn){
    skill.push_back(learn.getName());
}
void Player::increaseStates(int health,int attack,int defense){
    int hp = this -> getMaxHealth() + health;
    setMaxHealth(hp);
    setCurrentHealth(hp);
    int newattack = getAttack() + attack;
    setAttack(newattack);
    int newdefense = getDefense() + defense;
    setDefense(newdefense);
}

void Player::potionusing(int change){
    int ch = backpack[change].getHealth();
    if((getCurrentHealth()+ch) >= getMaxHealth()){
        setCurrentHealth(getMaxHealth());
    }
    else{
        setCurrentHealth((getCurrentHealth()+ch));
    }
    int att = backpack[change].getAttack();
    setAttack(getAttack()+att);
    int def = backpack[change].getDefense();
    setDefense(getDefense()+def);
    backpack.erase(backpack.begin()+change);
}
void Player::changeRoom(Room *change){
    previousRoom = currentRoom;
    currentRoom = change;
}
void Player::setSkill(string in){
    skill.push_back(in);
}
void Player::setmoney(int cash){
    money = cash;
}
bool Player::triggerEvent(Object* add){
    Player* play = static_cast<Player*> (add);
    cout<<"Health:"<<getCurrentHealth()<<"/"<<getMaxHealth()<<endl<<"Attack:"<<getAttack()<<endl<<"Defense:"<<getDefense()<<endl;
    cout<<"CurrentRoom:"<<getCurrentRoom()->getIndex()<<endl<<"Money:"<<getmoney()<<endl;
    if(inventory.empty() == true){
        cout<<"Your are naked XD"<<endl;
    }
    else{
        cout<<"Your Inventory:"<<endl;
        for(auto i : inventory){
            cout<<i.getTag()<<": "<<i.getName()<<endl;
        }
    }
    if(skill.empty() == true){
        cout<<"You have no skill"<<endl;
    }
    else{
        cout<<"Your skills:"<<endl;
        int x = 1;
        for(int i = 0;i < skill.size();i++){
            cout<<x<<". "<<skill[i]<<endl;
            x++;
        }
    }
    return true;
}
void Player::setCurrentRoom(Room *now){
    currentRoom = now;
}
void Player::setPreviousRoom(Room *before){
    previousRoom = before;
}
void Player::setInventory(vector<Item> inventory){
    inventory = this -> inventory;
}
void Player::setBackpack(vector<Item> add){
    backpack = add;
}
void Player::changebackpackInventory(int change){
    for(int i = 0;i < inventory.size();i++){
        if(inventory[i].getTag() == backpack[change].getTag()){
            Item temp = inventory[i];
            increaseStates(-inventory[i].getHealth(),-inventory[i].getAttack(),-inventory[i].getDefense());
            inventory[i] = backpack[change];
            increaseStates(backpack[change].getHealth(),backpack[change].getAttack(),backpack[change].getDefense());
            backpack[change] = temp;
        }
    }
}
void Player::setcd(int in){
    this -> cd = in;
}
int Player::attackpotionusing(int change){
    int att = backpack[change].getAttack();
    backpack.erase(backpack.begin()+change);
    return att;
}
void Player::openBackpack(){
    if(backpack.empty() == true){
        cout<<"You have nothing in your backpack QQ"<<endl;
    }
    else if(backpack.empty() == false){
        cout<<"You got:"<<endl;
        for(auto i:backpack){
            cout<<i.getTag()<<": "<<i.getName()<<endl;
        }
        cout<<"You want to: \n"<<"A.Change Inventory\n"<<"B.Use potion"<<endl;
        string decision;
        cin>>decision;
        while(decision != "A" && decision != "B"){
            cout<<"Enter Appropriate Decision"<<endl;
            cin>>decision;
        }
        if(decision == "A" && inventory.empty() == false){
            int p = 1;
            vector<Item> cha = getBackpack();
            for(int i = 0;i < cha.size();i++){
                if(cha[i]. getTag() == "weapon" || cha[i]. getTag() == "shield" || cha[i]. getTag() == "armor"){
                    int j = i+1;
                    cout<<j<<". "<<cha[i].getName()<<endl;
                    p = 0;
                }
            }
            if(p == 1){
                cout<<"You have nothing to change!!!\n";
            }
            else{
                cout<<"Enter you decision:\n";
                int y;
                cin>>y;
                y--;
                changebackpackInventory(y);
            }
        }
        else if(decision == "A" && inventory.empty() == true){
            cout<<"You have nothing to change"<<endl;
        }
        if(decision == "B"){
            int m = 1;
            for(int i = 0;i < backpack.size();i++){
                if(backpack[i].getTag() == "potion"){
                    m = 0;
                    int j = i + 1;
                    cout<<j<<". "<<backpack[i].getName()<<endl;
                }
            }
            if(m == 1){
                cout<<"You have nothing to use\n";
            }
            else{
            cout<<"Choose the potion you want to use"<<endl;
            int change;
            cin>>change;
            change--;
            potionusing(change);
            }
        }
    }
}
Room* Player::getCurrentRoom(){
    return currentRoom;
}
Room* Player::getPreviousRoom(){
    return previousRoom;
}
vector<Item> Player::getInventory(){
    return inventory;
}
vector<Item> Player::getBackpack(){
    return backpack;
}
vector<string> Player::getSkill(){
    return skill;
}
int Player::getcd(){
    return cd;
}
void Player::decreasecd(){
    cd--;
}
int Player::getmoney(){
    return money;
}
void Player::eraback(int e){
    backpack.erase(backpack.begin() + e);
}
