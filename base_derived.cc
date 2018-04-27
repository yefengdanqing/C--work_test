#include "../leetcode/common.h"
class Base
{
public:
	Base()
	{
		cout<<"base"<<endl;
	}
	void print_base()
	{
		cout<<"print_base"<<endl;
	}
	virtual void func()
	{
		cout<<"virtual base"<<endl;
	}
	//有多态实现和共有继承，定义为虚函数
	~Base()
	{
		cout<<"xigou_base"<<endl;
	}
};
class Derive : public Base
{
public:
	Derive()
	{
		cout<<"derive"<<endl;
	}
	/*void print_base()
	{
		cout<<"print_derive"<<endl;
	}*/
	void func()
	{
		cout<<"virtual derive"<<endl;
	}
	~Derive()
	{
		cout<<"xigou_derive"<<endl;
	}
};
int main()
{
	/*****test-0*******/
	//虚函数的虚表指针是在运行的时候确定，即new的时候确定
	Base* vptr_base=new Base;//基类虚表
	Base* vptr_derive=new Derive;//派生类虚表
	Derive* vptr_derive1=new Derive;//派生类虚表
	
	/*理解类成员函数通过隐世的*this来传
	入成员函数作为参数（为成员函数第一个参数）*/
	
	/*****test-1*******/
	Base* pb=new Base;
	pb->print_base();
	pb->func();
	//Base* pd =dynamic_cast<Base*>(pb);
	//Derive* pd=dynamic_cast<Derive*>(pb);//段错误
	Derive* pd=(Derive*)(pb);//不安全
	pd->print_base();//由调用对象的静态类型（声明类型）决定调用那个非虚函数
	pd->func();
	
	cout<<"/*****test-2*******/"<<endl;
	Derive* derive=new Derive;
	derive->Base::func();
	Base* base=(Base*)(derive);
	//Base* base=dynamic_cast<Base*>(derive);//运行ok
	derive->print_base();
	derive->func();
	
	cout<<"/*****test-3*******/"<<endl;
	Base* p=new Derive;//官方多态
	return 0;
}

