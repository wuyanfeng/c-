#include "school.h"
#include <iostream>
using namespace std;
/////////////////////////////////school���๫����Ա��������/////////////////////////////////////////////////
school::school():school_name(" ")
{
	cout << "���๹�캯�������ã�"  << endl;
}
school::school(const string &a,const string &b)
{
	school_name = a; 
	level = b; 
	cout << "���๹�캯�������ã�"  << endl;
}
school::~school()
{
	cout << "�����������������ã�" << endl;
}
inline void school::set_school_info(const string &a)
{
	school_name = a;
}
string school::get_info()
{
	return school_name;
}
/////////////////////////////////department���๫����Ա��������//////////////////////////////////////
department::department():department_name(" ")
{
	cout << "ĸ�๹�캯�������ã�"  << endl;
}
department::department(const string &a)
{
	department_name = a; 
	cout << "ĸ�๹�캯�������ã�"  << endl;
}
department::~department()
{
	cout << "ĸ���������������ã�" << endl;
}
inline void department::set_department_info(const string &a)
{
	department_name = a;
}
 string department::get_info()
{
	return department_name;
}
/////////////////////////////////���๫����Ա��������/////////////////////////////////////////////////
string school_class::get_info(void)
{
	cout << "����ѧУ����Ϊ��" << this->school::get_info() << endl//���������ж���get_info�������ʼ����������������ʶ�����ĸ�����
		<< "ѧУ�ȼ�Ϊ��" << this -> level << endl 
		<< "ϵ��" << this ->department::get_info() << endl//���������ж���get_info�������ʼ����������������ʶ�����ĸ�����
		<<  "�༶ѧ����Ϊ��" << student_number << endl;
	return "";
}
void school_class::set_class_info(const string &n,const string &l,const string &d,const int &a)
{
	this ->set_school_info(n); 
	this ->level = l; 
	this ->set_department_info(d); 
	student_number = a;
}
school_class::school_class(const string &n,const string &l,const string &m,int a):school(n,l),department(m)
{
	 student_number = a; 
	 cout << "���๹�캯�������ã�"  << endl;
}
school_class::school_class():school("",""),department(""),student_number(0)
{
	cout << "���๹�캯��������!" << endl;
}
school_class::~school_class()
{
	cout << "�����������������ã�" << endl;
}