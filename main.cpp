#include "myTool.h"

int main()
{
	myTool tool;
	do
	{
		int f = 1;
		switch (tool.login())
		{
		case 1:/*�û�����*/
			system("pause");
			system("cls");
			do
			{
				switch (tool.form1())
				{
				case 1:/*���ò�ѯ����*/
					system("cls");
					tool.search();
					system("pause");
					system("cls");
					break;
				case 2:/*��Ʊ*/
					system("cls");
					tool.booking();
					system("pause");
					system("cls");
					break;
				case 3:/*��Ʊ*/
					system("cls");
					tool.refund();
					system("pause");
					system("cls");
					break;
				case 0:/*�˳���¼��������һ��*/
					f = 0;
					system("cls");
				}
			} while (f);
			break;
		case 2:/*����Ա����*/
			system("pause");
			system("cls");
			do
			{
				switch (tool.form2())
				{
				case 1:/*�鿴�����ݳ�����Ϣ*/
					system("cls");
					tool.print_concert();
					system("pause");
					system("cls");
					break;
				case 2:/*�鿴�˿�����*/
					system("cls");
					tool.client_list();
					system("pause");
					system("cls");
					break;
				case 3:/*�޸�Ʊ��*/
					system("cls");
					tool.re_price();
					system("pause");
					system("cls");
					break;
				case 0:/*�˳���¼��������һ��*/
					f = 0;
					system("cls");
				}
			} while (f);
		}

	} while (1);
}