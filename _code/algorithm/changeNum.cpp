#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

// int solution(int x, int y, int n)
// {
//     int cnt = 0;
//     unordered_set<int> curr, next;
//     curr.insert(x);
//     while (!curr.empty())
//     {
//         if (curr.count(y))
//             return cnt;
//         next.clear();
//         for (int val : curr)
//         {
//             int pVal = val + n;
//             int dVal = val * 2;
//             int tVal = val * 3;
//             if (pVal <= y)
//                 next.insert(pVal);
//             if (dVal <= y)
//                 next.insert(dVal);
//             if (tVal <= y)
//                 next.insert(tVal);
//         }
//         curr = next;
//         cnt++;
//     }
//     return -1;
// }

void insertTree(int num, unordered_set<int>& tree, int y)
{
    if(num > y) return;
    tree.insert(num);
}

int solution(int x, int y, int n) {
    if(x==y) return 0;
    unordered_set<int> tree;
    tree.insert(x);
    int depth=0;
    while(!tree.count(y))
    {
        if(tree.empty()) break;
        unordered_set<int> nextTree;
        for(auto treeIdx : tree)
        {
            int num = treeIdx;
            insertTree(num+n, nextTree, y);
            insertTree(num*2, nextTree, y);
            insertTree(num*3, nextTree, y);
        }
        tree.clear();
        tree = nextTree;
        depth+=1;
    }
    
    return depth == 0 || tree.empty() ? -1 : depth;
}

int main()
{
    int ans;
    // ans = solution(1, 100000, 1);
    ans = solution(10,10,4);
    cout << ans << endl;
}