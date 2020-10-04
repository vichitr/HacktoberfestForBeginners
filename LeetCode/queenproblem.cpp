class Solution {
public:
    bool helper(vector<string> & ans,int r,int c)
    {
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i][c]=='Q')
                return false;
        }
        for(int j=0;j<ans.size();j++)
        {
            if(ans[r][j]=='Q')
                return false;
        }
        int r1=r-1;
        int c1=c-1;
        while(r1>=0 && c1>=0)
        {
            if(ans[r1][c1]=='Q')
                return false;
            r1--;
            c1--;
        }
        r1=r-1;
        c1=c+1;
        while(r1>=0 && c1<ans.size())
        {
            if(ans[r1][c1]=='Q')
                return false;
            r1--;
            c1++;
            
        }
        return true;
        
    }
    void queen( vector<vector<string>>&res,vector<string> & ans,int row,int left)
    {
        if(row==ans.size())
        {
            if(left==0)
                res.push_back(ans);
                
        }
        for(int j=0;j<ans.size();j++)
        {
               if(helper(ans,row,j))
               {
                   ans[row][j]='Q';
                   queen(res,ans,row+1,left-1);
                   ans[row][j]='.';
               }
            
                
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> ans(n,string(n,'.'));
        queen(res,ans,0,n);
        return res;
        
    }
};
