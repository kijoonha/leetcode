import numpy as np

class Solution:
    
    def rowchecker(self, board):
        for ii in range(9):
            row = board[ii]
            counts = np.unique(row, return_counts=True)
            #print(counts)
            if len(counts[1][1:])==0:
                continue
            maxcounts = max(counts[1][1:])
            if maxcounts>1:
                return False
        return True

    def colchecker(self, board):
        for ii in range(9):
            col = [item[ii] for item in board]
            counts = np.unique(col, return_counts=True)
            #print(counts)
            if len(counts[1][1:])==0:
                continue
            maxcounts = max(counts[1][1:])
            if maxcounts>1:
                return False
        return True

    def subgroupchecker(self, board):
        for ii in range(9):
            rowset = board[(ii//3)*3:(ii//3)*3+3]
            subgroup = [item[(ii%3)*3:(ii%3)*3+3] for item in rowset]
            counts = np.unique(subgroup, return_counts=True)
            #print(counts)
            if len(counts[1][1:])==0:
                continue
            maxcounts = max(counts[1][1:])
            if maxcounts>1:
                return False
        return True

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        return self.rowchecker(board) and self.colchecker(board) and self.subgroupchecker(board)

        
            