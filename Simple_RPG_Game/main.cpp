#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono_literals;

void delay (int seconds ){
 this_thread::sleep_for(chrono::seconds(seconds));

}

//this code is about RPG game that use turns mechanic between the player and the enemy

int main() {

    srand(time(0));

    int playerHealth = 100;
    int monsterHealth = 100;
    int choice;
    int healthPotions = rand() % 2 + 1 ; // This will make the player begin with random amount of health potions
    int randomMonsterAttack = 0 ; //I use this to make the monster have chance of heavy attack
    int monsterAttack = 0 ; // This will decide if the monster will hit heavy or light attack
    int chanceOfHealth = 0 ; // I use this to decrease the amount of health potions
    int dodgeChanceForHealth = 0 ; // This to give the player a chance of getting health potions after dodge
    int dodgeAttack = 0 ; // This to make chance for the monster to hit the player in the dodge
    int healthMiss = 0 ; // I use this to make the game harder if the player try to heal while he don't have " Health potions "
    int criticalAttack  ; // I use this to make the player have a chance of hitting critical attack
    int attack ;
    cout << "Welcome to the Dark Dungeon , A wild monster appears!" << endl;
    delay(2) ;
    cout << " ======== The rules ============ " << endl ;
    delay(2);
    cout << "---- You can hit the monster , and the monster will hit you too ----  " << endl ;
    delay(3);
    cout << "---- You have %10 of hitting a critical attack ----" << endl ;
    delay(3);
    cout << "---- You can heal , and the Monster won't hit you ----" << endl ;
    delay(3);
    cout << "---- if you ran out of Health potions and you try to heal, the game will get harder ----" << endl ;
    delay(3);
    cout << "---- if you dodge you have %10 of getting one health potion ----" << endl ;
    delay(3);
    cout << "---- but there is also a %10 chance to get hit by a heavy attack ----" << endl ;
    while (playerHealth > 0 && monsterHealth > 0) {

            monsterAttack = 0 ;
            randomMonsterAttack =  rand() % 7  + 3 ;
        cout << "-------------------------------------------------------------------------- " << endl   ;
        cout << "\--- Your Health: " << playerHealth << " | Monster Health: " << monsterHealth << " ---" << endl;
    monsterAttack += randomMonsterAttack;
    if ( monsterAttack  > 3 ) {
            cout << " You have " << healthPotions << " Health potions ! " << endl ;
            cout << "Light attack is coming! " << endl ;
        cout << " Attack (1) ||||   Heal (2)  ||||    Dodge (3) //  what is your choice ?: ";
        } else {
        cout << " You have " << healthPotions << " Health potions ! " << endl ;
        cout << " Heavy attack is coming !!!! " << endl ;
        cout << " Attack (1) ||||   Heal (2)  ||||    Dodge (3) //  what is your choice ?: " ;
         }
        cin >> choice;

        if (choice == 1 ) {

                 if (monsterAttack > 3 ) { // this "if" to see if the monster have heave heavy or light attack
                attack = rand() % 16 + 10 ;
                playerHealth -= attack ;
            } else {
            int attack = rand() % 21 + 20  ;
                playerHealth -= attack ;
            }
            criticalAttack = rand() % 91  ;
            if (criticalAttack < 10) {  // this "if" to see if the player will hit critical or normal attack
            int damage = rand() %  11 + 20;
            monsterHealth -= damage;
            cout << "You hit the monster with " << damage << " damage!" << endl;
            delay (1) ;
            cout << "The monster hits you with " << attack << " damage! " << endl ;
             delay (1) ;
            } else {
                 int damage = rand() % 16 + 5;
            monsterHealth -= damage;
            cout << "You hit the monster with " << damage << " damage!" << endl;
             delay (1) ;
            cout << "The monster hits you with " << attack << " damage " << endl ;
             delay (1) ;

        } }  else if (choice == 2 ) {

            if (0 < healthPotions ){
            int Heal = rand () % 41 + 10  ;
             if (playerHealth >= 100 ){
                cout << "You are on max HB" << endl ;
                 delay (1) ;
             } else {
             playerHealth += Heal ;
            if (playerHealth > 100 )
             playerHealth = 100 ;
             cout << "You healed " << Heal <<" HB" << endl ;
              delay (1) ;
             healthPotions -- ;
              } }      else {
                  healthMiss += 20  ;
              cout << "You are out of health potions " << endl ;
               delay (1) ;
              }

        }  else if (choice == 3 ) {
            dodgeAttack = 0 ;
            int attack = rand() % 21 + 20  ;
            dodgeAttack = rand() % 91 + 10 + healthMiss ; // here every time the player try to heal , the chance to fail the dodge is increasing

            chanceOfHealth = 0 ;
        dodgeChanceForHealth  = rand () % 91 + 15 ; // he have %10 chance to get Health potion after dodge
        chanceOfHealth += dodgeChanceForHealth  ;
        if (chanceOfHealth <= 15 ) {
        healthPotions ++  ;
        cout << " you got a health potion !" << endl ;
         delay (1) ;
        } else if (dodgeAttack > 89 ) {
            playerHealth -= attack ;
            cout << "You failed to dodge and you get attacked by " << attack << " damage !! " << endl ;
             delay (1) ;

        }   else {
        cout << "You dodged the attack !" << endl ;
         delay (1) ;
        } }






        this_thread::sleep_for(chrono::milliseconds(800));
    }

cout << "================================================================" << endl;
    if (playerHealth <= 0 && monsterHealth <= 0) {
        cout << "It's a draw , Both you and the monster died. " << endl;
    } else if (playerHealth > 0) {
        cout << "VICTORY ! You defeated the Dark Dungeon Monster!" << endl;
    } else {
        cout << "GAME OVER ! You were killed by the monster." << endl;
    }

    return 0;
}
