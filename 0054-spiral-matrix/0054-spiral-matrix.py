class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:

        ################
        start_i=0 
        start_j=0 
        end_i = len(matrix)
        end_j = len(matrix[0])

        index= 0
        result = []

        while start_i<end_i and start_j<end_j:
            if index%4 == 0:
                for jj in range(start_j, end_j):
                    result.append(matrix[start_i][jj])
                start_i +=1

            elif index%4 ==1:
                for ii in range(start_i, end_i):
                    result.append(matrix[ii][end_j-1])
                end_j-=1


            elif index%4 ==2:
                for jj in range(end_j-1, start_j-1, -1):
                    result.append(matrix[end_i-1][jj])
                end_i-=1

            elif index%4 ==3:
                for ii in range(end_i-1, start_i-1, -1):
                    result.append(matrix[ii][start_j])

                start_j += 1

            index+=1
        return result    
            


