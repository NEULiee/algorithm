#include <iostream>
#include <cmath>
using namespace std;

double lamp_position[1000001];

int main(int argc, const char * argv[]) {
    int N, M, x;
    double height = 0;
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> x;
        lamp_position[i] = x;
    }
    
    for (int i=0; i<=M; i++) {
        if (M==1) {
            height = max(lamp_position[i], N - lamp_position[i]);
            break;
        }
        if (i==0) {
            height = lamp_position[i];
        }
        else if (i==M){
            height = max(height, N - lamp_position[i-1]);
        }
        else {
            height = max(height, ceil((lamp_position[i] - lamp_position[i-1]) / 2));
        }
    }
    
    cout << height << "\n";
    
    return 0;
}
