class Solution {
    void add(vector<int> &ans, vector<vector<int>>& matrix, int minRow, int maxRow, int minCol, int maxCol, int &count, int total) {
        for (int j = minCol; j <= maxCol && count < total; j++) {
            ans.push_back(matrix[minRow][j]);
            count++;
        }
        for (int i = minRow + 1; i <= maxRow && count < total; i++) {
            ans.push_back(matrix[i][maxCol]);
            count++;
        }
        for (int j = maxCol - 1; j >= minCol && count < total; j--) {
            ans.push_back(matrix[maxRow][j]);
            count++;
        }
        for (int i = maxRow - 1; i > minRow && count < total; i--) {
            ans.push_back(matrix[i][minCol]);
            count++;
        }
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int n = matrix.size();
        int m = matrix[0].size();
        int minRow = 0, minCol = 0, maxRow = n - 1, maxCol = m - 1;
        vector<int> ans;
        int count = 0;
        int total = n * m;
        while (count < total) {
            add(ans, matrix, minRow, maxRow, minCol, maxCol, count, total);
            minRow++;
            maxRow--;
            minCol++;
            maxCol--;
        }
        return ans;
    }
};
