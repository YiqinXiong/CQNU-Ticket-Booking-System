#include "client.h"

// ��ȡ����
string client::get_name()
{
	return this->name;
}

// д�붩Ʊ��
void client::set_ordering_number(int n) {
	this->ordering_number = n;
}

// ��ȡ��Ʊ��
int client::get_ordering_number() {
	return this->ordering_number;
}

// д����Ʊ�ȼ�
void client::set_grade(int n) {
	this->grade = n;
}

// ��ȡ��Ʊ�ȼ�
int client::get_grade() {
	return this->grade;
}