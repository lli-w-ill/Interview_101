package Algorithms.classic.sort;

// 计数排序（实现一）
// 时间复杂度：O(n+k)
// 空间复杂度：O(k)
public class Counting_Sort_1 {

    private static int[] countSort(int[] arr) {
        if (arr == null || arr.length == 0) {
            return null;
        }
        // 初始 max 和 min
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        // 找到数组中最大值和最小值
        for (int num : arr) {
            max = Math.max(num, max);
            min = Math.min(num, min);
        }
        // 计算数组中每个数字出现的频率
        int[] freq = new int[max - min + 1];
        for (int i = 0; i < arr.length; i++) {
            // 计算当前数字相对于最小数的偏移量
            int pos = arr[i] - min;
            // 递增频率数组
            freq[pos]++;
        }
        // 根据频率数组，对 arr 进行排序
        int index = 0;
        for (int i = 0; i < freq.length; i++) {
            while (freq[i]-- > 0) {
                arr[index++] = i + min;
            }
        }
        return arr;
    }

    public static void main(String[] args) {
        int[] arr = new int[] { -5, 5, -1, 0, 4, -3, 2, -2, 1, 3, -4 };
        System.out.println("排序前：");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        System.out.println("排序后：");
        arr = countSort(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}

// 代码参考：https://www.cnblogs.com/zer0Black/p/6169858.html
