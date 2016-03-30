#ifndef _SCHOOL_H_
#define _SCHOOL_H_
#include <iostream>
#include <string>
using namespace std;
class A//抽象类不能实例化对象，其子类必须覆盖掉每一个纯虚函数
{
public:
	virtual string get_info()=0;//纯虚函数
};
class school:public A
{
public:
	school();
	school(const string &,const string &);
	virtual ~school();//若类中声明了虚函数则析构函数也要声明为虚函数
	inline void set_school_info(const string &);
	virtual string get_info();//virual 仅用于函数说明不能用于函数定义，且父类与子类同名函数返回值类型相同
private:
	string school_name;
protected://保护成员可被子类直接访问
	string level;
};
class department:public A
{
public:
	department();
	department(const string &);
	virtual ~department();
	inline void set_department_info(const string &);
	 virtual string get_info();
private:
	string department_name;
};
class school_class:public school,public department //子类可继承父类的全部属性
{
public:
	school_class();
	school_class(const string &,const string &,const string &,int );
	~school_class();
	void set_class_info(const string &,const string &,const string &,const int &);
	string get_info();
private:
	int student_number;
};
#endif