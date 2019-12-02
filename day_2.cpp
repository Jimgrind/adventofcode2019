
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	ifstream file;
	string temp = "";
	int len = 0;
	int* code;
	int i = 0;
	int t;

	file.open("day_2.txt");
	cout << "Getting length" << endl;
	while(!file.eof()) {
		len ++;
		getline(file, temp, ',');
	}

	code = new int[len];

	file.close();
	file.open("day_2.txt");

	cout << "reading info" << endl;
	while(!file.eof()) {
		
		getline(file, temp, ',');
		code[i] = stoi(temp);
		cout << code[i] << " ";
		i++;
	}
	cout << endl;


	code[1] = 12;
	code[2] = 2;
	for(int i = 0; i < len; i++) {
		cout << code[i] << " " << code[i + 1] << " " << code[i + 2] << " " << code[i + 3] << endl;
		i+=4;
	}
	for(int i = 0; i < len;) {
		//Interpret
		if(code[i] == 1) {
			printf("adding %d + %d to %d index\n", code[code[i+1]], code[code[i+2]], code[i+3]);
			code[code[i+3]] = code[code[i+1]] + code[code[i+2]];
			i+=4;
		} else if(code[i] == 2) {
			printf("multiplying %d * %d to %d index\n", code[code[i+1]], code[code[i+2]], code[i+3]);
			code[code[i+3]] = code[code[i+1]]*code[code[i+2]];

			i+=4;
		} else if(code[i] == 99) {
			printf("Ending interpretation at %d\n", i);
			break;
		} else {
			printf("Something went wrong\n");
		}
	}

	cout << code[0] << endl;
	delete [] code;
	file.close();
	return 0;
}