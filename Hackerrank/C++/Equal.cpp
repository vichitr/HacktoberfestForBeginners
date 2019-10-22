#include <bits/stdc++.h>
#DEFINE PI 3.14
using namespace std;

vector<string> split_string(string);

int ops(int n)
{
    int res=n/5;
    n%=5;
    res+=n/2;
    n%=2;
    res+=n;
    return res;
}

// Complete the equal function below.
int equal(vector<int> arr) {
    
    int min=INT_MAX;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]<min)
            min=arr[i];
    }
    
    int ans=INT_MAX;
    for(int i=0;i<=4;i++)
    {
        int this_ans=0;
        for(int j=0;j<arr.size();j++)
        {
            this_ans += ops(arr[j]-min+i);
        }
        if(this_ans<ans)
            ans=this_ans;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = equal(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
