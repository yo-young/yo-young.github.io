---
layout: default
title: record
parent: Erlang
nav_order: 8
---

# record

- 고정된 개수의 element를 보관하기 위한 자료구조
- C의 struct와 유사하나 record는 실제 데이터 타입은 아님
- 컴파일을 진행하는 동안 튜플 표현식으로 변환

```erlang
-record(cellMO, {cellId, freq}).
new(CellId, Freq) ->
    #cellMO{cellId=CellId, freq=Freq}.
main(_) ->
Cell1 = new(4, 300),

io:fwrite("Id of Cell1 : ~p\n", [Cell1#cellMO.cellId]),

ok.
```

- cellMO라는 record 정의
- new라는 함수를 통해 cellId와 Freq를 record에 저장
- Cell1이라는 term에 cellId 4, freq 300을 갖는 record를 저장
- 레코드는 term 이름에 `#`과 정의한 네이밍을 통해 접근 가능