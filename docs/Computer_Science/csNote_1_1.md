
  - [1.1 디자인 패턴](#11-디자인-패턴)
    - [1.1.1 싱글톤 패턴](#111-싱글톤-패턴)
    - [1.1.2 팩토리 패턴](#112-팩토리-패턴)
    - [1.1.3 전략 패턴](#113-전략-패턴)
    - [1.1.4 옵저버 패턴](#114-옵저버-패턴)
    - [1.1.5 프록시 패턴](#115-프록시-패턴과-프록시-서버)
    - [1.1.6 이터레이터 패턴](#116-이터레이터-패턴)
    - [1.1.7 노출모듈 패턴](#117-노출모듈-패턴)
    - [1.1.8 MVC 패턴](#118-mvc-패턴)
    - [1.1.9 MVP 패턴](#119-mvp-패턴)
    - [1.1.10 MVVM 패턴](#1110-mvvm-패턴)

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

### 1.1.2 팩토리 패턴

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

### 1.1.3 전략 패턴

- 전략 패턴 또는 정책 패턴
- 객체의 행위를 바꾸고 싶을 때 직접 수정하지 않고 전략이라고 부르는 캡슐화한 알고리즘을 컨텍스트 안에서 바꿔주면서 상호 교체가 가능하도록 하는 패턴
- 쉽게 말해 알고리즘을 교체 가능
- 알고리즘의 인터페이스를 정의하고 각각 클래스별로 캡슐화
- 결과는 같으나 결과를 만드는 방법이 여러개인 경우 사용
- 참고 블로그
[https://copynull.tistory.com/125](https://copynull.tistory.com/125)

```cpp
#include <iostream>
#include <algorithm>
#include <list>

class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
};

class KAKAOCardStrategy : public PaymentStrategy {
private:
    std::string name;
    std::string cardNumber;
    std::string cvv;
    std::string dateOfExpiry;

public:
    KAKAOCardStrategy(std::string nm, std::string ccNum, std::string cvv, std::string expiryDate) {
        this->name = nm;
        this->cardNumber = ccNum;
        this->cvv = cvv;
        this->dateOfExpiry = expiryDate;
    }

    void pay(int amount) {
        std::cout << amount << " paid using KAKAOCard." << std::endl;
    }
};

class LUNACardStrategy : public PaymentStrategy {
private:
    std::string emailId;
    std::string password;

public:
    LUNACardStrategy(std::string email, std::string pwd) {
        this->emailId = email;
        this->password = pwd;
    }

    void pay(int amount) {
        std::cout << amount << " paid using LUNACard." << std::endl;
    }
};

class Item {
private:
    std::string name;
    int price;

public:
    Item(std::string name, int cost) {
        this->name = name;
        this->price = cost;
    }

    std::string getName() {
        return name;
    }

    int getPrice() {
        return price;
    }
};

class ShoppingCart {
private:
    std::list<Item> items;

public:
    ShoppingCart() {
        this->items = std::list<Item>();
    }

    void addItem(Item item) {
        this->items.push_back(item);
    }

    int calculateTotal() {
        int sum = 0;
        for (Item item : items) {
            sum += item.getPrice();
        }
        return sum;
    }

    void pay(PaymentStrategy* paymentMethod) {
        int amount = calculateTotal();
        paymentMethod->pay(amount);
    }
};

int main() {
    ShoppingCart cart = ShoppingCart();

    Item A = Item("kundolA", 100);
    Item B = Item("kundolB", 300);

    cart.addItem(A);
    cart.addItem(B);

    // pay by LUNACard
    cart.pay(new LUNACardStrategy("kundol@example.com", "pukubababo"));
    // pay by KAKAOBank
    cart.pay(new KAKAOCardStrategy("Ju hongchul", "123456789", "123", "12/01"));

    return 0;
}
```

- KAKAOCardStrategy와 LUNACardStrategy는 PaymentStrategy를 상속
- 각 strategy는 pay 알고리즘을 overriding 구현
- 결과적으로 total payment는 동일하지만 strategy에 따라 알고리즘은 다를 수 있다.

### 1.1.4 옵저버 패턴

- 주체가 어떤 객체의 상태 변화를 관찰하다가 변화가 있을 때마다 옵저버 목록에 있는 옵저버들에게 변화를 알려줌
- 주체란 객체의 상태변화를 보고 있는 관찰자
- 옵저버들이란 객체의 상태 변화에 따라 전달되는 메서드 등을 기반으로 추가 변화 사항들이 생기는 객체
- 관찰자를 따로 두지 않고 상태가 변화하는 객체를 기반으로 구축도 가능
- 주로 이벤트 기반 시스템에 사용됨
- MVC(Model-View-Controller)에서도 사용됨
- 트위터는 대표적으로 옵저버 패턴을 사용한 서비스
    - 주체가 트윗을 업로드 하면 팔로우한 객체들에게 정보를 알려줌

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

class Observer;

class Subject {
public:
    virtual void registerObserver(Observer* obj) = 0;
    virtual void unregisterObserver(Observer* obj) = 0;
    virtual void notifyObservers() = 0;
    virtual std::string getUpdate(Observer* obj) = 0;
};

class Observer {
public:
    virtual void update() = 0;
};

class Topic : public Subject {
private:
    std::vector<Observer*> observers;
    std::string message;

public:
    Topic() {
        this->observers = std::vector<Observer*>();
        this->message = "";
    }

    void registerObserver(Observer* obj) {
        if (std::find(observers.begin(), observers.end(), obj) == observers.end()) {
            observers.push_back(obj);
        }
    }

    void unregisterObserver(Observer* obj) {
        observers.erase(std::remove(observers.begin(), observers.end(), obj), observers.end());
    }

    void notifyObservers() {
        std::for_each(observers.begin(), observers.end(), [](Observer* observer) { observer->update(); });
    }

    std::string getUpdate(Observer* obj) {
        return this->message;
    }

    void postMessage(std::string msg) {
        std::cout << "Message sended to Topic: " << msg << std::endl;
        this->message = msg;
        notifyObservers();
    }
};

class TopicSubscriber : public Observer {
private:
    std::string name;
    Subject* topic;

public:
    TopicSubscriber(std::string name, Subject* topic) {
        this->name = name;
        this->topic = topic;
    }

    void update() {
        std::string msg = topic->getUpdate(this);
        std::cout << name << ":: got message >> " << msg << std::endl;
    }
};

int main() {
    Topic topic = Topic();
    Observer* a = new TopicSubscriber("a", &topic);
    Observer* b = new TopicSubscriber("b", &topic);
    Observer* c = new TopicSubscriber("c", &topic);
    topic.registerObserver(a);
    topic.registerObserver(b);
    topic.registerObserver(c);

    topic.postMessage("amumu is op champion!!");

    return 0;
}
```

- topic은 주체이자 객체
    - Subject 인터페이스를 상속 받아 Observer 관련 함수 구현
- a, b, c 옵저버 객체 생성
- topic 객체의 registerObserver를 이용하여 옵저버 객체 등록
    - 이미 등록된 객체인지 확인하고 미등록 상태이면 등록
    - topic에 observer는 벡터로 관리되고 있음
- topic에서 message를 post한다.
    - notifyObservers함수가 호출되고 observers 벡터를 반복하며 각 옵저버 객체의 업데이트함수 호출

### 1.1.5 프록시 패턴과 프록시 서버

- 대상 객체에 접근하기 전 접근에 대한 흐름을 가로채 대상 객체의 인터페이스 역할을 하는 패턴

### Proxy server

- 서버와 클라이언트 사이에서 클라이언트가 프록시 서버를 통해 다른 네트워크 서비스에 간접적으로 접속할 수 있도록 해주는 시스템 또는 응용 프로그램
- nginx
    - 비동기 이벤트 기반의 구조
    - 다수의 연결을 효과적으로 처리 가능한 웹 서버
    - 주로 Node.js 서버 앞단의 프록시 서버로 활용
        - 익명 사용자의 직접적인 서버 접근 차단
        - 서버 앞단에서 로깅
- CloudFlare
    - 전 세계적으로 분산된 서버가 있고 이를 통해 어떠한 시스템의 콘텐츠를 빠르게 전달하는 CDN 서비스
    - DDOS 공격 방어
        - 거대한 네트워크 용량 및 캐싱 전략을 통해 소규모 DDOS 공격 방어
        - 방화벽 대시보드 제공
    - HTTPS 구축 가능
        - 별도의 인증서 설치 없이 쉽게 구축 가능
- CORS와 프론트엔드의 프록시 서버
    - CORS(Cross-Origin Resource Sharing)
        - 서버가 웹 브라우저에서 리소스를 로드할 때 다른 오리진을 통해 로드하지 못하게 하는 HTTP 헤더 기반 메커니즘
    - 오리진
        - 프로토콜과 호스트 이름. 포트의 조합
        - https://kundol.com:12010/test 라는 주소에서 오리진은 https://kundol.com:12010을 뜻한다.
    - 프론트엔드에서 127.0.0.1:3000으로 테스트할 때 백엔드 서버는 127.0.0.1:12010이라면 포트 번호가 다르기 때문에 CORS 에러가 발생. 이 때 프록시 서버를 통해 프론트엔드에서 요청되는 오리진을 127.0.0.1:12010 으로 바꿀 수 있음.

### 1.1.6 이터레이터 패턴

- 이터레이터를 사용하여 컬렉션의 요소에 접근
- 순회할 수 있는 다양한 자료형의 자료구조를 하나의 인터페이스로 순회 가능
- C++에서 사용하는 그 vector<int>::iterator를 의미하는 것이 맞다.
- 이 디자인 패턴의 의도는 캡슐화이다.
    - 객체를 저장하는 방식은 보여주지 않으면서 접근할 수 있는 방법
    - [https://flower0.tistory.com/446](https://flower0.tistory.com/446)
    

### 1.1.7 노출모듈 패턴

- 즉시 실행 함수를 통해 private, public 같은 접근 제어자를 만드는 패턴
- 즉시 실행 함수 : 함수를 정의하자마자 바로 호출하는 함수. 초기화 코드, 라이브러리내 전역 변수의 충돌 방지등에 사용

### 1.1.8 MVC 패턴

- Model, View, Controller로 이루어진 디자인 패턴
- 어플리케이션의 구성 요소를 세 가지 역할로 구분하여 개발 프로세스에서 각각의 구성 요소에만 집중해서 개발 가능
- 재사용성과 확장성이 용이
- 어플리케이션이 복잡해질 수록 모델과 뷰의 관계가 복잡해짐
- 대표적인 라이브러리로 React.js

### 1.1.9 MVP 패턴

- MVC 패턴으로부터 파생
- Contoller가 Presenter로 교체
- View와 Presenter는 1:1 관계
    - MVC 패턴보다 더 강한 결합을 가짐

### 1.1.10 MVVM 패턴

- MVC 패턴에서 Controller가 View model로 교체
- View model은 View를 더 추상화한 계층
- MVC 패턴과 다르게 커맨드와 데이터 바인딩 지원
- View와 View model 사이 양방향 데이터 바인딩 지원
    - 데이터 바인딩 : 화면에 보이는 데이터와 웹 브라우저의 메모리 데이터를 일치시키는 기법
- UI를 별도의 코드 수정 없이 재사용 가능 및 단위 테스팅이 용이
- 대표적인 프레임워크로 Vue.js

