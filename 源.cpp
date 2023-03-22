#include<iostream>
using namespace std;
#include<string>
#define max 2000

//设计个人结构体
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;

};
//设计通讯录结构体
struct AddressBooks
{
	struct Person PersonArry [max];

	//通讯录当前人个数

	int m_size;


};


//设计菜单
void showMenu()
{
	cout << "********************" << endl;
	cout << "****1.添加联系人****" << endl;
	cout << "****2.显示联系人****" << endl; 
	cout << "****3.删除联系人****" << endl;
	cout << "****4.查找联系人****" << endl;
	cout << "****5.修改联系人****" << endl;
	cout << "****6.清空联系人****" << endl;
	cout << "*******0.退出*******" << endl;
	cout << "********************" << endl;
}
//设计添加联系人函数
void addPerson(AddressBooks* abs)//只有地址传递才可以修饰形参，大多数时候使用都是地址传递
{
	if (abs->m_size == max)
	{
		cout << "通讯录人员已满,无法添加" << endl;
		return ;

	}
	else
	{
		//添加具体联系人

		//联系人姓名
		cout << "请输入联系人的姓名： " << endl;
		string name;
		cin >> name;
		abs->PersonArry[abs->m_size].m_Name = name;

		//联系人性别
		
		cout << "请输入联系人的性别： " << endl;
		cout << "   1.男     " << endl;
		cout << "   2.女     " << endl;

		int sex = 0;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				abs->PersonArry[abs->m_size].m_Sex = sex;
				break;
			}
		}
		
		
		//联系人年龄
		cout << "请输入联系人的年龄： " << endl;
		int age=0;
		cin >> age;
		abs->PersonArry[abs->m_size].m_Age = age;

		//联系人电话
		cout << "请输入联系人的电话： " << endl;
		string phone;
		cin >> phone;
		abs->PersonArry[abs->m_size].m_Phone = phone;

		//联系人家庭住址
		cout << "请输入联系人家庭住址： " << endl;
		string address;
		cin >> address;
		abs->PersonArry[abs->m_size].m_Addr = address;

		//更新联系人的数量
		abs->m_size++;
		cout << "联系人已经添加成功 " << endl;
		system("pause");
		system("cls");
	}
}
//显示通讯录的联系人名单
void showPerson(AddressBooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "通讯录中未添加联系人" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名 ：" << abs->PersonArry[i].m_Name << "\t";
			cout << "性别 ：" << (abs->PersonArry[i].m_Sex?"男":"女") << "\t";//三目算法
			cout << "年龄 ：" << abs->PersonArry[i].m_Age << "\t";
			cout << "电话号码 ：" << abs->PersonArry[i].m_Phone << "\t";
			cout << "家庭住址 ：" << abs->PersonArry[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//删除联系人
//检测要删除的联系人是否存在
int isExist(AddressBooks* abs,string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->PersonArry[i].m_Name == name)
		{
			return i;
		}
		else
		{
			
			return -1;
		}
	}
}

//设计删除联系人的程序
void delectPerson(AddressBooks* abs)
{
	cout << "请输入要删除的联系人： " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//-1为isexist返回的i
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->PersonArry[i] = abs->PersonArry[i + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;//进行for循环操作，运用isexist的函数进行遍历操作观察对比
	}
	else
	{
		cout << "未查到此人" << endl;
	}
	system("pause");
	system("cls");

}
//设计查找联系人的函数
void findPerson(AddressBooks* abs)
{
	string name;
	cin >> name;
	int ret = isExist(abs, name);//不需要在isexist函数中进行引用操作
	if (ret != -1)
	{
		cout << "姓名： " << abs->PersonArry[ret].m_Name << "\t";
		cout << "性别 ：" << (abs->PersonArry[ret].m_Sex ? "男" : "女") << "\t";
		//三目算法：（abs->PersonArry[ret].m_Sex?"男"：“女”）
		cout << "年龄 ：" << abs->PersonArry[ret].m_Age << "\t";
		cout << "电话号码 ：" << abs->PersonArry[ret].m_Phone << "\t";
		cout << "家庭住址 ：" << abs->PersonArry[ret].m_Addr << endl;
	}
	else
	{
		cout << "未查到此人" << endl;
	}
	system("pause");
	system("cls");
}
//设计修改联系人函数
void modifyPerson(AddressBooks* abs)
{
	cout << "请输入需要修改的联系人： " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->PersonArry[ret].m_Name = name;

		//性别

		cout << "请输入联系人的性别： " << endl;
		cout << "   1.男     " << endl;
		cout << "   2.女     " << endl;

		int sex = 0;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				abs->PersonArry[ret].m_Sex = sex;
				break;
			}
		}

		//年龄
		cout << "请输入联系人的年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->PersonArry[ret].m_Age = age;
		//电话号码
		cout << "请输入联系人的电话： " << endl;
		string phone;
		cin >> phone;
		abs->PersonArry[abs->m_size].m_Phone = phone;
		//家庭住址
		cout << "请输入联系人家庭住址： " << endl;
		string address;
		cin >> address;
		abs->PersonArry[ret].m_Addr = address;

	}
	else
	{
		cout << "未查到此人" << endl;
	}
	system("pause");
	system("cls");
}
//设计清理通讯录的联系人
void cleanPerson(AddressBooks* abs)
{
	cout << "请您确认需要清空通讯录： " << endl;
	cout << "1.确认删除" << endl;
	cout << "2.取消删除" << endl;
	int i = 0;
	cin >> i;
	if (i ==1)
	{
		abs->m_size = 0;
		cout << "该通讯录已经清空" << endl;
	}
	else if (i == 2)
	{
		cout << "已取消清空通讯录" << endl;
		exit(1);
	}
	
	system("pause");
	system("cls");
}

int main()
{
	AddressBooks abs;
	abs.m_size = 0;

	int select = 0;

	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:

			addPerson(&abs);//添加联系人
			break;
		case 2:
			showPerson(&abs);//显示通讯录联系人
			break;
		case 3:
		{
			cout << "请先查找需要删除的联系人姓名： " << endl;
			string name;
			cin >> name;

			if (isExist(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
			}//检测要删除的联系人是否存在于该通讯录中
			else
			{
				/*cout << "找到此人" << endl;*/
			}
			delectPerson(&abs);//删除联系人，通过进行数据迁移方式进行删除
		}
			break;
		case 4:
			findPerson(&abs);//查找联系人，运用上面写好的isexist函数
			break;
		case 5:
			modifyPerson(&abs);//修改联系人，对需要修改的进行重新输入和赋值；
			break;
		case 6:
			cleanPerson(&abs);//清空联系人，对于需要清空的通讯录系统进行清空
			break;
		case 0:
			cout << "欢迎下次使用通讯录系统" << endl;
			system("pause");
			exit(1);
			break;
		}
	}
	system("pause");
	return 0;
}