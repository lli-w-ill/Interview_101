#include <iostream>
#include <algorithm>    // std::find
#include <vector>
#include <queue>
#include <set>

using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::set;
using std::find;

class Solution_2 {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        int len = nums.size();
        if (len == 0) {
            return res;
        }

        queue<vector<int> > que;
        vector<int> cur;
        que.push(cur);
        int cnt = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                vector<int> temp = que.front();
                que.pop();
                for (int i = 0; i < nums.size(); i++) {
                    // vector没有独自的find方法，需要用std::find
                    if (find(temp.begin(), temp.end(), nums[i]) == temp.end()) {
                        // num 不在 temp 中
                        vector<int> t (temp);
                        t.push_back(nums[i]);
                        que.push(t);
                    }
                }
                if (temp.size() == len) {
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};

// 吃一堑：set是不维持原进入顺序的，即使3先于1加入到set，但是加入1后的结果可能是{1,3}，也有可能是{3,1}，一开始用queue<set<int>> que时在这里卡了很久。。
// 看完题解 https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/ 视频才发现BFS也可以解这道题。
// 反思：我觉得这个解法可以再优化，因为每次调用std::find都有O(n)的时间，这个地方应该可以像Soln_3用used空间换时间，但暂时没有特别好的想法。。而且36行vector<int> t(temp); 每次拷贝一次这里能不能也可以优化？
