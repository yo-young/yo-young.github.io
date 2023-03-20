#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> tanMap;
    map<int, vector<int>, greater<int>> numOfTan;
    for(auto& tan : tangerine)
    {
        tanMap[tan] += 1;
    }
    for(auto& tan : tanMap)
    {
        cout<<"i : "<<tan.first<<": "<< tan.second << endl;
        numOfTan[tan.second].push_back(tan.first);
    }
    cout<<endl;
    int remain = k;
    for(auto& sizeOfTan : numOfTan)
    {
        cout<<"i : "<<sizeOfTan.first<<": "<< sizeOfTan.second.size() << endl;
        //sizeOfTan.first는 귤의 개수, second는 해당 개수만큼 존재하는 귤의 크기들
        for(auto& size : sizeOfTan.second)
        {
            remain -= sizeOfTan.first;
            answer += 1;
            cout<<"remain: "<<remain<<endl;
            if(remain <= 0) return answer;
        }
    }

    
    return answer;
}

int main()
{
    int answer;
    vector<int> tangerine = {1, 3, 2, 5, 4, 5, 2, 3};
    //2,2, 3,3, 5,5, 1, 4

    answer = solution(3, tangerine);
    cout<<"answer : "<<answer<<endl;

    return 0;
}