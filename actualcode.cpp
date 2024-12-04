#include<iostream>
using namespace std;
//VARIABLE IS GLOBAL
//inventory using array
string inventory[10];
int money = 10;
int playerHealth = 100;
//function declaration
void shop();
void BattleSim();

int main() {
	cout << "make sure to use all lower capitals, and if the word" << endl;
	cout << "is all capitals then its an path you can type." << endl;
	cout << "YOU ARE EMPLOYED!" << endl;
	cout << "You are hired at a private company and you have to deal with people" << endl;
	cout << "trespassing on abandoned buildings. Today is your first" << endl;
	cout << "day on the job. Well what are you" << endl;
	cout << "waiting for? Go get em champ!" << endl;
	srand(time(NULL)); //seeds your number GEN
	int room = 1;
	string input;
	while (playerHealth > 0) { //game loop

		switch (room) {
		case 1:
			cout << "You walk in the building and see an old reception desk. You can go NORTH or SOUTH." << endl;
			cin >> input;
			if (input == "south")
				room = 2;
			else if (input == "north")
				room = 6;
			else if (input == "key" || "grab")
				inventory[0] = "Key";

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
			//BattleSim(); NEED TO ADD LATER BUT NOT RIGHT NOW
			cout << "There is a huge metal door.." << endl;
			cout << "You can go WEST or SOUTH." << endl;
			cin >> input;
			if (input == "west")
				room = 3;
			if (input == "south")
				room = 5;
			break;
		case 5:
			cout << "You can OPEN or go NORTH." << endl;
			if (inventory[1] != "Sword") {
				cout << "There is a chest on the floor but its locked" << endl;
				cout << "A note reads:" << endl;
				cout << "The key is in the desk, you will need it..." << endl;
			}
			cin >> input;
			if (input == "open")
				if (inventory[0] == "Key") {
					cout << "You unlock the chest with the KEY and got a SWORD!" << endl;
					inventory[1] = "Sword";
					inventory[0] = " "; //no more key
				}
				else {
					cout << "The chest rattles. It is locked" << endl;
					
				}
			else if (input == "north")
				room = 4;
			break;
		}// end of game loop
		
	}if (playerHealth <= 0)
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
