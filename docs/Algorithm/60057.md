---
layout: default
title: 문자열 압축 / level 2
parent: Algorithm
nav_order: 8
---

# 문자열 압축

[https://school.programmers.co.kr/learn/courses/30/lessons/60057](https://school.programmers.co.kr/learn/courses/30/lessons/60057)

## 문제 설명

- 문자열에서 같은 값이 연속해서 나타나는 것을 문자의 개수로 표현
- 문자열을 여러 문자로 잘라 압축할 수 있음

### Input

- string s 압축할 문자열

### Output

- 문자열을 압축했을 때 가장 짧은 길이

### example

- “ababcdcdababcdcd”
    - 2개 단위로 자르면 "2ab2cd2ab2cd”
    - 8개 단위로 자르면 "2ababcdcd”
- "abcabcdede”
    - 2개 단위로 자르면 "abcabc2de”
    - 3개 단위로 자르면 "2abcdede”

### Limitation

- 1 ≤ s ≤ 1000

---

### 풀이 과정

- 최대 길이가 1000이기 때문에 어지간한 알고리즘은 문제없을 것
- 자르는 단위를 2개부터 s의 길이까지 반복할 수 있을까?
- s의 길이가 자르는 단위로 나눠지지 않으면 패스
- temp 문자열에 자른 문자열을 저장해두고 다음 반복때 비교
    - 연속되지 않은 문자열은 새로 시작하는 거니까 가능해 보임
    - 같은 문자열 단위가 연속해서 나타나는 경우 카운트 필요
    - 같은 문자열 연속이 끊기는 경우 카운트+문자열을 answer에 입력

- 검색한 내용들
    - string 원하는 사이즈로 자르기 - [substr()](https://www.notion.so/substr-34639ca357bd42eaaaa29a9dc5215a1c)
    - to_string- [to_string](https://www.notion.so/to_string-8f6655cf431f414cb051a8f5b3a03c9c)
    - int의 최대값 - [타입의 최대값/최소값](https://www.notion.so/739d35fd80c84e4aa37280a77b9deb08)
    - 5번 test case - 문자열 길이가 1일 경

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

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
```

### 고찰

- 한번 풀었던 문제인데 역시나 문제에 제대로 작성되지 않은 조건 때문에 좀 더 헤맸다…
    - 조건은 문자열이 꼭 단위문자열로 딱 나누어 떨어질 필요는 없다는 것.
    - 예를 들어 “ababc”이면 2개의 단위 문자열로 나눌 때 “2abc”도 괜찮다는 것..
    - 그런데 이 경우 반대로 압축해제할때 문제가 발생할 수 있다는 점…
- 특별한 알고리즘이나 자료구조 필요한 문제는 아니었다.
- 문자열의 substr함수를 사용해서 문자열을 분리하는 것이 중요
- for문 안에서 해결하려고 최대한 노력했다.
- 문자열을 분리해서 벡터로 변환해서 계산한 코드를 봤다.
    - 알고리즘 자체는 내 코드와 큰 차이가 없어보인다.