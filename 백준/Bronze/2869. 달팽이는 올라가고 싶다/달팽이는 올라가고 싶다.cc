#include <iostream>
using namespace std;
int main()
{
	int A; int B; int V;
	cin >> A >> B >> V;
	int day = (V - A) / (A - B);
	if ((V - A) % (A - B) == 0) day += 1;
	else day += 2;
	cout << day;
}