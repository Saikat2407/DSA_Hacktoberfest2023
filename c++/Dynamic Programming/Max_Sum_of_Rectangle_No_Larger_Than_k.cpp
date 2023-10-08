class Solution {
public:
    void findMaxLessThanK(vector<int>& nums, int k, int &result) {
        int cuSum  = 0;
        int maxSum  = INT_MIN;
        set<int> st;
        st.insert(0);

        for(int i = 0; i<nums.size(); i++) {
            cuSum += nums[i];
            auto it = st.lower_bound(cuSum-k);

            if(it != end(st)) {
                maxSum = max(maxSum, cuSum-*it);
            }
            st.insert(cuSum);
        }

        result = max(result, maxSum);
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows   = matrix.size();
        int cols   = matrix[0].size();
        int result = INT_MIN;

        for(int L = 0; L<cols; L++) {
            vector<int> temp(rows, 0);
            for(int R = L; R<cols; R++) {

                for(int row = 0; row < rows; row++)
                    temp[row] += matrix[row][R];

                findMaxLessThanK(temp, k, result);            
            }
        }
        return result;
    }
};
