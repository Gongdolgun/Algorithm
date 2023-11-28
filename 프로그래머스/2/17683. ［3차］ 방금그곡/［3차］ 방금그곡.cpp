#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string convert(string m) {
    string res = "";
    for (int i = 0; i < m.length(); i++) {
        if (m[i] == '#') {
            res[res.length() - 1] = res[res.length() - 1] - 'A' + 'a';
        } else {
            res += m[i];
        }
    }
    return res;
}

string solution(string m, vector<string> musicinfos) {
    pair<int, string> answer = { 0,"(None)" };
    m = convert(m);
    for (string musicinfo : musicinfos) {
        vector<string> info;
        string temp = "";
        for (int i = 0; i < musicinfo.length(); i++) {
            if (musicinfo[i] == ',') {
                info.push_back(temp);
                temp = "";
            }
            else temp += musicinfo[i];
        }
        info.push_back(temp);
        int playtime = (stoi(info[1].substr(0, 2)) - stoi(info[0].substr(0, 2))) * 60 + stoi(info[1].substr(3, 2)) - stoi(info[0].substr(3, 2));
        string music = convert(info[3]);
        string fullmusic = "";
        for (int i = 0; i < playtime; i++) {
            fullmusic += music[i % music.length()];
        }
        if (fullmusic.find(m) != string::npos) {
            if (answer.first < playtime) {
                answer.first = playtime;
                answer.second = info[2];
            }
        }
    }
    return answer.second;
}
