#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1;
    int x_cnt = 1, y_cnt = 0;
    char x;
    if (s.size() == 1) return 1;
    if (s.size() == 2) {
        if (s[0] == s[1]) return 1;
        else return 2;
    }

    for (int i=0; i<s.size(); i++) {
        if (!i) {
            x=s[i];
            continue;
        }

        if (x_cnt == y_cnt && x_cnt) {
            cout << "x cnt : " << x_cnt << endl;
            answer++;
            x=s[i];
            x_cnt=1, y_cnt=0;
        }
        else {
            cout <<"x : "<<x<<", s["<<i<<"] : "<<s[i]<< endl;
            if (x == s[i]) x_cnt++;
            else y_cnt++;
        }
    }

    return answer;
}

int main() {
    int answer = solution("aaabbaccccabba");
    cout << answer << endl;

    return 0;
}