#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(int n, int k, vector<int> enemy) {
    //Min Heap 최소힙
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum=0;
    for (int i=0; i<enemy.size(); i++) {
        pq.push(enemy[i]);
        if (pq.size() > k) {
            cout<<"pq.top : "<<pq.top()<<endl;
            sum += pq.top();
            pq.pop();
        }
        if (sum > n) {
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