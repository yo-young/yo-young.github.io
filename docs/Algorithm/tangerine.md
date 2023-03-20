---
layout: default
title: 숫자 변환하기 / level 2
parent: Algorithm
nav_order: 8
---
# 귤 고르기

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/138476)

## 문제 설명

- k개의 귤을 골라 상자에 담아 판매
- 귤 크기 종류의 수를 최소화

### Input

- int k;
- vector<int> tangerine;

### Output

- int

### example

| k | tangerine | result |
| --- | --- | --- |
| 6 | [1, 3, 2, 5, 4, 5, 2, 3] | 3 |
| 4 | [1, 3, 2, 5, 4, 5, 2, 3] | 2 |
| 2 | [1, 1, 1, 1, 2, 2, 2, 3] | 1 |

### Limitation

- 1 ≤ `k` ≤ `tangerine`의 길이 ≤ 100,000
- 1 ≤ `tangerine`의 원소 ≤ 10,000,000

---

### 풀이 과정

- Map에 저장
    - 키 값 기반으로 정렬
    - 키는 tangerine의 원소, 값은 해당 원소의 개수
- 새로운 map에 다시 저장
    - 키는 원소의 개수, 값은 같은 개수를 가진 원소들의 벡터
- {2,2, 3,3, 5,5, 1, 4} 이라면
    - numOfTan[2] → 2,3,5
    - numOfTan[1] → 1,4
    - k=6이면 result는 2,3,5 세가지가 2개씩 존재하므로 3
    - 그럼 k=5라면? 2,3,5 세가지가 2개씩 존재하면 동일하게 3이 답
        - k=5, numOfTan[2].second=[2,3,5], answer=0;
        - k=3, numOfTan[2].second=[2,3], answer=1;
        - k=1, numOfTan[2].second=[2], answer=2;
        - k=-1, numOfTan[2].second=[], answer=3;
    - k=4라면, 2 종류가 2개씩 있으면 되니까 4가 정답
- 

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> tanMap;
    map<int, vector<int>, greater<int>> numOfTan;
    for(auto& tan : tangerine)
    {
        tanMap[tan] += 1;
    }
    for(auto& tan : tanMap)
    {
        // cout<<"i : "<<tan.first<<": "<< tan.second << endl;
        numOfTan[tan.second].push_back(tan.first);
    }
    // cout<<endl;
    int remain = k;
    for(auto& sizeOfTan : numOfTan)
    {
        // cout<<"i : "<<sizeOfTan.first<<": "<< sizeOfTan.second.size() << endl;
        //sizeOfTan.first는 귤의 개수, second는 해당 개수만큼 존재하는 귤의 크기들
        for(auto& size : sizeOfTan.second)
        {
            remain -= sizeOfTan.first;
            answer += 1;
            // cout<<"remain: "<<remain<<endl;
            if(remain <= 0) return answer;
        }
    }

    return answer;
}
```

### 고찰

- 처음에 map을 통해 귤의 사이즈별 개수를 저장
- 다른 map으로 동일한 개수를 가진 귤의 사이즈를 저장
    - 이 map은 greater를 통해 내림차순으로 정렬됨
- 정렬된 map을 순환
    - 해당 개수에 대한 사이즈의 벡터를 순환
    - k에서 귤의 개수를 빼면서 나머지를 계산
    - 계산될 때마다(귤의 사이즈마다) answer를 증가
    - 남은 귤의 개수가 0보다 작거나 같아지는 순간 answer 반환