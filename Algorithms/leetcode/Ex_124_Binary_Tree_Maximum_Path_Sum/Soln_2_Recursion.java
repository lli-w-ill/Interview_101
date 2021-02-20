package Algorithms.leetcode.Ex_124_Binary_Tree_Maximum_Path_Sum;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int res = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        dfs(root);
        return res;
    }

    private int dfs(TreeNode node) {
        if (node == null) {
            return 0;
        }
        // 计算左／右子树所有「一直向下的单链」中的最大路径和
        int leftSingleMaxPathSum = dfs(node.left);
        int rightSingleMaxPathSum = dfs(node.right);
        // 情况1: 只有node自身的值作为 max path sum（因为node下面的节点只会「帮倒忙」）
        int case1 = node.val;
        // 情况2: node和其左子树「一直向下的单链」中的最大路径 共同作为 max path sum
        int case2 = node.val + leftSingleMaxPathSum;
        // 情况3: node和其右子树「一直向下的单链」中的最大路径 共同作为 max path sum
        int case3 = node.val + rightSingleMaxPathSum;
        // 情况4: node和左子树还有右子树「一直向下的单链」中的最大路径 共同作为 max path sum
        int case4 = node.val + leftSingleMaxPathSum + rightSingleMaxPathSum;

        // 上述4种情况的最大 path sum，就是以当前node作为 root 的 max path sum
        res = Math.max(res, Math.max(case1, Math.max(case2, Math.max(case3, case4))));

        // 注意：返回给上一个节点，不能是以当前node为「root」的max path sum，因为不能“折叠”（所以不能包括case4）
        // 所以应该返回包括当前node 最大path sum 的「单链」
        return Math.max(case1, Math.max(case2, case3));
    }
}
