#define _CRT_SECURE_NO_WARNINGS 1
#if 0
// ��ͬ�̳з�ʽ�£�������Ķ���ģ��
// B <--- D    ���̳У�һ����ֻ��һ������


// ��̳�
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

// �����ཫ���������еĳ�Ա���̳е�������
// �����������ģ���У��ȼ̳��Ǹ����࣬�û����еĳ�Ա���ڶ���ģ�͵����Ϸ�
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
// �����⣺ʲô�����μ̳У����μ̳���ʲôȱ�ݣ���ν����

// ���μ̳У����̳� + ��̳�
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

	// C1��B�м̳�һ��_b, C2��B�м̳�һ��_b
	// D: ��C1�м̳�һ��_b, ��C2�м̳�һ��_b
	// D�о�������_b
	// ���ֱ��ͨ��������������_b,�������Ͳ�֪�������Ǹ�_b
	// ����ʱ�������ʲ���ȷ
	// ���Ͼ������μ̳�ȱ��---���μ̳еĶ���������
	//d._b = 1;
	//d.TestFunc();

	// ����ͨ�����룺�÷�����ȷ
	// 1. ��_bǰ���ӻ��������
	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;

	d.C1::TestFunc();
	d.C2::TestFunc();

	// 2. �ܷ����������Ա(B)��D����ֻ����һ��
	// ����---��������̳�
	return 0;
}
#endif
