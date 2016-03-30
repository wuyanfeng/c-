#include "caculate.h"
#include <string>
#include <iostream>
int caculate::get_value(void)
{
	return x;
}
 caculate::caculate(caculate &copy)
 {
	 x=copy.get_value();
 }
 void caculate::show_value(void)
 {
	std::cout << "The value is:" << x << std::endl;
 }


 array_type::array_type(int l)
 {
	 Length = l;
	 size=new char[Length];
	 std::cout << "数组创建成功" << std::endl;
 }
 array_type::~array_type(void)
 {
	 delete [] size;
	 std::cout << "数组已删除" << std::endl;
 }
 int & array_type::get_length(void)
 {
	 return Length;
 }
 char & array_type::operator[](int &i)
 {
	if(i < 0 || i >= Length)
	{
		std::cout << "数组溢出" << std::endl;
		return size[Length - 1];
	}
	else
	{
		return size[i];
	}
 }
char * array_type::get_addr(void)const
 {
	return size;
 }