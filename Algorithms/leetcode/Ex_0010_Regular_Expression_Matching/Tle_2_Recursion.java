package Algorithms.leetcode.Ex_0010_Regular_Expression_Matching;

class Tle_2 {
    public boolean isMatch(String s, String p) {
        if (p == null || p.length() == 0) {
            return s == null || s.length() == 0;
        }

        // 检查首字母是否匹配
        boolean firstMatch = (s.length() > 0) && (s.charAt(0) == p.charAt(0)) || (p.charAt(0) == '.');
        if (p.length() >= 2 && p.charAt(1) == '*') {
            // * 匹配 0 次首字母
            boolean res1 = isMatch(s, p.substring(2));
            if (res1) {
                return true;
            }
            // * 匹配一次或多次首字母
            boolean res2 = false;
            if (s.length() > 0) {
                res2 = isMatch(s.substring(1), p);
            }
            return (firstMatch == true) && res2;
        } else {
            boolean res3 = false;
            if (s.length() > 0) {
                res3 = isMatch(s.substring(1), p.substring(1));
            }
            return (firstMatch == true) && res3;
        }
    }
}