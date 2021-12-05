#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void readFile(char*arr,int &arr_count)
{//arr,arr_count를 호출한다. arr_count는 call by reference이다.
	cout << "Trying file load..." << endl; 
	cout << "*========================================*" << endl;

	char ch;
	ifstream enc;		//ifstream타입 변수 생성
	enc.open("Encryption.txt");
	//텍스트 파일을 불러운다.
	if (enc.is_open())
	{//파일이 올바르게 열렸을때 진행된다.
		while (!enc.eof())
		{//파일의 끝까지 실행
			enc.get(ch);//char를 불러온다.
			arr[arr_count] = ch;//arr_count번에 값 저장
			cout << arr[arr_count];//저장된 값 출력
			arr_count++;//arr_count 1증가
		}
		arr_count--;//마지막 arr_count는 필요없으므로 다시 뺀다.
	}
	enc.close();
	cout << endl << "*========================================*" << endl;
	cout << "File Loaded" << endl;
	cout << "arr_count : "<<arr_count << endl;
	cout <<  "*========================================*" << endl;
	return;

}

void decoder(char* arr, int arr_count)
{
	cout << "Trying decode..." << endl;
	int Key;
	cout << "Key 값을 입력해 주십시오 : ";
	cin >> Key;
	cout << "*========================================*" << endl;
	for (int i = 0; i < arr_count; i++)
	{
		if (arr[i] != ' ')//띄어쓰기는 예외처리한다.
			arr[i] = arr[i] + Key;//arr[i]에 Key 값을 더해 변환한다.
		cout << arr[i];//결과값을 확인해 본다.
	}
	cout <<endl<< "*========================================*" << endl;
	cout << "File decoded!" << endl;
	cout << "*========================================*" << endl;

	return;
}

void outFile(char* arr, int arr_count)
{
	cout << "Trying file export..." << endl;
	ofstream res; //ofstream 변수 생성
	res.open("Result.txt");
	//파일명 지정
	if (res.is_open())
	{//올바르게 열렸으면 실행
		res.write(arr, arr_count);
	}//arr[0]부터 arr[arr_count-1]까지 기록
	res.close();

	cout << "output file streamed" << endl;
	cout << "*========================================*" << endl;

	return;
}

int main()
{
	char* arr = new char[1024];
	//문자열을 받을 배열을 동적할당한다.
	int arr_count = 0;
	readFile(arr,arr_count);
	decoder(arr, arr_count);
	outFile(arr, arr_count);
	//main함수에서 각 함수를 호출한다.
	delete[] arr;
	//동적할당을 해제한다.
	return 0;
}// -4가 올바른 key이다.