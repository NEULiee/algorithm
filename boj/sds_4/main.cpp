// appending to string
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> func(vector<int> arr) {
    vector<int> answer;
    
    unordered_map<int, int> m;
    
    for (int i=0; i<(int)arr.size(); i++) {
        m[arr[i]]++;
    }
    
    for (auto &i: m) {
        if (i.second > 1) {
            answer.push_back(i.second);
    
        }
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}

int main ()
{
    vector<int> arr1 = {1, 2, 3, 3, 3, 3, 4, 4};
    vector<int> arr2 = {3, 2, 4, 4, 2, 5, 2, 5, 5};
    
    vector<int> answer = func(arr1);
    
    for (auto i: answer) {
        cout << i << " ";
    }
    cout << "\n";
    
    
    vector<int> answer2 = func(arr2);
    
    for (auto i: answer2) {
        cout << i << " ";
    }
    cout << "\n";
    

}
