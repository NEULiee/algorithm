#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v1 = {1, 2, 3};

// v1의 값들이 바뀌지 않음
for (int e: v1) {
    e++;
    cout << e << "\n";
}

for (int& e: v1) {
    e++;
    cout << e << "\n";
}
