#include <string>
#include <stack>

using namespace std;

// "올바른 괄호 문자열" 검증
bool check(string p) {
    stack<char> st;
    
    for(auto c: p) {
        if(c == '(') st.push(c);
        else {
            if(st.empty()) return false;
            st.pop();
        }
    }
    
    return st.empty();    
}

string solution(string p) {
    if(p.empty()) return p; // step 1
    string answer = "";
    
    string u = "", v = "";
    int l = 0, r = 0;
    
    // step 2
    for(int i=0; i<p.length(); ++i) {
        if(p[i] == '(') l++;
        else r++;
        
        if(l == r) {
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }
    
    if(check(u)) answer = u + solution(v); // step 3
    else { // step 4
        answer = "(" + solution(v) + ")"; // step 4-1,2,3
        
        // step 4-4
        for(int i=1; i<u.length()-1; ++i) {
            answer += u[i] == '(' ? ')' : '(';
        }
    }
    
    return answer;
}