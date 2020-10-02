#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;

    unordered_map<string,string> ansmap;
    string tag = "",att,val;

    for(int i=0 ;i<n ;i++)
    {
        string tempTag;
        cin>>tempTag;
        bool skip=false;

        if(tempTag[1]!='/')
        {
            if(tempTag[tempTag.size()-1] == '>')
            {
                tempTag = tempTag.substr(1,tempTag.size()-2);
                skip = true;
            }
            else
            {
                tempTag = tempTag.substr(1);
            }

            if(tag.size() == 0)
                tag = tempTag;
            else
                tag = tag +'.' + tempTag;

            if(skip)
            {
                continue;
            } 
        
            bool lastAtt = false;

            do
            {
                cin>>att;
                cin>>val>>val;

                if(val[val.size()-1] == '>')
                {
                    val = val.substr(1,val.size()-1);
                    lastAtt = true;
                }
                val = val.substr(1,val.size()-2);
                ansmap[tag + '~' + att] = val;
            } while (!lastAtt);          
       }
        else
        {
            int i =int(tag.size()-1);

            for(;i>=0;i--)
            {
                if(tag[i] == '.')
                    break;
            }

            if(i==-1)
                tag = "";
            else
                tag = tag.substr(0,i);    
        }
        
    }

    for(int i=0 ;i < q; i++)
    {
        string query;
        cin>>query;
        if(ansmap.count(query))
            cout<<ansmap[query]<<endl;
        else
                cout<<"Not Found"<<endl;    
    }

    return 0;
}