---
layout: default
title: 주차 요금 계산 / level 2
parent: Algorithm
nav_order: 8
---

# 주차 요금 계산

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/92341)

## 문제 설명

- 주차 요금 표 (fees)

| 기본 시간(분) | 기본 요금(원) | 단위 시간(분) | 단위 요금(원) |
| --- | --- | --- | --- |
| 180 | 5000 | 10 | 600 |
- 입/출차 기록 (records)

| 시각(시:분) | 차량 번호 | 내역 |
| --- | --- | --- |
| 05:34 | 5961 | 입차 |
| 06:00 | 0000 | 입차 |
| 06:34 | 0000 | 출차 |
| 07:59 | 5961 | 출차 |
| 07:59 | 0148 | 입차 |
| 18:59 | 0000 | 입차 |
| 19:09 | 0148 | 출차 |
| 22:59 | 5961 | 입차 |
| 23:00 | 5961 | 출차 |
- 주차 요금과 입/출차 기록이 주어지면 차량 번호에 따라 주차 요금을 계산하여 반환
- 위 주차 요금표 기준 차량번호 0000
    - 06:00 입차 06:34 출차 34분
    - 18:59 입차 23:59 출차 300분
    - 주차 요금 : 기본 요금 + (누적 주차 시간 - 기본 시간)/단위 시간 * 단위 요금
- **차량 번호가 작은 자동차부터** 청구할 주차 요금을 차례대로 정수 배열에 담아서 return

### Input

- vector<int> fees
- vector<string> records

### Output

- vector<int>

### example

| fees | records | result |
| --- | --- | --- |
| [180, 5000, 10, 600] | ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"] | [14600, 34400, 5000] |
| [120, 0, 60, 591] | ["16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN"] | [0, 591] |
| [1, 461, 1, 10] | ["00:00 1234 IN"] | [14841] |

### Limitation

- fees는 기본 시간, 기본 요금, 단위 시간, 단위 요금 형
- 1 ≤ records.size() ≤ 1,000
    - records는 시각, 차량번호, 내역 형식

---

### 풀이 과정

- 일단은 records 문자열을 처리하는 코드가 필요
    - istringstream과 getline을 사용하여 문자열 분리
- map에 차량 번호를 키로 입차 시간을 저장
    - map은 기본적으로 key를 기준으로 오름차순으로 저장
    - 입차 시간만 있는 경우 어떻게 처리하지?
    - map에 입차시간을 저장하는 것이 아니고 큐를 저장
    - 입차인 경우 큐에 입차 시간 저장
    - 출차인 경우
        - 출차 시간 - 입차 시간해서 누적 시간 계산
        - queue에서 pop → queue is empty
        - 누적시간은 큐와 pair로 map에 저장
    - Map
        - Key = 차량 번호
        - Value = pair<큐(입차시간), 누적 주차 시간>
- record를 한번 반복 후에 출차가 없는 차를 찾기 위해 map을 순회
    - Value의 큐가 empty인 경우 이미 출차
    - 큐가 empty가 아닌 경우 출차되지 않음.
    - 출차시간을 “23:59”으로 설정하여 주차 시간 계산
- 다시 map을 순회하며 누적 시간에 따른 주차 시간 계산해서 answer에 push

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map> // map은 key값을 기준으로 오름차순으로 정렬되어있음
#include <queue>

using namespace std;
void vectorSeparator(char separator, string elem, vector<string>& record) {
    string buf;
    istringstream iss(elem);
    while (getline(iss, buf, separator)) {
            cout << buf << " ";
            record.push_back(buf);
    }
    cout << endl;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    // 주차내역 + 주차시간
    pair<queue<string>, int> pair_historyTime;
    // 차량번호(주차내역 + 누적주차시간)
    map<string, pair<queue<string>, int>> map;

    for (auto& elem : records) {
        vector<string> record;
        vectorSeparator(' ', elem, record);
        // record[0] : 입/출차 시간
        // record[1] : 차량 번호
        // record[2] : 입/출차 내역
        // 현재 누적 주차 시간
        int current = map[record[1]].second;
        cout<<"car num : "<<record[1]<<", ";
        cout<<"current : "<<current<<endl;
        // history가 비어 있는 경우 해당 차량이 출차되었음을 의미
        queue<string> history;
        if (record[2] == "IN") {
            // 큐에 입차 시간 저장
            history.push(record[0]);
            // map에 큐와 현재 누적 시간 저장
            map[record[1]] = make_pair(history, current);
        }
        else { //"OUT"
            vector<string> enter, departure;
            //입차 시간
            string buf = map[record[1]].first.front();            
            map[record[1]].first.pop();
            // HH:MM 시간 분 분리
            vectorSeparator(':', buf, enter);
            //출차 시간
            buf = record[0];
            vectorSeparator(':', buf, departure);
            int parkingHour = stoi(departure[0]) - stoi(enter[0]);
            int parkingMin = stoi(departure[1]) - stoi(enter[1]);
            int parkingTime = parkingMin + parkingHour*60;
            map[record[1]].second = current + parkingTime;
            cout<<"car num : "<<record[1]<<", ";
            cout<<"out -- current : "<<map[record[1]].second<<endl;
        }
        cout<<endl;
    }
    cout<<"--------------------------"<<endl;
    // 출차 시간이 없는 차 처리
    for (auto& elem : map) {
        cout<<"car num : "<<elem.first <<endl;
        queue<string> history = elem.second.first;
        int current = elem.second.second;
        if (!history.empty()) {
            vector<string> enter, departure;
            //입차 시간
            string buf = history.front();
            vectorSeparator(':', buf, enter);
            //출차 시간
            vectorSeparator(':', "23:59", departure);
            int parkingHour = stoi(departure[0]) - stoi(enter[0]);
            int parkingMin = stoi(departure[1]) - stoi(enter[1]);
            int parkingTime = parkingMin + parkingHour*60;
            elem.second.second = current + parkingTime;
        }
    }
    cout<<"2--------------------------"<<endl;
    for (auto& elem : map) {
        // fees[0] : 기본 시간, fees[1] : 기본 요금
        // fees[2] : 단위 시간, fees[3] : 단위 요금
        int time = elem.second.second;
        if(time<fees[0]) {
            answer.push_back(fees[1]);
            continue;
        }
        cout <<"parking time : "<<time<<endl;

        int fee = fees[1] + ((time - fees[0])/fees[2] * fees[3]);
        int add = (time - fees[0])%fees[2];
        if(add) fee += fees[3];
        
        answer.push_back(fee);
    }

    return answer;
}
```

### 고찰

- map의 value에 큐와 정수형을 pair로 입력
    - 알고리즘은 통과했으나 코딩하는 과정에서 자료구조를 알아보기가 너무 힘듬
    - 디버깅하면서 헷갈리면 시간 많이 잡아먹을 가능성 있음
- 다른 사람의 풀이 참고
    - 대단하다…

```cpp
#include <bits/stdc++.h>
using namespace std;

int conv(string& t) {
    int h = (t[0] - 48) * 10 + t[1] - 48;
    int m = (t[3] - 48) * 10 + t[4] - 48;
    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> vec[10000];
    for (auto& record : records) {
        stringstream ss(record);
        string a, b, c;
        ss >> a >> b >> c;
        vec[stoi(b)].push_back(conv(a));
    }

    vector<int> ans;
    for (int i = 0; i < 10000; ++i) if (!vec[i].empty()) {
        if (vec[i].size() & 1) vec[i].push_back(23 * 60 + 59);

        int sum = 0;
        for (int j = 1; j < vec[i].size(); j += 2) sum += vec[i][j] - vec[i][j - 1];

        int val = fees[1];
        if (sum > fees[0]) val += (sum - fees[0] + fees[2] - 1) / fees[2] * fees[3];

        ans.push_back(val);
    }

    return ans;
}
```

- 일단 conv함수는 입력된 records에 입/출차 상관없이 시간을 분으로 변환한다.
    - 변환된 int형 시간은 vec이라는 벡터에 차량번호에 저장된다.
    - 그럼 vec[0000] = {360, 394, 1139} 로 저장될 것이다.
- 그리고 vec 를 순회해서 vec[i]가 empty가 아닌 경우
    - `vec[i].size() & 1` 의 의미는 홀수. 비트연산할 때 홀수는 마지막이 항상 1
    - 그래서 홀수면 23:59 출차 시간을 추가해준다.
    - vec[i]를 j로 순회하면서 출차시간-입차시간을 계산해서 sum에 누적한다.
    - fee를 계산해서 ans에 대입한다.
    - 차량번호 순서는 vec에 대입할 때 차량번호를 인덱스로 사용했기 때문에 i를 0부터 순회하면서 증가하여 작은 번호 부터 ans에 대입된다….