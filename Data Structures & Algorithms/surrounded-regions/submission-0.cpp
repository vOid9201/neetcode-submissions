class Solution {
public:

    vector<vector<int>> movt = {{0,-1},{0,1},{-1,0},{1,0}};

    void solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        queue<pair<int,int>> qt;

        for(int i=0;i<n;i++){
            if(board[i][0] == 'O')  qt.push({i,0});
            if(board[i][m-1] == 'O') qt.push({i,m-1});
        }
        for(int j=0;j<m;j++){
            if(board[0][j] == 'O' and j > 0 and j < m - 1) qt.push({0,j});
            if(board[n-1][j] == 'O' and j > 0 and j < m-1) qt.push({n-1,j});
        }


        while(!qt.empty()){
            int curr_i = qt.front().first , curr_j = qt.front().second;
            qt.pop();

            if(vis[curr_i][curr_j]) continue;
            vis[curr_i][curr_j] = true;

            for(auto x : movt){

                int n_i = curr_i+x[0] , n_j = curr_j+x[1];
                if(n_i >= 0 and n_i < n and n_j >= 0 and n_j < m and board[n_i][n_j] == 'O'
                and !vis[n_i][n_j]){
                    qt.push({n_i,n_j});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and board[i][j] == 'O') board[i][j] = 'X';
            }
        }

        return;
    }
};
