#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::swap;

void selection_sort(vector<int> &nums, int size) {
    int mid;
    for (int i = 0; i < size - 1; i++) {
        mid = i;
        for (int j = i + 1; j < size; j++) {
            if (nums[j] < nums[mid]) {
                mid = j;
            }
        }
        swap(nums[mid], nums[i]);
    }
}

int main() {
    vector<int> nums;
    
    // 输入数组的个数
    int size;
    cout << "输入准备排序数字的个数：";
    cin >> size;
    
    // 输入每个数字
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    // 插入排序
    selection_sort(nums, nums.size());

    for (const int &num : nums) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
