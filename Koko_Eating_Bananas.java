
// Ques link -> https://leetcode.com/problems/koko-eating-bananas/

class Koko_Eating_Bananas {

    public boolean pos(int mid,int arr[],int h){

        int t = 0;

        for(int i : arr){
            t+= Math.ceil(i*1.0/mid); // Imp
        }
        
        return t<=h;
    }
    public int minEatingSpeed(int[] arr, int h) {

    int min = 1; int max = arr[0]; int ans = 0;

    for(int i : arr){
        max  = Math.max(i,max);
    }

      int si = min; int ei = max;
        
        while(si<=ei){
          
          int mid = (si+ei)/2;

          if(pos(mid,arr,h)){
              ans = mid;
              ei = mid-1;
          }
          else si = mid+1;
        }
        
        return ans;   
    }
}