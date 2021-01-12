#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int N, M, A, B;
int root[100001];
set<int> virus;

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    
    for (int i=0; i<N; i++){
        root[i] = i;
    }
    
    for (int i=0; i<M; i++){
        cin >> A >> B;
        root[B] = root[A];
    }
    
    for (int i=0; i<N; i++){
        virus.insert(root[i]);
    }
    
    cout << virus.size() << "\n";
    
    return 0;
}
