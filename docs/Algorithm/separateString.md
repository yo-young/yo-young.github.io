---
layout: default
title: 문자열 나누기 / level 1
parent: Algorithm
nav_order: 9
---

# 문자열 나누기

[https://school.programmers.co.kr/learn/courses/30/lessons/140108](https://school.programmers.co.kr/learn/courses/30/lessons/140108)

## 문제 설명

- 첫 글자 x
- 오른쪽으로 읽으면서 x와 x가 아닌 글자가 나온 횟수
- 두 횟수가 같아지는 순간 멈추고, 해당 위치에서 문자열 분리
- s에서 분리한 문자열을 빼고 남은 부분에 대해서 반복
- 더 이상 읽을 글자가 없다면 지금까지 읽은 문자열을 분리하고 종료

### Input

- 문자열 s

### Output

- 분해한 문자열의 개수

### example

| s | result |
| --- | --- |
| "banana" | 3 |
| "abracadabra" | 6 |
| "aaabbaccccabba" | 3 |

### Limitation

- 1 ≤ s.size() ≤ 10000

---

### 풀이 과정

- for문으로 가능해 보임
- x를 저장해놓고 x와 같으면 x count, 아니면 y count
- x와 y가 같으면 answer 1 증가하고 x에 다음 문자 저장
- s길이가 1이면 answer = 1

```cpp
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
```

### 고찰

- 알고리즘의 어려움은 없었다.
- 금방 풀긴 했지만 약간의 디버깅이 필요했던 이유는 x_cnt의 초기값 설정을 1이 아닌 0으로 했던 것
    - 내가 세운 시나리오에서 초기값을 어떻게 설정하느냐에 따라 결과값이 달라지기 때문에 초기값에 대해 생각해야 한다.
- for문 하나에 if문 정도기 때문에 복잡도는 의미 없는 문제.
- 다른 사람의 풀이 참고
    - 내 코드보다 스마트하고 굉장히 깔끔하게 작성된 코드가 있었다.
    - 내가 생각했던 알고리즘 자체는 동일하지만 내 코드와 같이 1, 2에 대한 예외처리도 필요없이 split 함수로 모두 처리 가능
    
    ```cpp
    bool split(int& ind, const string& str)
    {
        const char cur = str[ind];
        int countA = 1;
        int countB = 0;
        ind++;
    
        while(ind < str.size())
        {
            if(countA == countB) {
                return true;
            }
            if(cur == str[ind]) {
                countA++;
            } else {
                countB++;
            }
            ind++;
        }
        return false;
    }
    
    int solution(string s) {
        int answer = 0;
        int ind = 0;    
        while(split(ind,s))
        {
            answer++;
        }
        return answer + 1;
    }
    ```
    
    - split이라는 함수에 index와 문자열을 파라미터로 받음
    - cursor는 현재 index에 해당하는 문자 저장
    - index 증가
    - while문으로 index 증가하면서 횟수 비교
    - 횟수가 동일한 경우에 return true → answer 증가
    - 문자열의 끝까지 간 경우 return false → 외부 while문 종료