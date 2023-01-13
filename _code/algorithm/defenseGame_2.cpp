#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(int n, int k, vector<int> enemy) {
    // Min Heap 최소힙
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum=0;
    // enemy에 대해 반복
    for (int i=0; i<enemy.size(); i++) {
        // 현재 enemy 수를 최소힙 우선순위 큐에 입력
        pq.push(enemy[i]);
        if (pq.size() > k) {
            // k개 이후에 입력되는 수를 더해줌
            // 최소힙이기 때문에 지금까지 입력된 수 중 제일 작은 수
            sum += pq.top();
            // 더해준 수는 큐에서 제외
            // 큐의 사이즈를 k개 만큼 유지
            // 다음에 들어오는 수가 현재 큐에 있는 수보다 크다면 우선순위 큐에 의해 정렬되어
            // 현재 큐에 있는 수 중 입력된 수보다 작은 수가 top에 위치하게 됨
            pq.pop();
        }
        if (sum > n) {
            // sum이 n보다 커지면 현재 인덱스를 반환
            return i;
        }
    }
}

int main() {
    int answer;

    answer = solution(7, 3, {4,2,4,5,3,3,1});
    // answer = solution(6, 0, {1,2,3});
    cout<<"answer : "<<answer<<endl;

    return 0;
}