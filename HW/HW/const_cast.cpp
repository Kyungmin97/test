#include<iostream>
using namespace std;

class A
{
  private:
	int num;
  public:
	A(int n) { num = n; }
	void show()const ;             
 };
void A::show() const  // const A *this �� this�� ����Ű�� ���ü�� constȭ ��Ŵ
{
	const_cast<A *>(this)->num++;
	//this->num++;
	cout << "num = " << num << endl;
}

void sub(const A &r);
int main()
{
	 A ob(10);
	 sub(ob);

	return 0;
}
void sub(const A &r)
{
	//r.show();
	const_cast<A &>(r).show();
}
