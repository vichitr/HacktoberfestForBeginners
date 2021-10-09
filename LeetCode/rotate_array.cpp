class Solution {
public:
    void rotate(vector<int>& vec1, int k) {
        int len = vec1.size();
       k = k % len;
      std:: rotate(vec1.begin(), vec1.begin()+k+1, vec1.end());
    }
};