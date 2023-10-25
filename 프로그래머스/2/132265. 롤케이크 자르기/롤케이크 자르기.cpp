#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int n = topping.size();
    unordered_map<int, int> total_topping, current_topping;

    for (int i = 0; i < n; i++) {
        total_topping[topping[i]]++;
    }

    for (int i = 0; i < n - 1; i++) {
        current_topping[topping[i]]++;
        total_topping[topping[i]]--;

        if (total_topping[topping[i]] == 0) {
            total_topping.erase(topping[i]);
        }

        if (current_topping.size() == total_topping.size()) {
            answer++;
        }
    }

    return answer;
}
