class Solution {
public:
    int guessNumber(int n) {
        
        // -1 mtlb num > target 
        // 1 num < target
        int mid =0;
        
        int s = 0;
        int e = n;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(guess(mid)==0){
                return mid;
            }
            else if(guess(mid)== -1){
                e = mid-1;
            }
            else{
                
                s = mid+1;
            }
        }
        
        return -1;
    
    }
};