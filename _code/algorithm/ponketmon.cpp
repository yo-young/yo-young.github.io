#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// int solution(vector<int> nums)
// {
//     int answer = 1;
//     int N = nums.size();
//     sort(nums.begin(), nums.end());
//     int cmp = nums[0];
//     for (int i=0; i<N; i++) {
//         if (answer == N/2) return answer;
//         if (nums[i] == cmp) {
//             continue;
//         }
//         else {
//             answer++;
//             cmp = nums[i];
//         }
//     }

//     return answer;
// }



int main() {
    vector<int> nums = {3,3,3,2,2,2};

    int answer = solution(nums);
    cout << answer << endl;

    return 0;
}