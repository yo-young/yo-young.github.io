#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    vector<int> box;
    stack<int> temp;
    temp.push(0);
    for (int i=0; i<order.size(); i++) {
        box.push_back(i+1);
    }
    int j=0;
    for (int i=0; i<box.size(); i++) {
      cout<<endl;
      cout<<"box["<<i<<"] : "<<box[i]<<", order["<<j<<"] : "<<order[j]<<endl;
      if(order[j] == box[i]) {
        answer+=1;
        j+=1;
        cout<<"1. order : "<<order[j-1]<<endl;
        continue;
      }
      if(order[j] == temp.top()) {
        answer+=1;
        j+=1;
        i-=1;
        temp.pop();
        cout<<"2. order : "<<order[j]<<", temp.top : "<<temp.top()<<endl;
        continue;
      }
      temp.push(box[i]);
      cout<<"3. stack push : "<<box[i]<<endl;
    }
  cout << endl;
    int size = temp.size();
    for (int i=0; i<size; i++) {
      if(!temp.top()) break;
      cout << "order["<<j<<"] : "<<order[j]<<endl;
      cout<<"temp : "<<temp.top()<<endl;
      if (order[j] == temp.top()) {
        j+=1;
        temp.pop();
        answer += 1;
      }
    }
  


    return answer;
}

int main() {
  vector<int> order = {5,4,3,2,1};
  int answer;
  
  answer = solution(order);

  cout<< "answer : " << answer <<endl;
  
  return 0;
}