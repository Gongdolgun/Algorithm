#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
int mOperator[4];
int mOperand[11];
int mMax = -1000000001;
int mMin = 1000000001;

void input()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> mOperand[i];

	for (int j = 0; j < 4; j++)
		cin >> mOperator[j];
}

void solution(int result, int cnt)
{
	if (cnt == N)
	{
		if (result > mMax)
			mMax = result;

		if (result < mMin)
			mMin = result;

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (mOperator[i] > 0)
		{
			mOperator[i]--;
			
			if (i == 0)
				solution(result + mOperand[cnt], cnt + 1);

			else if (i == 1)
				solution(result - mOperand[cnt], cnt + 1);

			else if (i == 2)
				solution(result * mOperand[cnt], cnt + 1);

			else
				solution(result / mOperand[cnt], cnt + 1);

			mOperator[i]++;
		}
	}

	return;
}

int main()
{
	input();
	solution(mOperand[0], 1);

	cout << mMax << '\n' << mMin;

	return 0;
}