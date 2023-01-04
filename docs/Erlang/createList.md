---
layout: default
title: List를 이용해서 새로운 list 만들기
parent: Erlang
nav_order: 9
---

- erlang에서 list를 반복해서 원소를 이용하여 새로운 list를 어떻게 만들 수 있을까?

### 예시

```erlang
main(_) -> io:fwrite("Hello, World!\n"),
Xlist = [1,2,3,4],

Alist =
[begin
  io:fwrite("~p\n", [X]),
  A = X+1,
  X+2
 end || X <- Xlist],

io:fwrite("~p", [Alist]).
```

### 결과

```
Hello, World!
1
2
3
4
[3,4,5,6]
```

- Xlist에서 X 원소 반복
- 여러 라인을 하나의 함수처럼 block화 시켜서 넣으려면 begin…end 구문 사용
- begin…end 구문에서 연산을 하고 마지막 라인이 Alist에 bound