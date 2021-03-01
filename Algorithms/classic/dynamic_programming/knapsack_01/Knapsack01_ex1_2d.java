package Algorithms.classic.dynamic_programming.knapsack_01;

/**
 * 一、题目：
 * 已知：
 *  · 有 N 件物品，所有物品的重量存放在一个数组 c 中，第 i 件物品的重量为 c[i] (0 <= i < N). 所有物品的价值存放在一个数组 w 中，第 i 件物品的价值为 w[i] (0 <= i < N)
 *  · 有一个容量为 V 的背包
 * 求解：「在无需把背包装满的情况下」，哪些物品装入背包可以总价值最大
 * 
 * 
 * 二、思路：
 * 这是经典的 0-1 背包问题，每种物品只有一件，只能选择放／不放
 * 
 * 三、状态转移方程：
 * f[i][v] = max { f[i-1][v] , f[i-1][v-c[i]] + w[i] }
 *                 f[i-1][v]: 不放入第 i 件物品
 *                             f[i-1][v-c[i]] + w[i] 放入第 i 件物品
 * 
 * 四、算法复杂度分析：
 * 时间复杂度：O(V * N)
 * 空间复杂度：O(V * N)     （注：不计入记录最优解的 used）
 * 空间复杂度：O(V * N^2)   （注：计入记录最优解的 used）
 * 
 * 五、背包问题参考：
 * 「背包问题九讲」博客：https://www.kancloud.cn/kancloud/pack/70125
 * 01背包问题测试数据：https://blog.csdn.net/miscclp/article/details/8787732
 * 
 * 其他参考：
 * Java快速输出数组：https://stackoverflow.com/questions/19648240/java-best-way-to-print-2d-array
 * Java拷贝数组：https://stackoverflow.com/questions/5785745/make-copy-of-an-array
 * 
 */

import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;

public class Knapsack01_ex1_2d {

    public static void knapsack01(int N, int[] c, int[] w, int V) {
        // f[i][j] 表示考虑前 i 个物品，背包重量为 j 情况下可以得到的最大价值
        // 第一行即 f[0][:] 表示什么都不装的情况
        // 最终 f[N][V] 即为所求
        int[][] f = new int[N+1][V+1];

        // 初始化 f
        for (int i = 0; i <= N; i++) {
            for (int v = 0; v <= V; v++) {
                f[i][v] = 0;
            }
        }

        // 这里为了好理解给 c 和 w 的最开始插入一个重量 和 价值都为 0 的物品，以保证 c[i], w[i] 都表示物品 i，而不用c[i-1], w[i-1] 来表示物品 i
        int[] new_c = new int[c.length + 1];
        new_c[0] = 0;
        System.arraycopy(c, 0, new_c, 1, c.length);

        int[] new_w = new int[w.length + 1];
        new_w[0] = 0;
        System.arraycopy(w, 0, new_w, 1, w.length);

        // 定义一个 Map，key 是在 f 表格内的坐标，value 是一维数组，value[i] = 1 表示最优解中包含物品 i, value[i] = 0 表示最优解中不包含物品 i
        Map<Integer, Map<Integer, int[]>> used = new HashMap<Integer, Map<Integer, int[]>>();
        
        // 初始化 used
        for (int i = 0; i <= N; i++) {
            for (int v = 0; v <= V; v++) {
                if (!used.containsKey(i)) {
                    used.put(i, new HashMap<Integer, int[]>());
                }
                used.get(i).put(v, new int[N + 1]);   // 包括上面new_c在头部加的价值／重量为 0 的虚拟物品
                for (int j = 0; j <= N; j++) {
                    used.get(i).get(v)[j] = 0;
                }
            }
        }
        
        // 填表 f
        for (int i = 1; i <= N; i++) {
            for (int v = 0; v <= V; v++) {
                if (v - new_c[i] >= 0) {
                    f[i][v] = Math.max(f[i-1][v], f[i-1][v - new_c[i]] + new_w[i]);

                    // 记录加入的物品
                    if (f[i][v] == f[i-1][v]) {
                        // 不加入物品 i
                        System.arraycopy(used.get(i-1).get(v), 0, used.get(i).get(v), 0, N + 1);
                        used.get(i).get(v)[i] = 0;
                    } else if (f[i][v] == f[i-1][v - new_c[i]] + new_w[i]) {
                        // 加入物品 i
                        System.arraycopy(used.get(i-1).get(v - new_c[i]), 0, used.get(i).get(v), 0, N + 1);
                        used.get(i).get(v)[i] = 1;
                    }
                }
            }
        }

        // 输出物品能装的最大价值
        System.out.println("最大价值为：" + f[N][V]);

        // 输出最终填充的状态矩阵
        // Arrays.stream(f).forEach((i) -> {
        //     Arrays.stream(i).forEach((j) -> System.out.print(j + " "));
        //     System.out.println();
        // });

        // 输出最优解中背包里所装的物品
        Arrays.stream(used.get(N).get(V)).forEach((i) -> {
            System.out.print(i + " ");
        });
        System.out.println();
        System.out.println();
    }

    public static void main(String[] args) {
        int N1 = 10;
        int[] c1 = new int[] {2, 7, 3, 4, 8, 5, 8, 6, 4, 16};
        int[] w1 = new int[] {15, 25, 8, 9, 15, 9, 13, 9, 6, 14};
        int V1 = 34;
        knapsack01(N1, c1, w1, V1);     // 正确结果：87

        int N2 = 10;
        int[] c2 = new int[] {2, 8, 4, 4, 8, 7, 8, 5, 16, 16};
        int[] w2 = new int[] {15, 25, 9, 9, 15, 12, 12, 6, 14, 9};
        int V2 = 34;
        knapsack01(N2, c2, w2, V2);     // 正确结果：85

        int N3 = 10;
        int[] c3 = new int[] {4, 5, 7, 2, 8, 3, 6, 1, 10, 9};
        int[] w3 = new int[] {25, 14, 15, 4, 14, 5, 8, 1, 10, 2};
        int V3 = 34;
        knapsack01(N3, c3, w3, V3);     // 正确结果：82

        int N4 = 10;
        int[] c4 = new int[] {4, 5, 7, 2, 8, 3, 9, 6, 1, 10};
        int[] w4 = new int[] {25, 14, 15, 4, 14, 5, 14, 8, 1, 10};
        int V4 = 34;
        knapsack01(N4, c4, w4, V4);     // 正确结果：83
    }
}

/**
 * 输出结果：
最大价值为：87
0 1 1 1 1 1 1 0 0 1 0 

最大价值为：85
0 1 1 1 1 1 1 0 0 0 0 

最大价值为：82
0 1 1 1 0 1 1 1 1 0 0 

最大价值为：83
0 1 1 1 0 1 0 1 0 1 0 
 */
