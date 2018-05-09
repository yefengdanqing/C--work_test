#include"../leetcode/common.h"
class Base
{ 
public:
	Base()
	{
	PrintBaseAddr();
	//	Func();
	}
	virtual void Func()
	{
		cout<<"this is base"<<endl;
	}
	void PrintBaseAddr()
	{
		//
		long* ptr=(long*)*((long*)this);
		cout<<"base vptr addr:"<<ptr<<endl;
		cout<<"call Func by ptr->";
		void (*pFunc)(Base* const)=(void(*)(Base* const))ptr[0];
		(*pFunc)(this);
		std::cout<<std::endl;
	}
	virtual ~Base()
 	{
	//	throw("destruct Base");
		PrintBaseAddr();
	}
};
class Derive : public Base
{ 
public:
	Derive()
	{
//		Func();
		PrintDeriveAddr();
	}
	virtual void Func()
	{
		cout<<"this is Derive"<<endl;
	}
	void PrintDeriveAddr()
	{
		long* ptr=(long*)*((long*)this);
		cout<<"Derive vptr addr:"<<ptr<<endl;
		cout<<"call Func by ptr->";
		void (*pFunc)(Derive* const)=(void(*)(Derive* const))ptr[0];
		(*pFunc)(this);
		cout<<endl;
	 }
	~Derive()
 	{
		//throw("destruct Base");
		PrintDeriveAddr();
 	} 
};  
class GarndSon:public Derive
{ 
public:
	GarndSon()
	{
//		Func();
		PrintGarndAdd();
	} 
	virtual void Func()
 	{
		cout<<"This is GarndSon"<<endl;
	}
	void PrintGarndAdd()
 	{
		long* ptr=(long*)*(long*)this;
		cout<<"GarndSon vptr addr:"<<ptr<<endl;
		cout<<"call Func by ptr->"; 
		void (*pFun)(GarndSon* const)=(void(*)(GarndSon* const))ptr[0];
		(*pFun)(this);
	}
	~GarndSon()
 	{
		PrintGarndAdd();
	}
};  
int main()
{ 
	Base* base=new GarndSon;
	delete base;
	return 0;
}
