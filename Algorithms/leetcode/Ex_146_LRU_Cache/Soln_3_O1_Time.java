package Algorithms.leetcode.Ex_146_LRU_Cache;

import java.util.HashMap;

// 定义哈希链表中的节点
class Node {
    public int key;
    public int val;
    public Node next;
    public Node prev;
    
    public Node (int k, int v) {
        this.key = k;
        this.val = v;
    }
}

class DoubleList {
    public Node head;
    public Node tail;
    public int size;

    public DoubleList() {
        // 定义头节点、尾节点，并将它们连接起来
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head.next = tail;
        head.prev = null;
        tail.next = null;
        tail.prev = head;

        size = 0;
    }

    // 在链表头部添加节点 x, 时间O(1)
    public void addFirst(Node x) {
        // 先初始化 x 的两边指针
        x.next = head.next;
        x.prev = head;
        // 然后修改 head.next向后指 和 head向前指 的指针
        head.next.prev = x;
        head.next = x;
        // 更新 size
        size += 1;
    }

    // 删除链表中的节点 x （且参数x保证一定在双链表中）, 时间O(1)
    public void remove(Node x) {
        x.next.prev = x.prev;
        x.prev.next = x.next;
        // 更新 size
        size -= 1;
    }

    // 删除链表中的最后一个节点，并返回该节点, 时间O(1)
    public Node removeLast() {
        if (size >= 1) {
            // 保证不要删除head节点
            // 先得到最后一个节点
            Node last = tail.prev;
            // 修改 last.prev.next 和 tail.prev
            last.prev.next = last.next;
            tail.prev = last.prev;
            // 返回之前需要将 last 的两边指针置空，以免返回后的last在外面“破坏”链表
            last.next = null;
            last.prev = null;
            // 更新 size
            size -= 1;
            return last;
        }
        return null;
    }

    // 返回链表长度, 时间O(1)
    public int size() {
        return size;
    }
}

class LRUCache {
    // key 映射到 Node
    private HashMap<Integer, Node> map;
    // 双向链表
    private DoubleList cache;
    // 最大容量
    private int capacity;

    public LRUCache(int capacity) {
        map = new HashMap<Integer, Node>();
        cache = new DoubleList();
        this.capacity = capacity;
    }
    
    public int get(int key) {
        if (!map.containsKey(key)) {
            return -1;
        }
        int val = map.get(key).val;
        put(key, val);  // 利用 put 方法把 key 对应的 Node 放到最前面，作为「最近访问的节点」
        return val;
    }
    
    public void put(int key, int value) {
        Node x = new Node(key, value);

        if (map.containsKey(key)) {
            // 如果链表中存在 key 对应的 Node，则删除 Node，将更新完 value 后新的 Node 添加到头部
            cache.remove(map.get(key));
            cache.addFirst(x);
            // 更新 map
            map.put(key, x);
        } else {
            // 如果 key 不存在链表中
            if (capacity == cache.size()) {
                // 如果当前链表达到容量上限，则需要先删除链表最后一个 Node
                Node last = cache.removeLast();
                // 更新 map
                map.remove(last.key);   // 这里是为什么需要在链表每个Node中也存一份key的原因，因为如果Node只存value，就不能根据头节点反向删除map中对应key的项
            }
            // 然后将新创建的 Node 添加到头部
            cache.addFirst(x);
            // 更新 map
            map.put(key, x);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

// 参考题解（强烈推荐）：https://leetcode-cn.com/problems/lru-cache/solution/lru-ce-lue-xiang-jie-he-shi-xian-by-labuladong/
// 与 Soln_2 相同，这个解法用到了「哈希链表」的数据结构
// 需要用双向链表的原因是：由于删除操作既需要知道该节点的前驱节点，也需要知道该节点的后继节点，所以用双向链表，而非单向
