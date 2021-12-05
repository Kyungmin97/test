#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

struct coord
{
	int x;
	int y;
};
coord** mallocCoord(int column, int row);
void RightAngleChecker(int column, int row, coord** a);
void freeCoord(int column, coord** a);

int main()
{
	int column = 0;
	int row = 0;
	cout << "Enter height of area : ";
	cin >> column;
	cout << "Enter width of area : ";
	cin >> row;
	coord** a = mallocCoord(column, row);
	cout << "<Right angle example>" << endl;
	RightAngleChecker(column, row, a);
	cout << "\n" << "<Non right angle example>" << endl;
	RightAngleChecker(column, row, a);
	freeCoord(column, a);
	return 0;

}


coord** mallocCoord(int column, int row)
{
	/***************Problem1-1***************/
	
	coord** a = new coord* [column];//column��ŭ�� coord ����ü �迭�� �����Ѵ�.

	for (int i = 0; i < column; i++) {
		a[i] = new coord[row];//�� column�迭�� row��ŭ�� �迭�� �����Ѵ�.
	}
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			a[i][j].x = j;//coord.x�� ���� ����
			a[i][j].y = i;//coord.y�� ���� ����
		}
	}
	return a;

	/******************End*******************/
}

void RightAngleChecker(int column, int row, coord** a)
{
	/***************Problem1-2***************/
	coord b[3];//�ﰢ���� ���� 3���� coord�� ���� ����

	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			cout << "(" << a[i][j].x << ", " << a[i][j].y << ")   ";//(x,y) ���
		}
		cout << endl;
	}

	cout << "Enter three points : ";
	for (int i = 0; i < 3; i++) {
		cin >> b[i].x >> b[i].y;//3���� ���� �Է¹޴´�.
	}
	cout << "For Coordinates : ";
	for (int i = 0; i < 3; i++) {
		cout << "(" << b[i].x << "," << b[i].y << ")   ";
	}cout << endl;//�Է¹��� 3���� coord[column][row] x,y��ǥ�� ����Ѵ�.


	for (int i = 0; i < 3; i++) {
		if (b[i].x >= row || b[i].y >= column || b[i].x < 0 || b[i].y < 0) {
			cout << "Allocation Error!" << endl;
			return;
		}
	}//���ǿ� ���õ����� �ʾ�����, �迭�� �ʰ��ϸ� Ż���ϰ� �Ͽ���.

	if (a[b[0].y][b[0].x].x == a[b[1].y][b[1].x].x && a[b[0].y][b[0].x].y == a[b[1].y][b[1].x].y
		|| a[b[1].y][b[1].x].x == a[b[2].y][b[2].x].x && a[b[1].y][b[1].x].y == a[b[2].y][b[2].x].y
		|| a[b[2].y][b[2].x].x == a[b[0].y][b[0].x].x && a[b[2].y][b[2].x].y == a[b[0].y][b[0].x].y
		) {
		cout << "NOT Triangle" << endl;
		return;
	}//���ǿ� ���õ����� �ʾ�����, �� �� �̻� ���� ��ġ�� ��� �Լ��� Ż���ϰ� �Ͽ���.


	double side1 = pow(a[b[0].y][b[0].x].x - a[b[1].y][b[1].x].x, 2) + pow(a[b[0].y][b[0].x].y - a[b[1].y][b[1].x].y, 2);
	double side2 = pow(a[b[1].y][b[1].x].x - a[b[2].y][b[2].x].x, 2) + pow(a[b[1].y][b[1].x].y - a[b[2].y][b[2].x].y, 2);
	double side3 = pow(a[b[2].y][b[2].x].x - a[b[0].y][b[0].x].x, 2) + pow(a[b[2].y][b[2].x].y - a[b[0].y][b[0].x].y, 2);
	//��Ÿ����� ���� a^2+b^2=c^2�� �̿��ϰ��� �� ���� ������ ������ ���Ͽ���.
	if (side1 + side2 == side3 || side1 + side3 == side2 || side2 + side3 == side1)
		cout << "Right angle triangle" << endl;
	else
		cout << "Non right angle triangle" << endl;
	//���� ���� � side�� �������� ���� ���ϹǷ�, ������ ��� ��� ���ǿ� �־���.

	/******************End*******************/
}

void freeCoord(int column, coord** a)
{
	/***************Problem1-3***************/

	for (int i = 0; i < column; i++) {
		delete[] a[i];//�޸������� ���� �� column�� �ִ� row �迭���� �����Ѵ�.
	}

	delete[] a;//column�� �Ҵ�� �޸𸮸� �����Ѵ�.
	/******************End*******************/
}