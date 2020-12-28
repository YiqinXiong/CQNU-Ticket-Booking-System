#include "myTool.h"

int myTool::login() {
	int f;
	string password;
	string p = "666666";       /*����Ա����*/
	cout << "*************************��¼*****************************\n\n";
	cout << "           1.�û���¼         2.����Ա��¼\n  ��ѡ���û���ݣ�";
	fflush(stdin);   /*ˢ��������������*/
	do {
		cin >> f;
		if (f == 1)
		{
			cout << "  ������";
			cin >> Name;
			cout << "\n\t\t��¼�ɹ�����\n\n**********************************************************\n\n";
			return 1;
		}
		else if (f == 2)
		{
			cout << "\n  �������Ա����(��ʾ6��6)��";
			fflush(stdin);
			do {
				cin >> password;
				if (password == p)
				{
					cout << "\n\t\t��¼�ɹ�����\n\n**********************************************************\n\n";
					return 2;
				}
				else cout << "\n������󣡣� ����������\n\n  �������Ա���룺";
			} while (1);
		}
		else cout << "������󣡣� ����������\n  ��ѡ���û���ݣ� ";
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

/*����޸ĺ���ݳ�����Ϣ*/
void myTool::put_concert()
{
	fstream f;
	f.open("�ݳ�����Ϣ.txt", ios::out);

	for (vector<concert>::iterator it = L.begin(); it != L.end(); it++)
		f << it->get_name() << " " << it->get_num() << " "
		<< it->get_singer() << " " << it->get_day() << " "
		<< it->get_people_quota() << " " << it->get_price() << " "
		<< it->get_more_ticket() << " " << it->get_client_list() << " "
		<< it->get_waiting_list() << '\n';
	f.close();
}

/*��ȡ�ļ��е��ݳ�����Ϣ*/
myTool::myTool() {
	string name, num, singer, day, client_list, waiting_list;
	int quota, more_ticket;
	double price;

	fstream f;
	f.open("�ݳ�����Ϣ.txt", ios::in);

	L.clear();
	while (f >> name >> num >> singer >> day >> quota >> price >> more_ticket >> client_list >> waiting_list) {
		L.push_back(concert(name, num, singer, day, quota, price, more_ticket, client_list, waiting_list));
	}
	f.close();
}

/*��ѯ����*/
void myTool::search() {
	string s;
	cout << "*************************��ѯ*****************************\n\n\t\t�ݳ�����:";
	cin >> s;
	concert* target = find_concert(s);
	if (!target)
		cout << "\n�޴��ݳ�����Ϣ!\n\n";
	else
		target->print();
	cout << "**********************************************************\n\n";
}

/*��Ʊ����*/
void myTool::refund()
{
	string s;
	cout << "*************************��Ʊ*****************************\n\n\t\t�ݳ�����:";
	cin >> s;
	concert* target = find_concert_by_num(s);
	if (!target) {
		cout << "\n�޴��ݳ�����Ϣ!\n\n";
	}
	else {
		target->refund(Name);
	}
	cout << "\n ��Ʊ��ɣ�\n";
	cout << "**********************************************************\n\n";
	put_concert();
}

/*��Ʊ����*/
void myTool::booking() {
	string s;
	cout << "*************************��Ʊ*****************************\n\n\t\t�ݳ�����:";
	cin >> s;
	concert* target = find_concert_by_num(s);
	if (!target) {
		cout << "\n�޴��ݳ�����Ϣ!\n\n";
	}
	else {
		target->booking(Name);
	}
	cout << "\n ��Ʊ��ɣ�\n";
	cout << "\n**********************************************************\n\n";
	put_concert();
}

/*��ӡ�����ݳ�����Ϣ������Ա������*/
void myTool::print_concert() {
	cout << "*************************�ݳ�����Ϣ*************************\n\n";
	for (vector<concert>::iterator it = L.begin(); it != L.end(); it++)
		it->print();
	cout << "\n**********************************************************\n\n";
}

/*�޸�ĳ�ݳ���Ʊ�ۣ�����Ա������*/
void myTool::re_price() {
	int i = 0;
	double p;
	string s;
	cout << "*************************�޸�Ʊ��*************************\n\n\t\t�ݳ�����:";
	cin >> s;
	concert* target = find_concert_by_num(s);
	if (!target) {
		cout << "\n�޴��ݳ�����Ϣ!\n\n";
	}
	else {
		cout << "  �ݳ�������" << target->get_name() << "\t  �ݳ�����:" << target->get_num()
			<< "\n\n\t    ԭƱ�ۣ�" << target->get_price() << "\n\t    ��Ʊ�ۣ�";
		cin >> p;
		target->set_price(p);
		cout << "\n   �޸�Ʊ�����\n";
	}
	put_concert();
	cout << "\n**********************************************************\n\n";
}

int myTool::form1()
{/*�˿��û�����*/
	int s;
	cout << "*************************�û�����*************************\n\n";
	cout << "   1.��ѯ�ݳ���\t   2.��Ʊ\t  3.��Ʊ     0.�˳���¼\n\n\t\tѡ�������";
	fflush(stdin);
	do {
		cin >> s;
		if (s >= 0 && s <= 3) break;
		cout << "\t������󣡣� \n\t������ѡ�������";
	} while (1);
	cout << "\n**********************************************************\n\n";
	return s;
}

int myTool::form2()
{/*����Ա����*/
	int s;
	cout << "***********************����Ա����*************************\n\n";
	cout << "   1.�ݳ�����Ϣ\t   2.�˿�����\t  3.�޸�Ʊ��     0.�˳���¼\n\n\t\tѡ�������";
	fflush(stdin);
	do {
		cin >> s;
		if (s >= 0 && s <= 3) break;
		cout << "\t������󣡣� \n\t������ѡ�������";
	} while (1);
	cout << "\n**********************************************************\n\n";
	return s;
}

void myTool::client_list()
{/*�鿴ĳ�ݳ���˿�����������Ա������*/
	string s;
	cout << "*************************�˿�����*************************\n\n\t\t�ݳ�����:";
	cin >> s;
	concert* target = find_concert_by_num(s);
	if (!target) {
		cout << "\n�޴��ݳ�����Ϣ!\n\n";
	}
	else {
		target->show_client_list();
	}
	cout << "\n**********************************************************\n\n";

}