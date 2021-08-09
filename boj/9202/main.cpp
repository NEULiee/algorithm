//
//  main.cpp
//  9202 BoggleBoggleBoggleBoggleBoggleBoggleBoggleBoggleBoggleBoggleBoggleBoggleBoggleBoggleBoggleBoggleBoggleBoggleBoggleBoggleBoggleBoggle
//
//  Created by Ha Neul Iee on 2021/07/18.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
using namespace std;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int w, b;
vector<string> words;
char boggle[4][4];
bool visited[4][4];

int maxScore, foundWordCount, longestSize;
string longestWord;
set<string> wordSet;

// 중복 x, 가장 긴 단어는 사전 순으로 앞서는 것
// dfs로 단어조합하기 -> Trie로 있는 단어인지 확인

struct Trie {
    map<char , Trie*> next;
    bool finish = false;
    
    void insert(string& word, int idx) {
        if ((int)word.size() <= idx) {
            this->finish = true;
            return;
        }
        
        map<char, Trie*>::iterator iter = next.find(word[idx]);
        if (iter == next.end()) {
            Trie* newTrie = new Trie();
            next[word[idx]] = newTrie;
            newTrie->insert(word, idx+1);
        }
        else {
            iter->second->insert(word, idx+1);
        }
    }
    
    void search(string& word, int idx) {
        if ((int)word.size() <= idx && this->finish) {
            wordSet.insert(word);
            foundWordCount++;
            maxScore += score[word.size()];
            if (longestSize < word.size()) {
                longestSize = (int)word.size();
                longestWord = word;
            }
            else if (longestSize == (int)word.size()) {
                longestWord = min(longestWord, word);
            }
            return;
        }
        
        for (auto& iter: next) {
            if (iter.first == word[idx]) {
                iter.second->search(word, idx+1);
            }
        }
        return;
    }
};

bool isIn(int row, int col) {
    return row >= 0 && row < 4 && col >= 0 && col < 4;
}

/* Trie 생성 */
Trie trie;

void dfs(string cur, int idx, int row, int col) {
    if (idx >= 8) {
        return;
    }
    trie.search(cur, 0);

    for (int i=0; i<8; i++) {
        int x = row + dx[i];
        int y = col + dy[i];
        
        if (isIn(x, y) && !visited[row][col]) {
            visited[row][col] = true;
            cur += boggle[x][y];
            dfs(cur + boggle[x][y], idx+1, x, y);
            cur.pop_back();
            visited[row][col] = false;
        }
    }
}

int main() {
    cin >> w;
    for (int i=0; i<w; i++) {
        string word;
        cin >> word;
        words.push_back(word);
        trie.insert(word, 0);
    }
    
    cin >> b;
    for (int t=0; t<b; t++) {
        
        maxScore = 0;
        longestSize = 0;
        foundWordCount = 0;
        
        for (int i=0; i<4; i++) {
            string board;
            cin >> board;
            for (int j=0; j<4; j++) {
                boggle[i][j] = board[j];
            }
        }
        
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                
                string s = string(1, boggle[i][j]);
                // string str = to_string(boggle[i][j]);
                
                visited[i][j] = true;
                dfs(s, 0, i, j);
                visited[i][j] = false;
            }
        }
        cout << maxScore << " " << longestWord << " " << wordSet.size() << '\n';
        
    }
    
    return 0;
}
