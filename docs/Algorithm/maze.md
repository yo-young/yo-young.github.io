---
layout: default
title: 미로 탈출 / level 2
parent: Algorithm
nav_order: 8
---

# 미로 탈출

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/159993)

## 문제 설명

- 격자 형태 직사각형 형태의 미로에서 탈출
- 미로에서 한 칸은 출구
- 한 칸은 출구를 열기 위한 레버
- 한 칸을 이동하는데 걸리는 시간은 1초
- 탈출 할 수 없으면 -1 반환

### Input

- vector<string> maps
    - S : start
    - E : escape
    - L : lever
    - O : way
    - X : wall

### Output

- int 탈출 시간

### example

| maps | result |
| --- | --- |
| ["SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"] | 16 |
| ["LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"] | -1 |

### Limitation

- 5 ≤ maps의 길이 ≤ 100

---

### 풀이 과정
- 2/19
    - 일반적인 미로탈출 문제에서 반드시 거쳐가야하는 지점이 존재
    - 보통 미로탈출문제는 DFS로 풀이
        - S 위치 탐색, L 위치 탐색
            - maps의 길이가 100이하이므로 완전 탐색 가능
        - DFS로 풀이
    - TC 15에서 Segmentation fault 발생
        - 벡터 범위 계산 다시 확인해 볼 것
    - 시간 초과
        - DFS가 아니라 BFS로 했어야 했나?
        - BFS 확인해 볼 것
    
    <aside>
    ✅ 2/19 결과
    
    | 테스트 1 〉 | 통과 (0.01ms, 3.61MB) |
    | --- | --- |
    | 테스트 2 〉 | 실패 (0.02ms, 4.19MB) |
    | 테스트 3 〉 | 실패 (시간 초과) |
    | 테스트 4 〉 | 통과 (0.01ms, 4.12MB) |
    | 테스트 5 〉 | 통과 (0.01ms, 4.2MB) |
    | 테스트 6 〉 | 실패 (0.01ms, 4.2MB) |
    | 테스트 7 〉 | 실패 (0.03ms, 3.66MB) |
    | 테스트 8 〉 | 실패 (시간 초과) |
    | 테스트 9 〉 | 실패 (0.01ms, 4.14MB) |
    | 테스트 10 〉 | 통과 (0.01ms, 4.14MB) |
    | 테스트 11 〉 | 실패 (시간 초과) |
    | 테스트 12 〉 | 실패 (0.24ms, 4.21MB) |
    | 테스트 13 〉 | 실패 (시간 초과) |
    | 테스트 14 〉 | 실패 (시간 초과) |
    | 테스트 15 〉 | 실패 (signal: segmentation fault (core dumped)) |
    | 테스트 16 〉 | 실패 (시간 초과) |
    | 테스트 17 〉 | 실패 (시간 초과) |
    | 테스트 18 〉 | 통과 (0.01ms, 4.17MB) |
    | 테스트 19 〉 | 실패 (0.01ms, 4.2MB) |
    | 테스트 20 〉 | 통과 (0.02ms, 3.66MB) |
    | 테스트 21 〉 | 실패 (0.03ms, 4.2MB) |
    | 테스트 22 〉 | 실패 (0.01ms, 4.14MB) |
    | 테스트 23 〉 | 통과 (0.01ms, 4.13MB) |
    </aside>
    
    ```cpp
    #include <iostream>
    #include <string>
    #include <vector>
    
    using namespace std;
    int answer = 0;
    bool found = false;
    vector<string> visitedMaps;
    
    void findSL(pair<int, int>& S, pair<int, int>& L, const vector<string>& maps)
    {
        for(int i=0; i<maps.size(); i++) {
            for(int j=0; j<maps[i].size(); j++) {
                if(maps[i][j] == 'S') {
                    S.first=i;
                    S.second=j;
                }
                if(maps[i][j] == 'L') {
                    L.first=i;
                    L.second=j;
                }
            }
        }
    }
    bool checkBorder(int x, int y, const vector<string>& maps) {
        if (x<0 || y<0) return false;
        if (x>=maps.size() || y>=maps.size()) return false;
        if (maps[x][y] == 'X') return false;
        return true;
    }
    
    void dfs(const int x,const int y, const vector<string>& maps, int cnt, char target)
    {
        if(target =='L' && maps[x][y] == 'L' ||
           target =='E' && maps[x][y] == 'E') {
            answer = cnt;
            found = true;
            return;
        }
        //right, down, left, up
        ++cnt;
        auto temp = visitedMaps[x][y];
        visitedMaps[x][y] = 'X';
        if(found) return;
        if (checkBorder(x, y+1, maps) &&
            visitedMaps[x][y+1] != 'X') {
            dfs(x, y+1, maps, cnt, target);
        }
        if (checkBorder(x+1, y, maps) &&
            visitedMaps[x+1][y] != 'X') {
            dfs(x+1, y, maps, cnt, target);
        }
        if (checkBorder(x, y-1, maps) &&
            visitedMaps[x][y-1] != 'X') {
            dfs(x, y-1, maps, cnt, target);
        }
        if (checkBorder(x-1, y, maps) &&
            visitedMaps[x-1][y] != 'X') {
            dfs(x-1, y, maps, cnt, target);
        }
        visitedMaps[x][y] = temp;
        --cnt;
    
    }
    
    int solution(vector<string> maps) {
        visitedMaps = maps;
        //find S, L
        pair<int, int> S;
        pair<int, int> L;
        findSL(S, L, maps);
        dfs(S.first, S.second, maps, 0, 'L');
        if(answer == 0) return -1;
    
        int toL = answer;
        found = false;
        visitedMaps = maps;
        dfs(L.first, L.second, maps, answer, 'E');
        if(toL == answer) return -1;
    
        return answer;
    }
    
    int main()
    {
        vector<string> maps =
            {"OOOOO",
             "XXXXO",
             "OOOOO",
             "OXXXX",
             "OOLES"};
            // {"SOOOL",
            //  "XXXXO",
            //  "OOOOO",
            //  "OXXXX",
            //  "OOOOE"};
        int answer;
        answer = solution (maps);
    
        cout << answer << endl;
    
        return 0;
    }
    ```
    
- 2/21
    - BFS로 재풀이
    
    ```cpp
    vector<string> visitedMaps(10000);
    pair<int, int> moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}};
    void findSL(pair<int, int>& S, pair<int, int>& L, const vector<string>& maps)
    {
        for(int i=0; i<maps.size(); i++) {
            for(int j=0; j<maps[i].size(); j++) {
                if(maps[i][j] == 'S') {
                    S.first=i;
                    S.second=j;
                }
                if(maps[i][j] == 'L') {
                    L.first=i;
                    L.second=j;
                }
            }
        }
    }
    bool checkBorder(int x, int y, const vector<string>& maps) {
        if (x<0 || y<0) return true;
        if (x>=maps.size() || y>=maps.size()) return true;
        if (maps[x][y] == 'X' || visitedMaps[x][y]) return true;
        return false;
    }
    typedef struct
    {
        int x, y;
        int time;
    } Position;
    bool operator<(Position a, Position b)
    {
        return a.time > b.time;
    }
    
    int bfs(priority_queue<Position>& pq, const vector<string>& maps, char dest) {
        while(!pq.empty())
        {
            int x = pq.top().x;
            int y = pq.top().y;
            int time = pq.top().time;
            pq.pop();
            for(int i=0; i<4; i++)
            {
                int nextX = x+moveDir[i].first;
                int nextY = y+moveDir[i].second;
                if(checkBorder(nextX, nextY, maps)) {
                    continue;
                }
                if (maps[nextX][nextY] == dest) {
                    return time+1;
                }
                visitedMaps[nextX][nextY] = 1;
                pq.push({nextX, nextY, time+1});
            }
        }
        return -1;
    }
    
    int solution(vector<string> maps) {
        pair<int, int> S;
        pair<int, int> L;
        findSL(S, L, maps);
        priority_queue<Position> pq;
        pq.push({S.first, S.second, 0});
        int time=0;
        //up, down, left, right
        int t = bfs(pq, maps, 'L');
        if (t == -1) return t;
        cout << "to L : " << t << endl;
        fill(visitedMaps.begin(), visitedMaps.end(), 0);
        pq = priority_queue<Position>();
        pq.push({L.first, L.second, t});
        t = bfs(pq, maps, 'E');
        cout << "to E : " << t << endl;
        return t;
    }
    ```
    
    - 결과
    
    | 테스트 1 〉 | 통과 (0.06ms, 4.01MB) |
    | --- | --- |
    | 테스트 2 〉 | 실패 (0.02ms, 4.15MB) |
    | 테스트 3 〉 | 실패 (0.02ms, 4.2MB) |
    | 테스트 4 〉 | 통과 (0.06ms, 4.2MB) |
    | 테스트 5 〉 | 실패 (0.06ms, 4.21MB) |
    | 테스트 6 〉 | 통과 (0.07ms, 4.15MB) |
    | 테스트 7 〉 | 실패 (signal: aborted (core dumped)) |
    | 테스트 8 〉 | 실패 (signal: segmentation fault (core dumped)) |
    | 테스트 9 〉 | 통과 (0.10ms, 3.68MB) |
    | 테스트 10 〉 | 통과 (0.01ms, 4.21MB) |
    | 테스트 11 〉 | 실패 (signal: aborted (core dumped)) |
    | 테스트 12 〉 | 실패 (signal: segmentation fault (core dumped)) |
    | 테스트 13 〉 | 실패 (0.02ms, 4.13MB) |
    | 테스트 14 〉 | 실패 (signal: segmentation fault (core dumped)) |
    | 테스트 15 〉 | 실패 (signal: aborted (core dumped)) |
    | 테스트 16 〉 | 실패 (signal: segmentation fault (core dumped)) |
    | 테스트 17 〉 | 실패 (signal: segmentation fault (core dumped)) |
    | 테스트 18 〉 | 통과 (0.01ms, 4.21MB) |
    | 테스트 19 〉 | 실패 (0.06ms, 3.67MB) |
    | 테스트 20 〉 | 통과 (0.02ms, 3.66MB) |
    | 테스트 21 〉 | 실패 (signal: aborted (core dumped)) |
    | 테스트 22 〉 | 실패 (0.02ms, 4.13MB) |
    | 테스트 23 〉 | 실패 (0.09ms, 4.21MB) |