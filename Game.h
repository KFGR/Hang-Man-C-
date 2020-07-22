#include <iostream>
#include <string>
#include<cstring>
#include<cctype>
#include <fstream>
#include<cstdlib>
#include<ctime>
#include<conio.h>

using namespace std;
#pragma once

class Game
{
private:
		fstream archivo;				//Lista de palabras
		string RandomWord;				//palabra al azar
		int lives;						//vidas del usuario
	
		string UserWord;			//palabra que entra el usuario
		
		
public:
	Game();								//default constructor
	~Game();							//destructor
	
	void setRandomWord(string);			//Inicializa la variable RandomWord	
	void setPalabraUsuario(string);		//Inicializa la variable Palabra_usuario
	void setlives(int);					//inicializa las vidas
	
	string getRandomWord() const;		//retorna la palabra random
	string getPalabraUsuario() const; 	//retorna la palabra del usuario
	int getlives()	const;				//retorna la variable vida
	
	
	
	void instrucciones();				//muestra las instrucciones del juego
	void creandoarchivo();				//crea el archivo de 10 palabras
	void random();						//busca una palabra random	
		
	void validateUser();				//pide y valida la palabra o letra del usuario
	int subtractlives();				//Le quita vidas al usuario
	void compare();						//compara la letra con las palabras
	void display();
	
		
		
			
};

/*

1.Crear el file con 10 palabras, en este caso de animales...
a.owl		f.pig
b.dog		g.ape
c.cat		h.ant
d.fly		i.bee
e.fox		j.bat
**	Cada letra es un indice el cual se va a guardar en una variable 
**	llamada indexFile y se pondra como un arreglo arreglo[indexFile]???


2.Hacer una función para escojer una palabra random...
	opciones:
		A. incluir <cstdlib> y <ctime> 
		B. funciones randoms de <fstream>, seekg o seekp


3. hacer una función para pedir al usuario la letra a entrar,
	si el usuario adivina la palabra el programa debe de dar el aviso
	de que esta correcta la palabra.
	Hacer una funcion para que cuante la cantidad de vidas que le quedan (8-vida)  [for loop]?
*/
