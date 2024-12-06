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
void BossSim();

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
			cout << "You walk into a small room where you accidently" << endl;
			cout << "step on a makeshift bear trap.." << endl;
			cout << "You can go NORTH or EAST" << endl;
			playerHealth -= 5;
			cin >> input;
			if (input == "north")
				room = 1;
			else if (input == "east")
				room = 3;
			break;
		case 3:
			cout << "You continue foward and hear weird noises.." << endl;
			cout << "You see hear weird noises in the next room.." << endl;
			cout << "You can go WEST or EAST..." << endl;
			cin >> input;
			if (input == "west")
				room = 2;
			else if (input == "east")
				room = 4;
			break;
		case 4:
			//BattleSim(); //NEED TO ADD LATER BUT NOT RIGHT NOW
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
		case 6:
			cout << "You walk into the room and see a goblin blocking the door" << endl;
			cout << "Goblin: 'goo goo ga ga' (Fight me to get through or pay me)" << endl;
			cout << "FIGHT or PAY 20 coins? Or just go SOUTH." << endl;
			cin >> input;
			if (input == "fight")
				BattleSim();
			else if (input == "pay")
				room = 7;
			else if (input == "south")
				room = 1;
			else if (input == "nah")
				cout << "Goblin: 'raaa raa go' (I didn't know you were chill like that)" << endl;
				room = 7;
			break;
		case 7:
			cout << "You walk into a fancy room with a huge door." << endl;
			cout << "Go WEST or go EAST" << endl;
			cin >> input;
			if (input == "west")
				room = 6;
			else if (input == "east")
				room = 8;
			else if (input == "rest")
				cout << "Go Foward" << endl;
			break;
		case 8:
			cout << "After what felt like forever you reach a huge metal door." << endl;
			cout << "Enter and go EAST or walk all the way back and go WEST." << endl;
			cin >> input;
			if (input == "west")
				room = 7;
			else if (input == "east")
				room = 9;
			break;
		case 9:
			shop();
			cout << "Continue thy path and venture EAST (You can't go west btw)" << endl;
			cin >> input;
			if (input == "west")
				cout << "I just said you couldn't go west" << endl;
			if (input == "east")
				room = 10;
			break;
		case 10:
			cout << "A huge slime blob stand before you." << endl;
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

void BossSim() {
	int BossHealth = 100; //LOCAL variable: can only be seen and used in this function
	int damage;
	char dummy;
	cout << endl << endl << "---------------------ENCOUNTER----------------------------" << endl;
	cout << "The boss growls" << endl;
	while (playerHealth > 0 && BossHealth > 0) {
		//player DMG
		damage = rand() % 11 + 5; //number between 0-10
		cout << "You hit the monster for" << " " << damage << " " << "damage" << endl;
		BossHealth -= damage;
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
		if (BossHealth > 0)
			cout << "Boss HP:" << BossHealth << endl;
		else
			cout << "You survived" << endl;
		cout << endl;

	} // end of mini loop

	cout << endl << endl << "---------------------BATTLE-FINISH----------------------------" << endl;

}



//NOTE TO SELF: MAKE STUFF COST MONEY
void shop() {
	char input = 'a';
	cout << endl << endl << "---------------------------------------------------------" << endl;
	cout << "What are you doing here? Oh well anyways welcome to my shop." << endl;
	cout << "type 'q' to quit" << endl;
	while (input != 'q') {
		cout << "Pick an item: S) Shield (+50 HP) D) Damage Potion (Chance to do more damage) ?) ???" << endl;
		cin >> input;
		switch (input) {
		case 's':
			cout << "You grabbed a huge iron shield." << endl;
			inventory[0] = "Chips";
			break;
		case 'd':
			cout << "Heres your MANGO" << endl;
			inventory[1] = "MANGO";
			break;
		case '?':
			cout << "Heres your CHEESE, it isn't drippy" << endl;
			inventory[2] = "Cheese";
			break;
		}

	}
	cout << "---------------------------------------------------------" << endl;
}
