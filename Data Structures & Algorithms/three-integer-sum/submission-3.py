class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        res = []
        for i in range(n - 2):
            cur = nums[i]
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            if cur > 0:
                break
            l = i + 1
            r = n - 1
            while l < r:
                total = cur + nums[l] + nums[r]
                if total == 0:
                    res.append([cur, nums[l], nums[r]])
                    l += 1
                    r -= 1
                    while l < r and nums[l] == nums[l - 1]:
                        l += 1
                    while r > l and nums[r] == nums[r + 1]:
                        r -= 1
                elif total > 0:
                    r -= 1
                else:
                    l += 1
        
        return res