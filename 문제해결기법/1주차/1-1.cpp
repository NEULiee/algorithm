// correct

#include <iostream>
#include <string>
using namespace std;

char gene[51][1001];
int geneCount[4];
char result[1001];

void hamming(int, int);

int main() {
	int testCase, M, N;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> M >> N;
		hamming(M, N);
	}
}

void hamming(int M, int N) {
	string input;
	int max;
	for (int i = 1; i <= M; i++) {
		cin >> input;
		for (int j = 1; j <= N; j++) {
			gene[i][j] = input[j - 1];
		}
	}

	for (int j = 1; j <= N; j++) {
		for (int i = 0; i < 4; i++) {
			geneCount[i] = 0;
		}
		for (int i = 1; i <= M; i++) {
			// A, C, G, T
			if (gene[i][j] == 'A') {
				geneCount[0]++;
			}
			else if (gene[i][j] == 'C') {
				geneCount[1]++;
			}
			else if (gene[i][j] == 'G') {
				geneCount[2]++;
			}
			else if (gene[i][j] == 'T') {
				geneCount[3]++;
			}
		}
		max = 0;
		for (int k = 0; k < 4; k++) {
			if (geneCount[k] > max) {
				if (k == 0) {
					max = geneCount[k];
					result[j] = 'A';
				}
				if (k == 1) {
					max = geneCount[k];
					result[j] = 'C';
				}
				if (k == 2) {
					max = geneCount[k];
					result[j] = 'G';
				}
				if (k == 3) {
					max = geneCount[k];
					result[j] = 'T';
				}
			}
		}
	}

	int h = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (result[j] != gene[i][j]) {
				h++;
			}
		}
	}

	for (int j = 1; j <= N; j++) {
		cout << result[j];
	}
	cout << "\n";
	cout << h << "\n";

}