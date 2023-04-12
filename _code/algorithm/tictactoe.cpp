#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

int main()
{
    vector<string> board
    // = {"O.X", ".O.", "..X"};
    = {"OOO", "...", "XXX"};

    int answer = solution(board);
    cout << "answer : "<<answer<<endl;

    return 0;
}