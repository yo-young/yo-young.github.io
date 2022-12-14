---
layout: default
title: Algorithm
nav_order: 8
has_children: true
permalink: /docs/Algorithm
---

# Algorithm

- [풀이 타임라인](#풀이-타임라인)
  - [문제 오픈 ~ 20분](#문제-오픈-20분)
  - [~ 40분](#40분)
  - [~ 80분](#80분)
  - [회고](#회고)
- [시간 복잡도](#시간-복잡도)

<small><i><a href='http://ecotrust-canada.github.io/markdown-toc/'>Table of contents generated with markdown-toc</a></i></small>

---

## 풀이 타임라인

> [https://www.slideshare.net/SuhyunPark23/kucc-2022-4](https://www.slideshare.net/SuhyunPark23/kucc-2022-4)  
> solved.ac를 운영하시는 박수현님 자료


### 문제 오픈 20분
- 푸는 방법을 대충 알 것 같다 → 진행
- 전혀 감이 안잡힌다.
    - 알고리즘 분류 확인
    - 알고 있는 알고리즘이라면 해당 분류의 문제 더 풀기
    - 모르는 알고리즘이라면 기본적인 내용 공부하기

### 40분

- 틀렸다! 출력 초과, 런타임 에러, 시간/메모리 초과
    - 어떤 상황에서 문제가 발생하는지 예제 만들어보기
    - 문제 잘못 읽음
    - 구현이 너무 복잡함 → 함수를 써보자
    - 예외 케이스 미고려
    - 시간/메모리 초과
- 틀리지 않았는데 비효율적이다! 시간/메모리초과
    - 알고 있는 다른 접근법
        - 첫 번째 접근법에서 사용한 알고리즘/자료구조의 복잡도 숙지
    - 여전히 모르겠다.
        - 다른 풀이 참고
        - 일주일 후에 혼자 다시 풀어보기
        - 비슷한 부류 문제 풀면서 연습하기

### 80분

- 알고 있는 다른 접근법
    - 첫 번째 접근법에서 사용한 알고리즘/자료구조의 복잡도 숙지
- 여전히 모르겠다.
    - 다른 풀이 참고
    - 일주일 후에 혼자 다시 풀어보기
    - 비슷한 부류 문제 풀면서 연습하기
    - 다른 풀이 참고
    

### 회고

- 이런 상황에서 이런 알고리즘/자료구조/테크닉을 쓰는구나
- 이런 상황에서 이렇게 하면 틀리는구나/비효율적이구나


## 시간 복잡도
> [https://yaneodoo2.tistory.com/entry/이것이취업을위한코딩테스트다-Chapter-01-코딩테스트-개요-1-복잡도-시간-복잡도](https://yaneodoo2.tistory.com/entry/%EC%9D%B4%EA%B2%83%EC%9D%B4%EC%B7%A8%EC%97%85%EC%9D%84%EC%9C%84%ED%95%9C%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8%EB%8B%A4-Chapter-01-%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-%EA%B0%9C%EC%9A%94-1-%EB%B3%B5%EC%9E%A1%EB%8F%84-%EC%8B%9C%EA%B0%84-%EB%B3%B5%EC%9E%A1%EB%8F%84)
> 

시간 복잡도에 대한 이론적인 내용보다는 일반적인 코딩 테스트의 경우에 대입해서 정리

일반적인 코딩테스트에서는 O(N^3)을 넘어가면 문제 풀이에서 사용하기 어렵다고한다.

O(N^3)의 대표적인 알고리즘은 3중 반복문, N이 1000이라면 연산 횟수는 10억이 된다.

그렇다고 이중반복문은 항상 가능한 것도 아니다. 내부에서 불리는 함수의 계산도 고려해야하기 때문에..

컴퓨터는 간단한 동작을 1초에 1억번 계산 가능할 수 있다고 한다.

N=5,000인 경우 O(N^2) 정도 가능하다. 어떤 글은 2000까지만 가능하다고 하는 글도 있다.
일 때 연산 횟수

|  | 연산 횟수(N=1000) | 적절한 N의 범위 |
| --- | --- | --- |
| O(N) | 1000 | 10,000,000 |
| O(NlogN) | 10,000 | 100,000 |
| O(N^2) | 100,000 | 2000~5000 |
| O(N^3) | 100,000,000 | 500 |