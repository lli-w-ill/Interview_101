#include <vector>

using std::vector;

class Solution_3 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last1 = m - 1;  // 当前 nums1 中最后一个数字的下标（也可以用 m 代替）
        int last2 = n - 1;  // 当前 nums2 中最后一个数字的下标（也可以用 n 代替）
        int realLastIdx = m + n - 1;   // 当前需要向 nums1 的末尾拷贝的下标
        
        while (last1 >= 0 && last2 >= 0) {
            if (nums1[last1] >= nums2[last2]) {
                nums1[realLastIdx] = nums1[last1--];
            } else {
                nums1[realLastIdx] = nums2[last2--];
            }
            realLastIdx --;
        }
        // 如果 nums2 还有没拷贝完的数字，要继续向 nums1 中拷贝
        while (last2 >= 0) {
            nums1[realLastIdx--] = nums2[last2--];
        }
    }
};

// 参考「编程指北」《谷歌大佬刷题笔记》（强烈推荐）：https://zhuanlan.zhihu.com/p/297648394


