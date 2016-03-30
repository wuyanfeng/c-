#include "link.h"

student_link *cread(student_link **head,student_link source)
{
	student_link *p1;
	student_link *p2;
	p1=new student_link;
	p2=p1;
	*head=p1;
	p1->name=source.name;
	p1->number=source.number;
	p1->score=source.score;
	p2->next = NULL;
	p2->pre = NULL;
	//delete p1;
	p1=NULL;
	p2 = NULL;

	return *head;
}
void add(student_link *head,string posi,student_link source)
{
	student_link *p=head;
	do
	{
		if(p->name == posi)
		{
			break;
		}
		else
			p=p->next;
	}
	while(p!=NULL);
	if(p == NULL)
	{
		cout << "没有该插入位置！" << endl;
	}
	else
	{
		student_link *p1=new student_link;

		p1->name=source.name;
		p1->number=source.number;
		p1->score=source.score;
		p1->next=p->next;
		p1->pre=p;
		p->next=p1;
		//delete p1;
		p1=NULL;
		p=NULL;

	}

}
void serch_stu(student_link *head,string serch_name)
{
	student_link *p=head;
	student_link *p1;
	bool result=false;
	cout << "开始搜索！" << endl;
	do
	{
		if(p->name == serch_name)
		{
			cout << p->name << '\t' << p->number << '\t' << p->score << endl;
			p1=p->next;
			p=p1;
			result=true;
		}
		else
		{
			p1=p->next;
			p=p1;
		}
			
	}
	while(p!=NULL);
	if(result == false)
		cout << "没有找到该成员！" << endl;
	cout << "搜索结束" << endl;
	p=NULL;
	p1=NULL;
}
void delete_stu(student_link *head,string serch_name)
{
	student_link *p=head;
	do
	{
		if(p->name == serch_name)
		{
			break;
		}
		else
			p=p->next;
	}
	while(p!=NULL);
	if(p==NULL)
	{
		cout << "没有该成员！" << endl;
		p=NULL;
		return;
	}
	else
	{
		student_link *p1;
		student_link *p2;
		p1=p->pre;
		p2=p->next;
		p1->next=p->next;
		p2->pre=p->pre;
		delete p;
		cout << "删除成功！" << endl;
		p1=NULL;
		p2=NULL;
	}
}

void show_all(student_link *head)
{
	student_link *p=head;
	while(p!=NULL)
	{
		cout << p->name << '\t' << p->number << '\t' << p->score << endl;
		p=p->next;
	}
	p=NULL;
	cout << "显示完毕！" << endl;
}
void delete_all(student_link *head)
{
	student_link *p=head;
	student_link *p1=p;
	while(p!=NULL)
	{
		p1=p->next;
		delete p;
		p=p1;
	}
	p=NULL;
	p1=NULL;
	cout << "链表已删除！" << endl;
}
bool str_check(string str)
{
	for(int i=0; i < (int)str.length(); i++)
	{
		if((str[i] > '9' || str[i] < '0') && (str[i] != '.'))
			return false;
	}
	return true;
}
int input_int(void)
{
	string temp;
	cin >> temp;
	while(!str_check(temp))
	{
		cout << "请输入数字" << endl;
		cin >> temp;
	}
	return atoi(temp.c_str());
}
float intput_float(void)
{
	string temp;
	cin >> temp;
	while(!str_check(temp))
	{
		cout << "请输入数字" << endl;
		cin >> temp;
	}
	return (float)atof(temp.c_str());
}
int show_link_number(student_link *head)
{
	int num=0;
	student_link *p=head;
	while(p!=NULL)
	{
		p=p->next;
		num++;
	}
	if(num == 0)
		cout << "该链表为空！" << endl;
	return num;
}