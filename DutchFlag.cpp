#include <iostream>
#include <time.h>

void swapChar(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


void swap(int*a, int *b)
{
	int temp = *b; *b = *a; *a = temp;
}

void DutchFlag(int * arr, const size_t arrSize)
{
	
	size_t low = 0, mid = 0, high = arrSize-1;
	for (size_t i = 0; i < arrSize; i++)
	{
		switch(arr[mid])
		{
		case (0) :
			swap(arr + low, arr + mid);
			low++; mid++;
			break;
		case (1) :
			mid++;
			break;
		case (2) :
			swap(arr + mid, arr + high);
			high--;
			break;

		}
	}
}

void permute(char * a, int start, int end)
{
	if (end == start)
	{
		std::cout << a  << std::endl;
	}
	else
	{
		for (int index = start ; index <= end; index++)
		{
			swapChar((a + start ), (a+ index));
			permute(a, start + 1, end);
			swapChar((a + start), (a + index));
		}

	}
}

int main_permutationString()
{
	char name[]= "NAME";
	int len = strlen(name);
	permute(name, 0, len - 1);
	return 0;
}

int main_DutchFlag(int argc, char *argv[])
{
	//int n;
	std::srand(time(nullptr));
	int arr[10];
	//int a = 98, b =18;
	//swap( &a, &b);
	for (size_t i = 0; i < 10; i++)
		arr[i] = std::rand() % 10;
	
	for (int i : arr)
		std::cout << " " << i;

	DutchFlag(arr, 10);

	std::cout << " order array  " << std::endl;
	for (int i : arr)
		std::cout << " " << i;

	return 0;
}