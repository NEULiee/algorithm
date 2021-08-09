#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int T, N, input;
int dp[9];

int main() {
    cin >> T;
    for (int i=1; i<=T; i++) {
        cin >> N;
        vector<int> requireTime;
        for (int j=0; j<N; j++) {
            cin >> input;
            requireTime.push_back(input);
        }
        sort(requireTime.begin(), requireTime.end());
        
        dp[0] = 0;
        dp[1] = requireTime[0];
        dp[2] = requireTime[1];
        dp[3] = requireTime[0] + requireTime[1] + requireTime[2];
        
        if (N < 4) {
            cout << "#" << i << " " << dp[N] << "\n";
            continue;
        }
        
        for (int j=4; j<=N; j++) {
            dp[j] = dp[j-2] + min(requireTime[1] + requireTime[0] + requireTime[j-1] + requireTime[1],
                                  requireTime[j-1] + requireTime[0] + requireTime[j-2] + requireTime[0]);
        }
        
        cout << "#" << i << " " << dp[N] << "\n";
    }
}
