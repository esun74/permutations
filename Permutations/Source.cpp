#include <iostream>
#include <iomanip>
#include <list>
#include "timer.h"
using namespace std;

unsigned long long int countpaths(list<bool> &paths);
bool inorder(list<bool> &paths);
void nextpath(list<bool> &paths);
void listswap(list<bool> &paths, list<bool>::reverse_iterator it, list<bool>::reverse_iterator it2);

int main()
{
	char response;

	int n, e;
	do {
		cout << "How many points north of A is B? ";
		cin >> n;
		cout << "How many points east of A is B? ";
		cin >> e;
		list<bool> paths;
		for (int i = 0; i < n; i++)
			paths.push_back(false);
		for (int i = 0; i < e; i++)
			paths.push_back(true);

		Timer t;
		t.start();

		cout << "There are " << countpaths(paths) << " northeast paths between A and B." << endl;
		t.stop();
		cout << "Process Timer" << endl << "------------------------------------------" << endl;
		cout << "Elapsed Time: ";
		t.show();

		cout << "Enter y or Y to continue next example or any other letter to exit: ";
		cin >> response;
	} while (toupper(response) == 'Y');


	return 0;
}


unsigned long long int countpaths(list<bool> &paths)
{
	unsigned long long int count = 0;
	while (!inorder(paths)) {
		nextpath(paths);
		for (list<bool>::iterator it = paths.begin(); it != paths.end(); it++)
			cout << static_cast<int>(*it);
		count++;
		cout << "     " << count;
		cout << endl;
	}
	return count;
}

bool inorder(list<bool> &paths)
{
	list<bool>::iterator it, it2;
	it = it2 = paths.begin();
	it++;
	while (it != paths.end())
	{
		if (*it > *it2) return false;
		it++; it2++;
	}
	return true;
}

void nextpath(list<bool> &paths)
{
	list<bool>::reverse_iterator it = paths.rbegin();
	if (*it)
	{
		while (*it) it++;
		list<bool>::reverse_iterator it2 = it; it2--;
		listswap(paths, it, it2);
	}
	else
	{
		list<bool>::reverse_iterator it2;
		while (!*it) it++;
		while (*it) it++;
		it2 = it; it2--;
		listswap(paths, it, it2);
		it = paths.rbegin(); it2--;
		while (it != it2)
		{
			listswap(paths, it, it2);
			if (it == it2) break;
			it++;
			if (it == it2) break;
			it2--;
		}
	}
}

void listswap(list<bool> &paths, list<bool>::reverse_iterator it, list<bool>::reverse_iterator it2)
{
	bool temp = *it;
	*it = *it2;
	*it2 = temp;
}