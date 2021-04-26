#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::swap;

void bubble_sort(vector<int> &nums, int size) {
    bool swapped;
    for (int i = 1; i < size; i++) {
        swapped = false;
        for (int j = 1; j < size - i + 1; j++) {
            if (nums[j] < nums[j-1]) {
                swap(nums[j], nums[j-1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
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
    bubble_sort(nums, nums.size());

    for (const int &num : nums) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
