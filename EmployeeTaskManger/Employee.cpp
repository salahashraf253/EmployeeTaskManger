#include "Employee.h"

Employee::Employee(string membername, char passwword[20], int memberid)
{
	name = membername;
	id = memberid;
	for (int i = 0; i < 20; i++)
	{
		password[i] = passwword[i];
	}

}

string Employee::getName()
{
	return name;
}

//int Employee::getPassword()
//{
//	return password;
//}

int Employee::getID()
{
	return id;
}
