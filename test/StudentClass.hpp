
#ifndef STUDENT_CLASS_H_
#define STUDENT_CLASS_H_
#include <iostream>
#include <string>

class student
{
public://���캯��������ڶ�˽�г�Ա�еĳ��������ý��г�ʼ��
	student():name(" "),number(1),score(0){std::cout << "ѧ�����캯�������ã�" << std::endl;} //����һ�ֳ�ʼ������student(){this -> name=" ";this -> number = 1; this -> score = 0;}//��������ʱ�Զ����ù��캯��
	inline student(std::string,int,float);
	student(int i){number = i;}
	inline student(const student &copy);     //���ƹ��캯��һ�㲻��ı����������������Ϊ��̬����
	~student(void){std::cout << "ѧ����������������" << std::endl;}														//���������ڶ�������ʱ����
	student operator++(){++number;return student(number);}//���������
	student operator++(int o){student temp(*this); number++; return temp;}
	void Set_Info(std::string = " ");//���������жԴ���������г�ʼ��
	void Set_Info(int = 0);//���������жԴ���������г�ʼ��
	void Set_Info(float = 0);//���������жԴ���������г�ʼ��
	void Show_Info(void)const;//��ʹ��const���κ������Է�ֹ���˽�б������޸�
	std::string get_name()const{return name;}
private: //˽�б���ֻ�������еĹ��к������ã�������������
	std::string name;
	int number;
	float score;
};
inline student::student(std::string x, int y, float z)
{
	name = x;
	number = y;
	score = z;
	std::cout << "ѧ�����캯�������ã�" << std::endl;
}
inline student::student(const student &copy)
{
	name = copy.name;
	number = copy.number;
	score = copy.score;
	std::cout << "ѧ�����ƹ��캯�������ã�" << std::endl;
}

#endif
