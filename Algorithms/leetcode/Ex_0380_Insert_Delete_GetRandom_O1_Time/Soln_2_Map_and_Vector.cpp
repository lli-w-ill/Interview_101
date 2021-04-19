#include <vector>
#include <unordered_map>
#include <cstdlib>

using std::vector;
using std::unordered_map;
using std::rand;

class RandomizedSet {
private:
    // key: value
    // value: key值在 vector 中的下标 (下标从 0 开始)
    unordered_map<int, int> hash;
    // 用来存放所有值（也就是 hash 中所有的key）
    vector<int> arr;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // 类型可以用 auto 代替
        unordered_map<int, int>::iterator it = hash.find(val);

        if (it != hash.end()) {
            // val 已经在 arr 中了
            return false;
        }

        // 在 arr 和 hash 中插入 val
        arr.push_back(val);
        hash.insert({val, arr.size() - 1});
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = hash.find(val);

        if (it == hash.end()) {
            // val 不在 arr 中
            return false;
        }

        int valIndex = hash[val];
        int lastIndex = hash.size() - 1;
        // 在 arr 中要删除的位置 (即 arr[valIndex]) 置为当前 arr 中最后一个数
        arr[valIndex] = arr[lastIndex];
        // 更新 arr 最后一个数 hash 中的坐标
        hash[arr[valIndex]] = valIndex;

        // 在 arr 和 hash 中删除 val 对应的值和下标（建议结合参考题解的插图）
        arr.pop_back();     // 删除最后一个数（因为已经赋给 valIndex 下标了）
        hash.erase(val);

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int size = arr.size();
        int index = rand() % size;
        return arr[index];
    }
};

// 参考题解（推荐）：https://leetcode-cn.com/problems/insert-delete-getrandom-o1/solution/cchang-shu-shi-jian-cha-ru-shan-chu-he-huo-qu-sui-/
// 
// 我的想法：题解中使用的是 unordered_map + vector，可不可以用 unordered_map + linked list (类似 Ex146. LRU Cache 使用的数据结构) 呢？

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

