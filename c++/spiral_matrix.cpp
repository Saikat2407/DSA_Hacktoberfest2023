class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int top=0;
        int left=0;
        int n = mat.size();
        int m = mat[0].size();
        int bottom =n-1;
        int right = m-1;
        vector<int> ans;
        while(top<=bottom && left<=right)
        {
            for(int i = left;i<=right;i++)
            {
                ans.push_back(mat[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                ans.push_back(mat[i][right]);
            }
            right--;
             if (top > bottom || left > right) break;
            for(int i =right ;i>=left;i--)
            {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
            for(int i=bottom;i>=top;i--)
            {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
        return ans;
    }
};