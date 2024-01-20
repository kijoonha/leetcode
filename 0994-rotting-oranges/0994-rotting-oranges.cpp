class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, -1, 0, 1};

        int m = grid.size(); //m = 4
        int n = grid[0].size(); //n = 5
        pair<pair<int, int>, int> currPair;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q;
        int tmax = 0;

        //grid==2를 q에 넣기
        for (int i=0 ; i<m ; i++){
            for (int j=0; j<n ; j++){
                if( grid[i][j]==2){
                    q.push({{i, j},0});
                    visited[i][j]=true;
                }
            }
        }

        for (int i=0 ; i<m ; i++){
            for (int j=0; j<n ; j++){

                while(!q.empty()){
                    currPair = q.front();
                    q.pop();
                    for (int i=0; i<4; i++){
                        int ii = currPair.first.first+dRow[i];
                        int jj = currPair.first.second+dCol[i];
                        int t = currPair.second;
                        if (t>tmax){
                            tmax = t;
                        }
                        if( isValid(ii, jj, visited, grid)){
                            q.push({{ii,jj},t+1});
                            visited[ii][jj]=true;
                            grid[ii][jj]=2;

                        }
                    }
                }
            }
        }
        for (int i=0 ; i<m ; i++){
            for (int j=0; j<n ; j++){
                cout<<"grid: "<<grid[i][j]<<endl;
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return tmax;
    }
    

    bool isValid(int Row, int Col, vector<vector<bool>> &visited, vector<vector<int>> & grid){
        if (Row>=grid.size() || Row<0 || Col >= grid[0].size() || Col<0){
            cout<<"row: "<<Row<<" Col : "<<Col<<"first";
            return false;
        }
        else if (grid[Row][Col] == 0 || grid[Row][Col]==2|| visited[Row][Col]){
            cout<<"second";
            return false;
        }
        else return true;

    } 

    
};
