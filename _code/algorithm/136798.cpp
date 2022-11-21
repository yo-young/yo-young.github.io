#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<int, int> numDiv;

void storeDiv(int n) {
    vector<int> div;
    for (int i=1; i*i<=n; i++) {
        if(n % i == 0) {
            div.push_back(i);
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