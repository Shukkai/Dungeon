#include "NPC.h"
NPC::NPC():GameCharacter(){}
NPC::NPC(string name,string script,vector<Item> commodity):GameCharacter(name,"NPC",0,0,0){
    this -> script = script;
    this -> commodity = commodity;
}
bool NPC::triggerEvent(Object* tri){
    Player* in = static_cast<Player*> (tri);
    cout<<getScript()<<endl;
    vector<Item> poss = getCommodity();
    if(poss.size() != 0){
            if(poss[0].getTag() == "weapon" || poss[0].getTag() == "shield" || poss[0].getTag() == "armor"){
                int flag = 1;
                for(auto i : in->getInventory()){
                    if(i.getTag() == poss[0].getTag() && in->getmoney() >= 10){
                        in->addItemtoBackpack(poss[0]);
                        flag = 0;
                        cout<<"You put "<<poss[0].getName()<<" into your bag"<<endl;
                        in->setmoney(in->getmoney() - 10);
                        commodity.erase(commodity.begin());
                        break;
                    }
                    else if(i.getTag() == poss[0].getTag() && in->getmoney() < 10){
                        cout<<"You don't have enough money!!!\n";
                        break;
                    }
                }
                if(flag == 1 && in->getmoney() >= 10){
                    in->addItemtoInventory(poss[0]);
                    in->setmoney(in->getmoney() - 10);
                    cout<<"You put on:"<<poss[0].getName()<<endl;
                    commodity.erase(commodity.begin());
                }
                else if(flag == 1 && in->getmoney() < 10){
                     cout<<"You don't have enough money!!!\n";
                }
            }
            else if(poss[0].getTag() == "key" || poss[0].getTag() == "potion" || poss[0].getTag() == "attackpotion"){
                if(in->getmoney() >= 10){
                in->addItemtoBackpack(poss[0]);
                in->setmoney(in->getmoney() - 10);
                cout<<"You got "<<poss[0].getName()<<" in your bag"<<endl;
                commodity.erase(commodity.begin());
                }
                else if (in->getmoney() < 10){
                    cout<<"You don't have enough money!!!\n";
                }
            }
            else if(poss[0].getTag() == "skill" && in->getmoney() >= 10){
                if(in->getSkill().empty() == true){
                    in->setcd(0);
                    cout<<"You can active your skill every 3 round!!!\n";
                }
                in->learnSkill(poss[0]);
                in->setmoney(in->getmoney() - 10);
                cout<<"You learn a new skill : "<<poss[0].getName()<<endl;
                commodity.erase(commodity.begin());
            }
            else if(poss[0].getTag() == "skill" && in->getmoney() < 10){
                cout<<"You don't have enough money\n";
            }
    return false;
    }
    else{
        cout<<"I have nothing to give you."<<endl;
        return false;
    }
}
void NPC::setScript(string script){
    this -> script = script;
}
void NPC::setCommodity(vector<Item> commodity){
    this -> commodity = commodity;
}
string NPC::getScript(){
    return script;
}
vector<Item> NPC::getCommodity(){
    return commodity;
}
