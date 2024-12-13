#include <iostream>
#include <cstdlib>
#include <list>
#include "Hash.h"
#include <ctime>
#include <chrono>
using namespace std;

int main()
{
	srand(time(0)); // seed the random number generation
	int numIndex = 1000; // number of indexes(arrays) in the table
	Hash hash_1000(numIndex); // create a hash table with 1000 slots

	// Insertion random data into the hash table and measure insertion time
	bool found = false;

	auto start_insert = std::chrono::high_resolution_clock::now(); // start time for insertion
	for (int i = 0; i < 100; i++) // 100- number of elements to be added
	{
		int random_value = rand() % 100; // Generate random values between 0 and 100
		hash_1000.insertData(random_value); // 100 = the range for values (1-100)
	}
	auto end_insert = std::chrono::high_resolution_clock::now(); // end time insertion
	std::chrono::duration<double> inserDataDuration = (end_insert - start_insert); // calculate duration
	cout << " Insert operation for 100: " << inserDataDuration.count() << "seconds. "  << endl;
	
	start_insert = std::chrono::high_resolution_clock::now(); // start time for insertion
	for (int i = 0; i < 1000; i++) // 1000- number of elements to be added
	{
		int random_value = rand() % 1000; // Generate random values between 0 and 100
		hash_1000.insertData(random_value); // 1000 = the range for values (1-100)
	}
	end_insert = std::chrono::high_resolution_clock::now(); // end time insertion
	inserDataDuration = (end_insert - start_insert); // calculate duration
	cout << " Insert operation for 1000: " << inserDataDuration.count() << "seconds. " << endl;

	start_insert = std::chrono::high_resolution_clock::now(); // start time for insertion
	for (int i = 0; i < 10000; i++) // 10000- number of elements to be added
	{
		int random_value = rand() % 10000; // Generate random values between 0 and 100
		hash_1000.insertData(random_value); // 1000 = the range for values (1-100)
	}
	end_insert = std::chrono::high_resolution_clock::now(); // end time insertion
	inserDataDuration = (end_insert - start_insert); // calculate duration
	cout << " Insert operation for 10000: " << inserDataDuration.count() << "seconds. " << endl;
	
	// Display the intial hash table
	cout << "intial hash table: " << endl;
	hash_1000.displayHash();

	
	// Perform retrieve operation for the random number in 100 dataset and measure time
	int rand_value = rand() % 100;// generate a random value between 0 and 99
	auto start_find = std::chrono::high_resolution_clock::now(); // start time for find
	 found = hash_1000.findValue(rand_value); // find random value
	auto end_find = std::chrono::high_resolution_clock::now();// end time for find
	std::chrono::duration<double> findDuration = (end_find - start_find); // calculate duration
; 	if (found)
	{
		cout << " random value  " << rand_value << " was found in " << findDuration.count() << "seconds." << endl;

		// Delete a random value in dataset 100 from the hash table after finding it
		auto start_delete = std::chrono::high_resolution_clock::now(); // start time for deletion
		bool deleted = hash_1000.removeValue(rand_value); // dlete random value 
		auto end_delete = std::chrono::high_resolution_clock::now();// end time for deletion
		std::chrono::duration<double> removeValueDuration = (end_delete - start_delete); // calculate duration
		cout << " Random value " << rand_value << " has been deleted from 100 dataset table. " << removeValueDuration.count() << " seconds. " << endl;
	}
	else 
	{
		cout << "random value" << rand_value << " was not in table." << endl;
	}

	// Perform retrieve operation for the random  number in 1000 dataset and measure time
	 rand_value = rand() % 1000;// generate a random value between 0 and 999
	start_find = std::chrono::high_resolution_clock::now(); // start time for find
	 found = hash_1000.findValue(rand_value); // find random value 
	end_find = std::chrono::high_resolution_clock::now();// end time for find
	findDuration = (end_find - start_find); // calculate duration
	if (found)
	{
		cout << " random value  " << rand_value << " was found in " << findDuration.count() << "seconds." << endl;

		// Delete a random value in dataset 1000 from the hash table after finding it
		auto start_delete = std::chrono::high_resolution_clock::now(); // start time for deletion
		bool deleted = hash_1000.removeValue(rand_value); // dlete random value 
		auto end_delete = std::chrono::high_resolution_clock::now();// end time for deletion
		std::chrono::duration<double> removeValueDuration = (end_delete - start_delete); // calculate duration
		cout << " Random value " << rand_value << " has been deleted from 1000 dataset table. " << removeValueDuration.count() << " seconds. " << endl;
	}
	else
	{
		cout << "random value" << rand_value << " was not in table." << endl;
	}

	// Perform retrieve operation for the random number in 10000 dataset and measure time
	rand() % 10000;// generate a random value between 0 and 9999
	start_find = std::chrono::high_resolution_clock::now(); // start time for find
	 found = hash_1000.findValue(rand_value); // find random value 
	end_find = std::chrono::high_resolution_clock::now();// end time for find
	findDuration = (end_find - start_find); // calculate duration
	; 	if (found)
	{
		cout << " random value  " << rand_value << " was found in " << findDuration.count() << "seconds." << endl;
		

		// Delete a random value in dataset 10000 from the hash table after finding it
		auto start_delete = std::chrono::high_resolution_clock::now(); // start time for deletion
		bool deleted = hash_1000.removeValue(rand_value); // dlete random value 
		auto end_delete = std::chrono::high_resolution_clock::now();// end time for deletion
		std::chrono::duration<double> removeValueDuration = (end_delete - start_delete); // calculate duration
		cout << " Random value " << rand_value << " has been deleted from 10000 dataset table. " << removeValueDuration.count() << " seconds. " << endl;
	}
	else
	{
		cout << "random value" << rand_value << " was not in table." << endl;
	}
	
	

	// Display Hash table after deleting random values from each dataset
	cout << "\nHash table after deletion:\n";
	hash_1000.displayHash();

	return 0;
}