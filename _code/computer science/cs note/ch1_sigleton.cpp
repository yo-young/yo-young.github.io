#include <iostream>

using namespace std;

class Singleton {
private:
    Singleton() {}
    Singleton(const Singleton& ref) {}
    ~Singleton() {}

    Singleton& operator=(const Singleton& ref) {}
public:
    static Singleton* getInstance() { 
        // 지역 static 객체로 만들 경우 전역으로 만든 객체와 달리
        // 해당 함수를 처음 호출하는 시점에서 초기화와 동시에 생성
        static Singleton ins;
        return &ins;
    }
};

int main() {
    Singleton* a = Singleton::getInstance();
    Singleton* b = Singleton::getInstance();
    if( a == b ) cout << "true" << endl;

    return 0;
}