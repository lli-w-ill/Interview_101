import os 
import copy
from typing import List, Tuple


class Solution:
    def findSecondMaxNumAndIndex(self, nums: List[int]) -> Tuple[int, List[int]]:
        firstMax = nums[0]
        firstMaxIndices = [0]
        secondMax = float('-inf')
        secondMaxIndices = []
        for i in range(1, len(nums)):
            if nums[i] > firstMax:
                # 更新第二大的数，和其坐标
                secondMax = firstMax
                secondMaxIndices.clear()
                secondMaxIndices = copy.copy(firstMaxIndices)   # 注意这里要拷贝firstMaxIndices，而不能单独低直接赋值，否则secondMaxIndices和firstmaxIndices将指向相同 list 对象
                # 更新第一大的数，和其坐标
                firstMax = nums[i]
                firstMaxIndices.clear()
                firstMaxIndices.append(i)
            elif nums[i] == firstMax:
                firstMaxIndices.append(i)
            elif nums[i] > secondMax:
                secondMax = nums[i]
                secondMaxIndices.clear()
                secondMaxIndices.append(i)
            elif nums[i] == secondMax:
                secondMaxIndices.append(i)
            else:
                continue
        return secondMax, secondMaxIndices


if __name__ == '__main__':
    curPath = os.path.dirname(os.path.realpath(__file__))
    filename = 'numbers.txt'
    soln = Solution()
    with open(curPath + '/' + filename, 'r') as reader:
        content = reader.readline()
        cnt = 1
        while content != '':
            nums = [int(num) for num in content if num.isdigit()]
            print('输入数组 =', nums)
            secondMax, secondMaxIndices = soln.findSecondMaxNumAndIndex(nums)
            print('第二大的数 =', secondMax)
            print('第二大的数的下标 =', secondMaxIndices)
            print('==================================================')
            content = reader.readline()
