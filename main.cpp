#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> maximumPerimeterTriangle(vector<int> sticks)
{
    vector<int> retValue(3, -1);

    sort(sticks.begin(), sticks.end());

    int n = sticks.size();

    size_t max = 0;

    for(int i = n - 1; i >= 2; i--)
    {
        for(int j = i - 1; j >= 1; j--)
        {
            for(int k = j - 1; k >= 0; k--)
            {
                if(sticks[i] < sticks[j] + sticks[k])
                {
                    if(size_t(sticks[i] + sticks[j] + sticks[k]) > max)
                    {
                        max = sticks[i] + sticks[j] + sticks[k];
                        retValue[0] = sticks[k];
                        retValue[1] = sticks[j];
                        retValue[2] = sticks[i];
                    }
                }
            }
        }
    }

    if(max == 0)
    {
        retValue.pop_back();
        retValue.pop_back();
    }

    return retValue;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string sticks_temp_temp;
    getline(cin, sticks_temp_temp);

    vector<string> sticks_temp = split(rtrim(sticks_temp_temp));

    vector<int> sticks(n);

    for (int i = 0; i < n; i++) {
        int sticks_item = stoi(sticks_temp[i]);

        sticks[i] = sticks_item;
    }

    vector<int> result = maximumPerimeterTriangle(sticks);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << " ";
        }
    }

    cout << endl;

    return EXIT_SUCCESS;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
