class Solution {
private:
    vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0, -1}};

    bool find(vector<vector<int>>& vis, vector<vector<char>>& board, string word, int i, int j, int ind){
        int n =  board.size();
        int m = board[0].size();
        
        if (ind == word.size()) return true;
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] == 1 || board[i][j] != word[ind]) {
            return false;
        }
        
        vis[i][j] = 1;
        bool ans = false;
        for (auto d : dir) {
            int row = d[0] + i;
            int col = d[1] + j;
            ans = ans || find(vis, board, word, row, col, ind + 1);
        }
        vis[i][j] = 0;  // Backtrack
        return ans;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<vector<int>> vis(n, vector<int>(m, 0));
                if (find(vis, board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
