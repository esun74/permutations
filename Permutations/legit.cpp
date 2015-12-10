#include <iostream>
#include <iomanip>
#include <cmath>
#include "timer.h"
using namespace std;

unsigned long long int factorial(int n, int end, int &two);
int reduce(int &temp);

int main()
{
	char response;
	unsigned long long int number;
	int n, e, twoA = 0, twoB = 0;
	do {
		twoA = 0;
		twoB = 0;
		cout << "How many points north of A is B? ";
		cin >> n;
		cout << "How many points east of A is B? ";
		cin >> e;
		Timer t;
		t.start();
		number = (factorial(n + e, n, twoA) / factorial(e, 0, twoB));
		for (int i = 0; i < abs(twoA - twoB); i++)
			number *= 2;
		cout << "There are " << number << " northeast paths between A and B." << endl;
		t.stop();
		t.show();

		cout << "Enter y or Y to continue next example or any other letter to exit: ";
		cin >> response;
		cout << endl;
	} while (toupper(response) == 'Y');
	return 0;
}

unsigned long long int factorial(int n, int end, int &two)
{
	if (n == end) return 1;
	else
	{
		int temp = n;
		two += reduce(temp);
		return temp * factorial(n - 1, end, two);
	}
}

int reduce(int &temp)
{
	if (temp % 2 != 0) return 0;
	else
	{
		temp /= 2;
		return 1 + reduce(temp);
	}
}

/*Execution Sample:
How many points north of A is B? 2
How many points east of A is B? 3
There are 10 northeast paths between A and B.
Process Timer
-------------------------------
Elapsed Time   : 0.002s
Enter y or Y to continue next example or any other letter to exit: y

How many points north of A is B? 12
How many points east of A is B? 14
There are 9657700 northeast paths between A and B.
Process Timer
-------------------------------
Elapsed Time   : 0.002s
Enter y or Y to continue next example or any other letter to exit: y

How many points north of A is B? 16
How many points east of A is B? 16
There are 601080390 northeast paths between A and B.
Process Timer
-------------------------------
Elapsed Time   : 0.003s
Enter y or Y to continue next example or any other letter to exit: n

Press any key to continue . . .
*/
