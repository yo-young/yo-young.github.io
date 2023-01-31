#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n) {
        int cnt = 0;
        unordered_set<int> curr, next;
        curr.insert(x);

        while (!curr.empty()) {
            if (curr.count(y))
                return cnt;
            next.clear();
            for (int val : curr) {
                int pVal = val + n;
                int dVal = val * 2;
                int tVal = val * 3;
                if (pVal <= y) next.insert(pVal);
                if (dVal <= y) next.insert(dVal);
                if (tVal <= y) next.insert(tVal);
            }
            curr = next;
            cnt++;
        }
        return -1;
}

int main() {
    int ans;

    ans = solution(1, 100000, 1);

    cout << ans <<endl;
}