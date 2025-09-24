#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

int main() {
	int n,max,sum=0,min,maxindex,minindex=0;
	const int N=300;
	
	int a[N];
	cout << "choose number of elements" << endl;
	cin >> n;
	maxindex = 0;
	if (n > N or n <= 0) {
		cout << "ARE U OKAY?";
		return 0;
	}
	cout << "Do you want to choose the elements yourself(pick 1) or randomly(pick 2)?";
	int w;
	cin >> w;
	if (w == 1) {
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
	}
	else if (w == 2) {
		srand(time(NULL));
		for (int i = 0; i < n; ++i) {
			a[i] = rand() % 1000-500;
			cout << a[i] << " ";
		}
	}
	else {
		cout << "ARE YOU  CLOWN?";
		return 0;
	}
	cout << endl;

	for (int i = 0; i < n; ++i) {
		if (i==0){
			max = abs(a[i]);
			min = abs(a[i]);
		}
			if (abs(a[i]) > max) {	
				max = abs(a[i]);
				maxindex = i;
			}
			if (abs(a[i]) <min) {
				min = abs(a[i]);
				minindex = i;
			}
	}
	int lastminindex=0;
	for (int i = 0; i < n; i++) {
		if (abs(a[i]) == min)lastminindex = i;
	}
	for (int i = lastminindex+1; i < n; i++) {
		sum += a[i];
	}
	
	cout <<"sum: "<< sum << endl;
	int term = a[maxindex];
	 a[maxindex]=a[minindex];
	 a[minindex] = term;
	 cout << "after swap:" << endl;
	 for (int i = 0; i < n; i++)
	 {
		 cout << a[i] <<" ";
	 }
	 for (int i = 0; i < n; i++) {
		 if (a[i] < 0)a[i] = a[i] * a[i];
	 }
	 cout << endl;
	 cout << "after changing the array:" << endl;
	 for (int i = 0; i < n; i++) {
		 cout << a[i]<<" ";
	 }
	 cout << endl;
	 sort(a, a + n);
	 for (int i = 0; i < n; i++) {
		 cout << a[i] << " ";
	 }
	return 0;
}