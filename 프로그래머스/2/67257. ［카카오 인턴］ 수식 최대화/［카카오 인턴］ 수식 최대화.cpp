#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <bitset>
#include <thread>
#include <mutex>
#include <cstring>
#include <numeric>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

ll calculate(const char& operation, string A, string B)
{
    if (A[0] == 'm')
        A[0] = '-';

    if (B[0] == 'm')
        B[0] = '-';

	switch (operation)
	{
	case '+':
        return stoll(A) + stoll(B);

	case '-':
        return stoll(A) - stoll(B);

	case '*':
        return stoll(A) * stoll(B);
	}

    return -1;
}

long long solution(string expression) {
    long long answer = 0;

    map<int, char> m;
    vector<int> v = { 0, 1, 2 };
    m[0] = '+';
    m[1] = '-';
    m[2] = '*';

    do
    {
        //cout << v[0] << v[1] << v[2] << '\n';

        string target_str = expression;

        for(int i = 0; i < v.size(); i++)
        {
            string operation;
            operation += m[v[i]];

            while (target_str.find(operation) != string::npos)
            {
            	int index = target_str.find(operation);

                string A, B;
                for (int j = index - 1; j >= 0; j--)
                {
                    if (target_str[j] == '+' || target_str[j] == '-' || target_str[j] == '*')
                        break;
                    
                	A += target_str[j];
                }

                reverse(A.begin(), A.end());

                for (int j = index + 1; j < target_str.length(); j++)
                {
                    if (target_str[j] == '+' || target_str[j] == '-' || target_str[j] == '*')
                        break;

                    B += target_str[j];
                }

                string find_str = A + operation + B;
                ll calculate_num = calculate(operation[0], A, B);
                string replace_str;
                if (calculate_num < 0)
                    replace_str = 'm' + to_string(abs(calculate_num));

                else
					replace_str = to_string(calculate_num);

                target_str.replace(target_str.find(find_str), find_str.length(), replace_str);
            }
        }

        if (target_str[0] == 'm')
            target_str[0] = '-';
        answer = max(answer, abs(stoll(target_str)));
    }
    while (next_permutation(v.begin(), v.end()));

    return answer;
}