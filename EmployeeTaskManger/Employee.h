#pragma once
#include<string>
#include<iostream>
using namespace std; 
class Employee
{
private:
	string name;
	int id;
public:
	char password[20] = {};
	Employee(string membername, char passwword[20], int memberid);
	string getName();
	/*int getPassword()*/;
	int getID();
};

