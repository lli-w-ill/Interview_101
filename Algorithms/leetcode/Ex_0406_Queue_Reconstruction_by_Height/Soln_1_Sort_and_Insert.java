package Algorithms.leetcode.Ex_0406_Queue_Reconstruction_by_Height;

import java.util.HashMap;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Solution_1 {
    public int[][] reconstructQueue(int[][] people) {
        // 保存 h_i 与 (k_i, (h_i, k_i)在people中的下标)
        // key: h_i
        // value: [0]: k_i; [1] 下标
        HashMap<Integer, ArrayList<int[]>> map = new HashMap<Integer, ArrayList<int[]>>();
        ArrayList<Integer> height = new ArrayList<Integer>();
        // 初始化 map, height
        for (int i = 0; i < people.length; i++) {
            int[] p = people[i];
            if (!map.containsKey(p[0])) {
                // 之前没见过同样身高的人，将新的身高加入到height中
                height.add(p[0]);
                map.put(p[0], new ArrayList<int[]>());
            }
            // 将对应key加入到 map[p[0]] 中
            map.get(p[0]).add(new int[] {p[1], i});
        }

        // 按身高高的在前排序 height
        Collections.sort(height, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if (o1 > o2) {
                    return -1;
                } else if (o1 == o2) {
                    return 0;
                } else {
                    return 1;
                }
            }
        });

        ArrayList<int[]> resList = new ArrayList<int[]>();
        for (int h : height) {
            // 按照 k_i 正序排序 map[h]
            Collections.sort(map.get(h), new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    if (o1[0] > o2[0]) {
                        // o1 前面站的人要比 o2 前面站的比h要高的人要多 (o1, o2都是身高h)
                        // 所以 o1 应该在 o2 后面
                        return 1;
                    } else if (o1[0] == o2[0]) {
                        return 0;
                    } else {
                        return -1;
                    }
                }
            });

            for (int[] p : map.get(h)) {
                int index = p[0];
                resList.add(index, people[p[1]]);
            }
        }

        // 将结果 2d list 转成二维数组
        int[][] res = new int[people.length][2];
        for (int i = 0; i < resList.size(); i++) {
            res[i] = resList.get(i);
        }
        return res;
    }
}
