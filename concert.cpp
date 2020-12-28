#include "concert.h"


client* concert::find_client(string s) {
	list<client>::iterator it;
	for (it = clist.begin(); it != clist.end(); it++) {
		if (it->get_name() == s) {
			return &(*it);
		}
	}
	return nullptr;
}

concert::concert(string name, string num, string singer, string day, int quota, double price, int more_ticket, string client_list, string waiting_list) {
	this->con_name = name;
	this->con_num = num;
	this->singer_name = singer;
	this->day = day;
	this->people_quota = quota;
	this->price = price;
	this->more_ticket = more_ticket;
	this->client_list = client_list;
	this->waiting_list = waiting_list;
	/*读取某演唱会顾客信息*/
	string name1;
	int orderNum1, grade1;

	fstream f;
	f.open(this->client_list, ios::in);

	this->clist.clear();
	while (f >> name1 >> orderNum1 >> grade1)
	{
		this->clist.push_back(client(name1, orderNum1, grade1));
	}
	f.close();

	/*读取某演唱会等候替补名单*/
	f.open(this->waiting_list, ios::in);

	this->wlist.clear();
	while (f >> name1 >> orderNum1 >> grade1)
	{
		this->wlist.push_back(client(name1, orderNum1, grade1));
	}
	f.close();
}

/*打印演唱会信息*/
void concert::print()
{
	cout << "  演唱会名：" << con_name << "  \t 演唱会编号:" << con_num << "\t    歌手名:" << singer_name
		<< "\n  时间:" << day << "\t\t  演出定额:" << people_quota << "\n  票价:" << price << "\t\t 余票量:" << more_ticket << "\n\n";
}

/*查看某演唱会顾客名单（管理员操作）*/
void concert::show_client_list() {
	string name, g;
	int orderNum, grade;

	fstream f;
	f.open(this->client_list, ios::in);
	cout << "\n  已购票顾客名单：\n";
	while (f >> name >> orderNum >> grade)
	{
		switch (grade)
		{
		case 1:
			g = "特级座";
			break;
		case 2:
			g = "高级座";
			break;
		case 3:
			g = "普通座";
		}
		cout << "\t姓名：" << name << "\t座位等级：" << g << "\t购票数：" << orderNum << endl;
	}
	f.close();

	f.open(this->waiting_list, ios::in);
	cout << "\n  候补订票顾客名单：\n";
	while (f >> name >> orderNum >> grade)
	{
		switch (grade)
		{
		case 1:
			g = "特级座";
			break;
		case 2:
			g = "高级座";
			break;
		case 3:
			g = "普通座";
		}
		cout << "\t姓名：" << name << "\t座位等级：" << g << "\t预订票数：" << orderNum << endl;
	}
	f.close();
}

/*退票*/
void concert::refund(string Name) {
	int n;
	/*姓名查找*/
	client* target = find_client(Name);
	if (!target) {
		cout << "\n退票错误！！ 您没有在此演唱会订票\n";
	}
	else {
		cout << "您在" << con_num << "演唱会：" << con_name << ")订了"
			<< target->get_ordering_number() << "张票\n请输入退票数量：";
		do
		{/*输入退票数*/
			cin >> n;
			if (n > 0 && n <= target->get_ordering_number())
				break;
			else
				cout << "\n输入错误！！请重新输入：";
		} while (1);
		if (n == target->get_ordering_number())
			wlist.remove(*target);	/*全部退票*/
		else if (n < target->get_ordering_number())
			target->set_ordering_number(target->get_ordering_number() - n);  /*退部分票*/

		this->more_ticket += n;   /*余票增加*/
		list<client>::iterator it;
		for (it = wlist.begin(); it != wlist.end(); it++) {
			/*找到需求票数满足的*/
			if (this->more_ticket >= it->get_ordering_number()) {
				this->more_ticket -= it->get_ordering_number();
				clist.push_back(*it);
			}
		}
		put_client();
		put_wait();
	}
}

/*订票*/
void concert::booking(string Name)
{/*订票操作*/
	this->print();
	int g, n;
	cout << " 门票等级（1：特级座，2：高级座，3：普通座）：";
	cin >> g;
	cout << " 购买票数：";
	do
	{/*合理输入购买票数*/
		cin >> n;
		if (n <= this->people_quota)
			break;
		else
			cout << "错误！！不能超过定额（" << this->people_quota << "）,重新输入：";
	} while (1);

	if (this->more_ticket)
	{/*有余票*/
		if (n <= this->more_ticket)
		{/*余票足够*/
			this->clist.push_back(client(Name, n, g));
			this->more_ticket -= n;
			cout << "\n 购票完成！\n";
		}
		else if (n > this->more_ticket)
		{/*余票小于购买数*/
			int x;

			/*询问用户*/
			cout << "\n\n（1：只买" << this->more_ticket << "张  2：买" << this->more_ticket << "张，"
				<< n - this->more_ticket << "张等候  3：不买)\n 余票不足" << n << "张，是否继续购买？:";
			cin >> x;
			switch (x)
			{
			case 1:
				this->clist.push_back(client(Name, this->more_ticket, g));
				this->more_ticket = 0;
				cout << "\n 购票完成！\n";
				break;
			case 2:

				this->clist.push_back(client(Name, this->more_ticket, g));
				this->wlist.push_back(client(Name, n - this->more_ticket, g));
				this->more_ticket = 0;
				cout << "\n 购票完成！\n";
				break;
			}
		}
	}
	else
	{/*无余票*/
		int y;
		cout << "\n 无余票！ 是否排队等候票？（1：是 0：否）";
		cin >> y;
		if (y)
		{/*进入等候名单*/
			this->wlist.push_back(client(Name, n, g));
		}
	}
	put_client();    /*刷新用户名单*/
	put_wait();
}

/*输出顾客信息到文件*/
void concert::put_client() {
	fstream f;
	f.open(this->client_list, ios::out | ios::trunc);
	for (list<client>::iterator it = clist.begin(); it != clist.end(); it++) {
		f << it->get_name() << " " << it->get_ordering_number() << " " << it->get_grade() << '\n';
	}
	f.close();
}

/*输出等候替补名单*/
void concert::put_wait() {
	fstream f;
	f.open(this->waiting_list, ios::out | ios::trunc);
	for (list<client>::iterator it = wlist.begin(); it != wlist.end(); it++) {
		f << it->get_name() << " " << it->get_ordering_number() << " " << it->get_grade() << '\n';
	}
	f.close();
}
