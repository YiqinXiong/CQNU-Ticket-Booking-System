#include "myTool.h"

int main()
{
	myTool tool;
	do
	{
		int f = 1;
		switch (tool.login())
		{
		case 1:/*用户界面*/
			system("pause");
			system("cls");
			do
			{
				switch (tool.form1())
				{
				case 1:/*调用查询函数*/
					system("cls");
					tool.search();
					system("pause");
					system("cls");
					break;
				case 2:/*订票*/
					system("cls");
					tool.booking();
					system("pause");
					system("cls");
					break;
				case 3:/*退票*/
					system("cls");
					tool.refund();
					system("pause");
					system("cls");
					break;
				case 0:/*退出登录，返回上一层*/
					f = 0;
					system("cls");
				}
			} while (f);
			break;
		case 2:/*管理员界面*/
			system("pause");
			system("cls");
			do
			{
				switch (tool.form2())
				{
				case 1:/*查看所有演唱会信息*/
					system("cls");
					tool.print_concert();
					system("pause");
					system("cls");
					break;
				case 2:/*查看顾客名单*/
					system("cls");
					tool.client_list();
					system("pause");
					system("cls");
					break;
				case 3:/*修改票价*/
					system("cls");
					tool.re_price();
					system("pause");
					system("cls");
					break;
				case 0:/*退出登录，返回上一层*/
					f = 0;
					system("cls");
				}
			} while (f);
		}

	} while (1);
}