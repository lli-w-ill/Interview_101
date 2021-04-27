#include <vector>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::unordered_map;
using std::cin;
using std::cout;
using std::endl;

void bucket_sort(vector<int> &nums, int size) {
    // 第一步：对 nums 中每个数字计算其出现频率，然后同时记录最大的频率，方便之后定义桶的数量
    unordered_map<int, int> frequency;
    int max_frequency = 0;
    for (const int &num : nums) {
        if (frequency.count(num) == 0) {
            // 第一次出现
            frequency[num] = 1;
        } else {
            frequency[num] ++;
        }

        if (frequency[num] > max_frequency) {
            max_frequency = frequency[num];
        }
    }

    // 第二步：定义 max_frequency 个桶，每个桶用 key 表示桶内数字在 nums 中出现的频率，用 value 存放所有出现频率为 key 的数字
    unordered_map<int, vector<int>> buckets;
    for (int i = 1; i <= max_frequency; i++) {
        // 初始化桶
        buckets[i] = vector<int> {};
    }
    // 扫描 frequency，将每个数字放入对应频率的桶
    // for (const auto &[key, value] : frequency) {    // c++17
    for (unordered_map<int, int>::iterator it = frequency.begin(); it != frequency.end(); it++) {
        int key = it->first;
        int value = it->second;
        // key 表示 num
        // value 表示 num 在 nums 中出现的频率
        buckets[value].push_back(key);
    }


    // 第三步：收集结果，如果要求升序，则从频率最小的桶开始遍历；如果要求逆序，则从频率最高的桶开始遍历
    nums.clear();   // 用原数组作结果集
    for (int i = 1; i <= max_frequency; i++) {
        if (buckets[i].size() > 0) {
            for (const int &num : buckets[i]) {
                nums.push_back(num);
            }
        }
    }
}

int main() {
    cout << "***** 桶排序 *****" << endl;

    vector<int> nums;
    
    // 输入数组的个数
    int size;
    cout << "输入准备排序数字的个数：";
    cin >> size;
    
    // 输入每个数字
    cout << "输入数组数字：";
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    // 桶排序
    bucket_sort(nums, nums.size());

    cout << "按照数字出现的频率的排序结果："; 
    for (const int &num : nums) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
