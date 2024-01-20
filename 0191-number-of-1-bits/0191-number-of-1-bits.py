class Solution:
    def hammingWeight(self, n: int) -> int:
        nn = n
        count = 0
        while nn>0 :
            if nn%2==1:
                count+=1
            nn = nn//2    
            
        return count