class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0 
        r = len(numbers) - 1

        while l < r:
            total = numbers[l] + numbers[r]

            if total == target:
                return [1 + l, 1 + r]
            elif total > target:
                r -= 1
            else:
                l += 1