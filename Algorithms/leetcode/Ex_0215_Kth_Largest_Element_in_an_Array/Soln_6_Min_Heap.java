package Algorithms.leetcode.Ex_0215_Kth_Largest_Element_in_an_Array;

import java.util.PriorityQueue;
import java.util.Comparator;

class Solution_6 {
    public int findKthLargest(int[] nums, int k) {
        // 第 K 大的元素就是整个数组排序后，后面一部分最小的元素
        int len = nums.length;
        PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>(k, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1 - o2;
            }
        });
        
        // 先将 len 个元素全部加入堆
        for (int i = 0; i < len; i++) {
            minHeap.add(nums[i]);
        }
        // 然后弹出堆顶元素 len - k 次
        for (int i = 0; i < len - k; i++) {
            minHeap.poll();
        }
        // 直接返回堆顶元素
        return minHeap.peek();
    }
}

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/partitionfen-er-zhi-zhi-you-xian-dui-lie-java-dai-/
// 最小堆：https://baike.baidu.com/item/%E6%9C%80%E5%B0%8F%E5%A0%86
// 最大堆：https://baike.baidu.com/item/%E6%9C%80%E5%A4%A7%E5%A0%86
// 题解提供了两个思路：
// 思路1: nums len个元素全部加入到最小堆（任一非终端节点的数据值均不大于其左子节点和右子节点的值），然后弹出堆顶，也就是堆小元素 len-k 次，此时最小堆中还剩下 k 个元素，而堆顶就是对内的最小元素，也就是 nums 中第 k 大的元素
// 思路2: nums len个元素全部加入到最大堆（根结点（亦称为堆顶）的关键字是堆里所有结点关键字中最大者，称为大根堆，又称最大堆），然后弹出堆顶元素 k-1 次，所以 nums 中比第 k 个元素还大的 k-1 个元素都已经出堆，所以现在堆顶元素就是第 k 大的
// 这个解法采用的是思路1，Soln_7采用的思路2


