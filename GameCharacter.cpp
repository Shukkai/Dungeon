#include "GameCharacter.h"
GameCharacter::GameCharacter():Object(){}
GameCharacter::GameCharacter(string name,string tag,int health,int attack,int defense):Object(name,tag){
    maxHealth = health;
    currentHealth = health;
    this -> attack = attack;
    this -> defense = defense;
}
bool GameCharacter::checkIsDead(){
    if(currentHealth == 0){
        return true;
    }
    else
        return false;
}
void GameCharacter::takeDamage(int damage){
    if((damage - defense) > 0){
        currentHealth = currentHealth - damage + getDefense();
    }
}
void GameCharacter::setMaxHealth(int health){
    maxHealth = health;
    currentHealth = health;
}
void GameCharacter::setCurrentHealth(int health){
    currentHealth = health;
}
void GameCharacter::setAttack(int att){
    attack = att;
}
void GameCharacter::setDefense(int def){
    defense = def;
}
int GameCharacter::getMaxHealth(){
    return maxHealth;
}
int GameCharacter::getCurrentHealth(){
    return currentHealth;
}
int GameCharacter::getAttack(){
    return attack;
}
int GameCharacter::getDefense(){
    return defense;
}
