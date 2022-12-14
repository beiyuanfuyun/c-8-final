#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//1.动态联编和静态联编
//**2.多态
//3.纯虚函数
//4.final 与继承和多态相关的内容

//-------------01----------------------
//联编：计算机彼此关联的过程
//静态编译的是：计算机在代码编译时就知道要调用到那个代码段，c语言不支持重载，
// c语言其函数基本都是静态编译，但也要注意是重载也不一定是动态联编，动态联编有条件的
// 
// 动态编译：计算机在编译时还不知道要调用到哪个函数，直到运行到这里才知道
// 实现 动态编译（就是多态） 的条件：1.继承 2. 虚函数
// 
//
//

//----------------------02--------------
//虚函数的特点
// 1、一旦定义了一个虚函数，那么系统会给给你这个类维护一个虚函数的表
// 2、虚函数会比普通函数多一次遍历的过程（因为原虚函数里面会添加一个四字节的指针，指向虚函数表的首地址，所以调用时总是要将 虚函数表遍历一遍）
// 3、如果子类继承，父类函数里面有虚函数那么子类继承，
// 不会继承这个表而是创建一个表，并会继承表的数据（表项），看不到这个表

//---------------03上------------------ 
// 纯虚函数：当子类的功能包括了父类函数，父类函数就可以变为纯虚函数了
// 写法：virtual void fun() = 0;
// //纯虚函数  无意义-一种给子类的模板、
//	//有纯虚函数 或者 继承 了 纯虚函数 没有实现的类被称为 抽象类
// 要是父类中有纯虚函数，那如果子类没有实现相应的功能，则就是有对象
// 如果没有实现就是没对象
// 
//-------------------------03下--------------------

//------------------04final--------------
//父类的虚函数和纯虚函数在子类还是虚函数
// 又是我们不希望父类函数的莫个函数在子类中被重写
// 在c++11及以后可以用关键字final来避免函数被再次重写


//--------------------------------------------------------------------------------------


//--------------------01--------------------------
//class father
//{
//public:
//	/*void fun()
//	{
//		cout << "父类fan" << endl;
//	}*/
// father()
// {
// cout<<"gouzao1"<<endl;
// }
//	virtual void fun()
//	{
//		cout << "父类fan" << endl;
//	}
// ~father()
// {
// cout<<"xigou1"<<endl;
// }
//
//};
//class child1 :public father
//{
//public:
// child()
// {
// cout<<"gouzao1"<<endl;
// }
//	void fun()
//	{
//		cout << "子类1fun" << endl;
//	}
// ~child()
// {
// cout<<"gouzao1"<<endl;
// }
//};
//class child2 :public father
//{
//public:
// child()
// {
// cout<<"gouzao1"<<endl;
// }
//	void fun()
//	{
//		cout << "子类2fun" << endl;
//	}
// ~child()
// {
// cout<<"gouzao1"<<endl;
// }
//};
// //引用方式
//void text(father& p1)
//{
//	p1.fun();
//}
//void text(child1 & p1)
//{
//	p1.fun();
//}
//void text(child2 & p1)
//{
//	p1.fun();
//}

//--------------------02------------------
//class father
//{
//public:
//	virtual void speak()
//	{
//		cout << "1234" << endl;
//	}
//};
//class child:public father
//{
//public:
//	virtual void speak()//virtual可以不加，加了是为了提醒自己
//	{
//		cout << "1" << endl;
//	}
//};
//class child2 :public father
//{
//public:
//	virtual void speak()
//	{
//		cout << "2" << endl;
//	}
//};

//--------03up--------------------------------
//class father
//{
//	//纯虚函数  无意义-一种给子类的模板、
//	//有纯虚函数 或者 继承 了 纯虚函数 没有实现的类被称为 抽象类
//
//	virtual void fun() = 0;
//	/*{
//		cout << "1234" << endl;
//	}*/
//};
//class child :public father
//{
//	 void fun()
//	{
//		cout << "1234" << endl;
//	}
//};
//
//----------------03down----------------

//-----------------04----------------------------------



int main()
{
	//-------------------01--------------------------------
	//father  ft;
	//child1 c1;
	//child2 c2;
	//ft.fun();//以下都是静态联编，在还没运行时编译器就知道要跳转的地方
	//c1.fun();
	//c2.fun();
	//
	// 
	//text(ft);//一个入口多个出口，但也只是通过重载做的一个伪动态联编，
	//实际上还是静态联编还是分流了，方向还是确定的
	//
	//
	//多态条件-1.虚函数  2. 继承关系
	//多态-运用动态联编-效果：通过父类指针和引用调用派生类对象的虚函数成员 
	//将会跳转到子类虚函数成员进行实现，如果没有 虚函数 和 继承 是无法实现的
	//通过父类指针  引用  调用子类成员（子类中的函数成员和父类函数中虚函数成员的名字相同时
	//才会调用不然,就是重复调用父类自身，而且调用顺序是先父类后子类且子类还得看写调用的顺序，且是先用父类构造子类构造子类析构父类的析构顺序）
	//
	// 如果子类与父类的虚函数重名时，会将 子类函数也同化为虚函数
	//text(ft);
	//text(c1);
	//text(c2);//同一个接口 通过对 不同对象 的调用， 有着不同的效果 这就是多态


	//---------------02----------------------
	////条件：1.继承 2.虚函数
	////
	//// 指针方式
	////父类指针指向子类对象
	//father* cal = new father;
	////cal->speak();
	//delete cal;
	//cal = new child;
	////cal->speak();
	//delete cal;
	//cal = new child2;
	//cal->speak();
	//
	// 多态的释放
	// 重点强调：
	// 当出现多态的编程方式时，需要把父类的析构定义为虚函数（虚析构），让编译器区自动调用子类的析构
	//父类函数的构造和析构，会被子类调用，但是运行发现子类只会调用父类的构造和析构
	// 会调用自身的构造但是不会调用自身的析构，如何解决这个问题呢？要用到 virtual 给父类的析构函数加上virtual关机字
     

	//-------------03------------------
	//
	//一旦莫一个类，类中有纯虚函数，或者继承了纯虚函数  没有重写实现
	//那么就不能有对象了（万年单身）
	//father* cal = new father;//报错
	//
	//father* cal = new child;//但是一旦有函数重写了相关函数就可以有对象了
	//父类相当于一个样本模板，让子类继承时去按照模板写才会有对象

	//------------04---------------------


	return 0;
}