#include "school.h"
#include <iostream>
using namespace std;
/////////////////////////////////school父类公共成员函数定义/////////////////////////////////////////////////
school::school():school_name(" ")
{
	cout << "父类构造函数被调用！"  << endl;
}
school::school(const string &a,const string &b)
{
	school_name = a; 
	level = b; 
	cout << "父类构造函数被调用！"  << endl;
}
school::~school()
{
	cout << "父类析构函数被调用！" << endl;
}
inline void school::set_school_info(const string &a)
{
	school_name = a;
}
string school::get_info()
{
	return school_name;
}
/////////////////////////////////department父类公共成员函数定义//////////////////////////////////////
department::department():department_name(" ")
{
	cout << "母类构造函数被调用！"  << endl;
}
department::department(const string &a)
{
	department_name = a; 
	cout << "母类构造函数被调用！"  << endl;
}
department::~department()
{
	cout << "母类析构函数被调用！" << endl;
}
inline void department::set_department_info(const string &a)
{
	department_name = a;
}
 string department::get_info()
{
	return department_name;
}
/////////////////////////////////子类公共成员函数定义/////////////////////////////////////////////////
string school_class::get_info(void)
{
	cout << "所属学校名称为：" << this->school::get_info() << endl//两个基类中都有get_info函数，故加入作用域操作符以识别是哪个基类
		<< "学校等级为：" << this -> level << endl 
		<< "系别：" << this ->department::get_info() << endl//两个基类中都有get_info函数，故加入作用域操作符以识别是哪个基类
		<<  "班级学生数为：" << student_number << endl;
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
	 cout << "子类构造函数被调用！"  << endl;
}
school_class::school_class():school("",""),department(""),student_number(0)
{
	cout << "子类构造函数被调用!" << endl;
}
school_class::~school_class()
{
	cout << "子类析构函数被调用！" << endl;
}