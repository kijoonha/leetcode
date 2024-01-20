from math import floor, log10
class Solution:
    def reverseBits(self, n: int) -> int:
        

        nn = n
        result = 0
        idx =1
        while nn>0:
            result += (nn%2)*2**(32-idx)
            nn = nn//2    
            idx+=1
        return result   
         
