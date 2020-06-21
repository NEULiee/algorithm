// correct

#include <iostream>
#include <stack>
using namespace std;

int stud[10001];
int visited[10001];
stack<int> s;

int teamMating();

int main() {
	std::ios::sync_with_stdio(false);
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cout << teamMating() << "\n";
	}
}

int teamMating() {
	int N, temp, count = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stud[i];
		visited[i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			s.push(i);
			temp = stud[i];
			while (1) {
				if (visited[temp] == 0) {	// 아직 방문 x
					visited[temp] = 1;
					s.push(temp);
					temp = stud[temp];
				}
				else if (visited[temp] == -1) {
					int p;
					while (1) {
						if (!s.size()) {
							break;
						}
						p = s.top();
						visited[p] = -1;
						s.pop();
					}
					break;
				}
				else if (visited[temp] == 1) {	// 이미 방문 - cycle
					int end = temp;
					bool tf = false;
					int p;
					while (1) {
						if (!s.size()) {
							break;
						}
						p = s.top();
						if (p == temp) {
							visited[p] = 2;
							tf = true;
						}
						else if (tf) {
							visited[p] = -1;
						}
						else {
							visited[p] = 2;
						}
						s.pop();
					}
					break;
				}
				else if (visited[temp] == 2) {
					int p;
					while (s.size()) {
						p = s.top();
						visited[p] = -1;
						s.pop();
					}
					break;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0 || visited[i] == -1) {
			count++;
		}
	}
	return count;
}