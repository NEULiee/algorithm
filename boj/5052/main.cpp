#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

struct Trie {
    map<char, Trie*> next;
    bool finish = false;
    bool edge = false;
    
    ~Trie () {
        next.clear();
    }
    
    void insert(string& numbers, int index) {
        if ((int)numbers.size() <= index) {
            this->finish = true;
            
            if ((int)this->next.size() == 0) {
                this->edge = true;
            }
            
            return;
        }
        
        this->edge = false;
        
        map<char, Trie*>::iterator nextTrie = next.find(numbers[index]);
        if (nextTrie == next.end()) {
            Trie* newTrie = new Trie();
            next[numbers[index]] = newTrie;
            newTrie->insert(numbers, index + 1);
        }
        else {
            nextTrie->second->insert(numbers, index + 1);
        }
    }
    
    void havePrepix(bool& answer) {
        for (auto& iter: next) {
            if (this->finish && !(this->edge)) {
                answer = false; return;
            }
            else {
                iter.second->havePrepix(answer);
            }
        }
        return;
    }
};

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    Trie phoneBookTrie;
    for (int i=0; i<(int)phone_book.size(); i++) {
        phoneBookTrie.insert(phone_book[i], 0);
    }
    
    phoneBookTrie.havePrepix(answer);
    return answer;
}

int main() {
    int t, n;
    string input;
    vector<string> phone_book;
    
    cin >> t;
    
    while(t--) {
        cin >> n;
        phone_book.clear();
        while(n--) {
            cin >> input;
            phone_book.push_back(input);
        }
        if (solution(phone_book) == true) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
