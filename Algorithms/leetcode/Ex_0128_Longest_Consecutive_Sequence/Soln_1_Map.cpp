#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution_1 {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, bool> hs;
        int max = INT_MIN;
        int min = INT_MAX;
        int res = 0;
        // 首先遍历nums，将所有出现的值在hs中标记
        // for (int num : nums) {   // enhanced for loop 在我的编译器里提示错误！啊嘞嘞？
        for (int i = 0; i < nums.size(); i++) {
            // hs.insert_or_assign({num, true});    // c++17
            // hs.insert({nums[i], true});  // 这行居然也提示错误。。改成std::pair了
            hs.insert(std::pair<int, bool>(nums[i], true));
            if (nums[i] > max) {
                max = nums[i];
            }
            if (nums[i] < min) {
                min = nums[i];
            }
        }
        // 然后遍历所有[min ... max]的值，一次在hs中查找是否为true
        // 如果有，则累计当前的连续序列长度
        // 如果没有，则比较当前的连续序列长度和历史最长长度，判断是否更新
        int seqLen = 0;
        for (int i = min; i <= max + 1; i++) {  // 这里i一直取到max+1，是因为如果nums中所有的值都在最长连续序列中，只取到max的话res就不会在for循环中更新，需要在for之后再加一个if判断，所以这里为了省掉for循环后的if判断，就多循环一次
            if (hs.find(i) != hs.end()) {
                seqLen += 1;
            } else {
                if (seqLen > res) {
                    res = seqLen;
                }
                seqLen = 0;
            }
        }
        return res;
    }
};

// C++ STL std::map.find的时间复杂度：https://stackoverflow.com/questions/9961742/time-complexity-of-find-in-stdmap
// std::map.find的时间复杂度：O(logn)，因为std::map and std::set are implemented by compiler vendors using highly balanced binary search trees (e.g. red-black tree, AVL tree).
// 解法时间复杂度：O(n * logn)
