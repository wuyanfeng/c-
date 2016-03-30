#ifndef _LINK_H_
#define _LINK_H_
#include <iostream>
#include <string>
using namespace std;

class student_link
{
public:
	string name;
	int number;
	float score;
	student_link *next;
	student_link *pre;
};
student_link *cread(student_link **head,student_link source);
void add(student_link *head,string posi,student_link source);
void serch_stu(student_link *head,string serch_name);
void delete_stu(student_link *head,string serch_name);
void show_all(student_link *head);
void delete_all(student_link *head);
int input_int(void);
float intput_float(void);
int show_link_number(student_link *head);
#endif