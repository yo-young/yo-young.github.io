---
layout: default
title: 최댓값과 최소값 / level 2
parent: Algorithm
nav_order: 8
---

# 최댓값과 최소값

[https://school.programmers.co.kr/learn/courses/30/lessons/12939](https://school.programmers.co.kr/learn/courses/30/lessons/12939)

## 문제 설명

- 공백으로 구분된 숫자들의 문자열
- 문자열의 숫자 중 최소값과 최대값을 찾아서 반환

### Input

- "1 2 3 4”

### Output

- "1 4”

### example

| s | return |
| --- | --- |
| "1 2 3 4" | "1 4" |
| "-1 -2 -3 -4" | "-4 -1" |
| "-1 -1" | "-1 -1" |

### Limitation

- s 문자열에는 정수가 두 개 이상

---

### 풀이 과정

- 문자열에서 공백으로 구분된 숫자 추출
    - 어떻게?
    - ‘ ‘ 공백을 기준으로 temp문자열에 append
    - ‘ ‘ 공백을 만나면 int 벡터에 변환해서 저장
    - int 벡터를 정렬해서 최소, 최대 구하기
- 추출만 하면 벡터에 저장해서 sort로 정렬
- 인덱스 0과 back()으로 마지막 원소 추출

```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> s_vector;
    string temp = "";

    for (int i=0; i<=s.size(); i++) {
        // cout << "i : " << i << endl;
        if (s[i] != ' ') {
            temp += s[i];
        }
        if (s[i] == ' ' || i == s.size()) {
            int tempNum = stoi(temp);
            s_vector.push_back(tempNum);
            temp = "";
        }
    }
    sort(s_vector.begin(), s_vector.end());
    answer += to_string(s_vector.front());
    answer += " ";
    answer += to_string(s_vector.back());

    return answer;
}
```

### 고찰

- 문자열을 int로 변환, int를 문자열로 변환
- sstream을 이용하여 ‘ ‘ 공백문자를 token으로 문자열을 분리하는 코드
    - 복잡도에 차이가 있을 것 같진 않지만 sstream을 활용하면 if문을 사용하지 않아도 된다.
    - 내 코드에 존재하는 if문 두 구문이 사라지면 에러 찾을 때도 용이하고 가독성도 좋아보일 것 같다.
    
    ```cpp
    string solution(string s) {
        string answer = "";
        string token;
        istringstream iss(s);
        vector<int> num;
    
        while(getline(iss, token, ' '))
        {
              num.push_back(stoi(token));
        }
    
        sort(num.begin(), num.end());
    
        answer = to_string(num.front()) + " " + to_string(num.back());
    
        return answer;
    }
    ```