#include<iostream>
using namespace std;
//VARIABLE IS GLOBAL
//inventory using array
string inventory[10];
int money = 10;
void BattleSim();
int playerHealth = 100;
//function declaration
void shop();


int main() {
	srand(time(NULL)); //seeds your number GEN
	int room = 1;
	string input;
	while (playerHealth > 0) { //game loop
		switch (room) {
		case 1:
			cout << "make sure to use all lower capitals, and if the word" << endl;
			cout << "is all capitals then its an path you can type." << endl;
			cout << "YOU ARE EMPLOYED!" << endl;
			cout << "You are hired at a private company and you have to clean up contamination leaks!" << endl;
			cout << "Your first day of the job has you at an abandoned building where people" << endl;
			cout << "have been hearing odd noises of screaming... Well what are you" << endl;
			cout << "waiting for? Go get em champ!" << endl;
			cout << "You walk in the building and see an old reception desk. You can go NORTH or SOUTH." << endl;
			cin >> input;
			if (input == "south")
				room = 2;
			else if (input == "north")
				room = 6;

			break;
		case 2:
			cout << "You walk south and see a man with a ski mask on" << endl;
			cout << "He looks like he wants to fight but hes injured" << endl;
			cout << "You can FIGHT, go NORTH or go EAST" << endl;
			cin >> input;
			if (input == "north")
				room = 1;
			else if (input == "fight")
				cout << "Why? Hes already injured, lets do that again" << endl;
			else if (input == "east")
				room = 3;
			break;
		case 3:
			cout << "You continue foward and hear weird noises.." << endl;
			cout << "You see a closet making noise.." << endl;
			cout << "You can go WEST or EAST..." << endl;
			cin >> input;
			if (input == "west")
				room = 2;
			else if (input == "east")
				room = 4;
			break;
		case 4:
			BattleSim();

		}
	}// end of game loop
	if (playerHealth <= 0)
		cout << "GAME OVER" << endl;
	else
		cout << "YOU WIN!" << endl;
}

void BattleSim() {
	int MonsterHealth = 20; //LOCAL variable: can only be seen and used in this function
	int damage;
	char dummy;
	cout << endl << endl << "---------------------ENCOUNTER----------------------------" << endl;
	cout << "an orge attacked!" << endl;
	while (playerHealth > 0 && MonsterHealth > 0) {
		//player DMG
		damage = rand() % 11 + 5; //number between 0-10
		cout << "You hit the monster for" << " " << damage << " " << "damage" << endl;
		MonsterHealth -= damage;
		cout << "Press any key to continue" << endl;
		cin >> dummy;

		//monster DMG
		damage = rand() % 21 + 3; //number between 0-20
		cout << "The monster hits you for" << " " << damage << " " << "damage" << endl;
		playerHealth -= damage;
		cout << "Press any key to continue" << endl;
		cin >> dummy;


		//value print for health
		if (playerHealth > 0)
			cout << "HP: " << playerHealth << endl;
		else
			cout << "You died" << endl;
		if (MonsterHealth > 0)
			cout << "Monster HP:" << MonsterHealth << endl;
		else
			cout << "You survived" << endl;
		cout << endl;

	} // end of mini loop

	cout << endl << endl << "---------------------BATTLE-FINISH----------------------------" << endl;

}

void shop() {
	char input = 'a';
	cout << endl << endl << "---------------------------------------------------------" << endl;
	cout << "welcome to the shop!" << endl;
	cout << "type 'q' to quit" << endl;
	while (input != 'q') {
		cout << "Pick an item: c) Chips m) MANGO d) cheese" << endl;
		cin >> input;
		switch (input) {
		case 'c':
			cout << "Heres your CHIPS" << endl;
			inventory[0] = "Chips";
			break;
		case 'm':
			cout << "Heres your MANGO" << endl;
			inventory[1] = "MANGO";
			break;
		case 'd':
			cout << "Heres your CHEESE, it isn't drippy" << endl;
			inventory[2] = "Cheese";
			break;
		}

	}
	cout << "---------------------------------------------------------" << endl;
}
