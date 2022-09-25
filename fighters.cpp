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
    cout << "1. Choose fighters" << endl;
    cout << "2. Create fighter" << endl;
    cout << "3. Start fight" << endl;
    cout << "4. Exit" << endl;
    cout << "************************" << endl;
}
 
int main()
{
    // User selection
    int option;
    int selectedFighter1;
    int selectedFighter2;
    // Random number generator
    srand(time(NULL));
    

    do {
        showMenu();
        cout << "Please choose an option: ";
        cin >> option;
        system("cls");

        switch(option) {
            case 1: cout << "Please choose Fighter 1: ";
                    // change this to string?
                    cin >> selectedFighter1;
                    cout << "Please choose Fighter 2: ";
                    cin >> selectedFighter2;
                    break;
            case 2: cout << "Create a fighter: ";
                break;
                    // Start fight. Set fighters here or the damage will accumulate 
                    // each time number 3 is chosen.
            case 3: Fighter goku("Goku", 100, 35, 15);
                    Fighter vegeta("Vegeta", 125, 35, 10);
                    Fight::StartFight(goku, vegeta); break;
        }
    } 
        while (option != 4);
    
    return 0;
}