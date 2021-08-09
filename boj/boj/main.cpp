#include<iostream>
#include <stack>

using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);

    for(int test_case = 1; test_case <= 10; ++test_case)
    {
        int n;
        string str;
        stack<char> s;
        cin >> n >> str;
        for (int i=0; i<n; i++) {
            int top = s.top();
            if (s.empty()) {
                s.push(str[i]);
            }
            else if ((top == '(' && str[i] == ')') || (top == '{' && str[i] == '}') || (top == '[' && str[i] == ']') || (top == '<' && str[i] == '>')) {
                s.pop();
            }
            else {
                s.push(str[i]);
            }
        }
        
        if (s.empty()) {
            cout << "#" << test_case << " " << 1 << "\n";
        }
        else {
            cout << "#" << test_case << " " << 0 << "\n";
        }
        
    }
    return 0;
}
