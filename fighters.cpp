#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>

using std::string;
using namespace std;

class Fighter{
private:
    int attackMax;
    int blockMax;
public:
    string name;
    int health;
    Fighter(string name, int health,
            int attackMax, int blockMax){
            this->name = name;
            this->health = health;
            this->attackMax = attackMax;
            this->blockMax = blockMax;
    }
    
    // Randomize attacks and blocks
    int Attack(){
        return std::rand() % this->attackMax;
    }
    int Block(){
        return std::rand() % this->blockMax;
    }

};
 
class Fight{
public:
    // Pass fighters into the function so we can track damage to each
    
    // Loop attack until fighters health is below zero
    static void StartFight(Fighter& fighter1, Fighter& fighter2){
        while(true){
            if(Fight::GetAttackResult(fighter1, fighter2).compare("Game Over") == 0){
                cout << "Game Over\n";
                break;
            }
            if(Fight::GetAttackResult(fighter2, fighter1).compare("Game Over") == 0){
                cout << "Game Over\n";
                break;
            }
        }
    }
    
    static string GetAttackResult(Fighter& fighterA, 
    Fighter& fighterB){
        // Calculate damage from randomized attacks and blocks
        int fighterAAttackAmt = fighterA.Attack();
        int fighterBBlockAmt = fighterB.Block();
        int damage2FighterB = ceil(fighterAAttackAmt - fighterBBlockAmt);
        
        // Remove health if damage is above 0
        damage2FighterB = (damage2FighterB <= 0) ? 0 : damage2FighterB;
        fighterB.health = fighterB.health - damage2FighterB;
        printf("%s attacks %s and deals %d damage\n", 
                fighterA.name.c_str(), 
                fighterB.name.c_str(),
                damage2FighterB);
        printf("%s is down to %d health\n", 
                fighterB.name.c_str(),
                fighterB.health);
        
        // Pass game over once fighters health reaches 0
        if(fighterB.health <= 0){
            printf("%s has lost and %s has won!\n",
                    fighterB.name.c_str(), fighterA.name.c_str());
            return "Game Over";
        } else {
            return "Fight Again";
        }
    }
};

void showMenu() {
    cout << "**********MENU**********" << endl;
    cout << "1. Create fighters" << endl;
    cout << "2. Start fight" << endl;
    cout << "3. Exit" << endl;
    cout << "************************" << endl;
}
 
int main()
{
    // User selection
    int option;
    // fighter 1 stats
    string name1;
    int health1;
    int damage1;
    int block1;

    // fighter 2 stats
    string name2;
    int health2;
    int damage2;
    int block2;
    // Random number generator
    srand(time(NULL));
    

    do {
        showMenu();
        cout << "Please choose an option: ";
        cin >> option;
        system("cls");

        switch(option) {
            case 1: // enter fighter stats
                    cout << "Please enter the name of Fighter 1: ";
                    cin >> name1;
                    cout << "\nPlease enter the health of Fighter 1: ";
                    cin >> health1;
                    cout << "\nPlease enter the damage of Fighter 1: ";
                    cin >> damage1;
                    cout << "\nPlease enter the block of Fighter 1: ";
                    cin >> block1;

                    cout << "\nPlease enter the name of Fighter 2: ";
                    cin >> name2;
                    cout << "\nPlease enter the health of Fighter 2: ";
                    cin >> health2;
                    cout << "\nPlease enter the damage of Fighter 2: ";
                    cin >> damage2;
                    cout << "\nPlease enter the block of Fighter 2: ";
                    cin >> block2;
                    
                    break;
                    // Start fight. Set fighters here or the damage will accumulate 
                    // each time number 3 is chosen.
            case 2: Fighter fighter1(name1, health1, damage1, block1);
                    Fighter fighter2(name2, 125, 35, 10);
                    Fight::StartFight(fighter1, fighter2); break;
        }
    } 
        while (option != 3);
    
    return 0;
}