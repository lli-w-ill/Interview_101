from collections import Counter

class Solution_1:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counter = Counter(tasks)
        # 桶的个数就是重复次数最多的任务的个数
        nbucket = counter.most_common(1)[0][1]
        # 最后一个桶中的任务个数
        last_bucket_size = list(counter.values()).count(nbucket);
        NUM1 = (nbucket - 1) * (n + 1) + last_bucket_size   # 有空闲时间时所需要的时间
        NUM2 = len(tasks)    # 没有浪费空闲时间时所需要的时间
        # print(NUM1, NUM2)
        # 没有浪费空闲时间时，即所有任务都“见缝插针”交叉执行时，NUM2 > NUM1
        # 当有空闲时间，即中间有什么任务也不执行的天数时，NUM1 > NUM2
        return max(NUM1, NUM2);    # 为什么要求大数，见参考题解最后一张解释图（注意这个解释图中n依旧是2，只不过因为没有浪费空闲时间所以NUM2 > NUM1）


# 参考题解（强烈推荐）：https://leetcode-cn.com/problems/task-scheduler/solution/tong-zi-by-popopop/
# 「桶思想」（强烈推荐）：https://leetcode-cn.com/problems/task-scheduler/solution/tong-si-xiang-jian-ji-gao-xiao-by-hzhu212/
# 想法：同一个桶中不能放入相同的任务，所以桶的个数就是需要执行次数最多的任务的个数（假设为A），因为需要将每个任务A分到一个桶中
#      除了最后一个桶，前面所有桶所需要的时间都是 n+1（执行需要时间1，冷却需要时间n），最后一个桶所需要的时间就等于它里面任务的个数
