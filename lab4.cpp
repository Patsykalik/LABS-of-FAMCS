#include <iostream>
#include <algorithm>

using namespace std;
bool isnumber(char char1) {
	if ('0' <= char1 and char1 <= '9')return true;
	else return false;
}
int strSpn(const char* string, const char* strcharset) {
	bool has = false;
	int answer = 0;
	for (int i = 0; string[i] != '\0'; ++i) {
		for (int j = 0; strcharset[j] != '\0'; ++j) {
			if (string[i] == strcharset[j]) has = true;
		}
		if (has == true) {
			answer++;
			has = false;
		}
	}
	return answer;
}
int main() {
	char answer[300][300];
	int o = 0;
	char strcharset[300] = "";
	char string[300] = "";
	cout << "choose the strcharset" << endl;
	cin.getline(strcharset, 300);
	cout << "choose the string" << endl;
	cin.getline(string, 300);
	int index = 0, d = 0, words = 0;
	for (int i = 0; i < 300; i++) {
		if (string[i] == ' ') {
			words++;
			index = 0;
		}
		else {
			answer[words][index] = string[i];
			index++;
		}
	}
	d = 0;
	o = 0;
	bool fine = true;
	int indexlast = 0;
	int indexprelast = 0;
	cout << "tusk A:" << endl;
	cout << strSpn(string, strcharset);
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			if (answer[i][j] >= 32 and answer[i][j] <= 126) {
				if (!isnumber(answer[i][j])) {
					fine = false;
				}
				else if (answer[i][j] == '0')o++;
			}

		}if (fine == true) {
			if (o > d) {
				d = o;
				indexlast = i;
				indexprelast = 0;
				o = 0;
			}
			else if (o == d and o != 0) {
				d = o;
				indexprelast = indexlast;
				indexlast = i;
				o = 0;
			}
		}
		fine = true;
		o = 0;
	}
	cout <<endl<<"tusk B:"<<endl;
	if (indexprelast != 0) {
		for (int i = 0; i < 300; i++) {
			if (answer[indexprelast][i] < 32 or answer[indexprelast][i]>126) {
				continue;
			}
			else
				cout << answer[indexprelast][i];
		}
	}
	else for (int i = 0; i < 300; i++) {
		if (answer[indexlast][i] < 32 or answer[indexlast][i]>126) {
			continue;
		}
		else
			cout << answer[indexlast][i];
	}

}