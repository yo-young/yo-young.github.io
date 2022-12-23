#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// int solution(int k, int m, vector<int> score) {
//     int answer = 0;
//     sort(score.rbegin(), score.rend());
//     int max = score.size()/m;
//     auto start = score.begin();
//     for (int i=0 ; i<max ; i++) {
//         int minScore= 10;
//         auto it=start;
//         for (int cnt=1; it<start+m ; ++it, ++cnt) {
//             minScore = minScore < *it ? minScore : *it;
//         }
//         answer += minScore * m;
//         start = it;
//     }

//     return answer;
// }

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.begin(), score.end(), greater<int>());

    int box_num = score.size() / m;
    int cur = m - 1;
    for(int i = 0 ; i < box_num ; i++){
        cout << "i : " << i << " cur : " << cur << endl;
        answer += score[cur] * m;
        cur += m;
    }

    return answer;
}


int main() {
    vector<int> score = {4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2};
    int k=4;
    int m=3;
    int answer = solution(k, m, score);
    cout << answer << endl;

    return 0;
}