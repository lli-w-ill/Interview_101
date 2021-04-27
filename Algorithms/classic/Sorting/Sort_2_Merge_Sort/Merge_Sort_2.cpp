#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

vector<int> merge(const vector<int> &left_nums, const vector<int> &right_nums, int left, int right, int mid) {
    vector<int> merged_nums;

    int left_index = 0;     // left_nums 中的下标
    int right_index = 0;    // right_nums 中的下标
    
    while (left_index <= mid - left && right_index <= right - mid - 1) {
        if (left_nums[left_index] < right_nums[right_index]) {
            merged_nums.push_back(left_nums[left_index]);
            left_index ++;
        } else {
            merged_nums.push_back(right_nums[right_index]);
            right_index ++;
        }
    }

    // 将 left_nums 或 right_nums 中还剩需要的元素加入 merged_nums
    while (left_index <= mid - left) {
        merged_nums.push_back(left_nums[left_index]);
        left_index ++;
    }
    while (right_index <= right - mid - 1) {
        merged_nums.push_back(right_nums[right_index]);
        right_index ++;
    }

    return merged_nums;

}

// 这里采用「左闭右闭」原则 ———— 排序 nums[left ... right] 中的元素
vector<int> merge_sort(vector<int> &nums, int left, int right) {
    if (left == right) {
        // 当前需要排序的数组只有一个元素了，已经有序
        return vector<int> {nums[left]};
    }
    if (left > right) {
        // 当前需要排序的数组越界了，返回空数组
        return vector<int> {};
    }

    // 计算中点（分割点）
    int mid = left + (right - left) / 2;

    // 在分割点处将 nums[left ... right] 进行（虚拟）分割，并对前后两部分分别进行归并排序
    // 归并排序左部分 nums[left ... mid]
    vector<int> left_nums = merge_sort(nums, left, mid);
    // 归并排序右部分 nums[mid + 1, ... right]
    vector<int> right_nums = merge_sort(nums, mid + 1, right);

    // 合并两数组 nums[left ... mid] 和 nums[mid + 1 ... right]
    vector<int> sorted_nums = merge(left_nums, right_nums, left, right, mid);

    return sorted_nums;
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
    nums = merge_sort(nums, 0, nums.size() - 1);

    for (const int &num : nums) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}
