#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int calculate(vector<int> user, vector<int> emoticons, vector<int>& saleRate) {
    int sales=0;
    for(int i=0; i<emoticons.size(); i++) {
        if(saleRate[i] >= user.front()) {
            sales += emoticons[i]*(100-saleRate[i])/100;
        }
        if(sales >= user.back()) return -1;
    }
    return sales;
}

void dfs(vector<vector<int>> users, vector<int> emoticons, vector<int>& saleRate, vector<int>& answer) {
    if(saleRate.size() == emoticons.size()) {
        for(int i=0; i<saleRate.size(); i++) cout<<"sale rate : "<<saleRate[i]<<endl;
        cout<<"--------------"<<endl;
        vector<int> temp{0,0};
        for(auto user : users) {
            int sales = calculate(user, emoticons, saleRate);
            cout<<"user.front : "<<user.front()<<endl;
            cout<<"sales : "<<sales<<endl<<endl;
            if(sales == -1) {
                temp.front() += 1;
                sales = 0;
            }
            temp.back() += sales;
        }
        answer = temp.front() > answer.front() ? temp : answer;
        if(temp.front() == answer.front()) {
            answer = temp.back() > answer.back() ? temp : answer;
        }
        cout<<"--------------"<<endl;
        return;
    }

    for (int i=10; i<=40; i+=10) {
        saleRate.push_back(i);
        dfs(users, emoticons, saleRate, answer);
        saleRate.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer{0,0};
    vector<int> s;

    dfs(users, emoticons, s, answer);    
    
    return answer;
}

int main() {
    vector<vector<int>> users = {{40, 10000}, {25, 10000}};
    vector<int> emoticons = {7000, 9000};
    vector<int> answer;

    answer = solution(users, emoticons);
    for(auto ans : answer) {
        cout<<"ans : "<<ans<<endl;
    }

    return 0;
}