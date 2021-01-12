#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    cout << max(x, y) + min(x, y) / 10 + min(x, y);
}
