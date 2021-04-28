#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;

class Solution_2 {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        
        // 将所有单词加入到 wordSet 方便搜索一个单词是否在当前列表内
        unordered_set<string> wordSet;
        for (const auto &word : wordList) {
            wordSet.insert(word);
        }
        // 特判：endWord 不在 wordSet 中
        if (!wordSet.count(endWord)) {
            return res;
        }

        // 移除开始和结束单词节点
        wordSet.erase(beginWord);
        wordSet.erase(endWord);

        // 定义「从起点单词开始进行 BFS 所扫描的单词」和「从终点单词开始进行 BFS 所扫描的单词」
        unordered_set<string> q1 {beginWord};
        unordered_set<string> q2 {endWord};

        // 定义邻接表
        // key: word
        // value: 和 word 只差一个字符的单词
        unordered_map<string, vector<string>> adjacencyList;

        bool reversed = false;  // 表示 run BFS 的方向
        bool found = false;     // 判断当前是否找到了一条合法的 beginWord -> endWord 路径

        // 开始 BFS（默认从 beginSet 开始）
        while (!q1.empty()) {
            unordered_set<string> visited;  // 记录本轮 BFS 访问过的单词节点

            for (const string &word : q1) {
                string changed_word = word;    // 创建临时变量，并在 w 上的每一位做修改 (trial and error)
                
                for (size_t i = 0; i < word.size(); i++) {
                    char ch = changed_word[i]; // 先做一份当前字符位的备份

                    // 每一位字符尝试 26 个字符
                    for (int j = 0; j < 26; j++) {
                        char newChar = 'a' + j;
                        // if (newChar == ch) {
                        //     continue;
                        // }
                        // 将 changed_word 的第 i 位换一个字符，并在 endSet 中查看是否已经扩展到这个新的单词
                        changed_word[i] = newChar;

                        if (q2.count(changed_word)) {
                            reversed ? adjacencyList[changed_word].push_back(word) : adjacencyList[word].push_back(changed_word);
                            found = true;
                        }

                        if (wordSet.count(changed_word)) {
                            // 走到这里说明当前 beginSet 和 endSet 还没有交叉，且当前 wordList 中有更改字符后的单词，那么就根据 BFS run 的方向将单词(word/changed_word)加入另一个单词(changed_word/word)的邻接表中
                            reversed ? adjacencyList[changed_word].push_back(word) : adjacencyList[word].push_back(changed_word);
                            visited.insert(changed_word);
                        }
                    }
                    // 注意：这里不能直接根据 found == true 然后 break，因为当前 BFS round 还没有 run 完，所以当前 BFS 当前 level 上的单词节点可能还存在同样最短距离的路径解
                    // if (found == true) {
                    //     break;
                    // }

                    // 注意这里需要恢复 changed_word[i] 回原字符
                    changed_word[i] = ch;
                }
            }

            // 走到这里说明：当前 BFS round 已经 run 完了
            // 首先判断当前是否已经找到了最短路径
            if (found == true) {
                break;
            }

            // 将 visited 中的单词全部从 wordSet 中移除掉，一是避免兜圈，二是当前到达每个单词节点的路径一定是最短的路径（如果之后有其他单词同样能到某个本轮已经访问过的单词节点，那么路径距离一定比本轮的要长）
            for (const string &word : visited) {
                wordSet.erase(word);
            }

            // 更新 q1, q2 并根据节点数量决定下一轮从哪一端开始 run BFS
            if (visited.size() <= q2.size()) {
                q1 = visited;
            } else {
                reversed = !reversed;
                q1 = q2;
                q2 = visited;
            }

        }

        if (found == true) {
            vector<string> path {beginWord};
            // 回溯找到所有最短的路径解
            backtracking(beginWord, endWord, adjacencyList, path, res);
        }
            
        return res;
    }

private:
    void backtracking(const string &src, const string &dest, unordered_map<string, vector<string>> &adjacencyList, vector<string> &path, vector<vector<string>> &res) {
        if (src == dest) {
            // 找到一条最短路径解
            res.push_back(path);
            return;
        }
        
        for (const auto &nextWord : adjacencyList[src]) {
            // 修改当前节点状态
            path.push_back(nextWord);   

            // 递归子节点
            backtracking(nextWord, dest, adjacencyList, path, res); 

            // 恢复当前节点状态
            path.pop_back();
        }
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
// 这个解法与参考解法思路相同，永远用 q1 代表下次 run BFS 的节点集（有可能是 beginSet 也有可能是 endSet）；
// 用 reversed 表示当前 run BFS 的方向。
//      1. reversed == true 说明当前 q1 == beginSet，当前是从 beginWord -> endWord 方向 run BFS；
//      2. reversed == false 说明当前 q1 == endSet，当前是从 endWord -> beginWord 方向 run BFS
// 个人感觉这个解法不如 Soln_1 写法方便理解
// 若理解思路，先看 Soln_1 在看 Soln_2 比较好

