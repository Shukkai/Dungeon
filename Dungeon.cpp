#include "Dungeon.h"
Dungeon::Dungeon(){}
void Dungeon::createPlayer(){
    string name;
    cin>>name;
    player = Player(name,100,30,20);
    player.setmoney(45);
}
void Dungeon::createMap(){
    vector<Object*> poss0;
    vector<Item> men;
    men.push_back(Item("Old Sword","weapon",0,15,0));
    men.push_back(Item("Kick of Sparda","skill",0,0,0));
    men.push_back(Item("Attack potion 1","attackpotion",0,10,0));
    static NPC mentor("The Great Mentor","Welcome young challenger.I have some gift before your journey.",men);
    poss0.push_back(&mentor);
    vector<Object*> poss1;
    static Monster Slime("Slime",40,10,20);
    poss1.push_back(&Slime);
    static Item oldarmor("Old Armor","armor",20,0,10);
    poss1.push_back(&oldarmor);
    static Item secretkey("Key For Secret Room","key",0,0,0);
    poss1.push_back(&secretkey);
    vector<Object*> poss2;
    static Monster goblin("Goblin",50,40,10);
    poss2.push_back(&goblin);
    static Item heal1("Healing potion 1","potion",50,0,0);
    poss2.push_back(&heal1);
    vector<Item> farm;
    farm.push_back(Item("Lock Down","skill",0,0,0));
    static Item heal2(Item("Healing potion 2","potion",50,0,0));
    farm.push_back(heal2);
    static NPC farmer("Just a Normal Farmer","Thank you challenger!! \nThe creature has been annoying me for a long time . Now I can enjoy my retire life .\nOh , I've a message for you : Go up you might find something\nGo down to keep your journey\nAnd the skill I gave you can let you survive when you almost die", farm);
    poss2.push_back(&farmer);
    vector<Object*> poss3;
    vector<Item> gu;
    gu.push_back(Item ("Old Shield","shield",30,0,15));
    static NPC guide("The guide","Hello challenger.\nYou can go LEFT if you get appropriate item with you.\nYou can go Down to keep your journey.\nLast, I have a gift for you",gu);
    poss3.push_back(&guide);
    vector<Object*> poss4;
    static Monster assassin("Assassin",60,30,10);
    poss4.push_back(&assassin);
    vector<Object*> poss5;
    static Monster babyshark("Baby Shark",75,50,20);
    poss5.push_back(&babyshark);
    static Item shieldad("Advance Shield","shield",40,0,25);
    poss5.push_back(&shieldad);
    vector<Object*> poss6;
    static Monster bigtongue("Big Tongue",80,60,15);
    poss6.push_back(&bigtongue);
    static Item spoon("Spoon","weapon",0,40,0);
    poss6.push_back(&spoon);
    vector<Object*> poss7;
    static Monster bigmom("Big Mother",100,65,30);
    poss7.push_back(&bigmom);
    static Item bat("Baseball Bat","weapon",0,35,5);
    poss7.push_back(&bat);
    static Item healingpotion2("Healing Potion 2","potion",80,0,0);
    poss7.push_back(&healingpotion2);
    vector<Object*> poss8;
    vector<Item> teach;
    teach.push_back(Item("Bird Hit","skill",0,0,0));
    teach.push_back(Item("Monkey Punch","skill",0,0,0));
    teach.push_back(Item("Skii","skill",0,0,0));
    static NPC kongfu("Kong Fu Master","HiYa!!!\n.Welcome to my Dojo boy\nTo help you beat the evil boss let me teach you some martial art\n",teach);
    poss8.push_back(&kongfu);
    vector<Object*> poss9;
    static Monster monkey("Monkey",110,70,35);
    poss9.push_back(&monkey);
    static Item adarmor("Advance Armor","armor",60,0,30);
    poss9.push_back(&adarmor);
    vector<Object*> poss10;
    static Monster grandmom("Gramndmom",120,65,50);
    poss10.push_back(&grandmom);
    vector<Item> red;
    Item potionheal3("Healing potion heal all","potion",200,0,0);
    red.push_back(potionheal3);
    static NPC fighterred ("FighterRed","Great dude\n.I'm amazed that you can reach here.\nNow I will give you a gift and a chance to challenge the Boss",red);
    poss10.push_back(&fighterred);
    static Item key1("Key for Boss Room (1)","key",0,0,0);
    poss10.push_back(&key1);
    vector<Object*> poss11;
    static Monster zombie("Zombie",140,10000,1000);
    poss11.push_back(&zombie);
    vector<Item> mr;
    static Item potionheal4("Healing potion heal all","potion",200,0,0);
    mr.push_back(potionheal4);
    static Item key2("Key for Boss Romm (2)","key",0,0,0);
    mr.push_back(key2);
    static NPC mrzombiekiller("Mr. Zombie Killer","Awesome Young man!\nYou can reach here is amazing\nI got a drug here\nEat it!!\nA key is also for you\n",mr);
    vector<Object*> poss12;
    static Monster Gorilla("Gorilla",150,70,30);
    poss12.push_back(&Gorilla);
    vector<Item> xua;
    static Item healpotion3("Healing potion heal all","potion",200,0,0);
    xua.push_back(healpotion3);
    static Item key3("Key for Boss Room (3)","key",0,0,0);
    xua.push_back(key3);
    static NPC Xuan ("Xuan","Good,take your potion and key then get out!!!",xua);
    poss12.push_back(&Xuan);
    vector<Object*> poss13;
    vector<Item> pow;
    static Item goldensword("Golden Sword","weapon",0,50,0);
    pow.push_back(goldensword);
    static Item goldenshield("Golden Shield","shield",45,0,40);
    pow.push_back(goldenshield);
    static Item goldarmor("Golden Armor","armor",55,20,30);
    pow.push_back(goldarmor);
    static NPC powerman("Power Man","Give You Power!!!\nHere is a full set of gear for you.\nGood luck!!!",pow);
    poss13.push_back(&powerman);
    vector<Object*> poss14;
    vector<Item> pigkiller;
    static Item utli("Kill piggie","skill",0,0,0);
    pigkiller.push_back(utli);
    static Item key4("Key for Boss Room (4)","key",0,0,0);
    pigkiller.push_back(key4);
    static NPC zerozerothree("003","Kill That PIG!!!\nThe skill i gave you would allow you to kill it in half chance",pigkiller);
    poss14.push_back(&zerozerothree);
    vector<Object*> poss15;
    static Monster Tun("God Of Tung",300,100,90);
    poss15.push_back(&Tun);
    vector<Object*> poss16;
    vector<Item> nnn;
    static NPC chan("LieWei Chan","Congratulation Challenger!!!\nYou have pass my challenge.\nHowever there's still a long journey for you to go.\nBut now you will be rewarded with a A++!!!",nnn);
    rooms.push_back(Room (0, 0, poss0));
    rooms.push_back(Room (0,1,poss1));
    rooms.push_back(Room(0, 2, poss2));
    rooms.push_back(Room(0, 3, poss3));
    rooms.push_back(Room (0,4,poss4));
    rooms.push_back(Room (0,5,poss5));
    rooms.push_back(Room (0,6,poss6));
    rooms.push_back(Room (0,7,poss7));
    rooms.push_back(Room (0,8,poss8));
    rooms.push_back(Room(0,9,poss9));
    rooms.push_back(Room(0,10,poss10));
    rooms.push_back(Room(0,11,poss11));
    rooms.push_back(Room(0,12,poss12));
    rooms.push_back(Room(0,13,poss13));
    rooms.push_back(Room(0,14,poss14));
    rooms.push_back(Room(0,15,poss15));
    rooms.push_back(Room(1,16,poss16));
    rooms[0].setDownRoom(&rooms[1]);
    rooms[2].setUpRoom(&rooms[0]);
    rooms[1].setUpRoom(&rooms[0]);
    rooms[2].setLeftRoom(&rooms[1]);
    rooms[1].setRightRoom(&rooms[2]);
    rooms[1].setLeftRoom(&rooms[3]);
    rooms[3].setRightRoom(&rooms[1]);
    rooms[4].setUpRoom(&rooms[0]);
    rooms[4].setRightRoom(&rooms[3]);
    rooms[3].setLeftRoom(&rooms[4]);
    rooms[2].setDownRoom(&rooms[5]);
    rooms[5].setUpRoom(&rooms[2]);
    rooms[3].setDownRoom(&rooms[6]);
    rooms[6].setUpRoom(&rooms[3]);
    rooms[5].setDownRoom(&rooms[7]);
    rooms[7].setUpRoom(&rooms[5]);
    rooms[7].setLeftRoom(&rooms[8]);
    rooms[8].setRightRoom(&rooms[7]);
    rooms[6].setRightRoom(&rooms[8]);
    rooms[8].setUpRoom(&rooms[6]);
    rooms[6].setDownRoom(&rooms[9]);
    rooms[9].setUpRoom(&rooms[6]);
    rooms[7].setDownRoom(&rooms[10]);
    rooms[10].setUpRoom(&rooms[7]);
    rooms[8].setDownRoom(&rooms[11]);
    rooms[11].setUpRoom(&rooms[8]);
    rooms[9].setDownRoom(&rooms[12]);
    rooms[12].setUpRoom(&rooms[9]);
    rooms[10].setDownRoom(&rooms[13]);
    rooms[11].setDownRoom(&rooms[13]);
    rooms[12].setDownRoom(&rooms[13]);
    rooms[4].setDownRoom(&rooms[14]);
    rooms[14].setUpRoom(&rooms[4]);
    rooms[13].setDownRoom(&rooms[15]);
    rooms[15].setUpRoom(&rooms[13]);
    rooms[14].setDownRoom(&rooms[15]);
    rooms[15].setLeftRoom(&rooms[14]);
    rooms[15].setDownRoom(&rooms[16]);
}
void Dungeon::handleMovement(){
    if(player.getCurrentRoom()->getUpRoom() != NULL){
        cout<<"A.You Want To Go To Up Room ?"<<endl;
    }
    if(player.getCurrentRoom()->getDownRoom()!= NULL){
        cout<<"B.You Want To Go To Down Room ?"<<endl;
    }
    if(player.getCurrentRoom()->getLeftRoom() != NULL){
        cout<<"C.You Want To Go To Left Room ?"<<endl;
    }
    if(player.getCurrentRoom()->getRightRoom() != NULL){
        cout<<"D.You Want To Go To Right Room ?"<<endl;
    }
    cout<<"Make Your Decision:"<<endl;
    string way;
    cin>>way;
    Room *r;
    while(1){
    if(way == "A"){
        r=player.getCurrentRoom()->getUpRoom();
        player.changeRoom(r);
        cout<<"You Have Moved To The Up Room"<<player.getCurrentRoom()->getIndex()<<endl;
        break;
    }
    else if(way == "B"){
        if(player.getCurrentRoom()->getDownRoom()->getIndex() == 15){
            int k = 1;
            for(auto i:player.getBackpack()){
                if(i.getName() == "Key for Boss Room (1)" || i.getName() == "Key for Boss Room (2)" || i.getName() == "Key for Boss Room (3)" || i.getName() == "Key for Boss Room (4)"){
                    k = 0;
                    break;
                }
            }
            if(k == 1){
                cout<<"You can't move to that room\n";
                break;
            }
            else{
                r=player.getCurrentRoom()->getDownRoom();
                player.changeRoom(r);
                cout<<"You Have Moved To The Down Room"<<player.getCurrentRoom()->getIndex()<<endl;
                break;
            }
        }
        else{
        r=player.getCurrentRoom()->getDownRoom();
        player.changeRoom(r);
        cout<<"You Have Moved To The Down Room"<<player.getCurrentRoom()->getIndex()<<endl;
        break;
        }
    }
    else if(way == "C"){
        if(player.getCurrentRoom()->getLeftRoom()-> getIndex() == 4){
            int p = 1;
            for(auto i : player.getBackpack()){
                if(i.getName() == "Key For Secret Room"){
                    p = 0;
                    break;
                }
            }
            if(p == 1){
                cout<<"You can't move to that room\n";
                break;
            }
            else{
                r=player.getCurrentRoom()->getLeftRoom();
                player.changeRoom(r);
                cout<<"You Have Moved To The Left Room"<<player.getCurrentRoom()->getIndex()<<endl;
                break;
            }
        }
        r=player.getCurrentRoom()->getLeftRoom();
        player.changeRoom(r);
        cout<<"You Have Moved To The Left Room"<<player.getCurrentRoom()->getIndex()<<endl;
        break;
    }
    else if(way == "D"){
        r=player.getCurrentRoom()->getRightRoom();
        player.changeRoom(r);
        cout<<"You Have Moved To The Right Room"<<player.getCurrentRoom()->getIndex()<<endl;
        break;
    }
    else{
        cout<<"Please Enter Appropriate Direction!!!"<<endl;
    }
    }
}
void Dungeon::handleEvent(Object* event){
    if(event->getTag() == "NPC"){
        NPC* npc =static_cast<NPC*> (event);
        cout<<npc->getName()<<endl;
        npc->triggerEvent(&player);
    }
    else if(event->getTag() == "Monster"){
        Monster* mon = static_cast<Monster*> (event);
        cout<<mon->getName()<<endl;
        if(mon->triggerEvent(&player) == false){
            cout<<"You Lose"<<endl;
        }
        if(mon->getCurrentHealth() <= 0){
            cout<<"Keep going"<<endl;
            player.getCurrentRoom()->popObject(event);
            player.setmoney(player.getmoney() + 10);
        }
    }
    else if(event->getTag() == "weapon" || event->getTag() == "armor" || event->getTag() == "shield" || event->getTag() == "potion" || event->getTag() == "key"){
        Item* pickup = static_cast<Item*> (event);
        cout<<"Fall item: "<<pickup->getName()<<endl;
        if(pickup->triggerEvent(&player ) == true){
            cout<<"Keep going"<<endl;
            player.getCurrentRoom() ->popObject(event);
        }
    }
}
void Dungeon::startGame(){
    cout<<"Welcome To The Dungeon!"<<endl;
    cout<<"Please Enter Your Name:"<<endl;
    createPlayer();
    createMap();
    player.setCurrentRoom(&rooms[0]);
    cout<<"Let's Begin Our Journey!"<<endl;
}
void Dungeon::chooseAction(vector<Object*> in){
    cout<<"What Do You Want To Do Next ?"<<endl;
    cout<<"A.Show Player's Current Status"<<endl;
    string act;
    int flag = 1;
    for(auto i:in){
        if(i->getTag() == "Monster"){
            flag = 0;
            break;
        }
    }
    if(flag == 0){
        cout<<"C.Interact"<<endl;
        cout<<"D.Open Your Backpack"<<endl;
        cout<<"Please Enter Your Action:"<<endl;
        cin>>act;
        while(act != "A" && act != "C" && act != "D"){
            cout<<"Please Enter Appropriate Action!!!"<<endl;
            cin>>act;
        }
        if(act == "A"){
            player.triggerEvent(&player);
        }
        else if(act == "C"){
            handleEvent(in[0]);

        }
        else if(act =="D"){
            player.openBackpack();
        }
    }
    else if(flag == 1){
        cout<<"B.Move To Another Room"<<endl;
        cout<<"C.Interact"<<endl;
        cout<<"D.Open Your Backpack"<<endl;
        cout<<"Please Enter Your Action:"<<endl;
        cin>>act;
        while(1){
            if(act != "B" && act != "A" && act != "D" && act != "C"){
                cout<<"Please Enter Appropriate Action!!!"<<endl;
                cin>>act;
            }
            else
                break;
        }
        if(act == "A"){
            player.triggerEvent(&player);
        }
        else if(act == "B"){
            handleMovement();
        }
        else if(act == "C"){
            if(in.empty() == true){
                cout<<"There's nothing in the room\n";
            }
            else{
            for(int i = 0;i < in.size();i++){
                handleEvent(in[i]);
            }
            }
        }
        else if(act == "D"){
            player.openBackpack();
        }
    }
}
bool Dungeon::checkGameLogic(){
    if(player.checkIsDead() == true){
        cout<<"You Lose..."<<endl;
        return false;
    }
    else if(player.getCurrentRoom()->getIsExit() == true){
        cout<<"You conquer the dungeon!!!"<<endl;
        return false;
    }
    else{
        return true;
    }
}
void Dungeon::runDungeon(){
    startGame();
    while(checkGameLogic() == true){
    vector<Object*> in = player.getCurrentRoom()->getObjects();
    chooseAction(in);
    system("pause");
    system("cls");
   }
    cout<<"End";
}
