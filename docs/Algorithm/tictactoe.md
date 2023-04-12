---
layout: default
title: 혼자서 하는 틱택토 / level 2
parent: Algorithm
nav_order: 8
---

# 혼자서 하는 틱택토

# 문제 이름

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/160585)

## 문제 설명

- 주어진 틱택토 게임판을 보고 실제로 틱택토 규칙을 지켜서 진행했을 때 나올 수 있는 상황인지 판단
- 선공은 항상 “O”, 후공은 “X”
- 실제로 나올 수 있는 상황인 경우 1 반환
- 반대인 경우 0 반환

### Input

- vector<string> board

### Output

- 1 or 0

### example

| board | result |
| --- | --- |
| ["O.X", ".O.", "..X"] | 1 |
| ["OOO", "...", "XXX"] | 0 |
| ["...", ".X.", "..."] | 0 |
| ["...", "...", "..."] | 1 |

### Limitation

- 

---

### 풀이 과정

- 선공이 O, 후공이 X라면 X는 O보다 많은 수가 존재할 수 없음
- O의 개수와 X의 개수가 같은 경우
    - O의 승리인 경우는 존재할 수 없음 - X가 두기 전에 게임이 종료됨
- O의 개수가 X보다 많은 경우
    - X가 승리인 경우는 존재할 수 없음 - O가 두기 전에 게임이 종료됨
- O가 X의 개수보다 2개 이상 많을 수 없음
- 그럼 승리판별은 어떻게 하지?
    - 가운데 글자[1][1]에서 체크해야할 곳
        - 상하 [0][1] / [2][1]
        - 좌우 [1][0] / [1][2]
        - 좌대각 [0][0] / [2][2]
        - 우대각 [0][2] / [2][0]
    - 대각선 방향
        - [0][2] → [1][1] → [2][0]

```cpp
bool win(vector<string> board, int x, int y)
{
    bool win;
    char c = board[x][y];
    int cnt=0;
    for(int i=0; i<3; i++) // 수직
    {
        if(board[i][y] == c) cnt += 1;
        if(cnt == 3) return true;
    }
    cnt=0;
    for(int i=0; i<3; i++) // 수평
    {
        if(board[x][i] == c) cnt += 1;
        if(cnt == 3) return true;
    }
    cnt=0;
    for(int i=0; i<3; i++)
    {
        if(board[i][i] == c) cnt += 1;
        if(cnt == 3) return true;
    }
    cnt=0;
    for(int i=0; i<3; i++)
    {
        if(board[i][2-i] == c) cnt += 1;
        if(cnt == 3) return true;
    }
    return false;
}

int solution(vector<string> board) {
    int answer = 1;
    int numO=0, numX=0;
    bool winO=false, winX=false;

    for(int i=0; i<board.size(); i++)
    {
        for (int j=0; j<board[0].size(); j++)
        {
            char c = board[i][j];
            if(c == 'O') {
                numO++;
                if(!winO) {
                    winO = win(board, i, j);
                }                
            }
            if(c == 'X') {
                numX++;
                if(!winX) {
                    winX = win(board, i, j);
                }
            }
        }
    }
    cout <<"winO : "<<winO<<endl;
    if(numO < numX) return 0;
    if(numO == numX)
    {
        if(winO) return 0;
    }
    if(numO > numX)
    {
        if(numO-numX > 1) return 0;
        if(winX) return 0;
    }

    return answer;
}
```

### 고찰

- 틱택토 게임은 3by3 게임판에서 진행하기 때문에 복잡도에 영향을 받는 문제는 아니라고 본다.
- 틱택토 게임에서 발생할 수 없는 상황을 판별할 때 그냥 생각나는 케이스들로 구현했는데 통과했다.
- win함수에서 cnt를 초기화하지 않아서 로컬 IDE와 프로그래머스 서버에서 결과가 다르게 나오는 상황이 있었다. 변수 초기화는 꼭 잊지말고 할 것.