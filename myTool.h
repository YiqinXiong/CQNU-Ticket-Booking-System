#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include "client.h"
#include "concert.h"
using namespace std;
class myTool
{
private:
	vector<concert> L;
	string Name;            /*�����û���¼������*/
	concert* find_concert(string s);
	concert* find_concert_by_num(string num);
	void put_concert();		/*����޸ĺ���ݳ�����Ϣ*/
public:
	myTool();
	string get_login_name() {
		return this->Name;
	}
	int login();
	void search();
	void refund();		/*��Ʊ����*/
	void booking();		/*��Ʊ����*/
	void print_concert();
	void re_price();	/*�޸�ĳ�ݳ���Ʊ�ۣ�����Ա������*/
	int form1();
	int form2();
	void client_list();


};

