#include <iostream>
#include <cstdlib>
#include <list>
#include "Hash.h"
#include <ctime>
#include <chrono>
using namespace std;

Hash::Hash(int numkeys) // constructor to initialize the hash table with the number of keys
{
	this->numkeys = numkeys;
	if (numkeys <= 0)
	{
		cout << "error: numkeys must be greater than 0." << endl;
		exit(1); // exit if numkeys is invalid
	}
	hash = new list<int>[numkeys]; // Allocate array of lists
}


int Hash::hashKey(int data) // generate hash key for the given data
{
	return data % this->numkeys; // Ensure key is within valid range
}
void Hash::insertData(int data) // Insert data into the hash table
{
	int dataKey = hashKey(data); // compute hash key
	hash[dataKey].push_back(data); // insert data into the corresonding list
}

void Hash::displayHash() // dsplay all elements in the hash table
{
	for (int i = 0; i < numkeys; i++)
	{
		cout << i;
		for (auto x : hash[i])
		{
			cout << "--> " << x;
		}
		cout << "\n";
	}
}

bool Hash::findValue(int data) // find a value in the hash table
{
	int dataKey = hashKey(data); // get the hash key

	for (int val : hash[dataKey])
	{
		if(val == data)
		return true;
	}
	return false;
	
};

bool Hash::removeValue(int data) // Delete a value from the hash table
{
	int dataKey = hashKey(data); // get the hash key

	auto i = hash[dataKey].begin(); // Get the list at the hash key

	while (i != hash[dataKey].end()) // iterate through the list
	{
		if (*i == data)
		{
			hash[dataKey].erase(i); // erase the data from the list
			return true;
		}
		else
		{
			i++;
		}
	}
	if (i != hash[dataKey].end())
	{
		return false; // data not found to delete
	}

	
	return 0;
};
	//Helper function to generate random integer values
int generateRandomNumber()
{
	srand(time(NULL)); // seed the random number generator
	int random_index = rand() % 10000; // Generate a random index in range 0-9999
	return random_index; // Return random number between 0 and 10000
}


	
