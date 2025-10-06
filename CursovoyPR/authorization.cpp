#include <iostream>
#include <string>
#include <algorithm> 
#include "authorization.h"
#include <fstream>
#include <iomanip>
#include "globals.h"

using namespace std;


void authorization::couttextA(int b)
{
	switch (b) {
	case 1: {
		cout << "=== МЕНЮ ===" << endl;
		cout << "Введите 1 для авторизации пользователя"
		<< endl << "Введите 2 для регистрации пользователя" << endl;
		break;
	}
	case 2: {
		cout << "Введите логин и пароль нового пользователя" << endl;
		break;
	}
	case 3: {
		cout << "Введите логин и пароль пользователя" << endl;
		break;
	}
	case 4: {
		cout << "Введено неверное значение!" << endl;
		break;
	}
	}
};

int authorization::vibauth()
{
	int a;
	cin >> a;
	cin.clear();
	return(a);
};

void authorization::sinin()
{
	couttextA(2);
	SinInCheck();
};

void authorization::getin()
{
	couttextA(3);
	LogInCheck();
};

void authorization::VvodAut()
{
	ohist();
	cin >> cn1 >> cn2;
	cn = cn1 + " " + cn2;
};

void authorization::SinInCheck()
{
	fstream f;
	string inf;
	VvodAut();
	f.open(Author_FILE_NAME);
	while (getline(f, inf)) {
		size_t spacePos = inf.find(' ');
		string LoginF = inf.substr(0, spacePos);
		if (LoginF == cn1) {
			an = 1;return;
		}
	}
	f.close();
	f.open(Author_FILE_NAME, ios::out | ios::app);
	f << cn <<"/"<< endl;
	an = 2;
	f.close();
	
};

void authorization::LogInCheck()
{
	fstream f;
	int x = 0;
	string inf;
	VvodAut();
	f.open(Author_FILE_NAME);
	while (getline(f, inf)) {
		size_t spacePos = inf.find('/');
		string Logpas = inf.substr(0, spacePos);
		if (cn == Logpas) {
			if (inf.find("*") != string::npos) {
				x = 2;break;
			}
			else {
				x = 1;break;
			}
			
			
		};
	}
	switch (x) {
	case 0: { an = 4; break; }
	case 1: { an = 3; break; }
	case 2: { an = 5; break; }
	}
	
	f.close();
};

void authorization::sisans()
{
	switch (an) {
	case 1: {
		cout << "Такой логин уже существует, зайди или используй другой логин"<<endl;
		break;
	}
	case 2: {
		cout << "Ты зарегестировался, поздравляю"<<endl;
		IsReg = false;
		break;
	}
	case 3: {
		cout << "Ты успешно зашел"<<endl;
		IsReg = false;
		break;
	}
	case 4: {
		cout << "Неверный логин или пароль"<<endl;
		break;
	}
	case 5: {
		cout << "Ты успешно зашел в качестве администратора" << endl;
		IsReg = false;
		IsAdmin = 1;
		break;
	}
	case 0: {
		cout << "";
	}
	}
};

void authorization::ohist()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
};