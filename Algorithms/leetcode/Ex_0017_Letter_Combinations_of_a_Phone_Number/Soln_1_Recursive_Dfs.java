package Algorithms.leetcode.Ex_0017_Letter_Combinations_of_a_Phone_Number;

import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Solution_1 {
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) {
            return new ArrayList<String>();
        }
        Map<Character, ArrayList<Character>> map = new HashMap<Character, ArrayList<Character>>();
        map.put('2', new ArrayList<Character>(Arrays.asList('a', 'b', 'c')));
        map.put('3', new ArrayList<Character>(Arrays.asList('d', 'e', 'f')));
        map.put('4', new ArrayList<Character>(Arrays.asList('g', 'h', 'i')));
        map.put('5', new ArrayList<Character>(Arrays.asList('j', 'k', 'l')));
        map.put('6', new ArrayList<Character>(Arrays.asList('m', 'n', 'o')));
        map.put('7', new ArrayList<Character>(Arrays.asList('p', 'q', 'r', 's')));
        map.put('8', new ArrayList<Character>(Arrays.asList('t', 'u', 'v')));
        map.put('9', new ArrayList<Character>(Arrays.asList('w', 'x', 'y', 'z')));

        ArrayList<String> res = new ArrayList<String>();
        this.dfs(digits, 0, new String(), res, map);
        return res;
    }

    private void dfs(String digits, int idx, String cur, ArrayList<String> res,
            Map<Character, ArrayList<Character>> map) {
        if (idx == digits.length()) {
            res.add(cur);
            return;
        }
        for (int i = 0; i < map.get(digits.charAt(idx)).size(); i++) {
            this.dfs(digits, idx + 1, cur + map.get(digits.charAt(idx)).get(i), res, map);
        }
    }
}
