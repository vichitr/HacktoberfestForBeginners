class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = 0,high = m*n-1,row,col;
        while(low<=high)
        {
            int mid = (low+high)/2;
            row = mid/n;
            col = mid%n;
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]>target)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;      
    }
};