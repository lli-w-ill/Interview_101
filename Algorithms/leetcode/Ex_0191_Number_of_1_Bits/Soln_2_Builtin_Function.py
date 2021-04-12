class Solution_2:
    def hammingWeight(self, n: int) -> int:
        return bin(n).count("1")
