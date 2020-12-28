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
	/*��ȡĳ�ݳ���˿���Ϣ*/
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

	/*��ȡĳ�ݳ���Ⱥ��油����*/
	f.open(this->waiting_list, ios::in);

	this->wlist.clear();
	while (f >> name1 >> orderNum1 >> grade1)
	{
		this->wlist.push_back(client(name1, orderNum1, grade1));
	}
	f.close();
}

/*��ӡ�ݳ�����Ϣ*/
void concert::print()
{
	cout << "  �ݳ�������" << con_name << "  \t �ݳ�����:" << con_num << "\t    ������:" << singer_name
		<< "\n  ʱ��:" << day << "\t\t  �ݳ�����:" << people_quota << "\n  Ʊ��:" << price << "\t\t ��Ʊ��:" << more_ticket << "\n\n";
}

/*�鿴ĳ�ݳ���˿�����������Ա������*/
void concert::show_client_list() {
	string name, g;
	int orderNum, grade;

	fstream f;
	f.open(this->client_list, ios::in);
	cout << "\n  �ѹ�Ʊ�˿�������\n";
	while (f >> name >> orderNum >> grade)
	{
		switch (grade)
		{
		case 1:
			g = "�ؼ���";
			break;
		case 2:
			g = "�߼���";
			break;
		case 3:
			g = "��ͨ��";
		}
		cout << "\t������" << name << "\t��λ�ȼ���" << g << "\t��Ʊ����" << orderNum << endl;
	}
	f.close();

	f.open(this->waiting_list, ios::in);
	cout << "\n  �򲹶�Ʊ�˿�������\n";
	while (f >> name >> orderNum >> grade)
	{
		switch (grade)
		{
		case 1:
			g = "�ؼ���";
			break;
		case 2:
			g = "�߼���";
			break;
		case 3:
			g = "��ͨ��";
		}
		cout << "\t������" << name << "\t��λ�ȼ���" << g << "\tԤ��Ʊ����" << orderNum << endl;
	}
	f.close();
}

/*��Ʊ*/
void concert::refund(string Name) {
	int n;
	/*��������*/
	client* target = find_client(Name);
	if (!target) {
		cout << "\n��Ʊ���󣡣� ��û���ڴ��ݳ��ᶩƱ\n";
	}
	else {
		cout << "����" << con_num << "�ݳ��᣺" << con_name << ")����"
			<< target->get_ordering_number() << "��Ʊ\n��������Ʊ������";
		do
		{/*������Ʊ��*/
			cin >> n;
			if (n > 0 && n <= target->get_ordering_number())
				break;
			else
				cout << "\n������󣡣����������룺";
		} while (1);
		if (n == target->get_ordering_number())
			wlist.remove(*target);	/*ȫ����Ʊ*/
		else if (n < target->get_ordering_number())
			target->set_ordering_number(target->get_ordering_number() - n);  /*�˲���Ʊ*/

		this->more_ticket += n;   /*��Ʊ����*/
		list<client>::iterator it;
		for (it = wlist.begin(); it != wlist.end(); it++) {
			/*�ҵ�����Ʊ�������*/
			if (this->more_ticket >= it->get_ordering_number()) {
				this->more_ticket -= it->get_ordering_number();
				clist.push_back(*it);
			}
		}
		put_client();
		put_wait();
	}
}

/*��Ʊ*/
void concert::booking(string Name)
{/*��Ʊ����*/
	this->print();
	int g, n;
	cout << " ��Ʊ�ȼ���1���ؼ�����2���߼�����3����ͨ������";
	cin >> g;
	cout << " ����Ʊ����";
	do
	{/*�������빺��Ʊ��*/
		cin >> n;
		if (n <= this->people_quota)
			break;
		else
			cout << "���󣡣����ܳ������" << this->people_quota << "��,�������룺";
	} while (1);

	if (this->more_ticket)
	{/*����Ʊ*/
		if (n <= this->more_ticket)
		{/*��Ʊ�㹻*/
			this->clist.push_back(client(Name, n, g));
			this->more_ticket -= n;
			cout << "\n ��Ʊ��ɣ�\n";
		}
		else if (n > this->more_ticket)
		{/*��ƱС�ڹ�����*/
			int x;

			/*ѯ���û�*/
			cout << "\n\n��1��ֻ��" << this->more_ticket << "��  2����" << this->more_ticket << "�ţ�"
				<< n - this->more_ticket << "�ŵȺ�  3������)\n ��Ʊ����" << n << "�ţ��Ƿ��������:";
			cin >> x;
			switch (x)
			{
			case 1:
				this->clist.push_back(client(Name, this->more_ticket, g));
				this->more_ticket = 0;
				cout << "\n ��Ʊ��ɣ�\n";
				break;
			case 2:

				this->clist.push_back(client(Name, this->more_ticket, g));
				this->wlist.push_back(client(Name, n - this->more_ticket, g));
				this->more_ticket = 0;
				cout << "\n ��Ʊ��ɣ�\n";
				break;
			}
		}
	}
	else
	{/*����Ʊ*/
		int y;
		cout << "\n ����Ʊ�� �Ƿ��ŶӵȺ�Ʊ����1���� 0����";
		cin >> y;
		if (y)
		{/*����Ⱥ�����*/
			this->wlist.push_back(client(Name, n, g));
		}
	}
	put_client();    /*ˢ���û�����*/
	put_wait();
}

/*����˿���Ϣ���ļ�*/
void concert::put_client() {
	fstream f;
	f.open(this->client_list, ios::out | ios::trunc);
	for (list<client>::iterator it = clist.begin(); it != clist.end(); it++) {
		f << it->get_name() << " " << it->get_ordering_number() << " " << it->get_grade() << '\n';
	}
	f.close();
}

/*����Ⱥ��油����*/
void concert::put_wait() {
	fstream f;
	f.open(this->waiting_list, ios::out | ios::trunc);
	for (list<client>::iterator it = wlist.begin(); it != wlist.end(); it++) {
		f << it->get_name() << " " << it->get_ordering_number() << " " << it->get_grade() << '\n';
	}
	f.close();
}
