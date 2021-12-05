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
	
	coord** a = new coord* [column];//column만큼의 coord 구조체 배열을 생성한다.

	for (int i = 0; i < column; i++) {
		a[i] = new coord[row];//각 column배열에 row만큼의 배열을 생성한다.
	}
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			a[i][j].x = j;//coord.x의 성분 대입
			a[i][j].y = i;//coord.y의 성분 대입
		}
	}
	return a;

	/******************End*******************/
}

void RightAngleChecker(int column, int row, coord** a)
{
	/***************Problem1-2***************/
	coord b[3];//삼각형을 위한 3개의 coord형 변수 선언

	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			cout << "(" << a[i][j].x << ", " << a[i][j].y << ")   ";//(x,y) 출력
		}
		cout << endl;
	}

	cout << "Enter three points : ";
	for (int i = 0; i < 3; i++) {
		cin >> b[i].x >> b[i].y;//3개의 점을 입력받는다.
	}
	cout << "For Coordinates : ";
	for (int i = 0; i < 3; i++) {
		cout << "(" << b[i].x << "," << b[i].y << ")   ";
	}cout << endl;//입력받은 3개의 coord[column][row] x,y좌표를 출력한다.


	for (int i = 0; i < 3; i++) {
		if (b[i].x >= row || b[i].y >= column || b[i].x < 0 || b[i].y < 0) {
			cout << "Allocation Error!" << endl;
			return;
		}
	}//조건에 제시되지는 않았으나, 배열을 초과하면 탈출하게 하였다.

	if (a[b[0].y][b[0].x].x == a[b[1].y][b[1].x].x && a[b[0].y][b[0].x].y == a[b[1].y][b[1].x].y
		|| a[b[1].y][b[1].x].x == a[b[2].y][b[2].x].x && a[b[1].y][b[1].x].y == a[b[2].y][b[2].x].y
		|| a[b[2].y][b[2].x].x == a[b[0].y][b[0].x].x && a[b[2].y][b[2].x].y == a[b[0].y][b[0].x].y
		) {
		cout << "NOT Triangle" << endl;
		return;
	}//조건에 제시되지는 않았으나, 두 점 이상 같은 위치일 경우 함수를 탈출하게 하였다.


	double side1 = pow(a[b[0].y][b[0].x].x - a[b[1].y][b[1].x].x, 2) + pow(a[b[0].y][b[0].x].y - a[b[1].y][b[1].x].y, 2);
	double side2 = pow(a[b[1].y][b[1].x].x - a[b[2].y][b[2].x].x, 2) + pow(a[b[1].y][b[1].x].y - a[b[2].y][b[2].x].y, 2);
	double side3 = pow(a[b[2].y][b[2].x].x - a[b[0].y][b[0].x].x, 2) + pow(a[b[2].y][b[2].x].y - a[b[0].y][b[0].x].y, 2);
	//피타고라스의 정리 a^2+b^2=c^2을 이용하고자 각 변의 길이의 제곱을 구하였다.
	if (side1 + side2 == side3 || side1 + side3 == side2 || side2 + side3 == side1)
		cout << "Right angle triangle" << endl;
	else
		cout << "Non right angle triangle" << endl;
	//구한 값의 어떤 side가 빗변인지 알지 못하므로, 세가지 경우 모두 조건에 넣었다.

	/******************End*******************/
}

void freeCoord(int column, coord** a)
{
	/***************Problem1-3***************/

	for (int i = 0; i < column; i++) {
		delete[] a[i];//메모리해제를 위해 각 column에 있는 row 배열들을 해제한다.
	}

	delete[] a;//column이 할당된 메모리를 해제한다.
	/******************End*******************/
}