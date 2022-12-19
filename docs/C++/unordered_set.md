---
layout: default
title: unordered_set
parent: C++
nav_order: 9
---

> [https://notepad96.tistory.com/30](https://notepad96.tistory.com/30)
> 

## unordered_set

- map의 일종인듯하다
- 중복된 값은 삽입되지 않는다
- 삽입된 순서대로 저장된다.

```cpp
unordered_set<int> uset;

uset.insert(3);	// 3
uset.insert(5);	// 3 5
uset.insert(1);	// 3 5 1
uset.insert(4);	// 3 5 1 4
uset.insert(2);	// 3 5 1 4 2
uset.insert(5); // 3 5 1 4 2
```

## unordered_multiset

- unordered_set과 동일하지만 중복 값도 삽입된다.

```cpp
unordered_multiset<int> umset;
umset.insert(5);	// 5
umset.insert(3);	// 5 3
umset.insert(1);	// 5 3 1
umset.insert(4);	// 5 3 1 4
umset.insert(2);	// 5 3 1 4 2
umset.insert(5);	// 5 5 3 1 4 2 
umset.insert(1);	// 5 5 3 1 1 4 2
```