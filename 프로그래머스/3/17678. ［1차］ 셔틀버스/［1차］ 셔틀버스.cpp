#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <thread>
#include <mutex>

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 98765421
#define ll long long

using namespace std;

// 1. 타임 테이블 분으로 저장
// 2. 버스 도착 시간 분으로 저장
// 3. 타임 테이블 정렬
// 4. queue에 저장
// 5. 

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 0; i < timetable.size();i++)
    {
        int hour = stoi(timetable[i].substr(0, 2));
        int minute = stoi(timetable[i].substr(3, 2));
        int result = hour * 60 + minute;

        pq.push(result);
    }

    queue<int> bus_stop;
    for(int i = 0; i < n; i++)
        bus_stop.push(540 + (t * i));

    int result = 0;
    while(!bus_stop.empty())
    {
        int bus_time = bus_stop.front();
        result = bus_time;
        bus_stop.pop();
    	int tmp = 0;                        // 탑승한 인원
        int crew = 0;

	    while (!pq.empty())
	    {
            if (tmp >= m)
                break;

		    crew = pq.top();

		    if(bus_time >= crew)             // 탈 수 있는 크루라면
		    {
			    pq.pop();
			    tmp++;
		    }

		    else
                break;
	    }

        if (bus_stop.empty() && tmp >= m)        // 다음 버스가 없고, 현재 버스가 꽉 찼다면
            result = crew - 1;

        if (bus_stop.empty() && tmp < m)         // 다음 버스가 없고, 현재 버스가 꽉 차지 않았다면
            result = bus_time;
    }

    int hour = result / 60;
    int minute = result % 60;

    string s_hour;
	string s_minute;

    if (hour < 12)
        s_hour = '0' + to_string(hour);

    else
        s_hour = to_string(hour);

    if (minute < 10)
        s_minute = '0' + to_string(minute);

    else
        s_minute = to_string(minute);

    answer = s_hour + ':' + s_minute;

    cout << answer;

    return answer;
}