#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<string> v1;
vector<string> v2;
;
string makelow(string str)
{
	for(int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);

    return str;
}

void makeVector(string str, vector<string>& vec)
{
	string stmp = "";

	for(int i = 0; i < str.length() - 1; i++)
	{
		if((str[i] >= 'a' && str[i] <= 'z') && (str[i+1] >= 'a' && str[i+1] <= 'z'))
		{
			stmp += str[i];
			stmp += str[i + 1];

			vec.push_back(stmp);
			stmp.clear();
		}
	}
}

int solution(string str1, string str2) {
    int answer = 0;

    str1 = makelow(str1);
    str2 = makelow(str2);

	makeVector(str1, v1);
	makeVector(str2, v2);

	if (v1.empty() && v2.empty())
		return 65536;

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	vector<string> inters(v1.size() + v2.size());
	vector<string> uni(v1.size() + v2.size());

	auto iter = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), uni.begin());
	uni.erase(iter, uni.end());

	auto iter2 = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inters.begin());
	inters.erase(iter2, inters.end());


	float rate = (float)inters.size() / (float)uni.size();

	answer = rate * 65536;
	cout << answer;

    return answer;
}

int main()
{
	string ex1;
	string ex2;

	cin >> ex1 >> ex2;

	solution(ex1, ex2);

	return 0;
}