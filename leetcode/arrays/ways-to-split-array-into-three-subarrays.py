class Solution:
    def waysToSplit(self, nums: List[int]) -> int:
        nw = 0
        for i in range(1, len(nums)):
            nums[i] += nums[i-1]
        print(nums)
        for i in range(len(nums)-2):
            l = bisect.bisect_left(nums, 2 * nums[i] ,i+1, len(nums)-1)
            r = bisect.bisect_right(nums, (nums[len(nums)-1] + nums[i])/2, i+1, len(nums)-1 )
            if (l <= r):
                nw = (nw + r-l) % 1000000007
        return nw
