---
layout: default
title: 숫자 변환하기 / level 2
parent: Algorithm
nav_order: 8
---

# 숫자 변환하기

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/154538)

## 문제 설명

- x → y 변환
    - x+n
    - x*2
    - x*3
- x를 y로 변환하기 위해 필요한 최소 연산 횟수 반환
- x를 y로 변환할 수 없다면 -1 반환

### Input

- int x, y, n

### Output

- int answer

### example

| x | y | n | result |
| --- | --- | --- | --- |
| 10 | 40 | 5 | 2(x*2*2) |
| 10 | 40 | 30 | 1(x+30) |
| 2 | 5 | 4 | -1 |

### Limitation

- 1 ≤ x ≤ y ≤ 1,000,000
- 1 ≤ n < y

---

- **풀이 과정**
    - 일단.. DFS로 풀 수 있을 것 같음
    - 연산 횟수는 DFS의 depth
    - x에 연산해서 y가 나오면 answer에 현재 depth를 저장하고 return
    - 문제는 x가 y를 만들 수 없는 경우를 처리해야할까?
        - dfs로 완탐하다가 시간초과나 재귀로 문제 생길 수도 있는데
        - 일단 완탐해보자
        - 역시 시간초과 발생
    - depth가 ans를 초과하면 바로 종료하도록 변경
        - 5, 7, 9, 10, 11, 14, 15, 16 시간초과
    - 곱셉부터 계산하도록 변경
        - 5, 7, 9, 10, 11, 14 시간초과
    
    ---
    
    - 재귀로 풀 수 없는 문제라고 함
    - 백준 숨바꼭질 문제랑 매우 유사한 문제라고함
    - [참고한 블로그](https://velog.io/@seunghyun97/%EC%88%AB%EC%9E%90-%EB%B3%80%ED%99%98%ED%95%98%EA%B8%B0)
    - set을 이용한 풀이
        - 트리구조
        
        ![Untitled](../../assets/images/algorithm/changeNum_1)
        
        - x에서 3개 연산을 y보다 작거나 같은 경우 수행하고 set에 저장
        - y랑 같은 수가 있으면 depth 반환. 어떤 연산인지는 상관 없음
        - y보다 큰수는 저장하지 않음. 위 그림에서 x*2와 x*3은 y보다 크기 때문에 더이상 계산하지 않는 것을 표현
    - unordered_set으로 curr, next 정의
        - curr에 x 저장
        - 중복을 제거하기 위해 set 구조 사용
    - curr이 빌 때까지 반복
        - curr에 y가 있으면 cnt 반환
        - next 초기화
        - curr을 순회
            - n덧셈, 2배, 3배 계산
            - 계산된 결과가 y보다 작거나 같으면 next에 저장
            - 세 연산의 결과가 모두 y보다 크면 저장되는 값 없음
        - curr에 next를 대입
            - next가 비어있으면 while반복문 종료
        - 카운트 증가
    
    ```cpp
    #include <iostream>
    #include <string>
    #include <vector>
    #include <unordered_set>
    
    using namespace std;
    
    int solution(int x, int y, int n)
    {
        int cnt = 0;
        unordered_set<int> curr, next;
        curr.insert(x);
    
        while (!curr.empty())
        {
            if (curr.count(y))
                return cnt;
            next.clear();
            for (int val : curr)
            {
                int pVal = val + n;
                int dVal = val * 2;
                int tVal = val * 3;
                if (pVal <= y)
                    next.insert(pVal);
                if (dVal <= y)
                    next.insert(dVal);
                if (tVal <= y)
                    next.insert(tVal);
            }
            curr = next;
            cnt++;
        }
        return -1;
    }
    
    int main()
    {
        int ans;
        ans = solution(1, 100000, 1);
        cout << ans << endl;
    }
    ```
    

### 

### 고찰

- set을 이용한 트리 구조 구현 학습
- 재귀는 만능이 아니다…
- 재풀이 필요