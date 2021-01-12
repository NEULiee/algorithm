#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int A, B;
    string C;
    cin >> A >> B >> C;
    
    if ((C[C.length() - 1] - '0') % 2){
        cout << (A^B) << "\n";
    }
    else {
        cout << A << "\n";
    }
    return 0;
}
