#include <iostream>
#include <string>
#include "StudentClass.hpp"
#include "caculate.h"
#include "school.h"
#include "link.h"
//student Class_One[5];//ȫ�ֶ������飬����ʱ�Զ�����������������Զ��ͷ�
void add_student(student *);
void show_student(student *);
void test_son_class(void)//���̳����������
{
	school_class yiban("ʯ��ׯѧԺ","����","��������ϵ",20);

	//yiban.set_class_info("��ƽ����","����","��������ϵ",50);
	school &a=yiban;
	a.get_info();
	school *p=new school_class;//����һ��ָ�����ָ�룬������Ϊ����
	p->get_info();
	delete p;
	//school_class *b=&yiban;
	//b->get_info();
	//school &c=yiban;
	//c.get_info();
	//std::cout << b->school::get_info()<<std::endl;//����ʹ�ó�Ա���޶��������������ȡ����̬����
	//yiban.get_info();
}
/*void heap_test(void)//�ڶ��д����������
{
	student *p=new student;
	std::cout << "Creat a heap area." << std::endl;
	p -> Set_Info("wu");
	p -> Set_Info(1);
	p -> Set_Info(100);
	p -> Show_Info();
	delete p;
}
void test_copy_struct(void)//���غ͸��ƹ��캯������
{
	student wiwi;
	wiwi.Set_Info("hello");
	wiwi.Set_Info(34);
	wiwi.Set_Info((float)100.0);
	student lili(wiwi);
	wiwi.Show_Info();
	lili.Show_Info();
}
void test_retreen(void)//��������ز���
{
	caculate a(3);
	caculate b(5);
	caculate c;
	c=a+b;
	c.show_value();
	c=a*b;
	c.show_value();
	c=b/a;
	c.show_value();
	a=1000;
	a.show_value();
}
void test_oper(void)//����operator������ת��Ϊ��Ա����
{
	caculate a(2);
	std::cout << "a=" << a << std::endl;
	std::cout << "(a)=" << (a) << std::endl;
	std::cout << "int(a)=" << int(a) << std::endl;
	int b=a;
	std::cout << "b=" << b << std::endl;
	a.show_value();
}
void test_struct_func(void)//���ݶ���Ĳ������ò�ͬ�Ĺ��캯������
{
	student a;
	student b("lili",1,100);
	a.Show_Info();
	b.Show_Info();
}*/
void string_in_test(void)
{
	std::cout << "�������ַ�����" << std::endl;
	char str[20];
	std::cin >> str;//�޷�ʶ��ո�������ַ�
	std::cout << str << std::endl;
	std::cin.sync();//������뻺����
	gets(str);//�޷�ʶ�𻺳������鳤��
	std::cout << str << std::endl;
	std::cin.sync();
	std::cin.get(str,20,'\n');
	std::cout << str << std::endl;
}
void  shuchu(void)
{
	int i,j;
	int a[10][10];
	for(i = 1; i < 10; i++)
	{
		for(j = 1;j <= i; j++)
		{
			if(j == i || j == 1)
				a[i][j] = 1;
			else
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			std::cout << a[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}
void test_array(void)
{
	array_type a(10);
	char i[100];
	int j;
	std::cout << "�����ַ���" << std::endl;
	std::cin.get(i,100,'\n');
	for(j = 0; j <= (int)strlen(i); j++)
	{
		a[j]=i[j];
	}
	std::cout << "������ַ����ǣ�" << a.get_addr() <<std::endl;
}

void test_link(void)
{
	char command;
	student_link *link_head=NULL;
	student_link temp;
	std::string inser_name;
	std::string search_name;

	while(1)
	{
		std::cout << "���������" << std::endl;
		std::cin >> command;
		switch(command)
		{
		case 'c':
			if(link_head == NULL)
			{
				std::cout << "����������:" << std::endl;
				std::cin >> temp.name;
				std::cout<< "������ѧ�ţ�" << std::endl;
				temp.number = input_int();
				std::cout << "�����������" << std::endl;
				temp.score = intput_float();
				cread(&link_head,temp);
			}
			else
				std::cout << "�����Ѿ����ڣ�" << std::endl;

			break;
		case 's':
			if(link_head != NULL)
			{
				std::cout << "��������ҵ�������" << std::endl;
				std::cin >> search_name;
				serch_stu(link_head,search_name);
			}
			else
				std::cout << "������Ϣ¼�룡" << std::endl;
			break;
		case 'a':
			if(link_head != NULL)
			{
				std::cout << "����������:" << std::endl;
				std::cin >> temp.name;
				std::cout<< "������ѧ�ţ�" << std::endl;
				temp.number = input_int();
				std::cout << "�����������" << std::endl;
				temp.score = intput_float();
				std::cout << "���������λ�ã����֣���" << std::endl;
				std::cin >> inser_name;
				add(link_head,inser_name,temp);
			}
			else
				std::cout << "������δ������" << std::endl;

			break;
		case 'd':
			std::cout << "������Ҫɾ�������֣�" << std::endl;
			std::cin >> search_name;
			delete_stu(link_head,search_name);
			break;
		case 'b':
			show_all(link_head);
			break;
		case 'q':
			delete_all(link_head);
			return;
		case 'n':
			std::cout << "��Ա��ĿΪ��" << show_link_number(link_head) << std::endl;
			break;
		default:
			std::cout << "û�и����" << std::endl;
			break;
		}
	}
}
int main(void)
{
	//heap_test();
	//test_copy_struct();
	//test_struct_func();
//	test_son_class();
	//string_in_test();
	//shuchu();
	//test_array();
	test_link();
	student *p=new student[5];//����һ��ָ������������ָ�벢ָ����е�����
	while(1)
	{
		char command;
		std::cout << "���������" << std::endl;
		std::cin >> command;
		switch(command)
		{
			case 'a':
				add_student(p);
				break;
			case 's':
				show_student(p);
				break;
			case 'q':
				delete [] p;//[]����ʡ�ԣ�����ֻ�ͷŵ�һ��Ԫ��
				return 0;
			default:
				std::cout << "Command not fount!" << std::endl;
				break;
		}
	}
	
	return 0;
}
void add_student(student *list)//��Ӷ���
{	
	const std::string message[]={"Please input students quantity:","Please input name:","Please input number score:","Add Success!"};
	const std::string * p;
	p=message;
	std::cout << (*(p++)) << std::endl;
	int qua;
	std::cin >> qua;
	for(int i=0; i < qua; i++)
	{
		std::string name;
		int number;
		float score;
		std::cout << (*(p++)) << std::endl;
		std::cin >> name;
		list[i].Set_Info(name);
		std::cout << (*(p++)) << std::endl;
		std::cin >> number >> score;
		list[i].Set_Info(number);
		list[i].Set_Info(score);
	}
	std::cout << (*p) << std::endl;

}
void show_student(student *list)//��ʾ��������
{
	std::cout << "Please input name:" << std::endl;
	std::string tmp;
	std::cin >> tmp;
	for(int i=0; i<5; i++)
	{
		if(tmp==list[i].get_name())
		{
			list[i].Show_Info();
			return;
		}
	}
}
