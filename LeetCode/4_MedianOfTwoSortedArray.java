class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int a[]= new int[nums1.length+nums2.length];
        for(int i=0;i<nums1.length;i++)
        {
            a[i]=nums1[i];
        }
        int k=0;
        for(int j=nums1.length;j<a.length;j++)
        {
            a[j]=nums2[k];
            k++;
        }
        Arrays.sort(a);
        double median;
        if(a.length%2==1)
        {
            median=a[a.length/2];
        }
        else{
            median=(a[a.length/2]+a[(a.length/2)-1])/2.0;
        }
    return median;
    }
}