#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> answer;

void hanoi(int n,int start,int to,int via)
{
    if(n==1)
    {
        answer.push_back({start, to});
        return;
    }
    hanoi(n-1, start, via, to);
    answer.push_back({start, to});
    hanoi(n-1, via, to, start);
}

vector<vector<int>> solution(int n) {

    hanoi(n, 1, 3, 2);

    return answer;
}