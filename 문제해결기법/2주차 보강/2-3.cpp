#include <iostream>
#include <string>
using namespace std;

int r_cnt[128];
int w_cnt[128];
int findStr();

int main() {
	std::ios::sync_with_stdio(false);
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cout << findStr() << "\n";
	}
}

int findStr() {
	string S, R;
	cin >> S >> R;
	int start = 0, end = 0, count = 0;
	int w_len = 0, min_len = S.size() + 1;
	for (int i = 0; i < 128; i++) {
		r_cnt[i] = 0;
		w_cnt[i] = 0;
	}

	for (int i = 0; i < R.size(); i++) {
		r_cnt[R[i]] += 1;
	}

	while (end < S.size()) {
		w_cnt[S[end]] += 1;
		// 아직 필요한 문자를 못찾았을 때
		if (r_cnt[S[end]] >= w_cnt[S[end]]) {
			count += 1;
		}
		// 필요한 문자를 다 찾았을 때
		while (count == R.size()) {
			w_len = end - start + 1;
			if (w_len < min_len) {
				min_len = w_len;
			}
			if (r_cnt[S[start]] >= w_cnt[S[start]]) {
				count--;
			}
			w_cnt[S[start]] -= 1;
			start += 1;
		}
		end += 1;
	}
	if (min_len > S.size()) {
		return 0;
	}
	return min_len;
}