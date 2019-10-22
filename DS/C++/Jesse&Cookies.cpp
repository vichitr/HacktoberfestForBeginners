#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the cookies function below.
 */
int cookies(int k, vector<int> A) {
    
    int count=0;
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(A.begin(),A.end());
    
    if(A.size()==1 && A[0]<k)
        return -1;
    else if(A.size()==1)
        return 0;
    
    if(A[A.size()-1]+2*A[A.size()-2]<k)
        return -1;
    
    for(int i=0;i<A.size();i++)
    {
        pq.push(A[i]);
    }
    
    while(1)
    {
        int key=1,x1,x2,x3;
        
        x1=pq.top();
        pq.pop();
        x2=pq.top();
        pq.pop();
        x3=x1+x2*2;
        pq.push(x3);
        count++;
        
        if(pq.top()>=k)
            break;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split_string(A_temp_temp);

    vector<int> A(n);

    for (int A_itr = 0; A_itr < n; A_itr++) {
        int A_item = stoi(A_temp[A_itr]);

        A[A_itr] = A_item;
    }

    int result = cookies(k, A);

    fout << result << "\n";

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
