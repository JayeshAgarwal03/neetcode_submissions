class Solution {
public:
    bool isValid(vector<string> &board, int i, int j){
        int p=i-1, q=j-1;
        
        while(p>=0 && q>=0){
            if(board[p][q]=='Q'){
                return false;
            }
            p--; q--;
        }

        p=i+1; q=j+1;
        while(p<board.size() && q<board.size()){
            if(board[p][q]=='Q'){
                return false;
            }
            p++; q++;
        }

        p=i-1; q=j+1;
        while(p>=0 && q<board.size()){
            if(board[p][q]=='Q'){
                return false;
            }
            p--; q++;
        }
        
        p=i+1; q=j-1;
        while(p<board.size() && q>=0){
            if(board[p][q]=='Q'){
                return false;
            }
            p++; q--;
        }

        p=0;
        for(p; p<board.size(); p++){
            if(p!=i){
                if(board[p][j]=='Q'){
                    return false;
                }
            }
        }

        q=0;
        for(q; q<board.size(); q++){
            if(q!=j){
                if(board[i][q]=='Q'){
                    return false;
                }
            }
        }

        return true;

    }
    void f(vector<string> &board, vector<vector<string>> &ans, int i, int j){
        if(j>=board.size()){
            return;
        }
        else if(i==board.size()){
            ans.push_back(board);
            return;
        }
        //cout<<i<<" "<<j<<"\n";

        for(int y=0; y<board.size(); y++){
            board[i][y]='Q';
            //cout<<isValid(board, i, y)<<"\n";
            if(isValid(board, i, y)){
                
                f(board, ans, i+1, 0);
            }
            board[i][y]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i=0; i<n; i++){
            s.push_back('.');
        }
        vector<string> board(n, s);
        vector<vector<string>> ans;

        // all the columns in the 0th row will be checked in the recursive function itself.
        // this loop pushes back duplicate valid soltions in the ans vector.
        // for(int j=0; j<n; j++){
        //     f(board, ans, 0, j);
        // }

        f(board, ans, 0, 0);

        return ans;
    }
};
