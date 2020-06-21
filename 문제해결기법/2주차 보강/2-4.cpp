// correct

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct item {
	string name;
	int start;
	int end;
};

bool compare(const item& a, const item& b) {
	return a.end < b.end;
}

item items[10001];

int game(int);

int main() {
	int testCase, n;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> n;
		cout << game(n) << "\n";
	}
}

int game(int n) {
	string name;
	int start, end, tempEnd = 0, result = 0;
	for (int i = 0; i < n; i++) {
		cin >> name;
		cin >> start >> end;
		items[i].name = name;
		items[i].start = start;
		items[i].end = end;
	}

	sort(items, items + n, compare);

	for (int i = 0; i < n; i++) {
		if (tempEnd <= items[i].start) {
			tempEnd = items[i].end;
			result++;
		}
	}

	return result;
}