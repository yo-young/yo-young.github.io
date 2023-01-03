---
layout: default
title: 면접을 위한 CS 전공지식 노트
parent: Computer Science
nav_order: 1
---

- [디자인 패턴과 프로그래밍 패러다임](#디자인-패턴과-프로그래밍-패러다임)
  - [1.1 디자인 패턴](#11-디자인-패턴)
    - [1.1.1 싱글톤 패턴](#111-싱글톤-패턴)

---

### 예제 소스

[https://github.com/wnghdcjfe/csnote](https://github.com/wnghdcjfe/csnote)  
[https://github.com/gilbutITbook/080326](https://github.com/gilbutITbook/080326)  

---


# 디자인 패턴과 프로그래밍 패러다임

## 1.1 디자인 패턴

- 프레임워크 : 공통으로 사용하는 특정 기능들을 모듈화한 것.  규칙이 엄격.

### 1.1.1 싱글톤 패턴

- 하나의 클래스에 오직 하나의 인스턴스만 가지는 패턴
- 하나의 인스턴스를 만들어 놓고 다른 모듈이 공유하며 사용
- 데이터베이스 연결 모듈에 많이 쓰임
    - 데이터베이스 연결에 관한 인스턴스를 정의
    - 다른 모듈에서 해당 인스턴스를 기반으로 쿼리를 전송

```cpp
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
```

- 단점
    - 의존성이 높아짐
    - 특히 TDD 할 때 걸림돌, 각 테스트마다 독립적인 인스턴스를 만들기 어렵기 때문
- 의존성 주입
    - 메인 모듈이 직접 다른 하위 모듈에 대한 의존성을 주지 않음
    - 중간에 의존성 주입자를 이용해 메인 모듈이 간접적으로 의존성을 주입하는 방식
    - 장점
        - 더 좋은 모듈화
        - 테스팅과 마이그레이션이 수월
        - 의존성 방향이 일관되어 쉽게 추론, 모듈 간 관계가 명확해짐
    - 단점
        - 모듈이 더 분리되어 클래스 수가 증가
    - 원칙
        - 상위 모듈은 하위 모듈에서 어떠한 것도 가져오지 않아야 함
        - 추상화에 의존해야 함

### 1.1.2 팩토리패턴

- ‘팩토리’가 되는 클래스 하나가 모든 타입을 처리하도록 설계
- 객체를 사용하는 코드에서 객체 생성 부분을 떼어내 추상화
- 상위 클래스는 뼈대를 결정하고 하위 클래스는 객체 생성에 관한 구체적인 내용을 결정
- 상위 클래스는 인스턴스 생성 방식에 대해 전혀 알 필요가 없으므로 보다 유연
- 객체 생성 로직이 따로 존재하므로 리팩터링에 용이
- 참고
    - [https://cinrueom.tistory.com/34](https://cinrueom.tistory.com/34)
    - [https://flower0.tistory.com/414](https://flower0.tistory.com/414)
    - [https://blog.naver.com/PostView.nhn?blogId=hblee4119&logNo=221968009389&parentCategoryNo=&categoryNo=21&viewDate=&isShowPopularPosts=false&from=postView](https://blog.naver.com/PostView.nhn?blogId=hblee4119&logNo=221968009389&parentCategoryNo=&categoryNo=21&viewDate=&isShowPopularPosts=false&from=postView)

```cpp
#include <iostream>
#include <string>

class Pizza {
public:
    void getType() {
        cout<<"type : "<<pizzaType<<endl;
    }
public:
    string pizzaType = "";
};

class CheesePizza : public Pizza {
public:
    CheesePizza() {
        pizzaType = "cheese";
    }
};

class PepperoniPizza : public Pizza  {
public:
    PepperoniPizza() {
        pizzaType = "Pepperoni";
    }
};

class PizzaFactory
{
public:
    Pizza* createPizza(string type) {
        Pizza* pizza;
        if(!type.compare("cheese")) pizza = new CheesePizza;
        if(!type.compare("pepperoni")) pizza = new PepperoniPizza;
        return pizza;
    }
};

int main()
{
    PizzaFactory factory;
    Pizza* cheesePizza = factory.createPizza("cheese");
    Pizza* pepperoni = factory.createPizza("pepperoni");
    cheesePizza->getType();
    pepperoni->getType();

	return 0;
}
```

- PizzaFactory 클래스에서 type에 따라 pizza 클래스를 생성
- 참고 블로그에서 PizzaFactory를 사용하는 PizzaStore 클래스를 선언하여 더욱 확장
- pizzaType이 추후에 추가되어도 PizzaFacotry 클래스만 변경하여 추가 가능