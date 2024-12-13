#pragma once
#include <iostream>
#include <cstdlib>
#include <list>
#include <ctime>
#include <chrono>
using namespace std;

class Hash
{
	int numkeys; // number of keys (size of hash table)
	list<int>* hash; // hash table represented as an array of lists

public: 
	Hash(int numkeys);
	void insertData(int data);
	int hashKey(int data);
	void displayHash();
	bool findValue(int data);
	bool removeValue(int data);

};
int generateRandomNumber(); 
