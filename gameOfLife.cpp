class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        if (board.empty() || board[0].empty())
        return;

    int m = board.size();
    int n = board[0].size();

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int live_neighbors = 0;

            for (const auto& direction : directions) {
                int dx = direction.first;
                int dy = direction.second;
                int x = i + dx;
                int y = j + dy;

                if (x >= 0 && x < m && y >= 0 && y < n && abs(board[x][y]) == 1)
                    live_neighbors++;
            }

            if (board[i][j] == 1 && (live_neighbors < 2 || live_neighbors > 3))
                board[i][j] = -1;

            if (board[i][j] == 0 && live_neighbors == 3)
                board[i][j] = 2;
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] > 0)
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }
        
    }
};