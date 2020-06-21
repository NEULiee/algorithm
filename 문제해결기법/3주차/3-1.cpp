// correct

#include <iostream>
using namespace std;

int cart[10001];

int hanoi();

int main() {
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cout << hanoi() << "\n";
	}
}

int hanoi() {
	int n, input, count = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		cart[input] = i;
	}
	for (int i = n - 1; i >= 1; i--) {
		if (cart[i + 1] > cart[i]) {
			count++;
		}
	}
	return count + 1;
}