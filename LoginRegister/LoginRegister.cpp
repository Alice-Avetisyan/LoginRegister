// LoginRegister.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream> //has the capabilities of both ofstream and ifstream: can create files, write information to files, and read information from files
#include <string>
using namespace std;

bool isLoggedIn(); //prototype of the function 


void main()
{
	//Intro to the program
	cout << "--------------------------------------------------" << endl;
	cout << "Welcome to the C++ program!" << endl;
	cout << "The program is a simple \'Login and Register\' console application" << endl;
	cout << "This program utilizes the fstream class." << endl;
	cout << "--------------------------------------------------" << endl;

	//choice setup
	int choice;
	cout << "Please choose your next action." << endl;

	cout << "1: Register" << endl << "2: Login\nYour choice: " << endl;
	cin >> choice;

	//choosing between
	if (choice == 1) //1: Register
	{
		string username, password;

		cout << "\nWrite your Username: ";
		cin >> username;

		cout<< "Write your Password: ";
		cin >> password;

		//used to create files and to write information to files
		ofstream file;
		file.open("logReg_" + username + ".txt");//opening the "file"
		file << username << endl << password;//writing username and password data
		file.close();//closing the file    

		main();
	}
	else if (choice == 2)//2: Login
	{
		bool status = isLoggedIn();//calling the function

		if (!status)
		{
			cout << "False login!" << endl;//if the input (username and password) data does not corresponed to the data in "logReg.text" file
			system("PAUSE");
		}
		else
		{
			cout << "Succesfully logged in!" << endl;//if the input (username and password) data does corresponed to the data in "logReg.text" file
			system("PAUSE");
		}
	}

	cout << "--------------------------------------------------" << endl;

}//main

//choice: Login
//This function is called when the user already has data and wishes to Login
bool isLoggedIn()
{
	string username, password, un, pw;//un and pw will be used to compare the inputted data

	cout << "Enter your username: ";
	cin >> username;
	cout << "Enter your password: ";
	cin >> password;

	//used to read information from files
	ifstream read("logReg_" + username + ".txt");
	//read - tells the function about the stream from where to read the input from
	//un/pw - is a string object, the input is stored in this object after being read from the stream
	getline(read, un); 
	getline(read, pw); 

	if (un == username && pw == password)//comparing
	{
		return true;
	}
	else 
	{
		return false;
	}
}//isLoggedIn

