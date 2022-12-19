---
layout: default
title: lamda 표현식
parent: C++
nav_order: 9
---

## 람다 표현식 형태

<aside>
✅ [캡처 블록] (파라미터) ->반환타입 {함수 몸통}

</aside>

- 캡처블록과 전달인자, 반환타입은 생략할 수 있다.

## [=] 캡처

[What does [=] mean in C++?](https://stackoverflow.com/questions/34778041/what-does-mean-in-c)

- 로컬 변수의 copy된 값을 가져온다
- [=]를 []로 바꾸면 에러가 발생할 것

## 예제

[C++ 람다 식](https://learn.microsoft.com/ko-kr/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170)

```cpp
struct S { void f(int i); };

void S::f(int i) {
    [&, i]{};      // OK
    [&, &i]{};     // ERROR: i preceded by & when & is the default
    [=, this]{};   // ERROR: this when = is the default
    [=, *this]{ }; // OK: captures this by value. See below.
    [i, i]{};      // ERROR: i repeated
}
```

## 함수의 인라인화가 가능

[C++ Lambda 사용 이유와 사용 방법](https://hwan-shell.tistory.com/84)

- 람다는 이름은 없지만 객체
- 컴파일 과정에서 객체 생성

```cpp
#include<iostream>
#include<functional>

int main(void) {

    auto f1 = [](int a, int b) {                    //인라인화 OK!!
        return a + b;
    };

    int(*f2)(int, int) = [](int a, int b) {            //인라인화 Fail!!
        return a + b;
    };

    std::function<int(int, int)> f3 = [](int a, int b) {    //인라인화 Fail!!
        return a + b;
    };

    return 0;
}
```

- auto 선언은 어떤 type인지 컴파일러만 알 수 있다.
    - auto 선언은 상수화되어 컴파일라가 인라인화를 진행한다.
- f2는 함수 포인터로 선언
    - 람다는 객체이므로 객체의 주소 값을 함수 포인터 변수로 전달 가능
    - f2는 포인터 변수이기 때문에 다른 값을 재 참조가 가능
    - 즉 실행 중 f2 값이 변경될 수 있음
- std::function은 auto와 동일하지 않다.
    - std::function은 함수, 함수 객체, 람다 등을 담을 수 있다.
    - 람다 함수를 담을 순 있지만 람다가 std::function에 의해 정의되는 것은 아님
    - f3은 변경이 가능하기 때문에 inline화 불가능