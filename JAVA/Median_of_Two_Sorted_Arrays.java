// Leetcode problem
// https://leetcode.com/problems/median-of-two-sorted-arrays/

public class Median_of_Two_Sorted_Arrays {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int i1=0;
        int i2=0;
        int i=0;
        int[] numsMerged = new int[nums1.length + nums2.length];
        while(i1 < nums1.length && i2 < nums2.length){
            if(nums1[i1]<nums2[i2]){
                numsMerged[i]=nums1[i1];
                i1++;
            }else{
                numsMerged[i]=nums2[i2];
                i2++;
            }
            i++;
        }
        while(i1<nums1.length){
            numsMerged[i]=nums1[i1];
            i1++;
            i++;
        }
        while(i2<nums2.length){
            numsMerged[i]=nums2[i2];
            i2++;
            i++;
        }
    
        if ((nums1.length + nums2.length) % 2 != 0) {
            return numsMerged[(nums1.length + nums2.length) / 2];
        } else {
            int middle1 = numsMerged[((nums1.length + nums2.length) / 2) - 1];
            int middle2 = numsMerged[(nums1.length + nums2.length) / 2];
            return (double) (middle1 + middle2) / 2.0;
        }

    }
}
