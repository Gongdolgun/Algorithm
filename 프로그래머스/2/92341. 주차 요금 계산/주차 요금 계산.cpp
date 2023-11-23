#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<string, pair<string, string>>> v;

int CalculateFee(int BaseTime, int BaseFee, int TotalTime, int Time, int Fee)
{
    int middle = ceil((TotalTime - BaseTime) / (float)Time);

    /*if ((TotalTime - BaseTime) % Time != 0)
        middle = (TotalTime - BaseTime) / Time + 1;

    else
        middle = (TotalTime - BaseTime) / Time;*/

    //middle = ceil(middle);

    return BaseFee + middle * Fee <= BaseFee ? BaseFee : BaseFee + middle * Fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    int BaseTime = fees[0], BaseFee = fees[1], Time = fees[2], Fee = fees[3];
    
    for(int i = 0; i < records.size(); i++)
    {
        string carNum, inTime, inout;

        for (int j = 0; j < 5; j++)
            inTime += records[i][j];

        for (int j = 6; j < 10; j++)
            carNum += records[i][j];

        for (int j = 11; j < records[i].length(); j++)
            inout += records[i][j];

        v.push_back(make_pair(carNum, make_pair(inTime, inout)));
    }

    sort(v.begin(), v.end());

    string currCar;
    int Resulttime = 0;
    

    for (int i = 0; i < v.size(); i++)
    {
        string stime, sminute;
        string currTime, currMinute;

    	if(v[i].second.second == "IN")                                                                  //IN 이라면
	    {
            if(i == v.size() - 1)                                                                       // 마지막이고 IN 이라면
            {
                for (int j = 0; j < 2; j++)
                    currTime += v[i].second.first[j];

                for (int j = 3; j < 5; j++)
                    currMinute += v[i].second.first[j];

                Resulttime += (23 - stoi(currTime)) * 60 + (59 - stoi(currMinute));

                answer.push_back(CalculateFee(BaseTime, BaseFee, Resulttime, Time, Fee));

                break;
            }

            currCar = v[i].first;

            if(v[i+1].first == currCar)                                                                 // 다음 차량이 지금 차량이랑 같다면
            {
	            for(int j = 0; j < 2; j++)
	            {
                    currTime += v[i].second.first[j];
                    stime += v[i+1].second.first[j];
                }

                for (int j = 3; j < 5; j++)
                {
                    currMinute += v[i].second.first[j];
                    sminute += v[i + 1].second.first[j];
                }

                Resulttime += (stoi(stime) - stoi(currTime)) * 60 + (stoi(sminute) - stoi(currMinute));// 최종 시간에 더해줌
            }

            else                                                                                       // 다음 차량이 지금 차량이랑 다르다면 (OUT없는 차)
            {
                for (int j = 0; j < 2; j++)
                    currTime += v[i].second.first[j];

                for (int j = 3; j < 5; j++)
                    currMinute += v[i].second.first[j];

                Resulttime += (23 - stoi(currTime)) * 60 + (59 - stoi(currMinute));                     // 23 : 59 로 계산해서 넘겨줌

                answer.push_back(CalculateFee(BaseTime, BaseFee, Resulttime, Time, Fee));   // 값 저장
                Resulttime = 0;                                                                         // Result 초기화
            }
	    }

        else                                                                                            // OUT 이라면
        {
            if (i == v.size() - 1)                                                                      // 마지막 차라면 OUT이고
            {
                answer.push_back(CalculateFee(BaseTime, BaseFee, Resulttime, Time, Fee));
                break;
            }

	        if(currCar == v[i+1].first)
                continue;
            
            answer.push_back(CalculateFee(BaseTime, BaseFee, Resulttime, Time, Fee));
            Resulttime = 0;
        }
    }

    return answer;
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<int> fees(n);
    vector<string> records(m);

    for (int i = 0; i < n; i++)
        cin >> fees[i];

    cin.ignore();

    for (int i = 0; i < m; i++)
        getline(cin, records[i]);

    solution(fees, records);

    return 0;
}