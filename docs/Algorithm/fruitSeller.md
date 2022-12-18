---
layout: default
title: 과일 장수 / level 1
parent: Algorithm
nav_order: 9
---

# 과일 장수

[https://school.programmers.co.kr/learn/courses/30/lessons/135808](https://school.programmers.co.kr/learn/courses/30/lessons/135808)

## 문제

### Input

- 1~k 배열
- m : 한 상자에 담는 사과의 수

사과 한상자의 가격은 가장 낮은 점수 p * m
p*m의 최대값을 계산해야함.
남는 사과는 버림.

### example

- k=3, m=4, score = {1,2,3,1,2,3}
    - {2,3,2,3}
    - (최저 점수) * (한 상자에 담긴 사과 개수) * (상자 개수)
    
    ⇒ 2 * 4 * 1 = 8
    

### limitation

- 7 ≤ score의 길이 ≤ 1000000

---

### 풀이 과정

- 점수 순서로 사과를 정렬
- 박스에 순서대로 담는다.
- 하위권의 남는 사과들은 버린다.

### 코드

```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.rbegin(), score.rend());
    int max = score.size()/m;
    auto start = score.begin();
    for (int i=0 ; i<max ; i++) {
        int minScore= 10;
        auto it=start;
        for (int cnt=1; it<start+m ; ++it, ++cnt) {
            minScore = minScore < *it ? minScore : *it;
        }
        answer += minScore * m;
        start = it;
    }

    return answer;
}
```

### 고찰

- max는 박스의 개수라고 할 수 있다.
- 박스의 개수만큼 반복하고 박스 한 개당 최소 점수를 계산해서 answer에 더해간다.
- start에서 start+m까지(엄밀히 말하면 start+m 전까지) 반복하면서 min 값을 찾는다.
- 한동안 level 1 문제만 풀고 있는데 level 1에서 내가 가져갈 수 있는 것이 무엇일까 고민이었고,
고민의 결과로 다른 사람의 풀이도 분석할 필요가 있다고 생각했다.

```cpp
int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.begin(), score.end(), greater<int>());

    int box_num = score.size() / m;
    int cur = m - 1;
    for(int i = 0 ; i < box_num ; i++){ //박스의 개수만큼 반복한다.
        answer += score[cur] * m; //score vector의 cur 위치에 있는 점수 * m
        cur += m;
    }

    return answer;
}
```

- 이중 for문을 사용했으나 slg126님의 코드를 보면 for문 하나로 계산했다.
- 박스의 개수만큼 반복하는 것은 필수 요건
- score[cur]이 의미하는 것은 최소 점수이다.
    - cur이 m-1로 초기화되었다. 즉 박스의 마지막에 들어가는 사과의 점수를 의미한다.
    - 사과는 이미 정렬되었기 때문에 박스에 마지막에 들어가는 사과는 최소 점수를 의미한다.
    - 최소 점수 * m을 answer에 더한다.
    - cur += m은 다음 박스에 마지막으로 들어가는 사과를 의미한다.
    
- 이미 정렬해둔 vector를 이용하여 최소 점수를 계산하기 위한 for문을 사용하지 않았다.
- 한 번 더 생각하고 깊게 생각하는 훈련이 필요하다..