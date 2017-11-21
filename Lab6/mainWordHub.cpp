/*
 * mainWordHub.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: Debra
 */


//#include "AVLTree.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Game.hpp"

using namespace std;

int main() {

	srand(time(NULL));

	cout << "Test 1" << endl; // Default start with Test 1, comment out this test when checking other tests.
	Game *game = new Game("testdict.txt",false);
	cout << "*******************************" << endl;

	cout << "Test 2" << endl; // Uncommon this test and comment out other tests for this to work.
	//Game *game2 = new Game("commondict.txt", false);
	//game2->startGame();
	cout << "*******************************" << endl;

	cout << "Test 3" << endl; // Uncommon this test and comment out other tests for this to work.
	//Game *game3 = new Game("testdict.txt",true);
	cout << "*******************************" << endl;

	cout << "Test 4" << endl; // Comment out the function in Test 3 for this to work.
	//game3->startGame();

	return 0;
}

