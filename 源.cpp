#include<iostream>
using namespace std;
#include<string>
#define max 2000

//��Ƹ��˽ṹ��
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;

};
//���ͨѶ¼�ṹ��
struct AddressBooks
{
	struct Person PersonArry [max];

	//ͨѶ¼��ǰ�˸���

	int m_size;


};


//��Ʋ˵�
void showMenu()
{
	cout << "********************" << endl;
	cout << "****1.�����ϵ��****" << endl;
	cout << "****2.��ʾ��ϵ��****" << endl; 
	cout << "****3.ɾ����ϵ��****" << endl;
	cout << "****4.������ϵ��****" << endl;
	cout << "****5.�޸���ϵ��****" << endl;
	cout << "****6.�����ϵ��****" << endl;
	cout << "*******0.�˳�*******" << endl;
	cout << "********************" << endl;
}
//��������ϵ�˺���
void addPerson(AddressBooks* abs)//ֻ�е�ַ���ݲſ��������βΣ������ʱ��ʹ�ö��ǵ�ַ����
{
	if (abs->m_size == max)
	{
		cout << "ͨѶ¼��Ա����,�޷����" << endl;
		return ;

	}
	else
	{
		//��Ӿ�����ϵ��

		//��ϵ������
		cout << "��������ϵ�˵������� " << endl;
		string name;
		cin >> name;
		abs->PersonArry[abs->m_size].m_Name = name;

		//��ϵ���Ա�
		
		cout << "��������ϵ�˵��Ա� " << endl;
		cout << "   1.��     " << endl;
		cout << "   2.Ů     " << endl;

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
		
		
		//��ϵ������
		cout << "��������ϵ�˵����䣺 " << endl;
		int age=0;
		cin >> age;
		abs->PersonArry[abs->m_size].m_Age = age;

		//��ϵ�˵绰
		cout << "��������ϵ�˵ĵ绰�� " << endl;
		string phone;
		cin >> phone;
		abs->PersonArry[abs->m_size].m_Phone = phone;

		//��ϵ�˼�ͥסַ
		cout << "��������ϵ�˼�ͥסַ�� " << endl;
		string address;
		cin >> address;
		abs->PersonArry[abs->m_size].m_Addr = address;

		//������ϵ�˵�����
		abs->m_size++;
		cout << "��ϵ���Ѿ���ӳɹ� " << endl;
		system("pause");
		system("cls");
	}
}
//��ʾͨѶ¼����ϵ������
void showPerson(AddressBooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "ͨѶ¼��δ�����ϵ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "���� ��" << abs->PersonArry[i].m_Name << "\t";
			cout << "�Ա� ��" << (abs->PersonArry[i].m_Sex?"��":"Ů") << "\t";//��Ŀ�㷨
			cout << "���� ��" << abs->PersonArry[i].m_Age << "\t";
			cout << "�绰���� ��" << abs->PersonArry[i].m_Phone << "\t";
			cout << "��ͥסַ ��" << abs->PersonArry[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//ɾ����ϵ��
//���Ҫɾ������ϵ���Ƿ����
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

//���ɾ����ϵ�˵ĳ���
void delectPerson(AddressBooks* abs)
{
	cout << "������Ҫɾ������ϵ�ˣ� " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//-1Ϊisexist���ص�i
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->PersonArry[i] = abs->PersonArry[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ�" << endl;//����forѭ������������isexist�ĺ������б��������۲�Ա�
	}
	else
	{
		cout << "δ�鵽����" << endl;
	}
	system("pause");
	system("cls");

}
//��Ʋ�����ϵ�˵ĺ���
void findPerson(AddressBooks* abs)
{
	string name;
	cin >> name;
	int ret = isExist(abs, name);//����Ҫ��isexist�����н������ò���
	if (ret != -1)
	{
		cout << "������ " << abs->PersonArry[ret].m_Name << "\t";
		cout << "�Ա� ��" << (abs->PersonArry[ret].m_Sex ? "��" : "Ů") << "\t";
		//��Ŀ�㷨����abs->PersonArry[ret].m_Sex?"��"����Ů����
		cout << "���� ��" << abs->PersonArry[ret].m_Age << "\t";
		cout << "�绰���� ��" << abs->PersonArry[ret].m_Phone << "\t";
		cout << "��ͥסַ ��" << abs->PersonArry[ret].m_Addr << endl;
	}
	else
	{
		cout << "δ�鵽����" << endl;
	}
	system("pause");
	system("cls");
}
//����޸���ϵ�˺���
void modifyPerson(AddressBooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ� " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != -1)
	{
		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->PersonArry[ret].m_Name = name;

		//�Ա�

		cout << "��������ϵ�˵��Ա� " << endl;
		cout << "   1.��     " << endl;
		cout << "   2.Ů     " << endl;

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

		//����
		cout << "��������ϵ�˵����䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->PersonArry[ret].m_Age = age;
		//�绰����
		cout << "��������ϵ�˵ĵ绰�� " << endl;
		string phone;
		cin >> phone;
		abs->PersonArry[abs->m_size].m_Phone = phone;
		//��ͥסַ
		cout << "��������ϵ�˼�ͥסַ�� " << endl;
		string address;
		cin >> address;
		abs->PersonArry[ret].m_Addr = address;

	}
	else
	{
		cout << "δ�鵽����" << endl;
	}
	system("pause");
	system("cls");
}
//�������ͨѶ¼����ϵ��
void cleanPerson(AddressBooks* abs)
{
	cout << "����ȷ����Ҫ���ͨѶ¼�� " << endl;
	cout << "1.ȷ��ɾ��" << endl;
	cout << "2.ȡ��ɾ��" << endl;
	int i = 0;
	cin >> i;
	if (i ==1)
	{
		abs->m_size = 0;
		cout << "��ͨѶ¼�Ѿ����" << endl;
	}
	else if (i == 2)
	{
		cout << "��ȡ�����ͨѶ¼" << endl;
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

			addPerson(&abs);//�����ϵ��
			break;
		case 2:
			showPerson(&abs);//��ʾͨѶ¼��ϵ��
			break;
		case 3:
		{
			cout << "���Ȳ�����Ҫɾ������ϵ�������� " << endl;
			string name;
			cin >> name;

			if (isExist(&abs, name) == -1)
			{
				cout << "���޴���" << endl;
			}//���Ҫɾ������ϵ���Ƿ�����ڸ�ͨѶ¼��
			else
			{
				/*cout << "�ҵ�����" << endl;*/
			}
			delectPerson(&abs);//ɾ����ϵ�ˣ�ͨ����������Ǩ�Ʒ�ʽ����ɾ��
		}
			break;
		case 4:
			findPerson(&abs);//������ϵ�ˣ���������д�õ�isexist����
			break;
		case 5:
			modifyPerson(&abs);//�޸���ϵ�ˣ�����Ҫ�޸ĵĽ�����������͸�ֵ��
			break;
		case 6:
			cleanPerson(&abs);//�����ϵ�ˣ�������Ҫ��յ�ͨѶ¼ϵͳ�������
			break;
		case 0:
			cout << "��ӭ�´�ʹ��ͨѶ¼ϵͳ" << endl;
			system("pause");
			exit(1);
			break;
		}
	}
	system("pause");
	return 0;
}