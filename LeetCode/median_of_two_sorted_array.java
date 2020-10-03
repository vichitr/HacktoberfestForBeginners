class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        
             if (nums1.length == 0 && nums2.length == 0) {
            throw new IllegalArgumentException("both arrays can not be empty");
        }
        int[] pq = new int[nums1.length + nums2.length];
        int c = 0;
        for (int i = 0; i < nums1.length; i++) {
            pq[c++] = nums1[i];
        }
        for (int i = 0; i < nums2.length; i++) {
            pq[c++] = nums2[i];
        }
        Arrays.sort(pq);

        if (!isEven(pq.length)) {
            // take the middle of the both combined
            return (int) pq[(pq.length)/2] * 1.0;

        } else {
            // take the middle of two both combined
            int n1 = pq[(pq.length-1) / 2];
            int n2 = pq[(pq.length-1) / 2 + 1];
            return (n1+n2) / 2.0;
        }
    }

    private boolean isEven(int num) {
        return num % 2 == 0;
    

    } 
   
}
