#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int firstAns = 0;
    string number = to_string(storey);
    reverse(number.begin(), number.end());
    //1의 자리부터 시작하도록 reverse
    for (auto num : number) {
        answer += (int)num-'0';
    }

    for (int i=0; i<number.size(); i++) {
        int tmp = (int)number[i]-'0';
        cout<<i<<" : "<<tmp<<endl;
        if (tmp == 0) continue;
        if (tmp > 5) {
            cout<<"1. answer+"<<(10-tmp)<<endl;
            firstAns += (10-tmp);
            int add = 1;
            for (int j=1; j<i+1; j++) {
                add *= 10;
            }
            storey += add*(10-tmp);
            number = to_string(storey);
            cout<<"add : "<<add*(10-tmp)<<endl;
            cout<<"new number : "<<storey<<endl;
            reverse(number.begin(), number.end());
        }
        else if (tmp == 5) {
            firstAns += (10-tmp);
            if (number[i+1] >= '5') {
                int add = 1;
                for (int j=1; j<i+1; j++) {
                    add *= 10;
                }
                storey += add*(10-tmp);
                number = to_string(storey);
                cout<<"add : "<<add*(10-tmp)<<endl;
                cout<<"new number : "<<storey<<endl;
                reverse(number.begin(), number.end());
            }
        }
        else {
            cout<<"2. answer+"<<tmp<<endl;
            firstAns += tmp;
        }
    }

    answer = answer < firstAns ? answer : firstAns;

    return answer;
}

int main() {
    int answer;
    int storey = 165;

    answer = solution(storey);
    cout<<"answer : "<<answer<<endl;

    return 0;
}