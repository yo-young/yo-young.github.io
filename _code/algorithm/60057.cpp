#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

void print(int i, int cur, int cnt, string answerStr);

int solution(string s) {
    int answer=INT_MAX;
    if(s.size() == 1) return 1;

    for (int i=1; i<s.size(); i++) {
        string answerStr = "";
        string temp = "";
        int cur=0, cnt=1;
        // 단위 길이가 s의 길이에 나누어떨어지지 않으면 패스
        // if (s.size()%i != 0) continue;
        // cout << "s.size : " << s.size() << ", s.size()/i : " << s.size()/i << endl;
        // s길이/단위길이 + 1 만큼 반복
        for (int j=0; j<=s.size()/i; j++) {
            // cout << "previous string : " << temp << endl;
            // cout << "current string : " << s.substr(cur, i) << endl;
            // 이전 문자열과 현재 문자열이 같은 경우 cnt 증가
            if (temp == s.substr(cur, i)) {
                temp = s.substr(cur, i);
                ++cnt;
            }
            //이전 문자열이 현재 문자열과 다른 경우
            //temp에 단위 문자열 저장
            // if (temp != s.substr(cur, i)) {
            else {
                //연속 문자열이 2개 이상인 경우
                if(cnt > 1) {
                    //answer문자열에 개수 추가
                    answerStr += to_string(cnt);
                    cnt = 1;
                }
                if(j != 0) answerStr += temp;
                temp = s.substr(cur, i);
            }

            cur += i;
            // print(i, cur, cnt, answerStr);
        }
        //문자열 분리 완료
        cur -= i;
        if(cur != s.size()) answerStr += s.substr(cur);
        
        answer = answerStr.size() < answer ? answerStr.size() : answer;
        // cout << "cur : " << cur << endl;
        // cout << "answerStr : " << answerStr << endl;
        // cout << "answer : " << answer << endl << endl;
    }

    return answer;
}

void print(int i, int cur, int cnt, string answerStr) {
    if(i!=3) return;
    cout << "----- print start-----" << endl;
    cout << "i : " << i << endl;
    cout << "cur : " << cur << endl;
    cout << "cnt : " << cnt << endl;
    cout << "answerStr : " << answerStr << endl;
    cout << "----- print end-----" << endl;
    cout << endl;
}

int main() {
    string s = "abcabcdede"; // 2abcdede
    int answer = solution(s);
    cout << answer << endl;

    cout << s.substr(9) << endl;

    return 0;
}