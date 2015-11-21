#include "Header.h"

Text t;
Random r;
Counter c;
Menu m;
Input in;
Number n;

//Text
const void Text::say_Text(int t) {
	switch (t) {
	case 1:
		cout << g1;					//Number is lower
		break;
	case 2:
		cout << g2;					//Number is higher
		break;
	case 3:
		cout << w1;					//Welcome
		break;
	case 4:
		cout << w2;					//I'm going to pick a number
		break;
	case 5:
		cout << w3;					//Object of the game
		break;
	case 6:
		cout << w4;					//Number of tries is recorded and will be displayed
		break;
	case 7:
		cout << q1;					//Thank you for playing!
		break;
	case 8:
		cout << c1;					//Correct input, you win!
		break;
	case 9:
		cout << t1;					//The number of tries so far:
		break;
	case 10: 
		cout << a1;					//play again?
		break;
	case 11:
		cout << w5;					//press 1 to begih or 2 to quit
		break;
	case 12: 
		cout << a2;					//enter a number to guess
		break;	
	case 13:
		cout << creator;			//Copyright
		break;
	case 14:
		cout << e1;					//Hit enter after input
		break;
	case 15:
		cout << i1;					//Any non-character input will terminate the program
		break;
	default:
		break;
	}
}

//Random
const void Random::seed() {
	srand(time(0));
}

const void Random::change_Rand_Num1() {
	random_Num = rand() % 50;
}

const void Random::change_Rand_Num2() {
	random_Num = rand() % 75;
}

//Counter
const void Counter::output_Tries() {
	cout << num_Tries << "\n";
}

//Input
const void Input::get_Input() {
	t.say_Text(12);

	while (cin >> in.input) {
		if (in.input > n.maxnum_Ret()) {
			t.say_Text(1);					//the number is lower, max domain
			c.increment_Tries();			//increment tries
			in.get_Input();					//loop input function
		}
		else if (in.input < n.minnum_Ret()) {	
			t.say_Text(2);					//the number is higher, min domain
			c.increment_Tries();			//increment tries
			in.get_Input();					//loop input function
		}
		else if (in.input > r.random_Num_Ret()) {
			t.say_Text(1);					//the number is lower, not the random number, need lower answer
			c.increment_Tries();			//increment tries
			in.get_Input();					//loop input function
		}
		else if (in.input < r.random_Num_Ret()) {
			t.say_Text(2);					//the number is higher, not the random number, need higher answer
			c.increment_Tries();			//increment tries
			in.get_Input();					//loop input function
		}
		else if (in.input = r.random_Num_Ret()) {
			t.say_Text(8);					//that is the correct input, you win
			c.increment_Tries();			//increment tries
			t.say_Text(9);					//the number of tries so far
			c.output_Tries();				//output tries
			c.increment_Passes();			//increment number of times played the game

			t.say_Text(10);					//Play again?

			if (c.passes = 1) {
				r.change_Rand_Num1();		//random number [1-50]
			}
			else if (c.passes >= 2) {		//random number [1-75]
				r.change_Rand_Num2();
			}
			m.menu();						//return to menu options to start again 
		}
	}
}

//Menu
const int Menu::menu() {
	r.seed();								//seed srand(time(0))
	while (cin >> menu_C) {
		switch (menu_C) {
		case 1:
			c.reset_Tries();				//reset tries
			in.get_Input();
			break;
		case 2:
			t.say_Text(7);					//thank you for playing 
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}

const void Menu::menu_Blurb() {
	t.say_Text(13);				//copyright

	t.say_Text(3);				//Welcome
	t.say_Text(4);				//I'm going to pick a random number
	t.say_Text(5);				//Object of the game
	t.say_Text(6);				//The number of tries will be displayed at the end
	t.say_Text(14);				//Hit enter after inputting a number
	t.say_Text(15);				//Any non-number input will end the program
	t.say_Text(11);				//Press '1' to begin or '2' to quit
}

