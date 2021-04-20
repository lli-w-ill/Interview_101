from itertools import groupby

class Err_2:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        res = 0
        dict_1 = {key: len(list(group)) for key, group in groupby(nums1)}
        dict_2 = {key: len(list(group)) for key, group in groupby(nums2)}
        dict_3 = {key: len(list(group)) for key, group in groupby(nums3)}
        dict_4 = {key: len(list(group)) for key, group in groupby(nums4)}

        print(dict_1)
        print(dict_2)
        print(dict_3)
        print(dict_4)

        for key_1 in dict_1.keys():
            for key_2 in dict_2.keys():
                for key_3 in dict_3.keys():
                    for key_4 in dict_4.keys():
                        if sum([key_1, key_2, key_3, key_4]) == 0:
                            res = res + dict_1[key_1] * dict_2[key_2] * dict_3[key_3] * dict_4[key_4]
                            print(key_1, key_2, key_3, key_4)

        return res

# groupby 计算数组中各个元素的出现次数 参考：https://stackoverflow.com/questions/2161752/how-to-count-the-frequency-of-the-elements-in-an-unordered-list
# 
# 错误测试用例：
'''
[1,-1,-1]
[-1,-1,1]
[1,-1,0]
[1,-1,1]
'''
# 预期结果：21
# 实际输出：13
