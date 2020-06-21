#include <iostream>
#include <algorithm>
using namespace std;

double expenditure[200001];
int cntArray[201];

int alarm();
double calcMedian(int);

int main() {
	std::ios::sync_with_stdio(false);
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cout << alarm() << "\n";
	}
}

int alarm() {
	int n, d, count = 0;
	double mid = 0;
	cin >> n >> d;

	// √ ±‚»≠
	for (int i = 0; i <= n; i++) {
		expenditure[i] = 0;
	}
	for (int i = 0; i <= 200; i++) {
		cntArray[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> expenditure[i];
	}
	for (int i = 0; i < d; i++) {
		cntArray[(int)expenditure[i]] += 1;
	}

	for (int i = d; i < n; i++) {
		mid = calcMedian(d);
		if ((mid * 2) <= expenditure[i]) {
			count++;
		}
		cntArray[(int)expenditure[i - d]] -= 1;
		cntArray[(int)expenditure[i]] += 1;
	}
	return count;
}

double calcMedian(int d) {
	int cnt = 0;
	double first = 0, second = 0;
	double mid = 0;
	if (d % 2 == 1) {	// »¶ºˆ
		for (int i = 0; i <= 200; i++) {
			cnt = cnt + cntArray[i];
			if (cnt > d / 2) {
				mid = i;
				break;
			}
		}
	}
	else {
		for (int i = 0; i <= 200; i++) {
			cnt += cntArray[i];
			if (cnt >= d / 2 && first == 0) {
				first = i;
			}
			if (cnt >= d / 2 + 1 && second == 0) {
				second = i;
				mid = (first + second) / 2;
				break;
			}
		}
	}
	return mid;
}