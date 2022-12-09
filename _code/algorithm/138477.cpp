#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void printFunc(int d, vector<int> score) {
    cout << "print start" << endl;
    for(int i=0; i<score.size(); i++) {
        cout << score[i] << " ";
    }
    cout << endl;
    cout << "print end" << endl;
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer, todayScore;
    int lastDay = score.size();
    
    for (int day=0; day<lastDay; day++) {
        todayScore.push_back(score[day]);
        sort(todayScore.rbegin(), todayScore.rend());
        // printFunc(day, todayScore);
        if (day < k) {
            answer.push_back(todayScore[day]);
        }
        else {
            answer.push_back(todayScore[k-1]);
        }
    }
    
    return answer;
}

int main() {
    vector<int> answer;
    vector<int> score = {10, 100, 20, 150, 1, 100, 200};
    answer = solution(3, score);
    cout << endl;
    cout << "-----answer-----" << endl;
    for (int i=0; i<answer.size(); i++) {
        cout << answer[i] << endl;
    }    

    return 0;
}