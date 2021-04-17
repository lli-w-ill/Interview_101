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

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.stack = []
        # 初始化：将 nestedList 中所有元素（不 flatten）逆序放入 stack 中
        for i in range(len(nestedList)-1, -1, -1):
            self.stack.append(nestedList[i])
    
    def next(self) -> int:
        # 因为在 hasNext 中如果发现栈顶元素是list，则会flatten，所以不用担心当前栈顶元素是list
        cur = self.stack.pop()
        return cur.getInteger()
    
    def hasNext(self) -> bool:
        while self.stack:
            # 访问栈顶元素
            top = self.stack[-1]
            
            if top.isInteger():
                # 如果栈顶元素是 int，那么不做任何操作，返回True
                return True
            else:
                # 如果栈顶元素是 list，那么flatten，并逆序将list中所有元素加入到stack中
                self.stack.pop()    # 弹出list（因为现在top就是那个list）
                # 逆序加入
                for i in range(len(top.getList())-1, -1, -1):
                    self.stack.append(top.getList()[i])
        # 如果当前栈已经为空，则没有下一个元素了，返回False
        return False


# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())

# 参考题解（非常推荐）：https://leetcode-cn.com/problems/flatten-nested-list-iterator/solution/fu-xue-ming-zhu-xiang-jie-ti-yi-shu-li-d-n4qa/
# 方法二（要掌握）：在调用 hasNext(), next() 时扁平化当前的嵌套子列表
# 这个方法比 Soln_1 中方法一更好，因为这个方法是一边迭代，一边扁平化获取当前元素的结果
