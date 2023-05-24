#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    int temp = arr[0];

    if(arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }
        

    for(int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < temp)
            temp = arr[i];
    }

    cout << temp << '\n';

    for(int j = 0; j < arr.size(); j++)
    {
        if (arr[j] != temp)
            answer.push_back(arr[j]);
    }

    return answer;
}

int main()
{
    vector<int> arr = { 4,1,6,8,7 };

    arr = solution(arr);

    for(auto& Arr : arr)
    {
        cout << Arr << " ";
    }

    cout << endl;
    return 0;
}