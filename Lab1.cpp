#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
	int i=0,k,n = 0;
	long double x,  answer = 0, chlen = 1;
	cin >> x >> k;
	if (x == 0)
	{
		cout << "x cannot be equal to zero" << endl;
		return 0;
	}
	double long x2 = x * x;
	while (abs(chlen) > pow(10, -k)){
		if (i == 0)
			answer += chlen;
		else {
			chlen *= (-1) * x2 / ((i * 2) * (2 * i + 1));
			answer += chlen;
		}
		i++;
		}
		
	
	cout << setprecision(k) << fixed << answer << endl;
	cout << setprecision(k) << fixed << sin(x) / x << endl;
	return 0;
}