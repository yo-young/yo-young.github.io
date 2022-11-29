---
layout: default
title: 동기와 비동기
parent: Computer Science
nav_order: 9
---

## 동기와 비동기

- 동기(synchronous : 동시에 일어나는)
    - 요청과 결과가 한 자리에서 동시에 일어남
    - A노드와 B노드 사이의 작업 처리 단위(transaction)를 동시에 수행
- 비동기(Asynchronous : 동시에 일어나지 않는)
    - 요청한 그 자리에서 결과가 주어지지 않음
    - 노드 사이의 작업 처리 단위를 동시에 수행하지 않아도 됨
- 동기와 비동기는 `어떤 작업 혹은 그와 연관된 작업`을 처리하고자 하는 시각의 차이
    - 동기는 추구하는 같은 행위(목적)가 동시에 수행
    - 비동기는 추구하는 행위(목적)가 다를 수도 있고, 동시에 수행되지 않음

## 블록과 논블록

- 블록 상태
    - 요청한 결과를 기다리는 동안 어떤 작업도 수행하지 못함
    - A 함수가 실행되고 A함수가 끝날 때까지 다른 함수가 실행되지 못함
- 논블록 상태
    - 요청한 작업과 연관되지 않은 작업을 수행할 수 있음
    - A 함수가 실행되자 마자 return하여 A함수를 호출한 코드에 제어권을 넘겨 다른 일을 할 수 있도록 함

os를 공부하면서 열심히 배웠던 동시성 문제는 블럭/논블럭과는 연관이 없고 동기/비동기와 연관이 있습니다.

> [https://private.tistory.com/24](https://private.tistory.com/24)
[https://dkswnkk.tistory.com/488](https://dkswnkk.tistory.com/488)
> 

--- 
## 업무에 적용

매우 기본적인 내용이지만 업무를 예로 들면 기억하기 좋을 것 같다.

### RSARTE

- 업무에 사용하는 RSARTE에는 각 software capsule마다 logical thread가 존재
- 각 thread는 state와 transition으로 구성(이외에 더 있지만 큰 부분에서..)
- state는 tigger event가 발생하지 않으면 다음 state로 transit되지 않는다.
    - `블럭 상태`
- 하지만 다른 logical thread가 수행되지 않는 것은 아니다. → 다른 thread가 동시에 수행 가능
    - `비동기`

### Module test

- test하고자 하는 target과 가상의 sim node들이 존재
- test하고자 하는 target에서 sim node로 메세지를 전송
- 다른 코드들이 수행되지 않는다.
    - `비동기`, `블럭 상태`