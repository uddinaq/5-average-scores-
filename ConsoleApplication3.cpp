#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>

using namespace std;

//Size of Array containing player names
const int PLAYERS = 10;

//Size of array containing player scores (Columns of 2d Array)
const int SCORES = 5;


//Reads data from file and stores in provided arrays.
bool GetBowlingData(string fileName, string players[], int scores[][SCORES]) {
	//open the file for reading
	ifstream fin(fileName);

	//if file not opened, return false
	if (fin.is_open() == false) {
		return false;
	}

	//if file opened read players data.
	for (int i = 0; i < PLAYERS; i++) {
		fin >> players[i];
		for (int j = 0; j < SCORES; j++) {
			fin >> scores[i][j];
		}
	}

	//Close the file
	fin.close();
	return true;

}

//Calculates and returns average scores
//Allocates the memory for array dynamically.
float* GetAverageScores(string* players, int scores[][SCORES]) {
	//Create new array
	float* averageScores = new float[PLAYERS];

	//Calculate average for each player
	for (int i = 0; i < PLAYERS; i++) {
		float  sum = 0;
		for (int j = 0; j < SCORES; j++)
			sum += scores[i][j];
		averageScores[i] = sum / SCORES;
	}
	//return pointer to array containing average.
	return averageScores;
}

//Prints Player details and their scores 
void PrettyPrintScores(string* players, int scores[][SCORES]) {
	//Get average scores ofo each player
	float* averageScores = GetAverageScores(players, scores);

	//Print data for each player
	for (int i = 0; i < PLAYERS; i++) {
		cout << setw(25) << left << "Player Name: " << players[i] << endl;
		cout << setw(25) << left << "Player Scores: ";

		//print players scores
		for (int j = 0; j < SCORES; j++)
			cout << scores[i][j] << "\t";
		cout << endl;
		cout << setw(25) << "Player Average Scores: " << averageScores[i] << endl << endl;
	}

	//Deallocate the memory allocated for averages array
	delete[] averageScores;
}

int main() {

	//File name containing input data
	const string fileName = "BowlingScores.txt";

	//Players array
	string players[PLAYERS];
	//Scores array
	int scores[PLAYERS][SCORES];
	bool readSuccessfully = false;
	//Read data from file
	readSuccessfully = GetBowlingData(fileName, players, scores);
	if (readSuccessfully == false)
		cout << "Error! Can't read data from file\n";
	else {
		PrettyPrintScores(players, scores);
	}
	return 0;
}