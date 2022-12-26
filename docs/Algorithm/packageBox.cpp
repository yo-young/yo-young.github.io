---
layout: default
title: 택배상자 / level 2
parent: Algorithm
nav_order: 8
---
# 택배상자

[https://school.programmers.co.kr/learn/courses/30/lessons/131704](https://school.programmers.co.kr/learn/courses/30/lessons/131704)

## 문제 설명

- 1 ~ n 순서 오름차순
- 알려준 순서에 맞게 재정렬 필요
- 보조 스택을 사용해도 원하는 순서대료 정렬하지 못한다면 종료
- 정렬된 수의 개수를 리턴

### Input

- vector<int> order

### Output

- int

### example

| order | result |
| --- | --- |
| 4,3,1,2,5 | 2 |
| 5,4,3,2,1 | 5 |

### Limitation

- 1 ≤ order.size() ≤ 1,000,000
- order[i]는 i번째 수를 i+1번째로 정렬해야함을 의미
ex) order[2] = 1 이면, 1은 3번째로 정렬되어야함

---

### 풀이 과정

- example 분석 - order = [4,3,1,2,5]
    - 4를 제일 먼저 입력하려면 1,2,3이 순서대로 스택에 입력
    - 4 입력되고 스택에서 3을 pop하고 3을 입력
    - 현재 j가 위치하고 있는 수는 5, 스택의 top은 2
    - 5와 2 모두 다음 순서가 아니기 때문에 종료
    - 4,3이 입력된 vector의 사이즈 2 리턴
- order[i] == box[j] 가 만족하지 않는 경우
    - stack이 empty가 아닌 경우
    - 스택 top == order[i] 가 만족하지 않는 경우
        - box[j]를 stack에 push
    - 만족하는 경우
        - 스택 pop하고 answer +1
    - stack이 empty인 경우
        - 
- 만족하는 경우
    - answer +1

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    vector<int> box;
    stack<int> temp;
    temp.push(0);
    for (int i=0; i<order.size(); i++) {
        box.push_back(i+1);
    }
    int j=0;
    for (int i=0; i<box.size(); i++) {
      if(order[j] == box[i]) {
        answer+=1;
        j+=1;
        continue;
      }
      if(order[j] == temp.top()) {
        answer+=1;
        j+=1;
        i-=1;
        temp.pop();
        continue;
      }
      temp.push(box[i]);
    }
    int size = temp.size();
    for (int i=0; i<size; i++) {
      if(!temp.top()) break;
      if (order[j] == temp.top()) {
        j+=1;
        temp.pop();
        answer += 1;
      }
    }
    return answer;
}
```

### 고찰

- box 벡터를 반복
    - 현재 order와 현재 box 비교
    - 현재 order와 현재 스택의 top 비교
        - 스택에 저장된 box를 꺼내는 경우 현재 box를 유지하기 위해 i를 감소
    - 둘 다 만족하지 않는 경우 현재 box를 스택에 push
- 위 알고리즘으로 해결할 수 없는 경우 - box의 역순으로 order가 정렬된 경우
    - 스택을 반복해서 top과 order를 비교
- 다른 사람의 풀이 참고
    - 이런 생각을 어떻게 하지..?
    ```cpp
    int solution(vector<int> order) {
        int answer = 0;
        stack<int> st;
        for(int i = 1; i <= order.size(); ++i)
        {
            st.push(i);
            while(!st.empty() && order[answer] == st.top())
            {
                st.pop();
                answer++;
            }
        }
        return answer;
    }
    ```
    
    - 스택에 일단 box를 push
    - while문 반복
        - 스택이 empty이고 order[answer]가 스택의 top과 동일한 경우
        - 스택에서 꺼내고 answer 증가
- 문제를 실제와 비교해서 구현하면 어렵다.
    - 코드의 관점에서 생각하는 훈련이 가능한가..?