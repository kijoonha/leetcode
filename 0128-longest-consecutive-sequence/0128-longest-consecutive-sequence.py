import numpy as np

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        aa = np.sort(nums)
        nums1 = aa[:-1]
        nums2 = aa[1:]
        diff = np.array(nums2) - np.array(nums1)
        mm = 0
        mmm = 0
        for ii in range(len(diff)):
            if (diff[ii]==1):
                mm = mm+1
            elif (diff[ii]==0):
                continue
            else:
                mm = 0
            print(mm)
            if mm > mmm:
                mmm = mm
        return mmm+1
