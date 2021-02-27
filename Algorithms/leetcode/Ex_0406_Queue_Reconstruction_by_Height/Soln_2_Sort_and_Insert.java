package Algorithms.leetcode.Ex_0406_Queue_Reconstruction_by_Height;

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;

class Solution_2 {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, new Comparator<int[]>(){
            @Override
            public int compare(int[] o1, int[] o2) {
                // 先按身高 h_i 降序排序
                if (o1[0] > o2[0]) {
                    return -1;
                } else if (o1[0] < o2[0]) {
                    return 1;
                } else {
                    // 如果身高相同，则再按 k_i 升序排序
                    return o1[1] - o2[1];
                }
            }
        });

        // 因为频繁插入元素，所以用 LinkedList 而不用 ArrayList
        LinkedList<int[]> resList = new LinkedList<int[]>();
        for (int[] i : people) {
            // 因为先插身高高的，而且是插到位置i，所以保证 resList[0 ... i-1] 身高一定不比 i[0] 小
            resList.add(i[1], i);
        }
        return resList.toArray(new int[people.length][2]);
    }
}

// 参考题解：https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/406-gen-ju-shen-gao-zhong-jian-dui-lie-java-xian-p/
// 思路：先将高个子占好位（先入list），矮个子插到到 k_i 位置上，保证前面肯定有 k_i 个高个子
// 注意矮个子插在高个子前面是不会影响高个子的 k_i 的，所以要先让高个子占好，再站矮个子
