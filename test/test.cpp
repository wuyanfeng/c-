#include <iostream>
#include <string>
#include "StudentClass.hpp"
#include "caculate.h"
#include "school.h"
#include "link.h"
//student Class_One[5];//全局对象数组，运行时自动创建，主程序结束自动释放
void add_student(student *);
void show_student(student *);
void test_son_class(void)//单继承派生类测试
{
	school_class yiban("石家庄学院","本科","电气工程系",20);

	//yiban.set_class_info("广平二中","高中","电气工程系",50);
	school &a=yiban;
	a.get_info();
	school *p=new school_class;//建立一个指向父类的指针，但对象为子类
	p->get_info();
	delete p;
	//school_class *b=&yiban;
	//b->get_info();
	//school &c=yiban;
	//c.get_info();
	//std::cout << b->school::get_info()<<std::endl;//可以使用成员名限定即作用域操作符取消动态联编
	//yiban.get_info();
}
/*void heap_test(void)//在堆中创建对象测试
{
	student *p=new student;
	std::cout << "Creat a heap area." << std::endl;
	p -> Set_Info("wu");
	p -> Set_Info(1);
	p -> Set_Info(100);
	p -> Show_Info();
	delete p;
}
void test_copy_struct(void)//重载和复制构造函数测试
{
	student wiwi;
	wiwi.Set_Info("hello");
	wiwi.Set_Info(34);
	wiwi.Set_Info((float)100.0);
	student lili(wiwi);
	wiwi.Show_Info();
	lili.Show_Info();
}
void test_retreen(void)//运算符重载测试
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
void test_oper(void)//利用operator将对象转换为成员变量
{
	caculate a(2);
	std::cout << "a=" << a << std::endl;
	std::cout << "(a)=" << (a) << std::endl;
	std::cout << "int(a)=" << int(a) << std::endl;
	int b=a;
	std::cout << "b=" << b << std::endl;
	a.show_value();
}
void test_struct_func(void)//根据对象的参数调用不同的构造函数测试
{
	student a;
	student b("lili",1,100);
	a.Show_Info();
	b.Show_Info();
}*/
void string_in_test(void)
{
	std::cout << "请输入字符串：" << std::endl;
	char str[20];
	std::cin >> str;//无法识别空格等特殊字符
	std::cout << str << std::endl;
	std::cin.sync();//清除输入缓冲区
	gets(str);//无法识别缓冲区数组长度
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
	std::cout << "输入字符串" << std::endl;
	std::cin.get(i,100,'\n');
	for(j = 0; j <= (int)strlen(i); j++)
	{
		a[j]=i[j];
	}
	std::cout << "输入的字符串是：" << a.get_addr() <<std::endl;
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
		std::cout << "请输入命令：" << std::endl;
		std::cin >> command;
		switch(command)
		{
		case 'c':
			if(link_head == NULL)
			{
				std::cout << "请输入姓名:" << std::endl;
				std::cin >> temp.name;
				std::cout<< "请输入学号：" << std::endl;
				temp.number = input_int();
				std::cout << "请输入分数：" << std::endl;
				temp.score = intput_float();
				cread(&link_head,temp);
			}
			else
				std::cout << "链表已经存在！" << std::endl;

			break;
		case 's':
			if(link_head != NULL)
			{
				std::cout << "请输入查找的姓名：" << std::endl;
				std::cin >> search_name;
				serch_stu(link_head,search_name);
			}
			else
				std::cout << "尚无信息录入！" << std::endl;
			break;
		case 'a':
			if(link_head != NULL)
			{
				std::cout << "请输入姓名:" << std::endl;
				std::cin >> temp.name;
				std::cout<< "请输入学号：" << std::endl;
				temp.number = input_int();
				std::cout << "请输入分数：" << std::endl;
				temp.score = intput_float();
				std::cout << "请输入插入位置（名字）：" << std::endl;
				std::cin >> inser_name;
				add(link_head,inser_name,temp);
			}
			else
				std::cout << "数据尚未创建！" << std::endl;

			break;
		case 'd':
			std::cout << "请输入要删除的名字：" << std::endl;
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
			std::cout << "成员数目为：" << show_link_number(link_head) << std::endl;
			break;
		default:
			std::cout << "没有该命令！" << std::endl;
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
	student *p=new student[5];//定义一个指向类对象数组的指针并指向堆中的数组
	while(1)
	{
		char command;
		std::cout << "请输入命令：" << std::endl;
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
				delete [] p;//[]不可省略，否则只释放第一个元素
				return 0;
			default:
				std::cout << "Command not fount!" << std::endl;
				break;
		}
	}
	
	return 0;
}
void add_student(student *list)//添加对象
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
void show_student(student *list)//显示对象属性
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
