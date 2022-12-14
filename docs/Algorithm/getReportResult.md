---
layout: default
title: 신고 결과 받기 / level 1
parent: Algorithm
nav_order: 9
---

# 신고 결과 받기

[https://school.programmers.co.kr/learn/courses/30/lessons/92334](https://school.programmers.co.kr/learn/courses/30/lessons/92334)

## 문제

- 각 유저는 한 번에 한 명의 유저를 신고
    - 신고 횟수 제한은 없음
    - 한 유저를 여러 번 신고해도 동일 유저에 대한 신고는 1회로 처리
- k번 이상 신고된 유저는 게시판 이용이 정지, 해당 유저를 신고한 모든 유저에게 정지 사실을 발송
    - 유저가 신고한 모든 내용을 취합하여 게시판 이용 정지와 동시에 정지 메일을 발송
    - 각 유저별로 처리 결과 메일을 받은 횟수를 배열

### Input

- vector<string> id_list
- vector<string> report
- int k

### Output

- vector<int> answer

### example

| id_list | report | k | result |
| --- | --- | --- | --- |
| ["muzi", "frodo", "apeach", "neo"] | ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"] | 2 | [2,1,1,0] |
| ["con", "ryan"] | ["ryan con", "ryan con", "ryan con", "ryan con"] | 3 | [0,0 |

|  | muzi | frodo | apeach | neo |
| --- | --- | --- | --- | --- |
| muzi |  | 1 |  | 1 |
| frodo |  |  |  | 1 |
| apeach | 1 | 1 |  |  |
| neo |  |  |  |  |

|  |  |
| --- | --- |
| muzi | 2 |
| frodo | 1 |
| apeach | 1 |
| neo |  |

### Limitation

- 2 ≤ `id_list`의 길이 ≤ 1,000
- 1 ≤ `report`의 길이 ≤ 200,000

---

풀이 과정

- report 길이가 최대 20만.. 이중반복문도 빠듯해보인다.
- report 횟수는 map에 저장. unordered_map의 시간복잡도는 상수
    - istringstream으로 문자열 분리 reporter와 reportee
- report횟수와 report한 유저를 어떻게 연결하지? 연결리스트?
    - map의 키를 신고 당한 유저로 정의
    - map의 value에 신고한 유저들의 아이디를 unordered_set(중복불가능)으로 저장
    - 아이디의 개수는 신고 횟수
- 메일 받은 회수를 id_list의 순서대로 정렬을 어떻게 하지?
    - ~~미리 id_list와 인덱스를 pair로 저장해둘까?~~
    - id_list의 인덱스를 그냥 map으로 따로 저장해둠

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.resize(id_list.size());

    unordered_map<string, int> id_list_idx;
    for (int i=0; i<id_list.size(); i++) {
        id_list_idx[id_list[i]] = i;
    }

    unordered_map<string,unordered_set<string>> reporterMap;
    string reporter, reportee;
    for (int i=0; i<report.size(); i++) {
        istringstream stream(report[i]);
        stream >> reporter >> reportee;
        reporterMap[reportee].insert(reporter);
        //reportee 키에 들어간 id 개수가 report된 숫자
    }

    for (int i=0; i<id_list.size(); i++) {
        // cout << id_list[i] << " : ";
        //id_list[i]는 신고 당한 사람
        //reporterMap[id_list[i]].size()는 신고 당한 횟수
        if (k <= reporterMap[id_list[i]].size()) {
            //신고한 사람들 검색
            for (auto reporter : reporterMap[id_list[i]]) {
                //id_list_idx[reporter] 신고한 사람의 인덱스
                answer[id_list_idx[reporter]] += 1;
            }
        }
    }

    return answer;
}
```

### 고찰

- level 1이라고 마냥 쉬운 문제는 아니었다. 다른 블로그의 풀이를 약간 참고했다.
    - 신고한 유저들의 아이디를 string으로 append하려고 했는데 set을 사용해서 좀더 편리하고 코드양이 줄었다.
    - id_list의 순서대로 answer를 저장해야해서 인덱스가 필요했는데 pair로 정의해둘까 고민했었는데 그냥 map으로 만들었어도 되는 부분이었다.
- report의 길이 20만이라서 단순히 반복문으로 검색하기엔 무리였고 map을 사용해서 복잡도를 줄여봤다.
- istringstream으로 문자열 분리하는 건 아주 편리하기 때문에 꼭 숙지해야겠다.
- 다른 사람의 풀이

```cpp
#include <vector>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // 1. id_list 인덱스 저장하는 부분
    const int n = id_list.size();
    map<string, int> Conv;
    for (int i = 0; i < n; i++) Conv[id_list[i]] = i;

    // 2. 
    vector<pair<int, int>> v;
    sort(report.begin(), report.end());
		//unique함수를 이용해서 report에서 중복된 원소 제거
    report.erase(unique(report.begin(), report.end()), report.end());
		//report 문자열 분리
    for (const auto& s : report) {
        stringstream in(s);
				//a는 report, b는 reportee
        string a, b; in >> a >> b;
				//pair{ reporter 인덱스, reportee 인덱스 }
        v.push_back({ Conv[a], Conv[b] });
    }

    // 3. cnt는 신고당한 횟수?
    vector<int> cnt(n), ret(n);
    // a(reporter), b(reportee) 반복
    // b(reportee)에 신고당한 횟수 증가시키기
    for (const auto& [a, b] : v) cnt[b]++;
    // 다시 반복하면서 b(reportee)의 신고당한 횟수가 k보다 크면
    // ret의 a(reporter)를 증가시키기
    for (const auto& [a, b] : v) if (cnt[b] >= k) ret[a]++;
    return ret;
}
```