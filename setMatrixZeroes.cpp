class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int m = matrix[0].size();
        unordered_set<int> rows;
        unordered_set<int> cols;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto row:rows)
        {
            for(int j=0;j<m;j++)
            {
                matrix[row][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(auto col:cols)
            {
                matrix[i][col]=0;
            }
        }
    }
};