#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void readFile(char*arr,int &arr_count)
{//arr,arr_count�� ȣ���Ѵ�. arr_count�� call by reference�̴�.
	cout << "Trying file load..." << endl; 
	cout << "*========================================*" << endl;

	char ch;
	ifstream enc;		//ifstreamŸ�� ���� ����
	enc.open("Encryption.txt");
	//�ؽ�Ʈ ������ �ҷ����.
	if (enc.is_open())
	{//������ �ùٸ��� �������� ����ȴ�.
		while (!enc.eof())
		{//������ ������ ����
			enc.get(ch);//char�� �ҷ��´�.
			arr[arr_count] = ch;//arr_count���� �� ����
			cout << arr[arr_count];//����� �� ���
			arr_count++;//arr_count 1����
		}
		arr_count--;//������ arr_count�� �ʿ�����Ƿ� �ٽ� ����.
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
	cout << "Key ���� �Է��� �ֽʽÿ� : ";
	cin >> Key;
	cout << "*========================================*" << endl;
	for (int i = 0; i < arr_count; i++)
	{
		if (arr[i] != ' ')//����� ����ó���Ѵ�.
			arr[i] = arr[i] + Key;//arr[i]�� Key ���� ���� ��ȯ�Ѵ�.
		cout << arr[i];//������� Ȯ���� ����.
	}
	cout <<endl<< "*========================================*" << endl;
	cout << "File decoded!" << endl;
	cout << "*========================================*" << endl;

	return;
}

void outFile(char* arr, int arr_count)
{
	cout << "Trying file export..." << endl;
	ofstream res; //ofstream ���� ����
	res.open("Result.txt");
	//���ϸ� ����
	if (res.is_open())
	{//�ùٸ��� �������� ����
		res.write(arr, arr_count);
	}//arr[0]���� arr[arr_count-1]���� ���
	res.close();

	cout << "output file streamed" << endl;
	cout << "*========================================*" << endl;

	return;
}

int main()
{
	char* arr = new char[1024];
	//���ڿ��� ���� �迭�� �����Ҵ��Ѵ�.
	int arr_count = 0;
	readFile(arr,arr_count);
	decoder(arr, arr_count);
	outFile(arr, arr_count);
	//main�Լ����� �� �Լ��� ȣ���Ѵ�.
	delete[] arr;
	//�����Ҵ��� �����Ѵ�.
	return 0;
}// -4�� �ùٸ� key�̴�.