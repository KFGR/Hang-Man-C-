#include "Game.h"
Game::Game()
{
	setRandomWord("");
	setPalabraUsuario("");
	setlives(8);
}

void Game::setRandomWord(string RandomWord)
{
	this->RandomWord=RandomWord;
}

void Game::setPalabraUsuario(string UserWord)
{
	this->UserWord=UserWord;
}

void Game::setlives(int lives)
{
	this->lives=lives;
}

string Game::getRandomWord()	const
{
	return this->RandomWord;
}

string Game::getPalabraUsuario()	const
{
	return this->UserWord;
}

int Game::getlives()	const
{
	return this->lives;
}
void Game::instrucciones()
{
	cout<<"Welcome to HangMan, this game has only one rule\n"
		<<"1. The user only have 8 lives, if you don't guess the \n"
		<<"word in 8 attempts you loose.\n"
		<<"**Be aware that this is a prototype of the game **\n\n";
}
void Game::creandoarchivo()
{
	//se crea el archivo de las palabras para el juego
	archivo.open("Palabras.txt");
	
	//condicional para que salga del programa
	if(archivo.fail())
	{
		cout<<"No se pudo crear el archivo...";
	}
	
	//escribiendo las palabras al archivo (10 en total)
	//Las palabras por el momento van hacer de animales
	archivo<<"owl\n";
	archivo<<"dog\n";
	archivo<<"cat\n";
	archivo<<"fly\n";
	archivo<<"fox\n";
	archivo<<"pig\n";
	archivo<<"ape\n";
	archivo<<"ant\n";
	archivo<<"bee\n";
	archivo<<"bat\n";
	
	archivo.close();
	
	
}

void Game::random()
{
	//abriendo el archivo para buscar la palabra random
	archivo.open("Palabras.txt");
	
	int indexFile;			//lineas del file
	string lista[10];		//lista de todas las palabras
	int index;				//index de la lista
	int numero=1;			//numero de palabras a copiar
	string l;
	
	unsigned seed = time(0);
	
	//copiar todas las palabras a la variable lista[index]
	while(!archivo.eof()) //end of file
	{
		getline(archivo,lista[index]);
		index++;
	}
	
	//solo una palabra se pasara a la variable RandomWord ( privada )
	for(int i=0;i<numero;i++)	
	{
		srand(seed);
		indexFile = rand() % 10;	//1 de 10 lineas se guardara en indexFile
		RandomWord = lista[indexFile];
	}
	

}



void Game::validateUser()
{
	cout<<"Entre una letra: ";
	cin>>UserWord;
	
	if(!isalpha(UserWord[0]))	
		cout<<"Solo se pueden usar letras..."<<endl;
	
		else
			tolower(UserWord[0]);
		
}


void Game::compare()
{
	

	string word="---";
	
	random();
	instrucciones();
	cout<<"please enter to begin the game...";
	
	//getch() para la pantalla hasta que el usuario entre una tecla
	//system("cls") borra la pantalla inicial
	getch();
	system("cls");
	
	
	while(lives>0 && word!=RandomWord)
	{
		system("cls");
		
		cout<<word<<endl;
		cout<<"You have "<<lives<<" lives.\n";
		validateUser();
		
		cout<<endl<<endl;
		
		int Found = RandomWord.find(UserWord);
		
		if(Found!=string::npos)						//si la palabra no existe sigue escribiendo una letra
		{
			for(int i=0;i<RandomWord.length();i++)	//loop para buscar las que se parecen
			{
				if(UserWord[0]==RandomWord[i])
				{
					 word[i]=UserWord[0];	//las lineas seran las letras del usuario si el proximo if se cumple
					 
					 if(UserWord==RandomWord)
					 	word = UserWord;	//si el usuario pone la palabra correcta las lineas se completan
					 
				}
			}
				
		}
	
		else
		{
			lives-=1;
		}
			
	}
	
	if(word == RandomWord)
		cout<<"The word is: "<<RandomWord<<"\n"
			<<"Congratulations!!, you have win the game...\n";
			
	else
		cout<<"\n\nYou have lost the game, the word was: "<<RandomWord<<"\n\n";
	
	setlives(8);	
}


void Game::display()
{
	compare();
	
	archivo.close();
}

Game::~Game()
{
	
}
