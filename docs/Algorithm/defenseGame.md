---
layout: default
title: 디펜스 게임 / level 2
parent: Algorithm
nav_order: 8
---

# 디펜스 게임*

[https://school.programmers.co.kr/learn/courses/30/lessons/142085](https://school.programmers.co.kr/learn/courses/30/lessons/142085)

*재풀이 필요

## 문제 설명

- 병사 n
- i 라운드에 enemy[i]마리의 적 등장
- 적의 수 1명 당 병사 1명을 소모
- 무적권은 병사 소모 없이 한 라운드 방어, 최대 k번 사용 가능
- 무적권을 적절히 사용해서 최대한 많은 라운드 진행

### Input

- int n, k
- vector<int> enemy

### Output

- int result

### example

| n | k | enemy | result |
| --- | --- | --- | --- |
| 7 | 3 | [4,2,4,5,3,3,1] | 5 |
| 2 | 4 | [3,3,3,3] | 4 |

### Limitation

- 1 ≤ n ≤ 1,000,000,000
- 1 ≤ k ≤ 500,000
- 1 ≤ enemy.size() ≤ 1,000,000
- i+1 라운드에 공격해오는 적의 수 : enemy[i]
- 모든 라운드를 막을 수 있는 경우 enemy[i]의 길이 return

---

### 풀이 과정

- 오름차순으로 정렬해서 풀이 불가능
- 탐색알고리즘 필요 - 깊이 우선 탐색 구현
    1. n과 enemy[i] 비교
    2. k 무적권 사용
- 시간초과 및 실패 발생
- 실패 해결 / 시간초과 여전히 발생

---

- 결국 풀이 검색
- enemy 길이가 백만 → O(nlogn) 안에 풀이
- O(nlogn)하면 필요한 자료구조 힙
- 우선순위 큐 선언하고 enemy 삽입
    - 큐의 길이가 k보다 크면 큐에서 pop하고 sum에 더해줌
        - 처음에 이 부분이 이해가 가지 않았음
        - 최소값을 pop하기 때문에(최소힙) 가장 높은 라운드를 가려가려면 작은 값들은 sum해서 n과 비교
        - 큰 값들은 k(무적권)을 이용하여 방어한다는 의미
    - sum이 n을 넘을 경우 해당 라운드 값 반환
    - 모두 수행된 경우 enemy 길이 반환

```cpp
//출처 https://jaimemin.tistory.com/2210
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < enemy.size(); i++)
    {
        int e = enemy[i];
        pq.push(e);

        if (pq.size() > k)
        {
            sum += pq.top();
            pq.pop();
        }
        if (sum > n)
        {
            return i;
        }
    }
    return enemy.size();
}
```

### 고찰

- 처음에 생각했던 탐색 알고리즘이 아니었음.
- 우선순위 큐를 문제에 사용한 경험이 없었기 때문에 나중에 다시 자력으로 풀어봐야할 문제
- 우선순위 큐 숙지 필요, 적어도 STL 사용법이라도