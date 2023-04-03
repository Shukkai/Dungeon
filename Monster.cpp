#include "Monster.h"
Monster::Monster():GameCharacter(){}
Monster::Monster(string name,int health,int attack,int defense):GameCharacter(name,"Monster",health,attack,defense){
}
bool Monster::triggerEvent(Object* add){
     Player* battle = static_cast<Player*> (add);
     cout<<"Health:"<<getCurrentHealth()<<"/"<<getMaxHealth()<<"\nAttack:"<<getAttack()<<"\nDefense"<<getDefense()<<endl;
     cout<<"What's Your Decision?"<<endl;
     string decision;
     cout<<"A.Battle!!\n"<<"B.Retreat\n"<<"C.Sleep\n"<<"D.Use Attack potion"<<endl;
     cin>>decision;
     while(decision != "A" && decision != "B" && decision != "C" && decision != "D"){
        cout<<"Enter Appropriate Decision!!!"<<endl;
     }
     if(decision == "A"){
            int z = 1;
            for(auto i : battle->getSkill()){
                if(i == "Kill piggie"){
                    z = 0;
                    break;
                }
            }
            if(z == 0){
                    srand( time(NULL) );
                    int x = rand() % 100;
                    if(x > 49){
                        this -> setCurrentHealth(0);
                        cout<<"003:You killed that fat Tung\n";
                    }
                    else{
                        battle->setCurrentHealth(0);
                        cout<<"Oh NO!!!\nSkill Active fail!!!";
                    }
            }
            while(1){
                if(getCurrentHealth() <= 0){
                        return true;
                }
                if(battle->getCurrentHealth() <= 0){
                    int u = 1;
                    for(auto i:battle->getSkill()){
                        if(i == "Lock Down"){
                            u = 0;
                            break;
                        }
                    }
                    if(u == 0){
                        cout<<"You active skill Lock Down\nYour health is now full\n";
                        battle->setCurrentHealth(battle->getMaxHealth());
                    }
                    else{
                        return false;
                    }
                }
                if(battle -> getSkill().empty() != true && battle-> getcd() == 0){
                    cout<<"Do you want to active your skill?"<<endl;
                    cout<<"YES or NO Make Your Decision"<<endl;
                    string x;
                    cin>>x;
                    while(x != "YES" && x != "NO"){
                        cout<<"Please Enter YES or NO!!!"<<endl;
                        cin>>x;
                    }
                    if(x == "YES"){
                        cout<<"Which Skill you want to active"<<endl;
                        vector<string> s = battle->getSkill();
                        int l = 1;
                        for(int i = 0;i < s.size();i++){
                            if(s[i] != "Lock Down"){
                            cout<<l<<". "<<s[i]<<endl;
                            l++;
                            }
                        }
                        int y;
                        cin>>y;
                        if(y == 1){
                            int h = this -> getMaxHealth() / 4;
                            h = getCurrentHealth() - h;
                            this -> setCurrentHealth(h);
                        }
                        else if(y == 2){
                            battle->increaseStates(0,10,0);
                            this -> takeDamage(30);
                        }
                        cout<<getName()<<"\nHealth"<<getCurrentHealth()<<"/"<<getMaxHealth()<<endl;
                        cout<<"Your Health:"<<battle->getCurrentHealth()<<"/"<<battle -> getMaxHealth()<<"\nYour Attack:"<<battle->getAttack()<<endl;
                        battle->setcd(3);
                        cout<<"Your skill cd :"<<battle->getcd()<<endl;
                        continue;
                    }
                    else if(x =="NO"){
                        cout<<"You keep your power"<<endl;
                        this -> takeDamage(battle->getAttack());
                        if(this -> getCurrentHealth() <= 0){
                            cout<<"You Beat The "<<getName()<<endl;
                            return true;
                        }
                        battle->takeDamage(this -> getAttack());
                        cout<<getName()<<"\nHealth"<<getCurrentHealth()<<"/"<<getMaxHealth()<<endl;
                        cout<<"Your Health:"<<battle->getCurrentHealth()<<"/"<<battle -> getMaxHealth()<<"\nYour Attack:"<<battle->getAttack()<<endl;
                        if(battle->getCurrentHealth() <= 0){
                        int u = 1;
                        for(auto i:battle->getSkill()){
                                if(i == "Lock Down"){
                                    u = 0;
                                    i.erase(i.end());
                                    break;
                            }
                        }
                            if(u == 0){
                                    cout<<"You active skill Lock Down\nYour health is now full\n";
                                    battle->setCurrentHealth(battle->getMaxHealth());
                            }
                            else{
                                return false;
                            }
                        }
                    string keep;
                    cout<<"What's next?\n"<<"A.Keep Fighting!!!\n"<<"B.Retreat....\n"<<"C.Use Attack Potion"<<endl;
                    cin>>keep;
                    while(keep != "A" && keep != "B" && keep != "C"){
                        cout<<"Enter Appropriate Decision!!!"<<endl;
                        cin>>keep;
                    }
                    if(keep == "B"){
                        cout<<"You have moved to Room:"<<battle->getPreviousRoom()->getIndex()<<endl;
                        battle->changeRoom(battle->getPreviousRoom());
                        return true;
                    }
                    else if(keep == "C"){
                            cout<<"Which potion you want to use?"<<endl;
                            vector<Item>poision;
                            for(i:battle->getBackpack()){
                            if(i.getTag() == "attack potion"){
                                poision.push_back(i);
                                }
                            }
                            if(poision.empty() == true){
                            cout<<"You got nothing to use"<<endl;
                            }
                            else{
                                int x = 1;
                                for(int i = 0;i < poision.size();i++){
                                    cout<<x<<"."<<poision[i].getName()<<endl;
                                    x++;
                                }
                            }
                        }
                        if(battle->getcd() >= 0){
                        battle->decreasecd();
                        }
                        cout<<"Remain turns to use skills: "<<battle->getcd()<<endl;
                    }
                }
                else{
                this -> takeDamage(battle->getAttack());
                if(this -> getCurrentHealth() <= 0){
                    cout<<"You Beat The "<<getName()<<endl;
                    return true;
                }
                battle->takeDamage(this -> getAttack());
                cout<<getName()<<"\nHealth"<<getCurrentHealth()<<"/"<<getMaxHealth()<<endl;
                cout<<"Your Health:"<<battle->getCurrentHealth()<<"/"<<battle -> getMaxHealth()<<"\nYour Attack:"<<battle->getAttack()<<endl;
                if(battle->getCurrentHealth() <= 0){
                    int u = 1;
                    for(auto i:battle->getSkill()){
                        if(i == "Lock Down"){
                            u = 0;
                            i.erase(i.end());
                            break;
                        }
                    }
                    if(u == 0){
                        cout<<"You active skill Lock Down\nYour health is now full\n";
                        battle->setCurrentHealth(battle->getMaxHealth());
                    }
                    else{
                        return false;
                    }
                }
                string keep;
                cout<<"What's next?\n"<<"A.Keep Fighting!!!\n"<<"B.Retreat....\n"<<"C.Use Attack Potion"<<endl;
                cin>>keep;
                while(keep != "A" && keep != "B" && keep != "C"){
                    cout<<"Enter Appropriate Decision!!!"<<endl;
                    cin>>keep;
                }
                if(keep == "B"){
                    cout<<"You have moved to Room:"<<battle->getPreviousRoom()->getIndex()<<endl;
                    battle->changeRoom(battle->getPreviousRoom());
                    return true;
                }
                else if(keep == "C"){
                         cout<<"Which potion you want to use?"<<endl;
                        vector<Item> posi = battle->getBackpack();
                        int o = 1;
                        for(int i = 0;i < posi.size();i++){
                            if(posi[i].getTag() == "attackpotion"){
                            int j = i + 1;
                            cout<<j<<". "<<posi[i].getName()<<endl;
                            o = 0;
                        }
                    }
                    if(o == 1){
                    cout<<"You have nothing to use!!!\n";
                    return true;
                    }
                else{
                    cout<<"Enter your decision\n";
                    int w;
                    cin>>w;
                    w--;
                    this->takeDamage(this -> getDefense() + battle->getBackpack()[w].getAttack());
                    battle->eraback(w);
                    cout<<getName()<<"\nHealth"<<getCurrentHealth()<<"/"<<getMaxHealth()<<endl;
                    cout<<"Your Health:"<<battle->getCurrentHealth()<<"/"<<battle -> getMaxHealth()<<"\nYour Attack:"<<battle->getAttack()<<endl;
                    return true;
                }
                    }
                battle->decreasecd();
                cout<<"Remain turns to use skills: "<<battle->getcd()<<endl;
                }
            }
     }
     else if(decision == "B"){
        cout<<"You Flee To The Room:"<<battle->getPreviousRoom()->getIndex()<<"You Coward XD"<<endl;
        battle->changeRoom(battle->getPreviousRoom());
        return true;
     }
     else if(decision == "C"){
        cout<<"You got hit by the monster!!!"<<endl;
        battle->takeDamage(this -> getAttack());
        cout<<"Your current health:"<<battle->getCurrentHealth()<<endl;
        return true;
     }
     else if(decision == "D"){
        cout<<"Which potion you want to use?"<<endl;
        vector<Item> posi = battle->getBackpack();
        int o = 1;
        for(int i = 0;i < posi.size();i++){
            if(posi[i].getTag() == "attackpotion"){
                int j = i + 1;
                cout<<j<<". "<<posi[i].getName()<<endl;
                o = 0;
            }
        }
        if(o == 1){
            cout<<"You have nothing to use!!!\n";
            return true;
        }
        else{
            cout<<"Enter your decision\n";
            int w;
            cin>>w;
            w--;
            this->takeDamage(this -> getDefense() + battle->getBackpack()[w].getAttack());
            battle->eraback(w);
            cout<<getName()<<"\nHealth"<<getCurrentHealth()<<"/"<<getMaxHealth()<<endl;
            cout<<"Your Health:"<<battle->getCurrentHealth()<<"/"<<battle -> getMaxHealth()<<"\nYour Attack:"<<battle->getAttack()<<endl;
            return true;
        }
     }
}
