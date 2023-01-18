#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs (const vector<vector<int>>& users, const vector<int>& emos, int idx, int dcRate, vector<pair<int, int>>& subSales) {
    int userDcRate = users[idx].front();
    int userMoney = users[idx].back();
    cout<<"user id : "<<idx;
    cout<<", dc rate : "<<userDcRate;
    cout<<", user dc rate : "<<userDcRate;
    cout<<", userMoney : "<<userMoney<<endl;
    int cost = 0;
    if(dcRate >= userDcRate) {
        for(auto emo : emos) {
            cost += emo*dcRate/100;
            if(cost > userMoney) {
                cout<<"subscribe !!"<<endl;
                subSales[idx].first = 1;
                cost = 0;
                break;
            }
        }
        cout <<"total cost : "<< cost <<endl;
    }
    subSales[idx].second = cost;
}

vector<int> solution(vector<vector<int>> users, vector<int> emos) {
    vector<int> answer;
    vector<pair<int, int>> subSales;
    subSales.reserve(users.size());

    dfs(users, emos, 0, 40, subSales);
    
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