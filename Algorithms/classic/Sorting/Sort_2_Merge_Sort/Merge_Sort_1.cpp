#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void merge_sort(vector<int> &nums, int left, int right, vector<int> &temp) {
    if (left + 1 >= right) {
        return;
    }

    // divide (划分)
    int mid = left + (right - left) / 2;    // 分割点
    // 分别归并排序前后两部分
    merge_sort(nums, left, mid, temp);      // 排序第一个数组 nums[left ... mid)
    merge_sort(nums, mid, right, temp);     // 排序第二个数组 nums[mid ... right)

    // conquer (合并)
    int p = left;   // 第一个数组指针
    int q = mid;    // 第二个数组指针
    int i = left;   // 合并后的数组指针

    while (p < mid || q < right) {
        if (q >= right || (p < mid && nums[p] <= nums[q])) {
            temp[i] = nums[p];
            i ++;
            p ++;
        } else {
            temp[i] = nums[q];
            i ++;
            q ++;
        }
    }
    for (int i = left; i < right; i++) {
        nums[i] = temp[i];
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

    // 归并排序
    vector<int> temp (size, 0);
    merge_sort(nums, 0, nums.size(), temp);

    for (const int &num : nums) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394
