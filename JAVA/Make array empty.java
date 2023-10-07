//Problem link::https://leetcode.com/problems/make-array-empty/
class Solution {
    int[] seg;
    void build(int index,int start,int end){
        if(start==end){
            seg[index] = 1;
            return;
        }
        int mid = (start+end)/2;
        build(2*index,start,mid);
        build(2*index+1,mid+1,end);
        seg[index] = seg[2*index]+seg[2*index+1];
    }
    int query(int index,int start,int end,int left,int right){
        if(left>right) return 0;
        if(right<start || left>end) return 0;
        if(left<=start && end<=right) return seg[index];
        int mid = (start+end)/2;
        int l = query(index*2,start,mid,left,right);
        int r = query(index*2+1,mid+1,end,left,right);
        return l+r;
    }
    void update(int index,int start,int end,int pos){
        if(pos<start || pos>end) return;
        if(pos==start && pos==end){
            seg[index] = 0; 
            return;
        }
        int mid = (start+end)/2;
        update(index*2,start,mid,pos);
        update(index*2+1,mid+1,end,pos);
        seg[index] = seg[2*index]+seg[2*index+1];
    }
    public long countOperationsToEmptyArray(int[] nums) {
        int n = nums.length;
        int[][] numsI = new int[n][2];
        for(int i=0; i<nums.length; i++){
            numsI[i][0] = nums[i];
            numsI[i][1] = i;
        }
        Arrays.sort(numsI,(a,b)->(a[0]-b[0]));
        seg = new int[4*n];
        build(1,0,n-1);
        int prev = -1;
        int index = 0;
        long ans = 0;
        while(index<n-1){
            int curIndex = numsI[index][1];
            if(curIndex>prev){
                int present = query(1,0,n-1,prev+1,curIndex-1);
                ans+=(present+1);
            }else{
                int present = query(1,0,n-1,prev+1,n-1);
                present+=query(1,0,n-1,0,curIndex-1);
                ans+=(present+1);
            }
            index++;
            update(1,0,n-1,curIndex);
            prev = curIndex;
        }
        return ans+1;
    }
}
