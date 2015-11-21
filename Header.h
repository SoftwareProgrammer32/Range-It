#pragma once

#include <iostream>
#include <string>
#include <random>
#include <time.h>

using namespace std;

class Text {
private:
	string g1 = "The number is lower. \n";																//1
	string g2 = "The number is higher. \n";																//2
	
	string w1 = "Welcome to 'Range It!' \n";															//3
	string w2 = "I'm going to pick a random number [1-100]. \n";										//4
	string w3 = "The object of the game is to guess the number I have chosen. \n";						//5
	string w4 = "The number ot tries it takes to guess the number will be displayed at the end. \n";	//6

	string q1 = "Thank you for playing! \n";															//7

	string c1 = "That is the correct number, you win! \n";												//8

	string t1 = "The number of tries so far: \n";														//9

	string a1 = "Play again? Y(1)/N(2)? \n";															//10
	
	string w5 = "Press '1' to begin or '2' to quit. \n";												//11

	string a2 = "Enter a number to guess. \n";															//12

	string creator = "Game engine created by: Jonathon Bailey \n \n";									//13

	string e1 = "Hit 'enter' after inputting a number. \n";												//14

	string i1 = "Any non-number input will quit the program. \n";										//15

public:
	const void say_Text(int t);

};

class Number {
private:
	const int MINNUM = 0;							//Minimum number value 
	const int MAXNUM = 100;							//Maximum number value

public:
	const int inline minnum_Ret() { return MINNUM; }

	const int inline maxnum_Ret() { return MAXNUM; }

};

class Random : public Number {
private:
	int random_Num = rand() % 100;
public:
	const int inline random_Num_Ret() { return random_Num; }

	const void seed();

	const void change_Rand_Num1();

	const void change_Rand_Num2();
};

class Counter {
private:
	int num_Tries{ 0 };

public:
	int passes{ 0 };

	const void inline increment_Tries() { ++num_Tries; }

	const void output_Tries();

	const void inline reset_Tries() { num_Tries = 0; }

	const void inline increment_Passes() { ++passes; }
};

class Input {
private:
	int input{ 0 };
public:
	const void get_Input();

};

class Menu {
private:
	int menu_C{ 0 };
public:
	const int menu();

	const void menu_Blurb();

};
