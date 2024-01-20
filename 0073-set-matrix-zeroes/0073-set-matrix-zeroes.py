class Solution:


    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix[0])
        m = len(matrix)

        col_zero, row_zero = self.find_zeros(matrix)

        for i in range(m):
            if row_zero[i]==1:
                for j in range(n):
                    matrix[i][j] =0 


        for j in range(n):
            if col_zero[j]==1:
                for i in range(m):
                    matrix[i][j] =0 
            
    def find_zeros(self, matrix: List[List[int]]) -> List[int]: 
        n = len(matrix[0])
        m = len(matrix)
        col_zero = [0]*n
        row_zero = [0]*m
        for i in range(m): #0이 있는 행,렬 찾기
            for j in range(n):
                if matrix[i][j] ==0:
                    col_zero[j] = 1
                    row_zero[i] = 1

        return col_zero, row_zero