#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the findPoint function below.
 */
vector<int> findPoint(int px, int py, int qx, int qy) {
    /*
     * Write your code here.
     */
    vector<int> ans;
    ans.push_back(qx +(qx - px));
    ans.push_back(qy +(qy - py)) ;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int n_itr = 0; n_itr < n; n_itr++) {
        string pxPyQxQy_temp;
        getline(cin, pxPyQxQy_temp);

        vector<string> pxPyQxQy = split_string(pxPyQxQy_temp);

        int px = stoi(pxPyQxQy[0]);

        int py = stoi(pxPyQxQy[1]);

        int qx = stoi(pxPyQxQy[2]);

        int qy = stoi(pxPyQxQy[3]);

        vector<int> result = findPoint(px, py, qx, qy);

        for (int result_itr = 0; result_itr < result.size(); result_itr++) {
            fout << result[result_itr];

            if (result_itr != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
