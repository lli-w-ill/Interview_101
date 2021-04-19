#include <map>
#include <iterator>     // std::advance
#include <cstdlib>      // std::srand, std::rand

using std::map;
using std::advance;
using std::rand;
using std::srand;

class RandomizedSet {
private:
    // key: value
    // value: 如果 map 中这个数存在则true，不存在则false（原则上不存在value=false的key，因为会被erase）
    map<int, bool> mp;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        // initialize random seed and genreate a random number
        srand (time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.count(val)) {
            // value 已经存在
            return false;
        } else {
            mp.insert({val, true});
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.count(val)) {
            mp.erase(val);
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int size = mp.size();

        // 生成随机 0 ~ size-1 的偏移
        int randomOffset = rand() % size;   

        // 定义随机 iterator 为 mp.begin() + 随机偏移量
        map<int, bool>::iterator randomIterator = mp.begin();
        advance(randomIterator, randomOffset);  // 这里不能直接用 + 号来向前移动 iterator，需要用到 advance 方法来递增迭代器

        return randomIterator->first;
    }
};

// advance 参考: https://www.cplusplus.com/reference/iterator/advance/?kw=advance
// rand 参考: https://www.cplusplus.com/reference/cstdlib/rand/


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
