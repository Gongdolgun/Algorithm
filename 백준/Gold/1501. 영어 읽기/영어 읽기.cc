#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

int n, m;
unordered_map<string, int> dic;
vector<string> words;

string sortMiddle(string str) {
    if (str.size() == 1) return str;
    if (str.size() == 2) return string(1, str[0]) + string(1, str[1]);

    string middle = str.substr(1, str.size()-2);
    sort(middle.begin(), middle.end());
    return str[0] + middle + str[str.size()-1];
}

void solution()
{
    for(int i = 0; i < words.size(); i++)
    {
        vector<string> vword;
        istringstream iss(words[i]);
        string word;
        while (iss >> word) {
            vword.push_back(word);
        }

        int result = 1;
        for(auto& word: vword) {
            string sorted = sortMiddle(word);
            if(dic.find(sorted) == dic.end()) {
                result = 0;
                break;
            }
            else {
                result *= dic[sorted];
            }
        }

        cout << result << '\n';
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    string str;
    for (int i = 0; i < n; i++){
        cin >> str;
        dic[sortMiddle(str)]++;
    }

    cin >> m;
    cin.ignore();

    words.resize(m);
    for (int i = 0; i < m; i++)
        getline(cin, words[i]);

    solution();

    return 0;
}
