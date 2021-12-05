#include<iostream>
using namespace std;
class Person
{
public:
	Person() {}
	~Person() {}
	int getID()
	{
		return ID;
	}
	int getHeight()
	{
		return height;
	}
	char* getName()
	{
		return name;
	}

	//************ ������ �Լ� �߰� *******************//

	//problem 1-1
	void init(int ID, const char* name, int height);
	//problem 1-2
	void printStudentInfo();
	//************ ������ �Լ� �߰� *******************//


private:
	int ID;
	int height;
	char* name;

};
//************************ �ɹ� �Լ� ���� ���� *************************//

	//problem 1-1
void Person::init(int ID, const char* name, int height)
{
	this->ID = ID; // ID���� Person�� ID�� �ִ´�.
	this->height = height; // height���� Person�� height�� �ִ´�.
	this->name = new char[strlen(name) + 1]; // ���ڿ� ���縦 ���� ���ڿ� ���� +1 ��ŭ �����Ҵ��Ѵ�.
	strcpy_s(this->name, strlen(name) + 1, name); // name�� Person�� name�� strcpy�� ������ �ִ´�.

}
//problem 1-2
void Person::printStudentInfo()
{
	cout <<"ID: "<< getID()<<" name: "<<getName()<<" height: "<<getHeight() << endl;
	//Person�� �������� private���� ����� public �Լ��� �����Ѵ�.
}

//************************ �ɹ� �Լ� ���� �� *************************//


//************************ �Ϲ� �Լ� ���� ���� *************************//
void personSwap(struct Person* a) {
	//problem 1-3
	Person temp; //swap�� ���� temp Person ����
	temp = a[0]; 
	a[0] = a[1];
	a[1] = temp;
	// HW1���� Ȱ���� ����� ���� �������� �Ѱ� �ָ鼭 swap
}
//************************ �Ϲ� �Լ� ���� �� *************************//


int main() {
	Person* p = new Person[2];

	p[0].init(20201125, "wnsh", 33);
	p[1].init(20215214, "jane", 47);

	p[0].printStudentInfo();
	p[1].printStudentInfo();

	personSwap(p);
	cout << "�� ��ȯ ��" << endl;
	p[0].printStudentInfo();
	p[1].printStudentInfo();

	return 0;
}
// Q. no need to use delete[]?

