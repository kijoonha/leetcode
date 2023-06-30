class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
        
        //row 확인
        for (int i=0 ; i<board.size();i++){
            set<char> s1;
            pair<set<char>::iterator, bool> ret1 = {set<char>::iterator{}, true};
            for (int j=0; j<board[0].size();j++){
                if (board[i][j] =='.')
                    continue;
                ret1 = s1.insert(board[i][j]);
                if (!ret1.second){                     
                    return false;
                }
            }
            s1.clear();
        }
            
        //column확인
        for (int j=0 ; j<board.size();j++){
            set<char> s2;
            pair<set<char>::iterator,bool> ret2 = {set<char>::iterator{}, true};
            for (int i=0; i<board[0].size();i++){
                if (board[i][j] =='.')
                    continue;
                ret2 = s2.insert(board[i][j]);
                if (!ret2.second){
                    return false;
                }
            }
            s2.clear();            
        }
        
        //small box확인
        int ii=0;
        int jj=0;
        for (int i=0 ; i<board.size();i++){
            set<char> s3;
            pair<set<char>::iterator,bool> ret3 = {set<char>::iterator{}, true};
            
            for (int j=0; j<board[0].size();j++){
                jj = ((int)(ii/9) * 3) + j%3 ;
                
                //.아닐경우만
                if (board[ii%9][jj] !='.'){
                    ret3 = s3.insert(board[ii%9][jj]);
                }                    
                if (!ret3.second){
                    cout<<3;
                    return false;
                }                    
                if (jj%3==2){                      //jj가 2일때,5일때, 8일때 i를 1씩 올리기
                    if (ii%3==2 && jj%3==2){       //9개 다 돌면 reset해야함
                        cout<<"clear";
                        s3.clear();}
                    ii++; 
                }
            }
        }
        return true;
    }
};