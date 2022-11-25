#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.resize(id_list.size());

    unordered_map<string, int> id_list_idx;
    for (int i=0; i<id_list.size(); i++) {
        id_list_idx[id_list[i]] = i;
    }

    unordered_map<string,unordered_set<string>> reporterMap;
    string reporter, reportee;
    for (int i=0; i<report.size(); i++) {
        istringstream stream(report[i]);
        stream >> reporter >> reportee;
        reporterMap[reportee].insert(reporter);
        //reportee 키에 들어간 id 개수가 report된 숫자
    }

    for (int i=0; i<id_list.size(); i++) {
        // cout << id_list[i] << " : ";
        //id_list[i]는 신고 당한 사람
        //reporterMap[id_list[i]].size()는 신고 당한 횟수
        if (k <= reporterMap[id_list[i]].size()) {
            //신고한 사람들 검색
            for (auto reporter : reporterMap[id_list[i]]) {
                //id_list_idx[reporter] 신고한 사람의 인덱스
                answer[id_list_idx[reporter]] += 1;
            }
        }
    }

    return answer;
}

int main() {
    vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
    vector<string> report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    // 프로도 두번, 네오 두번, 무지 한번
    int k = 2; //k번 신고당하면 이용 정지

    vector<int> answer = solution(id_list, report, k);
    for (int i=0; i<answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}