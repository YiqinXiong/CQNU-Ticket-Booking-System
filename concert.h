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
{ /*演唱会信息*/
private:
	string con_name;			/*演唱会名*/
	string con_num;				/*演唱会编号*/
	string singer_name;			/*歌手名*/
	string day;					/*演出日期（星期几）*/
	int people_quota;			/*演出定额*/
	double price;				/*票价*/
	int more_ticket;			/*余票量*/
	string client_list;			/*购票名单*/
	string waiting_list;		/*等候替补的顾客名单*/
	list<client> clist;			/*购票顾客list*/
	list<client> wlist;			/*等候替补的顾客list*/
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
