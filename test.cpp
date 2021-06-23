#include<iostream>
using namespace std;
//class tmp
//{
//	static int a;
//	static void func()
//	{
//
//	}
//};
//int main()
//{
//	cout << sizeof(tmp) << endl;//1 静态成员不会改变sizeof(tmp)
//	return 0;
//}


//同名静态成员处理（和同名非静态成员函数相似）
//class Father
//{
//public:
//	static void func()
//	{
//		cout << "Father中func函数的调用" << endl;
//	}
//	static int m_a;//类内声明
//	static int m_b;
//};
////类外赋值
//int Father::m_a = 10;
//int Father::m_b = 10;
//class son :public Father
//{
//public:
//	static void func()
//	{
//		cout << "son中func函数的调用" << endl;
//	}
//	static int m_a;
//	static int m_b;
//};
//int son::m_a = 20;
//int son::m_b = 20;
//void test()
//{
//	//通过对象访问
//	son s;
//	cout << s.m_a << endl;//20
//	cout << s.m_b << endl;//20
//	//如果要想得到10 即Father中的m_a和m_b
//	cout << Father::m_a << endl;
//	cout << Father::m_b << endl;
//
//	//通过类名访问
//	cout << son::m_a << endl;//20
//	cout << son::m_b << endl;//20  效果相同
//	 //如果要想得到10 即Father中的m_a和m_b
//	cout << son::Father::m_a << endl;//其中son::Father::m_a 第一个::代表通过类名的方式访问  第二个::号表示访问父类作用域下	
//	cout << son::Father::m_b << endl;//注：像通过Father::m_a来访问m_b的只有对静态成员变量有效  对于非静态成员变量必须有特定对象相对 即声明一个变量
//	cout << Father::m_a << endl;//这样也行
//}
//void test1()
//{
//	//同名静态成员函数的处理
//	son s1;
//	s1.func();//son中func函数的调用  先调用son中的func函数
//	s1.Father::func();//Father中func函数的调用
//	son::func();//son中func函数的调用  通过作用域调用成员函数
//	son::Father::func();//Father中func函数的调用
//	Father::func();//Father中func函数的调用
//	//注：如果子类和父类中有同名成员函数  如果没加作用域 则子类中的成员函数会覆盖父类中的成员函数 包括重载函数
//}
//int main()
//{
//	//test();
//	test1();
//	return 0;
//}
//多继承语法
//不建议写多继承语法
//class Father1
//{
//public:
//	Father1()
//	{
//		m_a = 10;
//	}
//	int m_a;
//};
//class Father2
//{
//public:
//	Father2()
//	{
//		m_a = 20;
//	}
//	int m_a;
//};
//class son :public Father1, public Father2//多继承，通过逗号来分隔不同的父类  可以添加无数个父类
//{
//public:
//	son()
//	{
//		m_c = 30;
//		m_d = 40;
//	}
//	int m_c;
//	int m_d;
//};
//void test()
//{
//	son s;
//	//cout << s.m_a << endl;//错误 son::m_a不明确  因为Father1和Father2中都有m_a 
//	//如果要访问m_a，则要加作用域
//	cout << s.Father1::m_a << endl;//10
//	cout << s.Father2::m_a << endl;//20
//	cout << sizeof(son) << endl;//16即此时son中有两份m_a加上m_c和m_d就有四个整形 16个字节
//	//或者通过作用域来访问
//	//cout << son::Father1::m_a << endl;//不行 m_a不是静态成员变量
//}
//int main()
//{
//	test();
//	return 0;
//}

//菱形继承
/*
           a
     b            c
           d
如图 b和c继承a，在由d继承b和c
不过这样的话d中就会继承两份a的成员
*/
//代码展示
//class A
//{
//public:
//	A()
//	{
//		m_a = 10;
//	}
//	int m_a;
//};
//class B :virtual public A
//{
//public:
//	int m_b;
//};
//
//class C :virtual public A
//{
//public:
//	int m_c;
//};
//class test1 :public B, public C
//{
//public:
//	int m_d;
//};
//void test()
//{
//	cout << sizeof(test1) << endl;//20 两个m_a,一个m_b,m_c,m_d 共五个整形 20个字节
//	test1 d;
//	//cout << d.m_a << endl;//错误 D::m_a不明确 应为B和C中都有m_a
//	//如果要解决此问题 需用到虚继承(virtual关键字) 即生成一个虚基类指针指向A 这样就不会出现重复数据的情况
//	cout << sizeof(test1) << endl;//24
//	cout << d.m_a << endl;//10 可以了
//	d.m_a = 20;//甚至可以直接修改 说明数据只有一份
//	cout << d.m_a << endl;//20
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//多态
/*
多态分为静态多态和动态多态
静态多态：如函数重载，运算符重载都属于静态多态 静态多态函数地址早绑定（编译阶段）
动态多态：派生类和虚函数实现运行时多态  动态多态地址晚绑定（运行阶段绑定）
*/
//代码展示
//class animal
//{
//public:
//	void speak()
//	{
//		cout << "动物在说话" << endl;
//	}
//};
//
//class cat :public animal
//{
//public:
//	void speak()
//	{
//		cout << "小猫在说话" << endl;
//	}
//};
//void dospeak(animal& p)//地址早绑定  如果不是虚函数 由于接收的类型为animal& 在编译阶段就已经绑定好了 就指向animal内的speak函数
//{
//	p.speak();
//}
//void test()
//{
//	cat c;
//	dospeak(c);//动物在说话
//	//如果要解决此问题 需用到虚函数
//
//}
//int main()
//{
//	test();
//	return 0;
//}
//虚函数展示
//class animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "动物在说话" << endl;
//	}
//};
//
//class cat :public animal
//{
//public:
//	void speak()
//	{
//		cout << "小猫在说话" << endl;
//	}
//};
//class dog :public animal
//{
//public:
//	void speak()
//	{
//		cout << "小狗在说话" << endl;
//	}
//};
//void dospeak(animal& p)//此处必须为引用 否则不会成功
//{
//	p.speak();
//}
//void test()
//{
//	cat c;
//	dospeak(c);//小猫在说话  就是根据你传入对象的不同来调用不同的函数 cat类型的就调用cat中的函数 而不是直接调用animal中的函数
//	dog d;
//	dospeak(d);//小狗在说话 接收时为 animal& p=d;这步很重要 虽然animal和dog不是相同的类 这就是虚函数的作用吧 根据传入的类型来访问不同函数
//}
//int main()
//{
//	test();
//	return 0;
//}
/*
动态多态满足条件
1.有继承关系
2.子类重写父类的虚函数（重写：子类中的函数与父类中的函数的名称，传参都要相同，区别于重载）
动态多态的使用
父类的指针或引用 指向子类对象（就如同animal& = c）
*/

/*
多态的好处
1.组织结构清晰
2.可读性强
3.对于前期和后期的拓展和维护性强
*/
//推荐使用多态进行程序架构  因为多态好处非常多
//案例：利用多态设计一个计算机
//class abstractcalculate
//{
//public:
//	virtual int getresult()
//	{
//		return 0;
//	}
//	int m_a;
//	int m_b;
//};
//class Add :public abstractcalculate
//{
//public:
//	int getresult()
//	{
//		return m_a + m_b;
//	}
//};
//class Sub :public abstractcalculate
//{
//public:
//	int getresult()
//	{
//		return m_a - m_b;
//	}
//};
//class Mul :public abstractcalculate
//{
//public:
//	int getresult()
//	{
//		return m_a * m_b;
//	}
//};
//void test()
//{
//	abstractcalculate* abc = new Add;
//	abc->m_a = 10;
//	abc->m_b = 10;
//	cout << abc->getresult() << endl;//20
//	delete abc;
//	abc = new Sub;//他这个就是根据new的类型不同来选择函数
//	abc->m_a = 10;
//	abc->m_b = 10;
//	cout << abc->getresult() << endl;//0
//	delete abc;
//	abc = new Mul;
//	abc->m_a = 10;
//	abc->m_b = 10;
//	cout << abc->getresult() << endl;//100
//	delete abc;
//	abc = NULL;
//}
//int main()
//{
//	test();
//	return 0;
//}

//纯虚函数和抽象类
//代码展示
//class Father
//{
//public:
//	virtual void func() = 0;//经过这种操作后func函数就是纯虚函数  Father类就是抽象类
//	int m_a;
//	int m_b;
//};
////在定义子类时 一定要重写纯虚函数  否则也被归为抽象类  不可定义变量
//class son :public Father
//{
//public:
//	void func()
//	{
//		cout << "func函数的调用" << endl;
//	}
//};
//
//void test()
//{
//	//Father a;//报错 此时Father类是抽象类  不可以定义变量
//	//没重写纯虚函前
//	//son s;//报错 此时son类是抽象类  不可以定义变量
//	//重写纯虚函数后
//	son s;
//	s.func();//这样的话当然也行  但我们一般利用父类的引用（如上动物在说话）或指针（如上计算机的设计）来调用
//	Father* abc = new son;
//	abc->func();//这样比较规范吧
//}
//int main()
//{
//	test();
//	return 0;
//}
//多态案例：制作饮品
//class abstractmakedrinking
//{
//public:
//	//煮水
//	virtual void boil() = 0;
//	//冲洗
//	virtual void washing() = 0;
//	//加入辅料
//	virtual void putsomething() = 0;
//	//等待
//	virtual void wait() = 0;
//	void makedrink()
//	{
//		boil();
//		washing();
//		putsomething();
//		wait();
//	}
//};
////咖啡
//class Coffee :public abstractmakedrinking
//{
//public:
//	//煮水
//	virtual void boil()
//	{
//		cout << "大火煮开农夫山泉" << endl;
//	}
//	//冲洗
//	virtual void washing()
//	{
//		cout << "冲洗咖啡豆" << endl;
//	}
//	//加入辅料
//	virtual void putsomething()
//	{
//		cout << "加入咖啡豆" << endl;
//	}
//	//等待
//	virtual void wait()
//	{
//		cout << "等待3分钟就可以喝到美味的咖啡了" << endl;
//	}
//};
////茶
//class Tea :public abstractmakedrinking
//{
//public:
//	//煮水
//	virtual void boil()
//	{
//		cout << "大火煮开农夫山泉" << endl;
//	}
//	//冲洗
//	virtual void washing()
//	{
//		cout << "冲洗茶叶" << endl;
//	}
//	//加入辅料
//	virtual void putsomething()
//	{
//		cout << "加入茶叶" << endl;
//	}
//	//等待
//	virtual void wait()
//	{
//		cout << "等待3分钟就可以喝到美味的茶了" << endl;
//	}
//};
////可以写一个制作饮料的函数
//void dowork(abstractmakedrinking* p)
//{
//	p->makedrink();
//}
//void test()
//{
//	dowork(new Coffee);
//	cout << "————————————————" << endl;
//	dowork(new Tea);//可以了
//	//同一个dowork接口 但可以执行不同的功能 这就是多态
//}
//int main()
//{
//	test();
//	return 0;
//}







