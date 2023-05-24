using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;

    long long total = 0;
    long long num = 0;

    for(int i = 1; i <= count; i++)
    {
        num += price;
        total += num;
    }

    money >= total ? answer = 0 : answer = total - money;

    return answer;
}