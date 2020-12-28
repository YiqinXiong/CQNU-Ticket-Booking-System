#include "client.h"

// 获取姓名
string client::get_name()
{
	return this->name;
}

// 写入订票量
void client::set_ordering_number(int n) {
	this->ordering_number = n;
}

// 获取订票量
int client::get_ordering_number() {
	return this->ordering_number;
}

// 写入门票等级
void client::set_grade(int n) {
	this->grade = n;
}

// 获取门票等级
int client::get_grade() {
	return this->grade;
}