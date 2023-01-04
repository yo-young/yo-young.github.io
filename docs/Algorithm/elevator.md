---
layout: default
title: 마법의 엘레베이터 / level 2
parent: Algorithm
nav_order: 8
---

# 마법의 엘레베이터

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/148653)

## 문제 설명

- 절대값이 10의 제곱수인 정수
    - -1, 1, -10, 10, -100, 100
- 현재 숫자 storey에서 0으로 만들기 위한 최소 더하기 횟수 반환
- storey가 16인 경우
    - -1 6번 -10 1번 총 7번
    - +1 4번 -10 2번 총 6번
    - 최소 6번이므로 6 반환

### Input

- int storey

### Output

- int answer

### example

| storey | result |
| --- | --- |
| 16 | 6 |
| 2554 | 16 |

### Limitation

- 1 ≤ storey ≤ 100,000,000

---

### 풀이 과정

- 일단 example 분석을 해보자
    - 2554
    - 2*1000 + 5*100 + 5*10 + 4*1
    
    ⇒ 2+5+5+4 = 16
    
- 1의 자리 숫자가 5 이하면 -1, 6 이상이면 +1
- 10의 자리 이상 숫자는 그냥 카운팅
- int → string 변환해서 자리수로 카운팅할 수 있나?
    - 제한적으로 가능
    - 2554는 가능
- 2667은 어떨까?
    - 위 방식대로 하면 2+6+7+3
    - +3을 하면 2670
    - +30을 하면 2700
    - +300을 하면 3000
    
    ⇒ 3+3+3+3 = 12
    
- string 변환해서 reverse하고 해당 자리 숫자가 5보다 크면 10-자리수를 더하고 다음 자리수에 1을 더해준다.
    - 주어진 예제는 통과했으나 blind test에서 반 정도 실패
    - 자리수가 증가하는 케이스 놓침
        - 예로 97의 경우
        - +3을 하면 100으로 증가
        - -100 한번으로 0 계산 가능, 총 횟수 4
- 현재 자리수가 5보다 크면 answer에 10-현재숫자를 plus
- storey에 현재 수를 자리수에 맞춰 더해줌
    - storey를 다시 string으로 변경해서 number에 대입해줌
    - 이후 number는 새로운 storey를 기준으로 계산될 것
    - 하지만 3개 케이스 실패

<aside>
💡 해결

- 포인트는 현재 자리의 수가 5인 경우 다음 자리의 수가 5 이상인지 확인하고 5 이상인 경우에만 자리수를 올리는 것.
- 다음 자리의 수가 5 이상인 경우 자리수를 올려서 +1을 하는 경우가 더 최소로 0을 만들 수 있음
</aside>

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int firstAns = 0;
    string number = to_string(storey);
    reverse(number.begin(), number.end());
    //1의 자리부터 시작하도록 reverse
    for (auto num : number) {
        answer += (int)num-'0';
    }

    for (int i=0; i<number.size(); i++) {
        int tmp = (int)number[i]-'0';
        cout<<i<<" : "<<tmp<<endl;
        if (tmp == 0) continue;
        if (tmp > 5) {
            cout<<"1. answer+"<<(10-tmp)<<endl;
            firstAns += (10-tmp);
            int add = 1;
            for (int j=1; j<i+1; j++) {
                add *= 10;
            }
            storey += add*(10-tmp);
            number = to_string(storey);
            cout<<"add : "<<add*(10-tmp)<<endl;
            cout<<"new number : "<<storey<<endl;
            reverse(number.begin(), number.end());
        }
        else if (tmp == 5) {
            firstAns += (10-tmp);
            if (number[i+1] >= '5') {
                int add = 1;
                for (int j=1; j<i+1; j++) {
                    add *= 10;
                }
                storey += add*(10-tmp);
                number = to_string(storey);
                cout<<"add : "<<add*(10-tmp)<<endl;
                cout<<"new number : "<<storey<<endl;
                reverse(number.begin(), number.end());
            }
        }
        else {
            cout<<"2. answer+"<<tmp<<endl;
            firstAns += tmp;
        }
    }

    answer = answer < firstAns ? answer : firstAns;

    return answer;
}
```

### 고찰

- 접근 방식 자체는 맞았으나 케이스 분석이 좀 더 필요했다.
- 다른 사람 코드를 확인해보니 string으로 변환할 필요 없이 % 연산을 이용해서 1의 자리 숫자를 추출했다.
- 그리고 10으로 나눠버려서 1의 자리 수를 버리고 storey가 0이 될 때까지 while로 반복하도록 구현했다.
- 자리수 연산을 할 때 나머지 연산자를 활용해야하는데 바로 안떠오른다.. 기억할 것
- 참고 블로그 [https://jaimemin.tistory.com/2213](https://jaimemin.tistory.com/2213)