#include<iostream>
#include<Windows.h>
using namespace std;
//VARIABLE IS GLOBAL
//inventory using array
string inventory[5];
int money = 10;
int playerHealth = 100;
bool room1 = false;
bool room2 = false;
bool room3 = false;
bool room4 = false;
bool room5 = false;
bool room6 = false;
bool room7 = false;
bool room8 = false;
bool room9 = false;
bool room10 = false;
//function declaration
void shop();
void BattleSim();
void BossSim();
void stats();

int main() {
	srand(time(NULL)); //seeds your number GEN
	cout << "make sure to use all lower capitals, and if the word" << endl;
	cout << "Type: STATS to see money, hp, and your inventory." << endl;
	cout << "YOU ARE EMPLOYED!" << endl;
	cout << "You are hired at a private company and you have to deal with people" << endl;
	cout << "trespassing on abandoned buildings. Today is your first" << endl;
	cout << "day on the job. Well what are you" << endl;
	cout << "waiting for? Go get em champ!" << endl;

	int room = 1;
	string input;


	while (playerHealth > 0) { //game loop

		switch (room) {
		case 1:
			if (room1 == false) {
				cout << "you found money!" << endl;
				money += 10;
				room1 = true;
			}
			cout << "You walk in the building and see an old reception desk. You can go NORTH or SOUTH." << endl;
			cin >> input;
			if (input == "south")
				room = 2;
			else if (input == "north")
				room = 6;
			else if (input == "stats")
				stats(); 
			else if (input == "key")
				if (inventory[0] != "Key") {
					inventory[0] = "Key";
				}
				else cout << "You already have the key." << endl;
			break;
		case 2:
			if (room2 == false) {
				cout << "You walk into a small room where you accidently" << endl;
				cout << "step on a makeshift bear trap.." << endl;
				cout << "You also found money!" << endl;
				playerHealth -= 5;
				money += 5;
				room2 = true;
			}
			cout << "You can go NORTH or EAST" << endl;
			cin >> input;
			if (input == "north")
				room = 1;
			else if (input == "east")
				room = 3;
			else if (input == "stats")
				stats();
			break;
		case 3:
			if (room3 == false) {
				cout << "You continue foward and see a small goblin." << endl;
				cout << "Goblin: If you give me some HP ill give you money.." << endl;
				cout << "Do you want to GIVE HEALTH to goblin?" << endl;
				cin >> input;
				if (input == "health" || input == "give" || input == "yes")
					playerHealth -= 10, money += 10, cout << "Pleasure doing buisness with you!" << endl;
				else
					cout << "Your loss.." << endl;
				room3 = true;
			}
			cout << "You can go WEST or EAST..." << endl;
			cin >> input;
			if (input == "west")
				room = 2;
			else if (input == "east")
				room = 4;
			else if (input == "stats")
				stats();
			break;
		case 4:
			if (room4 == false) {
				cout << "ooh! a dollar! GRAB it!" << endl;
				cin >> input;
				if (input == "nah" || input == "no")
					cout << "I told you should've grabbed it! Theres a goblin!!!" << endl, BattleSim(), room4 = true;
				else if (input == "grab" || input == "ok" || input == "okay")
					cout << "Oh no! The dollar was on a string.." << endl, BattleSim(), money += 5, room4 = true;
				break;
			}
			cout << "There is a huge metal door.." << endl;
			cout << "You can go WEST or SOUTH." << endl;
			cin >> input;
			if (input == "west")
				room = 3;
			if (input == "south")
				room = 5;
			else if (input == "stats")
				stats();
			break;
		case 5:
			if (room5 == false) {
				cout << "you found money!" << endl;
				money += 10;
				room5 = true;
			}
			cout << "You can OPEN or go NORTH." << endl;
			if (inventory[1] != "Sword") {
				cout << "There is a chest on the floor but its locked" << endl;
				cout << "A note reads:" << endl;
				cout << "The key is in the desk, you will need it..." << endl;
			}
			cin >> input;
			if (input == "open")
				if (inventory[0] == "Key") {
					if (inventory[1] == "Sword") {
						cout << "You already opened the chest." << endl;

					}
					else { cout << "You unlock the chest with the KEY and got a SWORD!" << endl;
					inventory[1] = "Sword";
					cout << "                    |__________________________________ " << endl;
					cout << " 	////////////|                                 / " << endl;
					cout << " 	\\\\\\\\\\\\\\\\\\\\\\\\|________________________________/ " << endl;
					cout << "                    |                                  " << endl;
					}
				}
				else {
					cout << "The chest rattles. It is locked" << endl;

				}
			else if (input == "north")
				room = 4;
			else if (input == "stats")
				stats();
			break;
		case 6:
			if (room6 == false) {
				cout << "You walk into the room and see a goblin blocking the door" << endl;
				cout << "Goblin: 'goo goo ga ga' (Fight me to get through or pay me)" << endl;
				cout << "FIGHT or PAY 20 coins? Or just go SOUTH." << endl;
				cin >> input;
				if (input == "fight")
					BattleSim(), room6 = true;

				else if (input == "pay")
					if (money > 20) {
						money -= 20;
						room = 7;
						room6 = true;
					}
					
					else {
						cout << "GRAHHH (Not enough!)" << endl;
						BattleSim();
						room = 7;
						room6 = true;
					}
				else if (input == "south")
					room = 1;
				else if (input == "stats")
					stats();
				break;
			}
			cout << "You step over the corspe of the goblin" << endl;
			cout << "You can go east or south." << endl;
			cin >> input;
			if (input == "east")
				room = 7;
			else if (input == "south")
				room = 1;
			else if (input == "stats")
				stats();
			break;
		case 7:
			if (room7 == false) {
				cout << "you found money!" << endl;
				money += 10;
				room7 = true;
			}
			cout << "You walk into a fancy room with a huge door." << endl;
			cout << "Go WEST or go EAST" << endl;
			cin >> input;
			if (input == "west")
				room = 6;
			else if (input == "east")
				room = 8;
			else if (input == "rest")
				cout << "Go Foward" << endl;
			else if (input == "stats")
				stats();
			break;
		case 8:
			if (room8 == false) {
				cout << "you found money!" << endl;
				money += 10;
				room8 = true;
			}
			cout << "After what felt like forever you reach a huge metal door." << endl;
			cout << "Enter and go EAST or walk all the way back and go WEST." << endl;
			cin >> input;
			if (input == "west")
				room = 7;
			else if (input == "east")
				room = 9;
			else if (input == "stats")
				stats();
			break;
		case 9:
			if (room9 == false) {
				cout << "you found money!" << endl;
				money += 10;
				room9 = true;
			}
			shop();
			cout << "Continue thy path and venture EAST (You can't go west btw)" << endl;
			cin >> input;
			if (input == "west")
				cout << "I just said you couldn't go west" << endl;
			if (input == "east")
				room = 10;
			else if (input == "stats")
				cout << "Look closely." << endl, stats();
			break;
		case 10:
			if (room10 == false) {
				BossSim();
				room10 = true;
			}
			if (playerHealth > 0) {
				cout << "You beat the boss, you walk out of the bulding and go home." << endl;
				cout << "You took a long nap but got fired because you went to the" << endl;
				cout << "wrong abanoned building. YOUR ARE UNEMPLOYED" << endl;
				system("color 76");
				system("pause");
			}

		}// end of game loop

	}if (playerHealth <= 0)
		cout << "GAME OVER" << endl;
	else
		cout << "YOU WIN!" << endl;

}

void BattleSim() {
	int MonsterHealth = 20;
	int hit;
	int choice;
	system("color 47");
	cout << endl << "---------BATTLE----------" << endl;
	while (playerHealth > 0 && MonsterHealth > 0) {
		// monster attack sequence
		if (inventory[4] == "Armor") {
			if (inventory[2] == "Sheild") {
				hit = rand() % 1 + 5; // monster does 5 dmg
				cout << "The monster hits you and you take " << hit << " dmg" << endl;
				playerHealth -= hit;
			}
		}

		else if (inventory[4] == "Armor") {
			hit = rand() % 6 + 5; // monster does 5-10 dmg
			cout << "The monster hits you and you take " << hit << " dmg" << endl;
			playerHealth -= hit;

		}

		else if (inventory[2] == "Sheild") {
			hit = rand() % 6 + 5; // monster does 5-10 dmg
			cout << "The monster hits you and you take " << hit << " dmg" << endl;
			playerHealth -= hit;

		}

		else {
			hit = rand() % 11 + 5; // hits for 5-15
			cout << "Monster bites you and you take " << hit << " dmg" << endl;
			playerHealth -= hit;

		}


		cout << "Press 1 to attack, 2 to use health potion, 3 to try to escape." << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			//player attack sequence
			if (inventory[1] == "Sword") {
				hit = rand() % 11 + 10; //hit for 10-20 dmg
				cout << "You slash the monster for " << hit << " dmg" << endl;
				MonsterHealth -= hit;

			}

			else {
				hit = rand() % 6 + 5; // hit for 5-10 dmg
				cout << "You punch the monster for " << hit << " dmg" << endl;
				MonsterHealth -= hit;

			}
			break;
		case 2: //drink a potion
			if (inventory[3] == "Potion") {
					cout << "*drinking potion*" << endl;
					playerHealth += 50;
					inventory[3] = " ";

			}
			else cout << "Sorry, you do NOT have a potion lil bro" << endl;
			break;

		case 3: // try to escape
			hit = rand() % 100 + 1; //from 1-100
			if (hit > 70) { //30% chance
				cout << "You successfully escape!" << endl;
				MonsterHealth = 0;

			}
			else cout << "You were unable to escape" << endl;
			break;

		}// end switch


		cout << "HP: " << playerHealth << endl;
		cout << "Monster HP: " << MonsterHealth << endl;
		  



	}
	system("color 07");
	cout << "-----------------------------------------------------------------------------" << endl;
}

void BossSim() {
	int BossHealth = 100;
	int hit;
	int choice;
	system("color 04");
	cout << endl << "---------BATTLE----------" << endl;
	while (playerHealth > 0 && BossHealth > 0) {
		// monster attack sequence
		if (inventory[4] == "Armor") {
			if (inventory[2] == "Sheild") {
				hit = rand() % 6 + 5; // monster does 5-10 dmg
				cout << "The monster hits you and you take " << hit << " dmg" << endl;
				playerHealth -= hit;
			}
		}

		else if (inventory[4] == "Armor") {
			hit = rand() % 11 + 5; // monster does 5-15 dmg
			cout << "The monster hits you and you take " << hit << " dmg" << endl;
			playerHealth -= hit;

		}

		else if (inventory[2] == "Sheild") {
			hit = rand() % 11 + 5; // monster does 5-15 dmg
			cout << "The monster hits you and you take " << hit << " dmg" << endl;
			playerHealth -= hit;

		}

		else {
			hit = rand() % 16 + 5; // hits for 5-15
			cout << "Monster bites you and you take " << hit << " dmg" << endl;
			playerHealth -= hit;

		}


		cout << "Press 1 to attack, 2 to use health potion, 3 to try to escape." << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			//player attack sequence
			if (inventory[1] == "Sword") {
				hit = rand() % 11 + 10; //hit for 10-20 dmg
				cout << "You slash the monster for " << hit << " dmg" << endl;
				BossHealth -= hit;

			}

			else {
				hit = rand() % 6 + 5; // hit for 5-10 dmg
				cout << "You punch the monster for " << hit << " dmg" << endl;
				BossHealth -= hit;

			}
		case 2: //drink a potion
			if (inventory[3] == "Potion") {
					cout << "*drinking potion*" << endl;
					inventory[3] = " ";
					playerHealth += 50;

			}
			else cout << "Sorry, you do NOT have a potion lil bro" << endl;
			break;

		case 3: // try to escape
			hit = rand() % 100 + 1; //from 1-100
			if (hit > 95) { //5% chance
				cout << "You successfully escape!" << endl;
				BossHealth = 0;

			}
			else cout << "You were unable to escape" << endl;
			break;

		}// end switch


		cout << "HP: " << playerHealth << endl;
		cout << "Boss HP: " << BossHealth << endl;




	}
	system("color 07");
	cout << "-----------------------------------------------------------------------------" << endl;
}

void shop() {
	char input = 'a';
	cout << endl << endl << "---------------------------------------------------------" << endl;
	cout << "What are you doing here? Oh well anyways welcome to my shop." << endl;
	cout << "type 'q' to quit" << endl;
	while (input != 'q') {
		cout << "Pick an item: S) Sheild (Take less damage) P) HP Potion (Heals 50 HP) A) Armor (Take less damage)" << endl;
		cout << "Sheild price: 25) Potion price: 15) Armor price: 25)" << endl;
		cin >> input;
		switch (input) {
		case 's':
			if (inventory[2] == "Sheild") {
				cout << "You already have this" << endl;

			}

			else 
				if (money >= 25) {
					cout << "You grabbed a huge iron shield." << endl;
					inventory[2] = "Sheild";
					money -= 25;
				}
				else if (money < 25) {
					cout << "You're too broke! Broke boy." << endl;
				}
			break;
		case 'p':
			if (inventory[3] == "Potion") {
				cout << "You already have this" << endl;

			}

			else
				if (money >= 15) {
					cout << "You grabbed a green potion." << endl;
					inventory[3] = "Potion";
					money -= 15;
				}
				else if (money < 15) {
					cout << "You're too broke! Broke boy." << endl;
				}
			break;
		case 'a':
			if (inventory[4] == "Armor") {
				cout << "You already have this" << endl;

			}

			else
				if (money >= 25) {
					cout << "You grabbed a set of iron armor." << endl;
					inventory[4] = "Armor";
					money -= 25;
				}
				else if (money < 25) {
					cout << "You're too broke! Broke boy." << endl;
				}
			break;
		}

	}
	cout << "---------------------------------------------------------" << endl;
}

void stats() {

	cout << endl;
	cout << "Inventory: ";
	for (int i = 0; i < 5; i++)
		cout << inventory[i] << " | ";
	cout << endl << endl;
	cout << "Money: " << money << endl;
	cout << endl;
	cout << "Health: " << playerHealth << endl;
	cout << endl;

}
