#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int A[1000];
int B;

void multiple();
int digits(int);

int main() {
	std::ios::sync_with_stdio(false);
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		multiple();
	}
}

void multiple() {
	string input;
	int digit = 0, tempA = 0, remainder = 0, now = 0;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		A[i] = input[i] - '0';
	}
	cin >> B;
	digit = digits(B);

	for (int i = 0; i < digit; i++) {
		tempA += A[i] * pow(10, digit - i - 1);
		now++;
	}

	while (1) {
		remainder = tempA % B;
		tempA = remainder * 10 + A[now];
		if (now >= input.size() && remainder < B) {
			if (remainder == 0) {
				cout << 1 << "\n";
				return;
			}
			else {
				cout << 0 << "\n";
				return;
			}
		}
		now++;
	}
}

int digits(int B) {
	if ((B / 10000) > 0) {
		return 5;
	}
	else if ((B / 1000) > 0) {
		return 4;
	}
	else if ((B / 100) > 0) {
		return 3;
	}
	else if ((B / 10) > 0) {
		return 2;
	}
	else {
		return 1;
	}
}