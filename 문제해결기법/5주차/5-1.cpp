#include <iostream>
#include <string>
using namespace std;

char arr[10001];

void palindrome();

int main() {
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		palindrome();
	}
}

void palindrome() {
	string input;
	int cnt = 0;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'a' && input[i] <= 'z') {
			arr[cnt] = input[i];
			cnt++;
		}
		else if (input[i] >= 'A' && input[i] <= 'Z') {
			arr[cnt] = input[i] + 32;
			cnt++;
		}
		else {
		}
	}

	if (cnt == 1) {
		cout << "Yes" << "\n";
		return;
	}
	for (int i = 0; i < cnt / 2; i++) {
		if (arr[i] == arr[cnt - i - 1]) {
			continue;
		}
		else {
			cout << "No" << "\n";
			return;
		}
	}
	cout << "Yes" << "\n";
}