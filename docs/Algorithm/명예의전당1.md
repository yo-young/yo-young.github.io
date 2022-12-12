---
layout: default
title: 명예의 전당 (1) / level 1
parent: Algorithm
nav_order: 9
---

# 명예의 전당 (1)

[https://school.programmers.co.kr/learn/courses/30/lessons/138477?language=cpp](https://school.programmers.co.kr/learn/courses/30/lessons/138477?language=cpp)

## 문제 설명

- 점수가 k번째 이내인 경우 명예의 전당
- 매일 최하위 점수 발표(k번째 점수)

### Input

- score

### Output

- k번 째 점수

### example

| k | score | result |
| --- | --- | --- |
| 3 | [10, 100, 20, 150, 1, 100, 200] | [10, 10, 10, 20, 20, 100, 100] |
| 4 | [0, 300, 40, 300, 20, 70, 150, 50, 500, 1000] | [0, 0, 0, 0, 20, 40, 70, 70, 150, 300] |

### Limitation

- k ≤ 100
- score길이 ≤ 1000

---

### 풀이 과정

- limitation만 보면 score가 입력될 때마다 for문으로 k번째 점수를 찾으면 될 것 같음

```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer, todayScore;
    int lastDay = score.size();
    
    for (int day=0; day<lastDay; day++) {
        todayScore.push_back(score[day]);
        sort(todayScore.rbegin(), todayScore.rend());
        if (day < k) {
            answer.push_back(todayScore[day]);
        }
        else {
            answer.push_back(todayScore[k-1]);
        }
    }
    return answer;
}
```

### 고찰

- sort에 rbegin을 사용해서 내림차순으로 정렬
- k번째 숫자만 뽑아내면 되기 때문에 for문 하나로도 충분
- 내용이 너무 심플해서 딱히 다른 사람 코드를 참고할 것은 안보였다.
    - 한 가지 todayScore 배열에서 k번째 요소를 지우면서 구현한 코드를 봤지만 메모리 이슈가 없는 문제였기 때문에 굳이 그렇게 할 필요는 없을 것 같다.
    - 유사한 형태에서 input 벡터의 사이즈가 엄청나게 커진다면 고려할 만한 코드이긴 했다.