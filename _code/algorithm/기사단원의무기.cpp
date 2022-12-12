#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<int, int> numDiv;

void storeDiv(int n) {
    vector<int> div;
    // 약수의 제곱은 n보다 클 수 없다.
    for (int i=1; i*i<=n; i++) {
        if(n % i == 0) {
            div.push_back(i); // 약수 저장
            // 약수 i를 저장하고 제곱이 되는 약수가 아니라면
            // i를 곱해서 n이 될 수 있는 수 n/i도 저장한다
            if(n/i != i) div.push_back(n/i);
        }
    }
    numDiv[n] = div.size();
    // cout << "n : " << n << " numDiv : " << numDiv[n] << endl;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    numDiv[1] = 1;
    for (int n=1; n<=number; n++) {
        if(!numDiv[n]) storeDiv(n);
        answer += numDiv[n] <= limit ? numDiv[n] : power;
    }
    return answer;
}

int main() {

    int answer = solution(5,3,2);
    cout << answer << endl;


    return 0;
}