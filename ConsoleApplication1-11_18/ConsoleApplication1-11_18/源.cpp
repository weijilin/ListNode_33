#define _CRT_SECURE_NO_WARNINGS 1
#if 0
// 不同继承方式下，派生类的对象模型
// B <--- D    单继承：一个类只有一个基类


// 多继承
class B1
{
public:
	int _b1;
};

class B2
{
public:
	int _b2;
};

// 派生类将两个基类中的成员都继承到子类中
// 在派生类对象模型中：先继承那个基类，该基类中的成员就在对象模型的最上方
class D : public B1, public B2
{
public:
	int _d;
};


int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;
	return 0;
}
#endif

#if 0
// 面试题：什么是菱形继承？菱形继承有什么缺陷？如何解决？

// 菱形继承：单继承 + 多继承
class B
{
public:
	void TestFunc()
	{}

public:
	int _b;
};

class C1 : public B
{
public:
	int _c1;
};

class C2 : public B
{
public:
	int _c2;
};


class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;

	D  d;

	// C1从B中继承一个_b, C2从B中继承一个_b
	// D: 从C1中继承一个_b, 从C2中继承一个_b
	// D中就有两份_b
	// 如果直接通过派生类对象访问_b,编译器就不知道访问那个_b
	// 编译时报错：访问不明确
	// 以上就是菱形继承缺陷---菱形继承的二义性问题
	//d._b = 1;
	//d.TestFunc();

	// 代码通过编译：让访问明确
	// 1. 在_b前增加基类的名称
	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;

	d.C1::TestFunc();
	d.C2::TestFunc();

	// 2. 能否让最顶层基类成员(B)在D类中只保存一份
	// 可以---菱形虚拟继承
	return 0;
}
#endif
