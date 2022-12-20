---
layout: default
title: 가장 가까운 같은 글자 / level 1
parent: Algorithm
nav_order: 9
---

# 가장 가까운 같은 글자

[https://school.programmers.co.kr/learn/courses/30/lessons/142086](https://school.programmers.co.kr/learn/courses/30/lessons/142086)

## 문제 설명

- 글자를 왼쪽부터 오른쪽으로 읽어 나가면서 중복 글자 거리 계산
- s = “banana” 인 경우
    - b는 처음 나왔기 때문에 자신의 앞에 같은 글자가 없습니다. 이는 -1로 표현합니다.
    - a는 처음 나왔기 때문에 자신의 앞에 같은 글자가 없습니다. 이는 -1로 표현합니다.
    - n은 처음 나왔기 때문에 자신의 앞에 같은 글자가 없습니다. 이는 -1로 표현합니다.
    - a는 자신보다 두 칸 앞에 a가 있습니다. 이는 2로 표현합니다.
    - n도 자신보다 두 칸 앞에 n이 있습니다. 이는 2로 표현합니다.
    - a는 자신보다 두 칸, 네 칸 앞에 a가 있습니다. 이 중 가까운 것은 두 칸 앞이고, 이는 2로 표현합니다.

### Input

- s 문자열

### Output

- int 벡터

### example

| s | result |
| --- | --- |
| "banana" | [-1, -1, -1, 2, 2, 2] |
| "foobar" | [-1, -1, 1, -1, -1, -1] |

### Limitation

- 1 ≤ s의 길이 ≤ 10000

---

### 풀이 과정

- s와 읽어가는 과정에서 저장할 임시 문자열이 필요
- 이중 for문으로 s와 임시 문자열을 반복
    
    ```cpp
    for(int i : s.size()) //s = banana
    {
    	temp = s[0~i]; // i=3, s[i] = a
    	for(int j : temp.size()-1) //temp = bana
    	{
    		if(cnt == 1) cnt++;
    		if(s[i] == temp[j]) // j=1일 때 temp[j] = 2
    		{
    			cnt=1;
    		}
    	}
    }
    ```
    

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = -1;
    answer.push_back(cnt);
    for(int i=1; i<s.size(); i++)
    {
        cout<<"s["<<i<<"] :"<< s[i] <<endl;
        string temp = s.substr(0,i+1);
        // cout<<"temp : "<< temp <<endl;
        for(int j=0; j<temp.size()-1; j++)
        {
            cout<<"temp["<<j<<"] :"<< temp[j] <<endl;
            if(cnt > 0) cnt++;
            if(s[i] == temp[j])
            {
                cnt=1;
            }
            cout<<"cnt : "<< cnt <<endl;
        }
        cout<<"answer cnt : "<< cnt <<endl;
        answer.push_back(cnt);
        cnt = -1;
    }
    
    return answer;
}
```

### 고찰

- 이중 for문으로 문자열을 비교 탐색
- 다른 사람의 풀이 참고
    - map을 이용하여 for문을 하나만 사용하여 풀이
    
    ```cpp
    vector<int> solution(string s) {
        vector<int> answer;
        map<char, int> m;
    
        for (int i = 0; i < s.size(); i++)
        {
            auto iter = m.find(s[i]);
            if (iter == m.end()) //처음찾는친구.
            {
                //현재 인덱스 저장.
                m[s[i]] = i;
                answer.emplace_back(-1);
            }
            else //이미 있음.
            {
                int length = i - m[s[i]];
                answer.emplace_back(length);
                //인덱스 새로 저장.
                m[s[i]] = i;
            }
        }
        return answer;
    }
    ```
    
    - 문자와 인덱스를 저장할 map 선언
    - find 함수가 end를 반환하면 처음 찾는 문자이므로 현재 인덱스 저장 및 -1 저장
    - 현재 인덱스에서 찾는 문자의 인덱스를 빼면 떨어진 거리
    - 현재 인덱스로 새로 저장