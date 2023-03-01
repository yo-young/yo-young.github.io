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
- 1/31
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
        
        ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/61e4b99b-7c07-4fbc-9aa9-b8374b7b1921/Untitled.png)
        
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
    
- 3/1
    - 트리를 이용해서 풀이?
    - 트리는 어떻게 구현할 것인지?
        - unordered_set을 이용. map은 키에 대응되는 값이 저장되지만 set은 입력값이 키이자 값이라고 할 수 있다.
        - set의 count함수는 키 값에 해당하는 데이터가 있으면 1 없으면 0을 반환 따라서 count(y)을 통해 y가 계산될 때까지 while을 이용하여 반복문 수행
            - 동일한 depth에 존재하는 데이터를 다시 트리로 계산해야하기 때문에 for문 수행
        - 계산된 값을 키로 사용한다.
            - x로 10이 주어진다면 10+n, 10*2, 10*3이 키가 된다.
                - 이 문제는 일종의 삼진트리. 세 값은 동일한 depth
                - next tree에 저장해둠
                - 계산한 뒤 이전 depth의 값인 10은 set에서 지운다. (tree clear)
                - clear된 tree에 계산된 next tree 저장
                - tree에는 현재 depth에 대한 값들만 저장되어 있음
            - 키가 y보다 크면 저장하지 않는다.
                - 계산이 반복되면서 y값이 나오지 않으면 tree가 비는 경우가 발생
                - -1로 리턴

### 고찰

- set을 이용한 트리 구조 구현 학습
- 재귀는 만능이 아니다…
- set을 알고 트리 구조를 알면 쉬운 문제였다.
- depth 관리와 원하는 값이 나오지 않는 케이스에 대한 처리가 중요.