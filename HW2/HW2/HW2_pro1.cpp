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

	//************ 구현할 함수 추가 *******************//

	//problem 1-1
	void init(int ID, const char* name, int height);
	//problem 1-2
	void printStudentInfo();
	//************ 구현할 함수 추가 *******************//


private:
	int ID;
	int height;
	char* name;

};
//************************ 맴버 함수 구현 시작 *************************//

	//problem 1-1
void Person::init(int ID, const char* name, int height)
{
	this->ID = ID; // ID값을 Person의 ID에 넣는다.
	this->height = height; // height값을 Person의 height에 넣는다.
	this->name = new char[strlen(name) + 1]; // 문자열 복사를 위해 문자열 길이 +1 만큼 동적할당한다.
	strcpy_s(this->name, strlen(name) + 1, name); // name을 Person의 name에 strcpy로 복사해 넣는다.

}
//problem 1-2
void Person::printStudentInfo()
{
	cout <<"ID: "<< getID()<<" name: "<<getName()<<" height: "<<getHeight() << endl;
	//Person의 변수값이 private임을 고려해 public 함수로 접근한다.
}

//************************ 맴버 함수 구현 끝 *************************//


//************************ 일반 함수 구현 시작 *************************//
void personSwap(struct Person* a) {
	//problem 1-3
	Person temp; //swap을 위해 temp Person 생성
	temp = a[0]; 
	a[0] = a[1];
	a[1] = temp;
	// HW1에서 활용한 방법과 같이 변수값을 넘겨 주면서 swap
}
//************************ 일반 함수 구현 끝 *************************//


int main() {
	Person* p = new Person[2];

	p[0].init(20201125, "wnsh", 33);
	p[1].init(20215214, "jane", 47);

	p[0].printStudentInfo();
	p[1].printStudentInfo();

	personSwap(p);
	cout << "값 교환 후" << endl;
	p[0].printStudentInfo();
	p[1].printStudentInfo();

	return 0;
}
// Q. no need to use delete[]?

