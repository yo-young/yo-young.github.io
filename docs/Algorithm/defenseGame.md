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

- 첫 번째 풀이
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
        - 큐의 길이가 k 보다 크면 큐에서 pop하고 sum에 더해줌
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
    
- 두 번째 풀이
    - 우선순위 큐 사용
    - 첫 번째 예제를 보면 n이 7이고 k는 3, 즉 3번의 무적권 사용이 가능
    - [4,2,4,5,3,3,1]를 순서대로 우선 순위 큐에 넣으면
        - k=3, [4,4,2]
        - k=4, [5,4,4,2]
        - k=5, [5,4,4,3,2]
        - k=6, [5,4,4,3,3,2]
    - k번까지 큐에 입력하고
    - k+1번부터 마지막까지 수의 합이 n보다 작거나 같으면 다음 반복 진행
        - 예를 들어 n이 5인 경우
        - k=4,  [5,4,4,3]에서 3 < 5 이므로 다음 진행
        - k=5,  [5,4,4,3,2]에서 (3+2) == 5 이므로 다음 진행
    - k+1번부터 마지막까지 수의 합이 n보다 크면 종료
        - k=6, [5,4,4,3,3,2]에서 (3+2+2) > 5 이므로 종료
        - return k-1.
```cpp
int solution(int n, int k, vector<int> enemy) {
    // Min Heap 최소힙
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum=0;
    // enemy에 대해 반복
    for (int i=0; i<enemy.size(); i++) {
        // 현재 enemy 수를 최소힙 우선순위 큐에 입력
        pq.push(enemy[i]);
        if (pq.size() > k) {
            // k개 이후에 입력되는 수를 더해줌
            // 최소힙이기 때문에 지금까지 입력된 수 중 제일 작은 수
            sum += pq.top();
            // 더해준 수는 큐에서 제외
            // 큐의 사이즈를 k개 만큼 유지
            // 다음에 들어오는 수가 현재 큐에 있는 수보다 크다면 우선순위 큐에 의해 정렬되어
            // 현재 큐에 있는 수 중 입력된 수보다 작은 수가 top에 위치하게 됨
            pq.pop();
        }
        if (sum > n) {
            // sum이 n보다 커지면 현재 인덱스를 반환
            return i;
        }
    }
}
```