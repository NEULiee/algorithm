// correct

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int codeword[27][129];
int bit[1025];
int minHamming[27];

void errorCorrection(int, int);

int main() {
	int testCase, M, N;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> M >> N;
		errorCorrection(M, N);
	}
}

void errorCorrection(int M, int N) {
	int bitlen, bitCount = 0, hamming = 0, minimum = 0;
	string input;
	for (int i = 1; i <= M; i++) {
		cin >> input;
		for (int j = 1; j <= N; j++) {
			codeword[i][j] = input[j - 1] - '0';
		}
	}
	cin >> bitlen;
	cin >> input;
	for (int i = 1; i <= bitlen; i++) {
		bit[i] = input[i - 1] - '0';
	}

	bitCount = bitlen / N;
	for (int i = 1; i <= bitCount; i++) {
		minimum = 1025;
		for (int j = 1; j <= M; j++) {
			hamming = 0;
			for (int k = 1; k <= N; k++) {
				if (codeword[j][k] != bit[k + (i - 1) * N]) {
					hamming++;
				}
			}
			if (minimum > hamming) {
				minimum = hamming;
				minHamming[i] = j;
			}
		}
	}

	for (int i = 1; i <= bitCount; i++) {
		cout << char(minHamming[i] + 64);
	}

	cout << "\n";
}