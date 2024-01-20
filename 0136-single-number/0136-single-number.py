
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        count_dict = {num : 0 for num in nums}
        result = 0
        for i in range(len(nums)):
            count_dict[nums[i]] += 1
        
        for i in range(len(nums)):
            if count_dict[nums[i]] ==1:
                result = nums[i]

        return result
        
