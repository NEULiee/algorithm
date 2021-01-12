#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> link;

int porting(int);

int main() {
	int N;
	cin >> N;
	cout << porting(N);
}

int porting(int N) {
	int input, size = 0;
	link.push_back(0);
	for (int i = 1; i <= N; i++) {
		cin >> input;
		size = link.size();
		if (link[size - 1] < input) {
			link.push_back(input);
		}
		else {
			vector<int>::iterator it = lower_bound(link.begin(), link.end(), input);
			*it = input;
		}
	}
	size = link.size();

	return size - 1;
}