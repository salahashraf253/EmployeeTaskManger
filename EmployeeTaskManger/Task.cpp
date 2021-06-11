#include "Task.h"

Task::Task(string title, string desc, string assigndaate, string enddatee, string name, int piror, int id)
{
	taskTitle = title;
	description = desc;
	assigningDate = assigndaate;
	endDate = enddatee;
	employeeName = name;
	pirority = piror;
	employeeID = id;
}

Task::Task()
{
}

void Task::readData(string title, string desc, string assigndaate, string enddatee, string name, int piror, int id)
{
	taskTitle = title;
	description = desc;
	assigningDate = assigndaate;
	endDate = enddatee;
	employeeName = name;
	pirority = piror;
	employeeID = id;
}

void Task::setPirority(int pirort)
{
	pirority = pirort;
}

string Task::getTitle()
{
	return taskTitle;
}

string Task::getDesc()
{
	return description;
}

string Task::getAssignDate()
{
	return assigningDate;
}

string Task::getEndDate()
{
	return endDate;
}

string Task::getName()
{
	return employeeName;
}

int Task::getPirority()
{
	return pirority;
}

int Task::getId()
{
	return employeeID;
}

void Task::setTitle(string title)
{
	taskTitle = title;
}

void Task::setDesc(string desc)
{
	description = desc;
}

void Task::setAssignDate(string assigndate)
{
	assigningDate = assigndate;
}

void Task::setEndDate(string enddaate)
{
	endDate = enddaate;
}

void Task::setName(string name)
{
	employeeName = name;
}

void Task::setId(int id)
{
	employeeID = id;
}
