import java.util.Scanner;

public class Quick_Select_1 {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("输入数组的大小: length = ");
        int length = in.nextInt();
        
        System.out.print("输入数组元素：");
        int[] nums = new int[length];
        for (int i = 0; i < length; i++) {
            nums[i] = in.nextInt();
        }

        int k;
        do {
            System.out.print("输出第 k 小的值 (0 ~ length-1): k = ");
            k = in.nextInt();
        } while (k < 0 || k >= length);

        System.out.println("第 k 小的值为：" + quick_select(nums, 0, nums.length - 1, k));

        in.close();
    }

    private static int quick_select(int[] nums, int left, int right, int k) {
        while (true) {
            // 将当前 nums[left ... right] 的最后一个元素认为 pivot
            int pivot = nums[right];

            int i = left - 1;
            int j = left;
            
            while (j < right) {
                if (nums[j] <= pivot) {
                    // 如果当前位小于 pivot，则先右移一位 i，然后交换 i, j 下标的值，然后右移 j
                    i ++;
                    swap(nums, i, j);
                    j ++;
                } else {
                    // 如果当前位大于 pivot，则什么都不做，右移 j
                    j ++;
                }
            }

            // 将 pivot 放在正确的位置上
            swap(nums, i + 1, j);
    
            if (i + 1 == k) {
                return nums[i + 1];
            } else if (i + 1 < k) {
                // 当前第 k 小的值在 pivot 的右边
                left = (i + 1) + 1;
            } else if (i + 1 > k) {
                // 当前第 k 小的值在 pivot 的左边
                right = i;
            }
            
        }
    }

    private static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

// 参考视频：https://www.youtube.com/watch?v=BP7GCALO2v8
//
// 注：
// 该算法中的 k 是 0-based，也就是：如果 nums = [0, 1, 2, 3, 4, 5]
// 第 0 小是 0（即 k = 0 时返回结果是 0），第 5 小是 5（即 k = 5 时返回结果是 5）
// 
// 设 N = nums.length
// Worst-case time complexity: O(N^2)
// Average-case time complexity: O(N)
