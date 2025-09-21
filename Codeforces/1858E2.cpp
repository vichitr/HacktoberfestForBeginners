#include <bits/stdc++.h>
using namespace std;


void display(vector <int> temp)
{
    int si = temp.size();
    for (int m=0;m<si;m++)
    {
        cout<<temp[m]<<endl;
    }

};

void distinct(vector <int> new_temp)

{
    vector <int> new_temp1 = new_temp;
    sort(new_temp1.begin(),new_temp1.end());

    auto it = unique(new_temp1.begin(), new_temp1.end());

    new_temp1.resize(distance(new_temp1.begin(), it));
    cout<<new_temp1.size()<<endl;

    // return c;
};


int main()
{
    vector <int> main_arr= {};
    vector <int> copy_arr = {};
    int q=0;
    cout<<"NUM OF QUERIES : ";
    cin>>q;

    for (int i=0;i<q;i++)
    {
   
        string input="";
        cin>>input;
        
        if (input=="?")
        {
            distinct(main_arr);
        
            // int answer = distinct(main_arr);
            // cout<<answer<<endl;

        }
        
        else if (input== "!")
        {
            main_arr = copy_arr;
           

        }


        else
        {
            copy_arr=main_arr;
            long long int test =0;
            int k=0;
            int mg=input.size();
            if (input[0] == '-') k=1;
            else if (input[0]=='+') k=0;

            for (int kii=0;kii<mg;kii++)
            {

                 
        
                if (input[kii] == '1')test+=pow(10,mg-1-kii)*1;
                else if (input[kii] == '2')test+=pow(10,mg-1-kii)*2;
                else if (input[kii] == '3')test+=pow(10,mg-1-kii)*3;
                else if (input[kii] == '4')test+=pow(10,mg-1-kii)*4;
                else if (input[kii] == '5')test+=pow(10,mg-1-kii)*5;
                else if (input[kii] == '6')test+=pow(10,mg-kii)*6;
                else if (input[kii] == '7')test+=pow(10,mg-1-kii)*7;
                else if (input[kii] == '8')test+=pow(10,mg-1-kii)*8;
                else if (input[kii] == '9')test+=pow(10,mg-1-kii)*9;
                else if (input[kii] == '0') test+=pow(10,mg-1-kii)*0;
            }

            if (k==1)test*=-1;


            if (test>0)
            {
                main_arr.push_back(test);
                
            }

            else
            {
             
                for (int temporary=0;temporary<abs(test);temporary++)
                {
                    main_arr.pop_back();
                   
                }
            }

            

        }
       

    }

    return 0;
};
