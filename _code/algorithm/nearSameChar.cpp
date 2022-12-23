#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// vector<int> solution(string s) {
//     vector<int> answer;
//     int cnt = -1;
//     answer.push_back(cnt);
//     for(int i=1; i<s.size(); i++)
//     {
//         cout<<"s["<<i<<"] :"<< s[i] <<endl;
//         string temp = s.substr(0,i+1);
//         // cout<<"temp : "<< temp <<endl;
//         for(int j=0; j<temp.size()-1; j++)
//         {
//             cout<<"temp["<<j<<"] :"<< temp[j] <<endl;
//             if(cnt > 0) cnt++;
//             if(s[i] == temp[j])
//             {
//                 cnt=1;
//             }
//             cout<<"cnt : "<< cnt <<endl;
//         }
//         cout<<"answer cnt : "<< cnt <<endl;
//         answer.push_back(cnt);
//         cnt = -1;
//     }
    
//     return answer;
// }

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> m;

    for (int i = 0; i < s.size(); i++)
    {
        auto iter = m.find(s[i]);
        if (iter == m.end()) //처음찾는친구.
        {
            //현재 인덱스 저장.
            m[s[i]] = i;
            answer.emplace_back(-1);
        }
        else //이미 있음.
        {
            cout<<"s["<<i<<"] : "<< s[i] <<endl;
            cout<<"m[s["<<i<<"] : "<< m[s[i]] <<endl;
            int length = i - m[s[i]];
            answer.emplace_back(length);
            //인덱스 새로 저장.
            m[s[i]] = i;
        }
    }
    return answer;
}

int main() {
    vector<int> answer = solution("banana");

    for(int i = 0; i<answer.size(); i++) 
    {
        cout<< answer[i] <<endl;
    }

    return 0;
}