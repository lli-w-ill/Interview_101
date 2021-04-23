package Algorithms.leetcode.Ex_0227_Basic_Calculator_II;

import java.util.Map;
import java.util.HashMap;
import java.util.Deque;
import java.util.ArrayDeque;

class Solution_2 {
    // 用 map 维护运算符优先级
    // value 越小，优先级越低
    private Map<Character, Integer> precedence = new HashMap<Character, Integer>() {
        /**
         *
         */
        private static final long serialVersionUID = 1L;
        
        {
            put('-', 1);
            put('+', 1);
            put('*', 2);
            put('/', 2);
            put('%', 2);
            put('^', 3);
        }};

    public int calculate(String s) {
        // 去掉所有的空格，并处理括号后紧接着正负号的情况 (- => (0- ; (+ => (0+
        // 也可以放到循环中做判断，这里用正则提前做预处理
        s = s.replaceAll(" ", "");
        s = s.replaceAll("\\(-", "(0-");
        s = s.replaceAll("\\(\\+", "(0+");  // 注意要转义(, +
        
        char[] charArray = s.toCharArray();
        int length = s.length();

        // 存放所有的数字
        Deque<Integer> nums = new ArrayDeque<>();
        // 防止第一个数是负数，提前在数字栈中加入一个 0
        nums.addLast(0);

        // 操作符栈 +, -, *, /, (, ), ...
        Deque<Character> ops = new ArrayDeque<>();

        // 开始扫描
        for (int i = 0; i < length; i++) {
            char c = charArray[i];
            if (c == '(') {
                // 遇到左括号，直接加入到运算符栈
                ops.addLast(c);
            } else if (c == ')') {
                // 遇到右括号，一直计算到运算符栈中最近的一个左括号为止
                while (!ops.isEmpty() && ops.peekLast() != '(') {
                    calc(nums, ops);
                }
                // 将对应的左括号弹出
                ops.pollLast();
            } else {
                // 能走到这里，应该是 数字 或者 运算符
                if (isNumber(c)) {
                    // 数字
                    int num = 0;
                    int j = i;
                    // 从 i 开始往后一直取到第一个非数字字符的前一个字符
                    while (j < length && isNumber(charArray[j])) {
                        num = num * 10 + (charArray[j] - '0');
                        j ++;
                    }
                    nums.addLast(num);
                    i = j - 1;  // -1 为了抵消for结尾的递增
                } else {
                    // 运算符
                    // 每次在入栈当前运算符之前，需要先把运算符栈内优先级比当前运算符高或相等的都先计算了
                    while (!ops.isEmpty() && ops.peekLast() != '(') {
                        char prevOp = ops.peekLast();
                        if (precedence.get(prevOp) >= precedence.get(c)) {
                            calc(nums, ops);
                        } else {
                            break;
                        }
                    }
                    // 加入当前运算符
                    ops.addLast(c);
                }
            }
        }

        // 按从左到右顺序计算剩余运算符
        while (!ops.isEmpty()) {
            calc(nums, ops);
        }
        return nums.peekLast();
    }

    private void calc(Deque<Integer> nums, Deque<Character> ops) {
        if (nums.isEmpty() || nums.size() < 2) {
            return;
        }
        if (ops.isEmpty()) {
            return;
        }

        int rightOperand = nums.pollLast();
        int leftOperand = nums.pollLast();
        char op = ops.pollLast();
        int ans;

        switch (op) {
            case '+':
                ans = leftOperand + rightOperand;
                break;
            case '-':
                ans = leftOperand - rightOperand;
                break;
            case '*':
                ans = leftOperand * rightOperand;
                break;
            case '/':
                ans = leftOperand / rightOperand;
                break;
            case '^':
                ans = (int) Math.pow(leftOperand, rightOperand);
                break;
            case '%':
                ans = leftOperand % rightOperand;
                break;
            default:
                ans = 0;
        }
        // 将结果加入到数字栈中
        nums.addLast(ans);
    }

    private boolean isNumber(char c) {
        return Character.isDigit(c);
    }
}

// 参考题解（双栈解法，非常推荐理解里面的思路）：https://leetcode-cn.com/problems/basic-calculator-ii/solution/shi-yong-shuang-zhan-jie-jue-jiu-ji-biao-c65k/
// 建议配合题解中提到的相关计算器题目 (Ex224, Ex227, Ex772, Ex770) 一起做
