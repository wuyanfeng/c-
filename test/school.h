#ifndef _SCHOOL_H_
#define _SCHOOL_H_
#include <iostream>
#include <string>
using namespace std;
class A//�����಻��ʵ����������������븲�ǵ�ÿһ�����麯��
{
public:
	virtual string get_info()=0;//���麯��
};
class school:public A
{
public:
	school();
	school(const string &,const string &);
	virtual ~school();//�������������麯������������ҲҪ����Ϊ�麯��
	inline void set_school_info(const string &);
	virtual string get_info();//virual �����ں���˵���������ں������壬�Ҹ���������ͬ����������ֵ������ͬ
private:
	string school_name;
protected://������Ա�ɱ�����ֱ�ӷ���
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
class school_class:public school,public department //����ɼ̳и����ȫ������
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