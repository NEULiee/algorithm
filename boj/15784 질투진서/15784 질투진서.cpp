#include <iostream>
using namespace std;

int main(int argc, const char * argv[]){
    int N, a, b;
    cin >> N >> a >> b;
    int charm[1001][1001];
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            cin >> charm[i][j];
        }
    }
    for (int j=1; j<=N; j++){
        if (charm[a][j] > charm[a][b] || charm[j][b] > charm[a][b]){
            cout << "ANGRY" << "\n";
            return 0;
        }
    }
    cout << "HAPPY" << "\n";
    return 0;
}
