// EmployeeTaskManger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include"Task.h"
#include"Employee.h"

using namespace std;
////////////////////////Global Variables///////////////////////////////////////
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
class comparator
{
public:
	bool operator()(const Task& a, const Task& b)
	{

		return a.pirority < b.pirority;
	}
};
ifstream TasksFile("Tasks.txt");
ifstream EmloyeesFile("Employees.txt");
//const int fileLines=7;
const int EMPLOYEESNUMBER = 6;
vector<Task> tasksArrayList;
vector<Employee> EmployeesArrayList;
priority_queue<Task, vector<Task>, comparator>  queueCopy(priority_queue<Task, vector<Task>, comparator> temp);
///////xxxxxxxxxxxxxxxxxxx///////Global Variables/////////////xxxxxxxxxxxxxxxx///////////
/////////////////////Functions///////////////////////
void readingTasks();
void readingEmployees();
void Login();
void TaskDisplay(int id);

///////////xxxxxxxxxxxxxxxxx//////////Functions////////////xxxxxxxxxxxxxxxxxx///////////
int main()
{
	readingTasks();
	readingEmployees();
	Login();
}
//Login Validation Function
void Login() {
	SetConsoleTextAttribute(h, 18);
	cout << "\t\t\t\tWelcome To Employee Task Manager System " << endl;

	SetConsoleTextAttribute(h, 1);
	cout << " Please Enter ID To Login: " << endl;
	int id;
	SetConsoleTextAttribute(h, 14);
	cin >> id;
	while (id <= 0 || id > EMPLOYEESNUMBER)
	{
		SetConsoleTextAttribute(h, 1);
		cout << "Please enter valid id:" << endl;
		SetConsoleTextAttribute(h, 14);
		cin >> id;
	}

	//while (id<=0 || id> EMPLOYEESNUMBER)
	//{
	//	cout << "Please enter valid id:" << endl;
	//	cin >> id;
	//}
	SetConsoleTextAttribute(h, 128);
	cout << "Welcome " << EmployeesArrayList.at(id - 1).getName() << endl;

	SetConsoleTextAttribute(h, 1);
	cout<< " Please Enter Your Password : " << endl;
	char password[20] = {}, p;
	SetConsoleTextAttribute(h, 14);
	for (int i = 0; i < 20; i++)
	{
		p = _getch();
		if (p!=13)
		{
			password[i] = p;
			cout << "*";
		}
		else break;
	}
	char T_Pass[20] = {};
	for (int i = 0; i < 20; i++)
	{
		T_Pass[i] = EmployeesArrayList.at(id - 1).password[i];
	}
	while (strcmp( password, T_Pass) != 0)
	{
		SetConsoleTextAttribute(h, 4);
		cout << "\nWrongd Password " << endl;

		SetConsoleTextAttribute(h, 6);
		for (int i = 0; i < 20; i++)
		{
			p = _getch();
			if (p!=13)
			{
				password[i] = p;
				cout << "*";
			}
			else
			{
				break;
			}
		}

	}
	SetConsoleTextAttribute(h, 11);
	cout << "\nSuccessful login" << endl;
	TaskDisplay(id);
}
///putting in a new arraylist the tasks of logged in employees
//then sorting it using priority queue 
//asking user to enter priority for his tasks
///displayin his tasks based on priority
void TaskDisplay(int id) {
	vector<Task> EmployeetasksArrayList;
	for (int i = 0;i < tasksArrayList.size();i++) {
		if (id == tasksArrayList.at(i).getId()) {
			EmployeetasksArrayList.push_back(tasksArrayList.at(i));
		}
	}
	for (int i = 0;i < EmployeetasksArrayList.size();i++) {
		SetConsoleTextAttribute(h, 1);
		cout << "Please Enter Priority for : " << endl;
		cout<< EmployeetasksArrayList.at(i).getTitle() << " Task : ";
		
		int pr;
		SetConsoleTextAttribute(h, 14);
		cin >> pr;
		EmployeetasksArrayList.at(i).setPirority(pr);
	}
	priority_queue<Task, vector<Task>, comparator> tasksPriorityQueue;
	for (int i = 0;i < EmployeetasksArrayList.size();i++) {
		tasksPriorityQueue.push(EmployeetasksArrayList.at(i));
	}
	SetConsoleTextAttribute(h, 9);
	cout << "Welcome This Is Your Tasks List : "  << endl;
	priority_queue<Task, vector<Task>, comparator> temp = queueCopy(tasksPriorityQueue);
	while (!temp.empty()) {
		cout << "Title : " << temp.top().taskTitle << endl;
		cout << "Description : " << temp.top().description << endl;
		cout << "AssignDate : " << temp.top().assigningDate << endl;
		cout << "EndDATE : " << temp.top().endDate << endl;
		cout << "Task Priority : " << temp.top().pirority << endl;
		temp.pop();
	}
	SetConsoleTextAttribute(h, 1);
	cout << "Please Enter 1 IF You Want To Edit A Task : ";

	int edit = 1;

	SetConsoleTextAttribute(h, 14);
	cin >> edit;
	while (edit == 1) {
		int number; 
		SetConsoleTextAttribute(h, 1);
		cout << "Please Enter Number Of Task You Want To Edit : ";

		SetConsoleTextAttribute(h, 14);
		cin >> number;
		if (number <= EmployeetasksArrayList.size()&&number!=0) {
			SetConsoleTextAttribute(h, 1);
			cout << "New Task Title : ";

			SetConsoleTextAttribute(h, 14);
			cin>> EmployeetasksArrayList.at(number - 1).taskTitle;

			SetConsoleTextAttribute(h, 1);
			cout << "New Task Description : ";

			SetConsoleTextAttribute(h, 14);
			cin>>EmployeetasksArrayList.at(number - 1).description;
			
			SetConsoleTextAttribute(h, 1);
			cout << "New Task AssignDate : ";

			SetConsoleTextAttribute(h, 14);
			cin >> EmployeetasksArrayList.at(number - 1).assigningDate;
			
			SetConsoleTextAttribute(h, 1);
			cout << "New Task EndDATE : ";

			SetConsoleTextAttribute(h, 14);
			cin >> EmployeetasksArrayList.at(number - 1).endDate;

			SetConsoleTextAttribute(h, 1);
			cout << "New Task  Priority : ";

			SetConsoleTextAttribute(h, 14);
			cin >> EmployeetasksArrayList.at(number - 1).pirority;

			priority_queue<Task, vector<Task>, comparator> tasksEditedPriorityQueue;
			for (int i = 0;i < EmployeetasksArrayList.size();i++) {
				tasksEditedPriorityQueue.push(EmployeetasksArrayList.at(i));
			}
			SetConsoleTextAttribute(h, 5);
			cout << " This Is Your  Edited Tasks List : " << endl;
			priority_queue<Task, vector<Task>, comparator> temp2 = queueCopy(tasksEditedPriorityQueue);
			while (!temp2.empty()) {
				SetConsoleTextAttribute(h, 13);
				cout << "Title : " << temp2.top().taskTitle << endl;
				cout << "Description : " << temp2.top().description << endl;
				cout << "AssignDate : " << temp2.top().assigningDate << endl;
				cout << "EndDATE : " << temp2.top().endDate << endl;
				cout << "Task Priority : " << temp2.top().pirority << endl;
				temp2.pop();
			}
		}
		else {
			SetConsoleTextAttribute(h, 1);
			cout << "Enter Valid Task Number : " << endl;
			SetConsoleTextAttribute(h, 14);
		}
		SetConsoleTextAttribute(h, 1);
		cout << "Please Enter 1 IF You Want To Edit Another Task : ";

		SetConsoleTextAttribute(h, 14);
		cin >> edit;

	}
	priority_queue<Task, vector<Task>, comparator> tasksEditedPriorityQueue;
	for (int i = 0;i < EmployeetasksArrayList.size();i++) {
		tasksEditedPriorityQueue.push(EmployeetasksArrayList.at(i));
	}
	int accomplish = 1;
	SetConsoleTextAttribute(h, 1);
	cout << "Please Enter 1 If You Want To Submit Task Accomplish : ";
	
	SetConsoleTextAttribute(h, 14);
	cin >> accomplish;
	while (accomplish == 1)
	{

		if (tasksEditedPriorityQueue.size() == 1) {

			SetConsoleTextAttribute(h, 4);
			cout << endl << "ALL TASKS ARE DONE YOUR ARE VERY AMAZING " << endl;
			
			SetConsoleTextAttribute(h, 128);
			cout<< EmployeesArrayList.at(id - 1).getName() << " KEEP UP THE GOOD WORK ";
			break;
		}
		else {
			tasksEditedPriorityQueue.pop();
			SetConsoleTextAttribute(h, 3);
			cout << "Your Next Task Is  : " << endl;
			cout << "Title : " << tasksEditedPriorityQueue.top().taskTitle << endl;
			cout << "Description : " << tasksEditedPriorityQueue.top().description << endl;
			cout << "AssignDate : " << tasksEditedPriorityQueue.top().assigningDate << endl;
			cout << "EndDATE : " << tasksEditedPriorityQueue.top().endDate << endl;
			cout << "Task Priority : " << tasksEditedPriorityQueue.top().pirority << endl;
		}
		SetConsoleTextAttribute(h, 1);
		cout << "Please Enter 1 If You Want To Submit Task Accomplish : ";

		SetConsoleTextAttribute(h, 14);
		cin >> accomplish;

	}
	SetConsoleTextAttribute(h, 4);
	cout << "\nThank You GoodBye\n ";
	system("pause");

}

/// Function read tasks from file and saving it in array list
void readingTasks() {
	while (TasksFile) {
		string taskTitle;
		string description;
		string assigningDate;
		string endDate;
		string employeeName;
		int pirority;
		int employeeID;
		getline(TasksFile, taskTitle);
		string tem;
		getline(TasksFile, description);
		getline(TasksFile, assigningDate);
		getline(TasksFile, endDate);
		getline(TasksFile, employeeName);
		TasksFile >> pirority >> employeeID;
		getline(TasksFile, tem);
		tasksArrayList.push_back(Task(taskTitle, description, assigningDate, endDate, employeeName, pirority, employeeID));
		
	}
}
// Function saving arraylist in priority queue
/*
void savingPriorityQueue() {
	for (int i = 0;i < fileLines;i++) {
		tasksPriorityQueue.push(tasksArrayList.at(i));
	}
}*/
/// Function read Employees from file and saving it in array list
void readingEmployees() {
	while (EmloyeesFile) {
		string name;
		char password[20];
		int id;
		string temp;
		getline(EmloyeesFile, name);
		EmloyeesFile>>password ;
		
		EmloyeesFile >> id;
		getline(EmloyeesFile, temp);
		EmployeesArrayList.push_back(Employee(name, password, id));
		///Display Test
		//cout << name << " " << password << " " << id << endl;
	}
}
//Function Copy Queue into another 
priority_queue<Task, vector<Task>, comparator>  queueCopy(priority_queue<Task, vector<Task>, comparator> temp) {
	priority_queue<Task, vector<Task>, comparator> newqueue;
	while (!temp.empty()) {
		newqueue.push(temp.top());
		temp.pop();
	}
	return newqueue;
	
}




