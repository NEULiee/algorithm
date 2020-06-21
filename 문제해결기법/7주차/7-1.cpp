// correct

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> num;
vector<int> answer;

int solve(int);

int main() {
	int T, N, a, b, x, count = 0, input;
	cin >> T;
	while (T--) {
		num.clear();
		answer.clear();
		count = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> input;
			num.push_back(input);
		}
		cin >> a >> b >> x;
		sort(num.begin(), num.end());
		answer.push_back(solve(x));
		while (1) {
			if (next_permutation(num.begin(), num.end()) == false) {
				break;
			}
			answer.push_back(solve(x));
		}
		for (int i = 0; i < answer.size(); i++) {
			if (a <= answer[i] && answer[i] <= b) {
				count++;
			}
		}
		cout << count << "\n";
	}
}

int solve(int x) {
	int size = num.size();
	int ans = 0;
	int temp;
	for (int i = 0; i < size; i++) {
		temp = pow(x, i);
		temp = temp % 1013;
		ans += (num[i] * temp) % 1013;
	}
	return ans % 1013;
}