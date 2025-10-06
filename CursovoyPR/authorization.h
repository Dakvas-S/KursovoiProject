#pragma once
#include <string>
using namespace std;
class authorization
{
	string cn1="", cn2="", cn="";
	int an = 0;
	
public:
	bool CK = true; int m = 0;

	void couttextA(int b);//вывести текст для разных целей
	int vibauth();// выбор пункта меню

	void sinin();// регистрация
		
	void SinInCheck();//проверка данных пользователя для регистрации

	void getin();// вход
		
	void LogInCheck();//проверка данных пользователя для входа

	void VvodAut(); // Ввод данных пользователя

	void sisans();//ответ системы

	void ohist();// очистка ввода
	
};

