#include <queue>
#include <map>
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); //m = 4
        int n = grid[0].size(); //n = 5
        std::pair<int, int> currPair;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        std::queue<std::pair<int, int>> q;
        int cnt = 0;

        for (int i=0 ; i<m; i++){
            for (int j=0 ; j<n; j++){
                if (visited[i][j]){
                    continue;
                }
                if (grid[i][j]=='1') {
                    q.push(make_pair(i,j));
                    visited[i][j] = true;
                    while (!q.empty()){
                        currPair = q.front();
                        q.pop();
                        int ii = currPair.first;
                        int jj = currPair.second;
                        
                        if (ii+1<m && (!visited[ii+1][jj]) && (grid[ii+1][jj]=='1')) {

                            q.push(make_pair(ii+1,jj)); 
                            visited[ii+1][jj] = true;
                        }
                        if (ii>0  && (!visited[ii-1][jj])  && (grid[ii-1][jj]=='1')) {
                            q.push(make_pair(ii-1,jj));
                            visited[ii-1][jj] = true;
                        }
                        if (jj+1<n  && (!visited[ii][jj+1]) && (grid[ii][jj+1]=='1')) {
                            q.push(make_pair(ii,jj+1));
                            visited[ii][jj+1] = true;
                        }
                        if (jj>0  && (!visited[ii][jj-1])  && (grid[ii][jj-1]=='1')) {
                            q.push(make_pair(ii,jj-1));
                            visited[ii][jj-1] = true;
                        }
                    }
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};