---
layout: default
title: 기사단원의 무기 / level 1
parent: Algorithm
nav_order: 9
---

# 기사단원의 무기

[https://school.programmers.co.kr/learn/courses/30/lessons/136798](https://school.programmers.co.kr/learn/courses/30/lessons/136798)

## 문제

- 자신의 번호의 약수 개수만큼의 공격력을 가진 무기를 구매
- 제한 수치보다 큰 공격력을 가진 무기를 구매해야 하는 기사는 정해진 공격력(power)을 가진 무기를 구매
- 기사단의 총 공격력의 합을 리턴

### Input

- number : 기사단원의 수
- limit : 공격력 제한 수치
- power : 제한 수치를 초과한 기사가 사용할 무기의 공격력

### Limitation

- 1≤ number ≤ 100000

### Example

- 15번 기사 → 약수 1,3,5,15 → 공격력 4
- 제한 수치 = 3, power = 2
- 15번 기사의 공격력 = 2

---

### 풀이 과정

- 약수의 개수를 계산해서 벡터로 저장
- 저장할 때 limit보다 큰 경우 power로 저장
- 벡터의 합 리턴
- 시간 초과 발생
    - 아마도 약수를 구하는 for문이 문제라고 생각됨
    - 약수는 항상 짝을 지어 생긴다. 15의 약수 1-15, 3-5
    - 앞의 짝은 제곱 약수가 가장 크다. 9의 약수 1, 3, 9 
    → 3보다 큰 수는 절대 약수가 될 수 없다.
    - 따라서 for문은 i*i가 n과 같을 때까지만 반복해도 된다.

### 코드

```cpp
unordered_map<int, int> numDiv;

void storeDiv(int n) {
    vector<int> div;
    // 약수의 제곱은 n보다 클 수 없다.
    for (int i=1; i*i<=n; i++) {
        if(n % i == 0) {
            div.push_back(i); // 약수 저장
            // 약수 i를 저장하고 제곱이 되는 약수가 아니라면
            // i를 곱해서 n이 될 수 있는 수 n/i도 저장한다
            if(n/i != i) div.push_back(n/i);
        }
    }
    numDiv[n] = div.size();
    // cout << "n : " << n << " numDiv : " << numDiv[n] << endl;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    numDiv[1] = 1;
    for (int n=1; n<=number; n++) {
        if(!numDiv[n]) storeDiv(n);
        answer += numDiv[n] <= limit ? numDiv[n] : power;
    }
    return answer;
}
```

### 고찰

- 약수에 대한 이해가 좀 필요한 문제였다.
- 다른 사람의 풀이를 보니 굳이 벡터에 저장하지 않았어도 상관없었다.
문제가 원한 것은 약수의 개수였기 때문에…
```cpp
for( int i = 1; i * i <= iNum; ++i )
    {
        if( i * i == iNum )
        {
            ++iCount;
        }
        else if( iNum % i == 0 )
        {
            iCount += 2;
        }
    }
```