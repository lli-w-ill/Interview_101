# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

import collections

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.queue = collections.deque();
        # 扁平化整个嵌套列表
        self.dfs(nestedList)
    
    def next(self) -> int:
        return self.queue.popleft()
    
    def hasNext(self) -> bool:
        return len(self.queue)

    def dfs(self, nests: [NestedInteger]):
        for nest in nests:
            if nest.isInteger():
                self.queue.append(nest)
            else:
                self.dfs(nest.getList())

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())

# 参考题解（非常推荐）：https://leetcode-cn.com/problems/flatten-nested-list-iterator/solution/fu-xue-ming-zhu-xiang-jie-ti-yi-shu-li-d-n4qa/
# 方法一：在构造函数中提前扁平化整个嵌套列表
