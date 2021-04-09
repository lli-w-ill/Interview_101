#include <algorithm>    // std::find
#include <deque>
#include <string>
#include <vector>
#include <set>

using std::find;
using std::deque;
using std::string;
using std::vector;
using std::set;


class Solution_1 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            // endWord 不在 wordList 中
            return 0;
        }

        int distance = 1;
        
        // 单词库
        set<string> wordDict (wordList.begin(), wordList.end());
        // 要访问的单词队列
        deque<string> deq;
        deq.push_back(beginWord);

        while (!deq.empty()) {
            int size = deq.size();    // 当前层的节点数

            for (int i = 0; i < size; i++) {
                string word = deq.front();
                deq.pop_front();

                if (word == endWord)
                    return distance;
                
                // 将与 word 相差一个字符的其他单词加入到 deq 中
                addNeighborWords(word, wordDict, deq);
            }

            distance ++;
        }

        return 0;
    }

private:
    void addNeighborWords(string &word, set<string> &wordDict, deque<string> &deq) {
        for (int i = 0; i < word.size(); i++) {
            char backup = word[i];
            
            for (int j = 0; j < 26; j++) {
                // 改变一个字符
                char newChar = (char) ('a' + j);

                if (newChar != backup) {
                    word[i] = newChar;
                    // 看是否在 wordDict 中存在
                    if (wordDict.find(word) != wordDict.end()) {
                        // 加入改变单个字符后的新单词（下一层的新节点）
                        deq.push_back(word);
                        // 并从 wordDict 删除这个单词（避免之后重复加入导致死循环）
                        wordDict.erase(word);
                    }
                }                
            }

            // 恢复 word
            word[i] = backup;
        }

        // 最后需要将 word 从 wordDict 中移除，避免被重复加入
        wordDict.erase(word);
    }
};
