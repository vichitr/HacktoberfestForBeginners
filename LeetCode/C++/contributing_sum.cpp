class Solution {
public:
    map<vector<int>,bool> m;
    void recurse(vector<int>&candidates, int target,vector<int> ans){
        if(target == 0){
            sort(ans.begin(),ans.end());
            m[ans] = true;
            return;
        }
        for(int i=0;i<candidates.size();i++){
            if(target-candidates[i]>=0){
                vector<int> temp = ans;
                temp.push_back(candidates[i]);
                recurse(candidates,target-candidates[i],temp);
            }
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> ans;
        recurse(candidates,target,ans);
        for(auto x: m)
            if(x.second)
                v.push_back(x.first);
        return v;
    }
};
