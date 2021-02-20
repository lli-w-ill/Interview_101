#include <deque>
#include <utility>  // std::pair
#include <iterator> // std::distance

using std::deque;
using std::pair;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        int res = -1;
        int res_i = -1;
        // 尝试在cache中找到key
        for (deque<pair<int, int> >::iterator it = cache.begin(); it != cache.end(); it++) {
            if (it->first == key) {
                res = it->second;
                res_i = std::distance(cache.begin(), it);
                break;
            }
        }
        // 如果找到了key，需要重新把这个<key, value> pair放到队尾，作为最近使用过的元素
        if (res_i != -1) {
            cache.erase(cache.begin() + res_i);
            cache.push_back(pair<int, int> (key, res));
        }
        return res;
    }
    
    void put(int key, int value) {
        // 首先尝试在cache找到key元素
        int keyIdx = -1;
        for (deque<pair<int, int> >::iterator it = cache.begin(); it != cache.end(); it++) {
            if (it->first == key) {
                keyIdx = distance(cache.begin(), it);
                break;
            }
        }
        if (keyIdx == -1) {
            // 说明没有找到key元素
            if (size == capacity) {
                // 如果队现在满了，需要先将队头元素，也就是「最久未使用的key」出队
                cache.pop_front();
                size -= 1;
            }
            // 在队尾加入新元素
            cache.push_back(pair<int, int> (key, value));
            size += 1;
        } else {
            // 如果找到了key元素
            // 先将key元素pop出，然后在队尾插入新的<key, value>
            cache.erase(cache.begin() + keyIdx);
            cache.push_back(pair<int, int> (key, value));
        }
    }

private:
    int capacity;
    int size;   // 记录当前cache中有多少元素
    deque<pair<int, int> > cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// 遍历deque<pair<int, int> >: https://stackoverflow.com/questions/25606108/iterate-over-vector-of-pair
// 通过iterator遍历时，如何计算下标：https://stackoverflow.com/questions/12495382/how-do-i-iterate-over-a-vector-and-also-know-the-index-of-the-element
// 这个解法的 get 和 put 的时间复杂度都是 O(n)
