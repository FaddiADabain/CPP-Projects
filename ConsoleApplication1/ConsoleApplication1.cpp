#include <iostream>
using namespace std;

int multiply(int, int);

int main()
{
	cout << multiply(5, 10);
}

int multiply(int x, int y)
{
	if (x == 1)
		return y;
	else
		y += multiply(x - 1, y);
}
