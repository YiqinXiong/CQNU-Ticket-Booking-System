#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <list>
using namespace std;

class client
{
private:
	string name;          /*姓名*/
	int ordering_number;    /*订票量*/
	int grade;             /*门票等级*/
	friend bool operator== (const client& t1, const client& t2) {
		return (t1.name == t2.name) && (t1.ordering_number == t2.ordering_number) && (t1.grade == t2.grade);
	}
public:
	client(string name, int orderNum, int grade) :name(name), ordering_number(orderNum), grade(grade) {}
	string get_name();
	void set_ordering_number(int n);
	int get_ordering_number();
	void set_grade(int n);
	int get_grade();
};

