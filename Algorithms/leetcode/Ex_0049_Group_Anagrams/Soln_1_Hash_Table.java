package Algorithms.leetcode.Ex_0049_Group_Anagrams;

import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<Long, ArrayList<String>> hs = new HashMap<Long, ArrayList<String>>();
        int[] primes = new int[] {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        int len = strs.length;
        for (int i = 0; i < len; i++) {
            long product = 1;
            for (int j = 0; j < strs[i].length(); j++) {
                product *= primes[strs[i].charAt(j) - 'a'];
            }
            if (hs.containsKey(product)) {
                hs.get(product).add(strs[i]);
            } else {
                hs.put(product, new ArrayList<String> (Arrays.asList(strs[i])));
            }
        }
        List<List<String>> res = new ArrayList<List<String>>();
        for (long key : hs.keySet()) {
            res.add(hs.get(key));
        }
        return res;
    }
}

// 参考：https://leetcode-cn.com/problems/group-anagrams/solution/zhi-shu-pai-xu-shu-zu-6xing-dai-ma-chao-9kdni/
// 这个解法，但字符串很长时，而且字符都靠近z时，key可能会越界
// 从这个解法复习到一个知识点：任何一个大于1的自然数N，如果N不为质数，那么N可以唯一分解成有限个质数的乘积
