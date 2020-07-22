#include <iostream>
using namespace std;
#include "Game.h"

void replay(Game &Person, char &again)
{
	Person.creandoarchivo();
	Person.display();

	cout<<"\nDo you like to play hangman again? (Y / N)";
	cin>>again;

	if(again!='y'||again!='Y')
	cout<<"\n\nThanks for using our game!!...";
}
int main() 
{
	Game Person;
	char again;
	
	do
		replay(Person,again);	
	while(again=='y'||again=='Y');
	
	return 0;
}

/*
.find y string::npos
https://www.geeksforgeeks.org/string-find-in-cpp/

algoritmo de como comparar cada letra o la palabra por string
https://repl.it/@zaynahshaikh/C-Hangman

Kelvin Figueroa 
Jonathan Camacho

9/17/2019
*/
