#pragma once
#include<iostream>
using namespace std;

#include "pet.h"
#include "ILandAnimal.h"

class Cat:public Pet, public ILandAnimal
{
public:
	Cat(string name="noname", PetKind kind=UNKNOWN, age_t age=0):Pet(name,kind,age){}
	virtual void eat(){cout<<"����� ���̸� �Խ��ϴ�"<<endl;}
	virtual void creep(){cout<<"�� ������ ��ӻ�� �Ƚ��ϴ�"<<endl;}
};