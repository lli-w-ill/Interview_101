#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// 采用「左闭右闭」原则的二分法 （注意不是 nums[left ... right] 而是 nums[first ... last]）
void quick_sort(vector<int> &nums, int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    
    // 排序 nums[first ... last]
    int first = left;
    int last = right - 1;
    int pivot = nums[first];    // 使用第一个元素作为划分当前 nums[left ... right] 为两部分的 key

    while (first < last) {
        // 从右 (last) 开始，找到第一个小于 pivot 的下标
        while (first < last && nums[last] >= pivot) {
            last --;
        }
        nums[first] = nums[last];
        // 从左 (first) 开始，找到第一个大于 pivot 的下标
        while (first < last && nums[first] <= pivot) {
            first ++;
        }
        nums[last] = nums[first];
    }

    // 将「基准」放在排序后其应该在的位置，并对前后分别快排
    nums[first] = pivot;
    quick_sort(nums, left, first);
    quick_sort(nums, first + 1, right);
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

    // 快速排序
    quick_sort(nums, 0, nums.size());

    for (const int &num : nums) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
