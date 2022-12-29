#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < enemy.size(); i++)
    {
        cout<<"enemy["<<i<<"] : "<<enemy[i]<<endl;
        int e = enemy[i];
        pq.push(e);

        if (pq.size() > k)
        {
            sum += pq.top();
            cout<<"sum : "<<sum<<endl;
            pq.pop();
        }
        if (sum > n)
        {
            return i;
        }
    }
    return enemy.size();
}

int main() {
    int answer;

    answer = solution(7, 3, {4,2,4,5,3,3,1});
    // answer = solution(6, 0, {1,2,3});
    cout<<"answer : "<<answer<<endl;

    return 0;
}