#ifndef _CACULATE_H_
#define _CACULATE_H_
class caculate
{
public:
	caculate():x(0){}
	~caculate(){}
	caculate(caculate &copy);
	caculate(int i){x = i;}
	int get_value(void);
	void show_value(void);
	caculate operator++(void){++x; return caculate (x);}
	const caculate operator++(int o){caculate temp(*this); ++x; return temp;}
	const caculate operator--(){--x; return caculate(x);}
	const caculate operator--(int o){caculate temp(*this); --x; return temp;}
	const caculate operator+(caculate &a){ return caculate(x + a.get_value());}
	const caculate operator-(caculate &a){return caculate(x-a.get_value());}
//	const caculate operator*(caculate &a){return caculate(x * a.get_value());}//*��һ������²��������أ�������ָ��ȷ��ų�ͻ 
	const caculate operator/(caculate &a){return caculate(x / a.get_value());}
	operator int(){return x;}//��������������ö�����ֱ�ӷ��ʳ�Ա����
private:
	int x;
};

class array_type
{
public:
	array_type(){}
	array_type(int l);
	~array_type();
	int &get_length();
	char *get_addr()const;
	char &operator[](int &i);
private:
	int Length;
	char *size;
};

#endif