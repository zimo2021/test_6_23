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
//	cout << sizeof(tmp) << endl;//1 ��̬��Ա����ı�sizeof(tmp)
//	return 0;
//}


//ͬ����̬��Ա������ͬ���Ǿ�̬��Ա�������ƣ�
//class Father
//{
//public:
//	static void func()
//	{
//		cout << "Father��func�����ĵ���" << endl;
//	}
//	static int m_a;//��������
//	static int m_b;
//};
////���⸳ֵ
//int Father::m_a = 10;
//int Father::m_b = 10;
//class son :public Father
//{
//public:
//	static void func()
//	{
//		cout << "son��func�����ĵ���" << endl;
//	}
//	static int m_a;
//	static int m_b;
//};
//int son::m_a = 20;
//int son::m_b = 20;
//void test()
//{
//	//ͨ���������
//	son s;
//	cout << s.m_a << endl;//20
//	cout << s.m_b << endl;//20
//	//���Ҫ��õ�10 ��Father�е�m_a��m_b
//	cout << Father::m_a << endl;
//	cout << Father::m_b << endl;
//
//	//ͨ����������
//	cout << son::m_a << endl;//20
//	cout << son::m_b << endl;//20  Ч����ͬ
//	 //���Ҫ��õ�10 ��Father�е�m_a��m_b
//	cout << son::Father::m_a << endl;//����son::Father::m_a ��һ��::����ͨ�������ķ�ʽ����  �ڶ���::�ű�ʾ���ʸ�����������	
//	cout << son::Father::m_b << endl;//ע����ͨ��Father::m_a������m_b��ֻ�жԾ�̬��Ա������Ч  ���ڷǾ�̬��Ա�����������ض�������� ������һ������
//	cout << Father::m_a << endl;//����Ҳ��
//}
//void test1()
//{
//	//ͬ����̬��Ա�����Ĵ���
//	son s1;
//	s1.func();//son��func�����ĵ���  �ȵ���son�е�func����
//	s1.Father::func();//Father��func�����ĵ���
//	son::func();//son��func�����ĵ���  ͨ����������ó�Ա����
//	son::Father::func();//Father��func�����ĵ���
//	Father::func();//Father��func�����ĵ���
//	//ע���������͸�������ͬ����Ա����  ���û�������� �������еĳ�Ա�����Ḳ�Ǹ����еĳ�Ա���� �������غ���
//}
//int main()
//{
//	//test();
//	test1();
//	return 0;
//}
//��̳��﷨
//������д��̳��﷨
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
//class son :public Father1, public Father2//��̳У�ͨ���������ָ���ͬ�ĸ���  �����������������
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
//	//cout << s.m_a << endl;//���� son::m_a����ȷ  ��ΪFather1��Father2�ж���m_a 
//	//���Ҫ����m_a����Ҫ��������
//	cout << s.Father1::m_a << endl;//10
//	cout << s.Father2::m_a << endl;//20
//	cout << sizeof(son) << endl;//16����ʱson��������m_a����m_c��m_d�����ĸ����� 16���ֽ�
//	//����ͨ��������������
//	//cout << son::Father1::m_a << endl;//���� m_a���Ǿ�̬��Ա����
//}
//int main()
//{
//	test();
//	return 0;
//}

//���μ̳�
/*
           a
     b            c
           d
��ͼ b��c�̳�a������d�̳�b��c
���������Ļ�d�оͻ�̳�����a�ĳ�Ա
*/
//����չʾ
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
//	cout << sizeof(test1) << endl;//20 ����m_a,һ��m_b,m_c,m_d ��������� 20���ֽ�
//	test1 d;
//	//cout << d.m_a << endl;//���� D::m_a����ȷ ӦΪB��C�ж���m_a
//	//���Ҫ��������� ���õ���̳�(virtual�ؼ���) ������һ�������ָ��ָ��A �����Ͳ�������ظ����ݵ����
//	cout << sizeof(test1) << endl;//24
//	cout << d.m_a << endl;//10 ������
//	d.m_a = 20;//��������ֱ���޸� ˵������ֻ��һ��
//	cout << d.m_a << endl;//20
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//��̬
/*
��̬��Ϊ��̬��̬�Ͷ�̬��̬
��̬��̬���纯�����أ���������ض����ھ�̬��̬ ��̬��̬������ַ��󶨣�����׶Σ�
��̬��̬����������麯��ʵ������ʱ��̬  ��̬��̬��ַ��󶨣����н׶ΰ󶨣�
*/
//����չʾ
//class animal
//{
//public:
//	void speak()
//	{
//		cout << "������˵��" << endl;
//	}
//};
//
//class cat :public animal
//{
//public:
//	void speak()
//	{
//		cout << "Сè��˵��" << endl;
//	}
//};
//void dospeak(animal& p)//��ַ���  ��������麯�� ���ڽ��յ�����Ϊanimal& �ڱ���׶ξ��Ѿ��󶨺��� ��ָ��animal�ڵ�speak����
//{
//	p.speak();
//}
//void test()
//{
//	cat c;
//	dospeak(c);//������˵��
//	//���Ҫ��������� ���õ��麯��
//
//}
//int main()
//{
//	test();
//	return 0;
//}
//�麯��չʾ
//class animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "������˵��" << endl;
//	}
//};
//
//class cat :public animal
//{
//public:
//	void speak()
//	{
//		cout << "Сè��˵��" << endl;
//	}
//};
//class dog :public animal
//{
//public:
//	void speak()
//	{
//		cout << "С����˵��" << endl;
//	}
//};
//void dospeak(animal& p)//�˴�����Ϊ���� ���򲻻�ɹ�
//{
//	p.speak();
//}
//void test()
//{
//	cat c;
//	dospeak(c);//Сè��˵��  ���Ǹ����㴫�����Ĳ�ͬ�����ò�ͬ�ĺ��� cat���͵ľ͵���cat�еĺ��� ������ֱ�ӵ���animal�еĺ���
//	dog d;
//	dospeak(d);//С����˵�� ����ʱΪ animal& p=d;�ⲽ����Ҫ ��Ȼanimal��dog������ͬ���� ������麯�������ð� ���ݴ�������������ʲ�ͬ����
//}
//int main()
//{
//	test();
//	return 0;
//}
/*
��̬��̬��������
1.�м̳й�ϵ
2.������д������麯������д�������еĺ����븸���еĺ��������ƣ����ζ�Ҫ��ͬ�����������أ�
��̬��̬��ʹ��
�����ָ������� ָ��������󣨾���ͬanimal& = c��
*/

/*
��̬�ĺô�
1.��֯�ṹ����
2.�ɶ���ǿ
3.����ǰ�ںͺ��ڵ���չ��ά����ǿ
*/
//�Ƽ�ʹ�ö�̬���г���ܹ�  ��Ϊ��̬�ô��ǳ���
//���������ö�̬���һ�������
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
//	abc = new Sub;//��������Ǹ���new�����Ͳ�ͬ��ѡ����
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

//���麯���ͳ�����
//����չʾ
//class Father
//{
//public:
//	virtual void func() = 0;//�������ֲ�����func�������Ǵ��麯��  Father����ǳ�����
//	int m_a;
//	int m_b;
//};
////�ڶ�������ʱ һ��Ҫ��д���麯��  ����Ҳ����Ϊ������  ���ɶ������
//class son :public Father
//{
//public:
//	void func()
//	{
//		cout << "func�����ĵ���" << endl;
//	}
//};
//
//void test()
//{
//	//Father a;//���� ��ʱFather���ǳ�����  �����Զ������
//	//û��д���麯ǰ
//	//son s;//���� ��ʱson���ǳ�����  �����Զ������
//	//��д���麯����
//	son s;
//	s.func();//�����Ļ���ȻҲ��  ������һ�����ø�������ã����϶�����˵������ָ�루���ϼ��������ƣ�������
//	Father* abc = new son;
//	abc->func();//�����ȽϹ淶��
//}
//int main()
//{
//	test();
//	return 0;
//}
//��̬������������Ʒ
//class abstractmakedrinking
//{
//public:
//	//��ˮ
//	virtual void boil() = 0;
//	//��ϴ
//	virtual void washing() = 0;
//	//���븨��
//	virtual void putsomething() = 0;
//	//�ȴ�
//	virtual void wait() = 0;
//	void makedrink()
//	{
//		boil();
//		washing();
//		putsomething();
//		wait();
//	}
//};
////����
//class Coffee :public abstractmakedrinking
//{
//public:
//	//��ˮ
//	virtual void boil()
//	{
//		cout << "�����ũ��ɽȪ" << endl;
//	}
//	//��ϴ
//	virtual void washing()
//	{
//		cout << "��ϴ���ȶ�" << endl;
//	}
//	//���븨��
//	virtual void putsomething()
//	{
//		cout << "���뿧�ȶ�" << endl;
//	}
//	//�ȴ�
//	virtual void wait()
//	{
//		cout << "�ȴ�3���ӾͿ��Ժȵ���ζ�Ŀ�����" << endl;
//	}
//};
////��
//class Tea :public abstractmakedrinking
//{
//public:
//	//��ˮ
//	virtual void boil()
//	{
//		cout << "�����ũ��ɽȪ" << endl;
//	}
//	//��ϴ
//	virtual void washing()
//	{
//		cout << "��ϴ��Ҷ" << endl;
//	}
//	//���븨��
//	virtual void putsomething()
//	{
//		cout << "�����Ҷ" << endl;
//	}
//	//�ȴ�
//	virtual void wait()
//	{
//		cout << "�ȴ�3���ӾͿ��Ժȵ���ζ�Ĳ���" << endl;
//	}
//};
////����дһ���������ϵĺ���
//void dowork(abstractmakedrinking* p)
//{
//	p->makedrink();
//}
//void test()
//{
//	dowork(new Coffee);
//	cout << "��������������������������������" << endl;
//	dowork(new Tea);//������
//	//ͬһ��dowork�ӿ� ������ִ�в�ͬ�Ĺ��� ����Ƕ�̬
//}
//int main()
//{
//	test();
//	return 0;
//}







