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