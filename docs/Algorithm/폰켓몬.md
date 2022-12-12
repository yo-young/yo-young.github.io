---
layout: default
title: 폰켓몬 / level 1
parent: Algorithm
nav_order: 9
---

# 폰켓몬

> [https://school.programmers.co.kr/learn/courses/30/lessons/1845](https://school.programmers.co.kr/learn/courses/30/lessons/1845)
>

## 문제

N개의 숫자 중에서 N/2 개를 고른다.

N개의 숫자 중에서 최대한 다른 종류의 숫자를 고른다.

숫자의 종류 수를 리턴

### Input

N개의 숫자

### example

| nums | result |
| --- | --- |
| [3,1,2,3] | 2 |
| [3,3,3,2,2,4] | 3 |
| [3,3,3,2,2,2] | 2 |

### limitation

- 1 < N < 10000
- 1 < nums < 200000

### 풀이 과정

- nums 배열 사이즈 전체 탐색
- cmp 숫자 저장해서 비교
- cmp랑 같으면 continue 다르면 answer 증가하고 cmp에 저장
- answer 가 N/2 가 되면 리턴

### 코드

```cpp
int solution(vector<int> nums)
{
    int answer = 1;
    int N = nums.size();
    sort(nums.begin(), nums.end());
    int cmp = nums[0];
    for (int i=0; i<N; i++) {
        if (answer == N/2) return answer;
        if (nums[i] == cmp) {
            continue;
        }
        else {
            answer++;
            cmp = nums[i];
        }
    }

    return answer;
}
```

### 고찰

- map을 어떻게 사용할 지 떠오르지 않아서 완전 탐색 구현했다.
- 다른 사람 풀이 중 2개를 참고해서 공부
- unordered_map을 이용한 풀이
    - <int, int>의 hash map을 선언
    - hash map에 nums의 값을 키로 삽입하면서 1씩 증가
    - hash의 size와 N/2의 값 중 작은 값을 리턴

```cpp
int solution(vector<int> nums)
{
    unordered_map<int, int> hash;
    for (auto num: nums) {
        hash[num] += 1;
    }
    return min(hash.size(), nums.size() / 2);
}
```

- unordered_set을 이용한 풀이
    - unordered_set에 nums를 삽입 → 중복 제거
    - N/2와 s의 사이즈 중 작은 값을 리턴

```cpp
int solution(vector<int> nums) {
    unordered_set<int> s(nums.begin(), nums.end());

    return min(nums.size() / 2, s.size());
}
```