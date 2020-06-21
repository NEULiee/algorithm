#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2;
int len[1001][1001];

int lcs();

int main() {
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cout << lcs() << "\n";
	}
}

int lcs() {
	cin >> str1 >> str2;
	int size1 = str1.size();
	int size2 = str2.size();

	for (int i = 1; i <= size1; i++) {
		for (int j = 1; j <= size2; j++) {
			len[i][j] = 0;
		}
	}

	for (int i = 1; i <= size1; i++) {
		for (int j = 1; j <= size2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				len[i][j] = len[i - 1][j - 1] + 1;
			}
			else {
				len[i][j] = max(len[i - 1][j], len[i][j - 1]);
			}
		}
	}
	return len[size1][size2];
}