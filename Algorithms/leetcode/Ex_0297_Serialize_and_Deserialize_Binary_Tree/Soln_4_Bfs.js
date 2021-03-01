/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function(root) {
    const queue = [root];
    let res = [];
    while (queue.length) {
        const node = queue.shift(); // 弹出队头节点
        if (node) {
            res.push(node.val);
            queue.push(node.left);
            queue.push(node.right);
        } else {
            res.push('X');
        }
    }
    return res.join(',');
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    if (data == 'X') {
        return null;
    }
    const list = data.split(',');
    const root = new TreeNode(list[0]);
    const queue = [root];
    let index = 1;
    while (index < list.length) {
        const node = queue.shift(); // 弹出队头节点
        const leftVal = list[index];
        index += 1;
        const rightVal = list[index];
        index += 1;

        if (leftVal != 'X') {
            const leftNode = new TreeNode(leftVal);
            node.left = leftNode;
            queue.push(leftNode);
        }

        if (rightVal != 'X') {
            const rightNode = new TreeNode(rightVal);
            node.right = rightNode;
            queue.push(rightNode);
        }
    }
    return root;
};

/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/solution/shou-hui-tu-jie-gei-chu-dfshe-bfsliang-chong-jie-f/
