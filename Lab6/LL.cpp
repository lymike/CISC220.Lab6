/*
 * LL.cpp
 *
 *  Created on: Nov 10, 2017
 *      Author: Michael Ly
 */

#include "LL.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

LL::LL(){
	first = NULL;
	last = NULL;
	size = 0;
	score = 0;
}

void LL::push(string s) {
	if (first == NULL) {
		addFirst(s);
	}
	else {
		NodeL* n = new NodeL(s);
		last->next = n;
		last = n;
		size += 1;
	}
}

void LL::addFirst(string s) {
	NodeL *n = new NodeL(s);
	first = n;
	last = n;
	size += 1;
}

void LL::printList() {
	NodeL *tmp = first;
	while(tmp != NULL){
		cout << tmp->word << tmp->wscore << ", ";
		tmp = tmp->next;
	}
	cout << endl;
}

void LL::getScore() {
	score = 0;
	NodeL *tmp = first;
	while(tmp != NULL) {
		score += tmp->wscore;
		tmp = tmp->next;
	}
}
