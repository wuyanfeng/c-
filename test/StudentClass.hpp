
#ifndef STUDENT_CLASS_H_
#define STUDENT_CLASS_H_
#include <iostream>
#include <string>

class student
{
public://构造函数最好用于对私有成员中的常量和引用进行初始化
	student():name(" "),number(1),score(0){std::cout << "学生构造函数被调用！" << std::endl;} //另外一种初始化方法student(){this -> name=" ";this -> number = 1; this -> score = 0;}//建立对象时自动调用构造函数
	inline student(std::string,int,float);
	student(int i){number = i;}
	inline student(const student &copy);     //复制构造函数一般不会改变对象参数，因此声名为静态对象
	~student(void){std::cout << "学生析构函数被调用" << std::endl;}														//析构函数在对象销毁时调用
	student operator++(){++number;return student(number);}//运算符重载
	student operator++(int o){student temp(*this); number++; return temp;}
	void Set_Info(std::string = " ");//可在声明中对传入参数进行初始化
	void Set_Info(int = 0);//可在声明中对传入参数进行初始化
	void Set_Info(float = 0);//可在声明中对传入参数进行初始化
	void Show_Info(void)const;//可使用const修饰函数，以防止其对私有变量的修改
	std::string get_name()const{return name;}
private: //私有变量只允许类中的公有函数调用，不允许对象调用
	std::string name;
	int number;
	float score;
};
inline student::student(std::string x, int y, float z)
{
	name = x;
	number = y;
	score = z;
	std::cout << "学生构造函数被调用！" << std::endl;
}
inline student::student(const student &copy)
{
	name = copy.name;
	number = copy.number;
	score = copy.score;
	std::cout << "学生复制构造函数被调用！" << std::endl;
}

#endif
