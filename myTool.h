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
	string Name;            /*用于用户登录的姓名*/
	concert* find_concert(string s);
	concert* find_concert_by_num(string num);
	void put_concert();		/*输出修改后的演唱会信息*/
public:
	myTool();
	string get_login_name() {
		return this->Name;
	}
	int login();
	void search();
	void refund();		/*退票操作*/
	void booking();		/*订票操作*/
	void print_concert();
	void re_price();	/*修改某演唱会票价（管理员操作）*/
	int form1();
	int form2();
	void client_list();


};

