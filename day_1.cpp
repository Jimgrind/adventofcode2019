
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	ifstream file;
	string temp = "";
	int fuel = 0;

	file.open("day_1.txt");

	while(!file.eof()) {
		getline(file, temp);

		fuel += (stoi(temp)/3) - 2;

	}

	cout << fuel << endl;
	return 0;
}