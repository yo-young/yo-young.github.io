#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
// int answer = 0;
// bool found = false;
// void dfs(const int x,const int y, const vector<string>& maps, int cnt, char target)
// {
//     if(target =='L' && maps[x][y] == 'L' ||
//        target =='E' && maps[x][y] == 'E') {
//         answer = cnt;
//         found = true;
//         return;
//     }
//     //right, down, left, up
//     ++cnt;
//     auto temp = visitedMaps[x][y];
//     visitedMaps[x][y] = 'X';
//     if(found) return;
//     if (checkBorder(x, y+1, maps) &&
//         visitedMaps[x][y+1] != 'X') {
//         dfs(x, y+1, maps, cnt, target);
//     }
//     if (checkBorder(x+1, y, maps) &&
//         visitedMaps[x+1][y] != 'X') {
//         dfs(x+1, y, maps, cnt, target);
//     }
//     if (checkBorder(x, y-1, maps) &&
//         visitedMaps[x][y-1] != 'X') {
//         dfs(x, y-1, maps, cnt, target);
//     }
//     if (checkBorder(x-1, y, maps) &&
//         visitedMaps[x-1][y] != 'X') {
//         dfs(x-1, y, maps, cnt, target);
//     }
//     visitedMaps[x][y] = temp;
//     --cnt;
// }
// int solution(vector<string> maps) {
//     visitedMaps = maps;
//     //find S, L
//     pair<int, int> S;
//     pair<int, int> L;
//     findSL(S, L, maps);
//     dfs(S.first, S.second, maps, 0, 'L');
//     if(answer == 0) return -1;
//     int toL = answer;
//     found = false;
//     visitedMaps = maps;
//     dfs(L.first, L.second, maps, answer, 'E');
//     if(toL == answer) return -1;
//     return answer;
// }
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
    int answer=0;
    pair<int, int> S;
    pair<int, int> L;
    findSL(S, L, maps);
    priority_queue<Position> pq;
    pq.push({S.first, S.second, 0});
    int time=0;
    //up, down, left, right
    int t = bfs(pq, maps, 'L');
    cout << "to L : " << t << endl;
    fill(visitedMaps.begin(), visitedMaps.end(), 0);

    return answer;
}

int main()
{
    vector<string> maps =
        // {"SOOXL",
        //  "OOOOX",
        //  "OOOOO",
        //  "OOOOO",
        //  "EOOOO"};
        {"SOOOL",
         "XXXXO",
         "OOOOO",
         "OXXXX",
         "OOOOE"};
    int answer;
    answer = solution (maps);

    cout << answer << endl;



    return 0;
}