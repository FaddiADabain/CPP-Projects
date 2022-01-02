#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void print(int[], int);
int linearSearch(int[], int, int);

int main()
{
	srand((unsigned)time(0));
	int arr[15];
	int random;

	for (int i = 0; i < 15; i++)
	{
		random = rand() % 21;
		arr[i] = random - 10;
	}

	print(arr, 15);
	linearSearch(arr, 15, -8);

}

void print(int X[], int size)
{

	for (int i = 0; i < size; i++)
		cout << X[i] << " ";
	cout << "\n";

}

int linearSearch(int list[], int size, int value)
{
	bool found = false;
	int position = -1;
	int index = 0;

	while (index < size && !found)
	{

		if (list[index] == value)
		{
			found = true;
			position = index;
			cout << "The number " << value << " was found  at index: " << position << endl;
		}
		++index;

	}

	cout << "Comparisons made: " << index << endl;

	return position;
}
