class Solution:

    def check(self, board: List[List[str]], i:int, j:int) -> bool:
        p=i//3
        q=j//3

        #cheking the box
        for x in range(3*p, 3*p+3):
            for y in range(3*q, 3*q+3):
                if(x!=i and y!=j and board[x][y]==board[i][j]):
                    print(x, y, i, j)
                    return False
        

        for x in range(len(board)):
            if(x!=i and board[x][j]==board[i][j]):
                print(x, y, i, j)
                return False

        for y in range(len(board[0])):
            if(y!=j and board[i][y]==board[i][j]):
                print(x, y, i, j)
                return False
        
        return True


    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(len(board)):
            for j in range(len(board[0])):
                if(board[i][j]!='.' and not self.check(board, i, j)):
                    return False
                    
        return True
        