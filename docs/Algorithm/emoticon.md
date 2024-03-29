---
layout: default
title: 이모티콘 할인 행사 / level 2
parent: Algorithm
nav_order: 8
---

# 이모티콘 할인 행사

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/150368)

## 문제 설명

- n명의 사용자들에게 이모티콘 m개를 할인 판매
    - 이모티콘 플러스 서비스 가입자를 최대로 늘리는 것
    - 이모티콘 판매액을 최대한 늘리는 것
- 할인율은 10%~40% 10% 단위로 설정
- 각 사용자는 일정 비율 이상 할인하는 이모티콘을 모두 구매
    - 이모티콘 구매 비용의 합이 일정 가격 이상이 된다면 구매를 취소하고 이모티콘 플러스 서비스에 가입
- 카카오톡 사용자 `n`명의 구매 기준을 담은 2차원 정수 배열 `users`
- 1차원 정수 배열 `emoticons`
- 이모티콘 플러스 서비스 가입 수와 이모티콘 매출액을 리턴

<aside>
✅ 다음은 2명의 카카오톡 사용자와 2개의 이모티콘이 있을때의 예시입니다.

| 사용자 | 비율 | 가격 |
| --- | --- | --- |
| 1 | 40 | 10,000 |
| 2 | 25 | 10,000 |

| 이모티콘 | 가격 |
| --- | --- |
| 1 | 7,000 |
| 2 | 9,000 |

1번 사용자는 40%이상 할인하는 이모티콘을 모두 구매하고, 이모티콘 구매 비용이 10,000원 이상이 되면 이모티콘 구매를 모두 취소하고 이모티콘 플러스 서비스에 가입합니다.

2번 사용자는 25%이상 할인하는 이모티콘을 모두 구매하고, 이모티콘 구매 비용이 10,000원 이상이 되면 이모티콘 구매를 모두 취소하고 이모티콘 플러스 서비스에 가입합니다.

1번 이모티콘의 가격은 7,000원, 2번 이모티콘의 가격은 9,000원입니다.

만약, 2개의 이모티콘을 모두 40%씩 할인한다면, 1번 사용자와 2번 사용자 모두 1,2번 이모티콘을 구매하게 되고, 결과는 다음과 같습니다.

| 사용자 | 구매한 이모티콘 | 이모티콘 구매 비용 | 이모티콘 플러스 서비스 가입 여부 |
| --- | --- | --- | --- |
| 1 | 1, 2 | 9,600 | X |
| 2 | 1, 2 | 9,600 | X |

이모티콘 플러스 서비스 가입자는 0명이 늘어나고 이모티콘 판매액은 19,200원이 늘어납니다.

하지만, 1번 이모티콘을 30% 할인하고 2번 이모티콘을 40% 할인한다면 결과는 다음과 같습니다.

| 사용자 | 구매한 이모티콘 | 이모티콘 구매 비용 | 이모티콘 플러스 서비스 가입 여부 |
| --- | --- | --- | --- |
| 1 | 2 | 5,400 | X |
| 2 | 1, 2 | 10,300 | O |

2번 사용자는 이모티콘 구매 비용을 10,000원 이상 사용하여 이모티콘 구매를 모두 취소하고 이모티콘 플러스 서비스에 가입하게 됩니다.따라서, 이모티콘 플러스 서비스 가입자는 1명이 늘어나고 이모티콘 판매액은 5,400원이 늘어나게 됩니다.

</aside>

### Input

- int n
- vector<vector<int>> user
- vector<int> emoticons

### Output

- vector<int> answer

### example

| users | emoticons | result |
| --- | --- | --- |
| [[40, 10000], [25, 10000]] | [7000, 9000] | [1, 5400] |
| [[40, 2900], [23, 10000], [11, 5200], [5, 5900], [40, 3100], [27, 9200], [32, 6900]] | [1300, 1500, 1600, 4900] | [4, 13860] |

### Limitation

- 1 ≤ users.size() ≤ 100
- 1 ≤ emoticons.size() ≤ 7

---

### 풀이 과정
- **풀이 과정**
    - 할인율이 4 종류라는 건 이모티콘이 7개일 때
        - 최대 4^7 = 16384가지..?
        - 그럼 총 경우의 수는 16384* 최대 유저수 100 = 1638400
    - 힌트를 보니 완전탐색 문제가 맞다.. 160만가지 정도면 완전탐색 가능
    - DFS로 재귀함수 돌릴 때 어떻게 구현할 것인지?
    - 각 유저마다 할인율이 달라질 수 있음.
        - 이모티콘 가격은 정해진 할인율에 따라서 그냥 더하면 됨
    
    ---
    
    - 결국 2시간 초과로 다른 사람 풀이를 검색
        - [https://jaimemin.tistory.com/2222](https://jaimemin.tistory.com/2222)
        - early return 기법을 잘 사용한 코드인듯
    - 내가 놓친 부분은 salesRate를 벡터로 만들어서 재귀로 emoticons의 길이와 동일할 때까지 채워주는 부분
        - 두 벡터의 사이즈가 동일해지면 계산 함수 호출
        - 계산 함수에서 users 순회
            - salesRate 순회
                - user가 원하는 할인율이 현재 할인율보다 크면 다음 유저로 continue
                - temp에 이모티콘마다 할인율을 적용해서 누적합
            - salesRate 반복 끝
            - temp가 user의 돈보다 크거나 같으면 이모티콘플러스 구독
            - 아니면 sales에 누적합
        - 모든 유저에 대한 계산이 끝나면
        - 이전에 계산된 최대 구독자수가 더 크면 종료
        - 이전에 계산된 총 매출이 더 크면 종료
        - 아니면 구독자수와 매출을 저장
    - 재귀 구현할 때 어떤 변수가 변경되는지 잘 생각해봐야함
        - 여기선 유저마다 할인율이 달라지는게 아니라 이모티콘마다 할인율이 달라지는게 포인트
        - 그래서 이모티콘 벡터의 사이즈와 비교해서 경우의 수를 만들어야했다.
        - DFS 재귀의 기본형태
        
        ```cpp
        for (int i = 10; i <= 40; i += 10)
        {
        	// 변수 저장
        	salesRates.push_back(i);
        	// 재귀 함수 호출
        	func(salesRates, users, emoticons);
        	// 저장된 변수 복원
        	salesRates.pop_back();
        }
        ```
        
    

### 풀이 과정 (1/30 재풀이)

- 각 사용자의 원하는 할인율과 예산 그리고 이모티콘의 가격이 주어짐
- 할인율은 10, 20, 30, 40% 중 하나
- 이모티콘의 할인율을 결정하고 그에 따라 이모티콘 구매비용과 이모티콘플러스 가입 여부를 판단해야함
- 이모티콘은 최대 7개이므로 4의 7제곱 16384
    - 이 정도면 완전탐색 가능할 듯
- 재귀를 통한 모든 조합 탐색
    - 이모티콘 할인율을 결정하는 결정하는 함수 필요
    - 반복문으로 10부터 시작
- 할인율이 정해지면 user 순회하면서 각 사용자마다 이모티콘 구매 비용 계산
    - 계산 함수에서 -1을 반환하면 구독자 수 증가
- 구독자수가 높은 케이스 저장
- 구독자수가 동일하면 매출액이 높은 케이스 저장

### 고찰

- 재귀 함수에서 어떤 것을 입력할 지 잘 고민해야하겠다.
- 재귀 함수에서 입력되는 변수는 결국 조합
- 이 문제 같은 경우 각 이모티콘의 할인율 조합이 필요했던 문제이다.