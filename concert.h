#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include "client.h"
using namespace std;

class concert
{ /*�ݳ�����Ϣ*/
private:
	string con_name;			/*�ݳ�����*/
	string con_num;				/*�ݳ�����*/
	string singer_name;			/*������*/
	string day;					/*�ݳ����ڣ����ڼ���*/
	int people_quota;			/*�ݳ�����*/
	double price;				/*Ʊ��*/
	int more_ticket;			/*��Ʊ��*/
	string client_list;			/*��Ʊ����*/
	string waiting_list;		/*�Ⱥ��油�Ĺ˿�����*/
	list<client> clist;			/*��Ʊ�˿�list*/
	list<client> wlist;			/*�Ⱥ��油�Ĺ˿�list*/
	client* find_client(string s);
	//static int number;
public:
	concert(string name, string num, string singer, string day, int quota, double price, int more_ticket, string client_list, string waiting_list);
	string get_name() {
		return this->con_name;
	}
	string get_num() {
		return this->con_num;
	}
	string get_singer() {
		return this->singer_name;
	}
	string get_day() {
		return this->day;
	}
	int get_people_quota() {
		return this->people_quota;
	}
	double get_price() {
		return this->price;
	}
	void set_price(double p) {
		this->price = p;
	}
	int get_more_ticket() {
		return this->more_ticket;
	}
	string get_client_list() {
		return this->client_list;
	}
	string get_waiting_list() {
		return this->waiting_list;
	}
	void print();
	void show_client_list();
	void booking(string Name);
	void refund(string Name);
	void put_client();
	void put_wait();
};
