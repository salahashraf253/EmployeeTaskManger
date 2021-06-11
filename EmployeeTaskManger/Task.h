#pragma once
#include<iostream>
#include<string>
using namespace std;
class Task
{
private: 
	
public:
	int pirority;
	string taskTitle;
	string description;
	string assigningDate;
	string endDate;
	string employeeName;
	int employeeID;
	Task(string title, string desc, string assigndaate, string enddatee,string name , int piror ,int id );
	Task();
	void readData(string title, string desc, string assigndaate, string enddatee, string name, int piror, int id);
	string getTitle();
	string getDesc();
	string getAssignDate();
	string getEndDate();
	string getName();
	int getPirority();
	int getId();
	void setTitle(string title);
	void setDesc(string desc);
	void setAssignDate(string assdate);
	void setEndDate(string enddaate);
	void setName(string name);
	void setPirority(int pirort);
	void setId(int id);

	


};

