#include <iostream>
#include <string.h>
using namespace std;

class IOutput
{
public:
	virtual void Show() = 0;
	virtual void Show(string info) = 0;
};

class IMath
{
public:
	virtual int Max() = 0;
	virtual int Min() = 0;
	virtual float Avg() = 0;
	virtual bool Search(int valueToSearch) = 0;
};

class Array : public IOutput, public IMath
{
	int* arr;
	int size;
public:
	Array() = default;
	Array(const int* a, int s)
	{
		arr = new int[s];
		for (int i = 0; i < s; i++)
		{
			arr[i] = a[i];
		}
		size = s;
	}
	int Max()
	{
		int max = arr[0];
		for (int i = 0; i < size; i++)
		{
			if (max < arr[i])
			{
				max = arr[i];
			}
		}
		return max;
	}
	int Min()
	{
		int min = arr[0];
		for (int i = 0; i < size; i++)
		{
			if (min > arr[i])
			{
				min = arr[i];
			}
		}
		return min;
	}
	float Avg()
	{
		int sum = 0;
		int num = 0;
		float avg = 0;
		for (int i = 0; i < size; i++)
		{
			sum += arr[i];
			num++;
		}
		avg = sum / num;
		return avg;
	}
	bool Search(int valueToSearch)
	{
		for (int i = 0; i < size; i++)
		{
			if (valueToSearch == arr[i])
			{
				return true;
			}
		}
		return false;
	}
	void Show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << "\t";
		}
		cout << endl << endl;
	}
	void Show(string info)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << "\t";
		}
		cout << endl;
		cout << info;
		cout << endl << endl;
	}
	~Array()
	{
		delete[] arr;
	}
};

int main()
{
	const int a[4]{ 1,2,4,5 };
	Array b(a, 4);
	b.Show();
	cout << b.Search(0) << endl;
}