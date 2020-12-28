#include "myTool.h"

int myTool::login() {
	int f;
	string password;
	string p = "666666";       /*管理员密码*/
	cout << "*************************登录*****************************\n\n";
	cout << "           1.用户登录         2.管理员登录\n  请选择用户身份：";
	fflush(stdin);   /*刷新输入流缓冲区*/
	do {
		cin >> f;
		if (f == 1)
		{
			cout << "  姓名：";
			cin >> Name;
			cout << "\n\t\t登录成功！！\n\n**********************************************************\n\n";
			return 1;
		}
		else if (f == 2)
		{
			cout << "\n  输入管理员密码(提示6个6)：";
			fflush(stdin);
			do {
				cin >> password;
				if (password == p)
				{
					cout << "\n\t\t登录成功！！\n\n**********************************************************\n\n";
					return 2;
				}
				else cout << "\n密码错误！！ 请重新输入\n\n  输入管理员密码：";
			} while (1);
		}
		else cout << "输入错误！！ 请重新输入\n  请选择用户身份： ";
	} while (1);
}

concert* myTool::find_concert(string s) {
	vector<concert>::iterator it;
	for (it = L.begin(); it != L.end(); it++) {
		if (it->get_name() == s) {
			return &(*it);
		}
	}
	return nullptr;
}

concert* myTool::find_concert_by_num(string num) {
	vector<concert>::iterator it;
	for (it = L.begin(); it != L.end(); it++) {
		if (it->get_num() == num) {
			return &(*it);
		}
	}
	return nullptr;
}

/*输出修改后的演唱会信息*/
void myTool::put_concert()
{
	fstream f;
	f.open("演唱会信息.txt", ios::out);

	for (vector<concert>::iterator it = L.begin(); it != L.end(); it++)
		f << it->get_name() << " " << it->get_num() << " "
		<< it->get_singer() << " " << it->get_day() << " "
		<< it->get_people_quota() << " " << it->get_price() << " "
		<< it->get_more_ticket() << " " << it->get_client_list() << " "
		<< it->get_waiting_list() << '\n';
	f.close();
}

/*读取文件中的演唱会信息*/
myTool::myTool() {
	string name, num, singer, day, client_list, waiting_list;
	int quota, more_ticket;
	double price;

	fstream f;
	f.open("演唱会信息.txt", ios::in);

	L.clear();
	while (f >> name >> num >> singer >> day >> quota >> price >> more_ticket >> client_list >> waiting_list) {
		L.push_back(concert(name, num, singer, day, quota, price, more_ticket, client_list, waiting_list));
	}
	f.close();
}

/*查询操作*/
void myTool::search() {
	string s;
	cout << "*************************查询*****************************\n\n\t\t演唱会名:";
	cin >> s;
	concert* target = find_concert(s);
	if (!target)
		cout << "\n无此演唱会信息!\n\n";
	else
		target->print();
	cout << "**********************************************************\n\n";
}

/*退票操作*/
void myTool::refund()
{
	string s;
	cout << "*************************退票*****************************\n\n\t\t演唱会编号:";
	cin >> s;
	concert* target = find_concert_by_num(s);
	if (!target) {
		cout << "\n无此演唱会信息!\n\n";
	}
	else {
		target->refund(Name);
	}
	cout << "\n 退票完成！\n";
	cout << "**********************************************************\n\n";
	put_concert();
}

/*订票操作*/
void myTool::booking() {
	string s;
	cout << "*************************订票*****************************\n\n\t\t演唱会编号:";
	cin >> s;
	concert* target = find_concert_by_num(s);
	if (!target) {
		cout << "\n无此演唱会信息!\n\n";
	}
	else {
		target->booking(Name);
	}
	cout << "\n 订票完成！\n";
	cout << "\n**********************************************************\n\n";
	put_concert();
}

/*打印所有演唱会信息（管理员操作）*/
void myTool::print_concert() {
	cout << "*************************演唱会信息*************************\n\n";
	for (vector<concert>::iterator it = L.begin(); it != L.end(); it++)
		it->print();
	cout << "\n**********************************************************\n\n";
}

/*修改某演唱会票价（管理员操作）*/
void myTool::re_price() {
	int i = 0;
	double p;
	string s;
	cout << "*************************修改票价*************************\n\n\t\t演唱会编号:";
	cin >> s;
	concert* target = find_concert_by_num(s);
	if (!target) {
		cout << "\n无此演唱会信息!\n\n";
	}
	else {
		cout << "  演唱会名：" << target->get_name() << "\t  演唱会编号:" << target->get_num()
			<< "\n\n\t    原票价：" << target->get_price() << "\n\t    新票价：";
		cin >> p;
		target->set_price(p);
		cout << "\n   修改票价完成\n";
	}
	put_concert();
	cout << "\n**********************************************************\n\n";
}

int myTool::form1()
{/*乘客用户界面*/
	int s;
	cout << "*************************用户界面*************************\n\n";
	cout << "   1.查询演唱会\t   2.订票\t  3.退票     0.退出登录\n\n\t\t选择操作：";
	fflush(stdin);
	do {
		cin >> s;
		if (s >= 0 && s <= 3) break;
		cout << "\t输入错误！！ \n\t请重新选择操作：";
	} while (1);
	cout << "\n**********************************************************\n\n";
	return s;
}

int myTool::form2()
{/*管理员界面*/
	int s;
	cout << "***********************管理员界面*************************\n\n";
	cout << "   1.演唱会信息\t   2.顾客名单\t  3.修改票价     0.退出登录\n\n\t\t选择操作：";
	fflush(stdin);
	do {
		cin >> s;
		if (s >= 0 && s <= 3) break;
		cout << "\t输入错误！！ \n\t请重新选择操作：";
	} while (1);
	cout << "\n**********************************************************\n\n";
	return s;
}

void myTool::client_list()
{/*查看某演唱会顾客名单（管理员操作）*/
	string s;
	cout << "*************************顾客名单*************************\n\n\t\t演唱会编号:";
	cin >> s;
	concert* target = find_concert_by_num(s);
	if (!target) {
		cout << "\n无此演唱会信息!\n\n";
	}
	else {
		target->show_client_list();
	}
	cout << "\n**********************************************************\n\n";

}