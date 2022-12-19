---
layout: default
title: shrink_to_fit
parent: C++
nav_order: 9
---

[https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=sorkelf&logNo=221039099285](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=sorkelf&logNo=221039099285)

vector는 동적 배열로 element를 추가하면 자동으로 내부 메모리를 증가시킨다.

resize 또는 clear는 element를 지울 뿐 메모리(capacity)는 변경되지 않는다.

- 이를 해결하기 위해 swap을 사용

```cpp
#include <vector>
vector<int> vec;
vec.reserve(1000); //vec.capacity() : 1000
vec.resize(200); //vec.capacity() : 1000
vec.clear(); //vec.capacity() : 1000
vector<int>(vec).swap(vec); //vec.capacity() : 0
```

- C++ 11에서 shrink_to_fit() 함수 제공

```cpp
#include <vector>
vector<int> vec;
vec.reserve(1000); //vec.capacity() : 1000
vec.resize(200); //vec.capacity() : 1000
vec.clear(); //vec.capacity() : 1000
vec.shrink_to_fit() //vec.capacity() : 0
```

- vector의 현재 사이즈만큼 새로운 vector를 만들어서 카피하는 것이므로 메모리 재할당에 대한 CPU 타임 필요. 즉, 사이즈가 큰 경우 shrink를 사용할 경우 많은 시간이 소요
- non-binding 함수 - 컴파일러에서 구현하지만 필수는 아님