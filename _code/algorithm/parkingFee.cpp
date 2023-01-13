#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map> // map은 key값을 기준으로 오름차순으로 정렬되어있음
#include <queue>

using namespace std;

// void vectorSeparator(char separator, string elem, vector<string>& record) {
//     string buf;
//     istringstream iss(elem);
//     while (getline(iss, buf, separator)) {
//             cout << buf << " ";
//             record.push_back(buf);
//     }
//     cout << endl;
// }

// vector<int> solution(vector<int> fees, vector<string> records) {
//     vector<int> answer;

//     // 주차내역 + 주차시간
//     pair<queue<string>, int> pair_historyTime;
//     // 차량번호(주차내역 + 누적주차시간)
//     map<string, pair<queue<string>, int>> map;

//     for (auto& elem : records) {
//         vector<string> record;
//         vectorSeparator(' ', elem, record);
//         // record[0] : 입/출차 시간
//         // record[1] : 차량 번호
//         // record[2] : 입/출차 내역
//         // 현재 누적 주차 시간
//         int current = map[record[1]].second;
//         cout<<"car num : "<<record[1]<<", ";
//         cout<<"current : "<<current<<endl;
//         // history가 비어 있는 경우 해당 차량이 출차되었음을 의미
//         queue<string> history;
//         if (record[2] == "IN") {
//             // 큐에 입차 시간 저장
//             history.push(record[0]);
//             // map에 큐와 현재 누적 시간 저장
//             map[record[1]] = make_pair(history, current);
//         }
//         else { //"OUT"
//             vector<string> enter, departure;
//             //입차 시간
//             string buf = map[record[1]].first.front();            
//             map[record[1]].first.pop();
//             // HH:MM 시간 분 분리
//             vectorSeparator(':', buf, enter);
//             //출차 시간
//             buf = record[0];
//             vectorSeparator(':', buf, departure);
//             int parkingHour = stoi(departure[0]) - stoi(enter[0]);
//             int parkingMin = stoi(departure[1]) - stoi(enter[1]);
//             int parkingTime = parkingMin + parkingHour*60;
//             map[record[1]].second = current + parkingTime;
//             cout<<"car num : "<<record[1]<<", ";
//             cout<<"out -- current : "<<map[record[1]].second<<endl;
//         }
//         cout<<endl;
//     }
//     cout<<"--------------------------"<<endl;
//     // 출차 시간이 없는 차 처리
//     for (auto& elem : map) {
//         cout<<"car num : "<<elem.first <<endl;
//         queue<string> history = elem.second.first;
//         int current = elem.second.second;
//         if (!history.empty()) {
//             vector<string> enter, departure;
//             //입차 시간
//             string buf = history.front();
//             vectorSeparator(':', buf, enter);
//             //출차 시간
//             vectorSeparator(':', "23:59", departure);
//             int parkingHour = stoi(departure[0]) - stoi(enter[0]);
//             int parkingMin = stoi(departure[1]) - stoi(enter[1]);
//             int parkingTime = parkingMin + parkingHour*60;
//             elem.second.second = current + parkingTime;
//         }
//     }
//     cout<<"2--------------------------"<<endl;
//     for (auto& elem : map) {
//         // fees[0] : 기본 시간, fees[1] : 기본 요금
//         // fees[2] : 단위 시간, fees[3] : 단위 요금
//         int time = elem.second.second;
//         if(time<fees[0]) {
//             answer.push_back(fees[1]);
//             continue;
//         }
//         cout <<"parking time : "<<time<<endl;

//         int fee = fees[1] + ((time - fees[0])/fees[2] * fees[3]);
//         int add = (time - fees[0])%fees[2];
//         if(add) fee += fees[3];
        
//         answer.push_back(fee);
//     }

//     return answer;
// }

int conv(string& t) {
    int h = (t[0] - 48) * 10 + t[1] - 48;
    int m = (t[3] - 48) * 10 + t[4] - 48;
    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> vec[10000];
    for (auto& record : records) {
        stringstream ss(record);
        string a, b, c;
        ss >> a >> b >> c;
        vec[stoi(b)].push_back(conv(a));
    }

    vector<int> ans;
    for (int i = 0; i < 10000; ++i) if (!vec[i].empty()) {
        if (vec[i].size() & 1) vec[i].push_back(23 * 60 + 59);

        int sum = 0;
        for (int j = 1; j < vec[i].size(); j += 2) sum += vec[i][j] - vec[i][j - 1];

        int val = fees[1];
        if (sum > fees[0]) val += (sum - fees[0] + fees[2] - 1) / fees[2] * fees[3];

        ans.push_back(val);
    }

    return ans;
}

int main() {
    vector<int> answer;
    vector<int> fees = {180, 5000, 10, 600};
    vector<string> records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT",
                              "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN",
                              "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};

    answer = solution(fees, records);

    for (auto& a : answer) {
        cout << a << endl;
    }

    return 0;
}