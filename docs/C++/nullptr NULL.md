---
layout: default
title: nullptr / NULL
parent: C++
nav_order: 2
---

# nullptr / NULL

[https://en.cppreference.com/w/cpp/types/NULL](https://en.cppreference.com/w/cpp/types/NULL)

[https://en.cppreference.com/w/cpp/language/nullptr](https://en.cppreference.com/w/cpp/language/nullptr)

## 요약

- NULL은 C++ 11까지 0 으로 정의되어 있음
- C++11 이후로는 nullptr
- NULL은 null pointer constant
- null pointer constant는 멤버 타입에 대한 포인터로 암시적으로 변환될 수 있음
- nullptr은 pointer literal 그리고 std::nullptr_t 타입의 prvalue

## 개인적인 해석

- cppreference는 100% 이해가 안된다.
- 다른 블로그에 의하면 NULL은 0 또는 void* 이다.
- 아래 코드에서 NULL이 0인지 void*인지 알 수 없기 때문에 에러가 발생

```cpp
void func(int a) { cout << "call func(int)" << endl; }
void func(int a*) { cout << "call func(int*)" << endl; }

func(NULL);
```

- 위 예를 보면 null pointer를 위한 코드를 구현할 때 굳이 NULL로 써야할 이유가 없다.