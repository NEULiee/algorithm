#include <iostream>
using namespace std;

int arr[100000];

int subsum(int, int);

int main() {
	int N, S;
	cin >> N >> S;
	cout << subsum(N, S);
}

int subsum(int N, int S) {
	int input, start = 0, end = 0, sum = 0, len = 100000;

	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[i] = input;
	}

	sum = arr[start];

	while (end < N && start <= end) {
		if (sum < S) {
			end++;
			if (end >= N) {
				break;
			}
			sum += arr[end];
		}
		 else if (sum == S) {
			if (len > (end - start + 1)) {
				len = end - start + 1;
			}
			end++;
			sum += arr[end];
		}
		else if (sum > S) {
			if (len > (end - start + 1)) {
				len = end - start + 1;
			}
	
			sum -= arr[start];
			start++;

			if (start > end && start < N) {
				end = start;
				sum = arr[end];
			}
		}
	}

	if (len == 100000) {
		return 0;
	}
	else {
		return len;
	}
}