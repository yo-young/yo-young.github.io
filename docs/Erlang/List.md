---
layout: default
title: List
parent: Erlang
nav_order: 8
---

# List

- 적어도 현재 재직중인 회사에서 사용하는 Erlang 코드 중 list는 가장 필수적인 내용
- Erlang의 list는 어지간한 것들은 다 담을 수 있음.
- 복합 데이터 타입

```erlang
B = [1, 2.0, "3", <<"4">>, e, {f,6}, [7,8,9]].
```

- 정수, 실수, 문자열, binary, atom, 튜플, 리스트
- 심지어 functional object도 담을 수 있음.

```erlang
F1 = fun(X) -> X+1 end,
F2 = fun(X) -> X+2 end,
L1 = [F1, F2],
[Head|_] = L1,

io:fwrite("~p", [Head(1)]),

ok.
```

### Append

- Append 작업은 `++` 연산자를 사용
- `lists:append` 도 사용 가능

### **Subtract**

- `--` 연산자 사용
- `lists:subtract` 도 사용 가능

### head

- 리스트의 첫 번째 원소를 head라고 한다.
- head를 가져오는 방법은 세가지

```erlang
1> hd([1,2,3]).
1
2> lists:nth(1,[1,2,3]).
1
3> [Head| _ ] = [1,2,3].
[1,2,3]
4> Head.
1
```

- BIF(Built-in Functions)를 활용하는 방법입니다. BIF는 순수 얼랭이 아닌 C나 기타 다른 언어를 이용해 구현

### tail

- head를 제외한 나머지를 tail이라고 한다.
- 방법은 head와 유

```erlang
1> tl([1,2,3,4,5]).
[2,3,4,5]
2> lists:nthtail(1, [1,2,3,4,5]).
[2,3,4,5]
3> lists:nthtail(2, [1,2,3,4,5]).
[3,4,5]
4> [_| Tail] = [1,2,3,4,5].
[1,2,3,4,5]
5> Tail.
[2,3,4,5]
6> [_ | [_ | TailInTail]] = [1,2,3,4,5].
[1,2,3,4,5]
7> TailInTail.
[3,4,5]
```

## cons operator

- 리스트 중간에 `|` 기호를 두고 좌측은 Head 원소, 우측은 Tail 원소로 나누는 연산자

## **List Comprehensions**

- 기존 리스트와 수식, 조건을 이용하여 새로운 리스트를 만드는 방법
- 새로운 연산자 `||`와 `<-`
- `<-`은 우측 리스트의 요소를 각각 하나씩 X에 담는다.
- 그것을 이용해 `||`의 좌측에 있는 계산을 수행

```erlang
1> [ X*2 || X <- [1,2,3,4] ].
[2,4,6,8]
```