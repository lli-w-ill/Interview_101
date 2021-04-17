# 首先定义链表中的 Node
class ListNode:
    def __init__(self, key: int, value: int, prev: ListNode=None, next: ListNode=None):
        self.key = key
        self.val = value
        self.prev = prev
        self.next = next;

class LRUCache:

    def __init__(self, capacity: int):
        # 定义并连接链表的 表头节点 和 表尾节点
        self.head = ListNode(-1, -1)
        self.tail = ListNode(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head
        
        # 定义字典，key是之后往链表中插入的key值，value是对应key值的ListNode
        self.key2Node = {}

        # 记录当前链表中节点的个数和最大容量
        self.size = 0   # size 其实可用 len(self.key2Node) 代替，但为了清楚还是单独定义一个成员变量记录
        self.capacity = capacity

    def get(self, key: int) -> int:
        # 首先看链表中是否有对应 key 的 ListNode
        target = self.__searchByKey(key)
        if target is None:
            return -1
        else:
            # 更新 target 在链表中的位置，即把 target 抽出来重新放在链表的末端，作为「最近被使用的」节点即可
            value = target.val
            self.__removeByKey(key)
            self.__append(key, value)
            return value

    def put(self, key: int, value: int) -> None:
        # 判空
        # if self.capacity == 0:  # 这个不必要，因为题目保证了 capacity >= 1
        #     # 保证不要删除self.head节点
        #     return 

        # 首先尝试在链表中找对应 key 的 ListNode
        target = self.__searchByKey(key)
        if target is None:
            # 表示 key 是一个新的 key
            if self.size == self.capacity:
                # 如果当前链表中的节点数已经等于了最大容量
                # 那么先将「最久未使用的」节点，即self.head.next删除（这里由于题目中保证输入 capacity >= 1，所以不用考虑 capacity=0 时会删除 self.tail 的情况）
                self.__removeByKey(self.head.next.key)
                # 然后创建新节点，并插入到链表尾部
                self.__append(key, value)
            else:
                # 如果当前链表中节点数还没有达到最大容量，直接在尾部插入即可
                self.__append(key, value)
        else:
            # 表示 key 对应的 ListNode 在链表中
            # 那么删除该 ListNode，在尾部重新插入新value的 ListNode即可
            self.__removeByKey(key)
            self.__append(key, value)

    # 定义私有方法：向链表的尾部加入 ListNode
    def __append(self, key: int, val: int) -> None:
        lastNode = self.tail.prev
        
        # 创建newNode
        newNode = ListNode(key, val)

        # 修改lastNode, self.tail之间的指针，并初始化newNode的两头指针（下面的后两行其实可以放在创建newNode时一起初始化，这里为了清楚就和修改指针放在一起)
        lastNode.next = newNode
        self.tail.prev = newNode
        newNode.next = self.tail
        newNode.prev = lastNode

        # 在字典中记录
        self.key2Node[key] = newNode

        # 更新size
        self.size += 1

    # 定义私有方法：删除链表中为 key 的 ListNode
    def __removeByKey(self, key: int) -> None:
        node = self.key2Node.get(key, None)
        if node is not None:
            node.prev.next = node.next
            node.next.prev = node.prev
            del self.key2Node[key]
            self.size -= 1
    
    # 定义私有方法：尝试在链表中找到 key=key 的ListNode，如果没有则返回None
    def __searchByKey(self, key: int) -> ListNode:
        target = self.key2Node.get(key, None)
        return target


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

# 参考以前账号写的结果，应该当时参考了某篇文章：这个解法所有的数据结构是 dictionary, doubly linked list
# 因为要做到 O(1) 时间的增删，应该想到的不是数组，而是链表
# 但链表的问题是如何在 O(1) 时间内定位到要找的 key，所以接下来应该会想到 dictionary，当时写时应该是这个思路
# 这道题感觉难点在于：
#   1. 想到用双向量表
#   2. dictionary 中的 key，value 分别存什么
#   3. 通过定义私有方法来简化 get 和 put 操作（否则会有一对if-else判断）
#   4. 这道题真的很考验「细节」还有对 LRU缓存 的理解啊
