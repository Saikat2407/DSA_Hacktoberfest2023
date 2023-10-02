class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left_max[n];
        left_max[0]=height[0];
        for(int i=1;i<n;i++){
           left_max[i]=max(height[i],left_max[i-1]);
        }
        int right_max[n];
        right_max[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
           right_max[i]=max(height[i],right_max[i+1]);
        }
        int trapped_water=0;
        for(int i=0;i<n;i++){
           int water_level=min(right_max[i],left_max[i]);
            trapped_water+=water_level-height[i];
        }
        return trapped_water;
    }
};