#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> s_vector;
    string temp = "";

    for (int i=0; i<=s.size(); i++) {
        // cout << "i : " << i << endl;
        if (s[i] != ' ') {
            temp += s[i];
            // cout << "----1----  " << temp << endl;
        }
        if (s[i] == ' ' || i == s.size()) {
            int tempNum = stoi(temp);
            s_vector.push_back(tempNum);
            temp = "";
            // cout << "----2----  " << tempNum << endl;
        }
    }
    // cout << "---------------" << endl;
    // for (int i=0; i<s_vector.size(); i++) {
    //     cout << s_vector[i] << endl;
    // }
    sort(s_vector.begin(), s_vector.end());
    answer += to_string(s_vector.front());
    answer += " ";
    answer += to_string(s_vector.back());

    return answer;
}

int main() {
    string answer = solution("-1 -2 -3 -4");
    cout << answer << endl;

    return 0;
}