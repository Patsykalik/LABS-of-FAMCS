#include <iostream>
using namespace std;
void showmatrix(int** a,int &n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Введите размеры квадратной матрицы:" << endl;
	cin >> n;
	cout << endl;
	if (n > 10) {
		cout << "Сторона матрицы не превосходит 10!!!";
		return 0;
	}
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i; j++) {
			cin >> a[i][j];
			a[n - 1 - j][n - 1 - i] = a[i][j];
		}
	}
	showmatrix(a, n);
	int product=1;
	bool negative = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] >= 0)product *= a[i][j];
			else {
				negative = true;
				break;
			}
		}
		if (negative==false)
		cout << product << endl;
		product = 1;
		negative = false;
	}
	int mindiagonal=0, sum = 0;
	for (int j = 0; j < n; j++) {


		for (int i = 0; i < n; i++) {
			if (i + j <= n - 1)
				sum += a[i][i + j];
			else break;
		}
		if (j == 0)mindiagonal = sum;
		else {
			if (mindiagonal > sum)mindiagonal = sum;
			
		}
		sum = 0;
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (i + j <= n - 1)
				sum += a[i + j][i];
			else break;
		}
		if (mindiagonal > sum)mindiagonal = sum;
		sum = 0;
	}
	cout << endl<<"Минимальная диагональ равна:"<<endl;
	cout << mindiagonal;
	for (int i = 0; i < n; i++){
		delete[] a[i];
	}
	delete[] a;
	return 0;
}