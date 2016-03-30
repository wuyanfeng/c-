#include <iostream>
#include <string>
#include "StudentClass.hpp"
using namespace std;
void student::Show_Info(void)const
{
	cout << "Name:\t" << this -> name << endl;
	cout << "Number:\t" << this -> number << endl;
	cout << "Score:\t" << this -> score << endl;
}
void student::Set_Info(string na)//成员函数的重载
{
	this -> name = na;

}
void student::Set_Info(int n)
{
	this -> number=n;
}
void student::Set_Info(float s)
{
	this -> score=s;
}

