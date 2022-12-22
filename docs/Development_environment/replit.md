---
layout: default
title: repl.it으로 코딩하기
parent: Development environment
nav_order: 1
---

## repl.it 설치
- AppStore에서 repl.it 어플 설치
- github 계정으로 로그인

## repl.it에 git repository import하기
- 어플에서는 github repo를 가져올 수 없는 것 같음
- PC에서 replit.com에 접속
  - `Create a repl` -> `Import from GitHub`
  - 원하는 Repo를 가져온다

## repl.it 어플에서 작업하기
- 마크다운 파일 작성 후 어플 아래 쪽의 Run 버튼을 누르면 터미널로 전환된다
- 터미널에서 git command를 통해 commit/push를 할 수 있다

## repl.it에서 commit & push
- github의 보안정책으로 인해 ID/PW가 아닌 ID/Token으로만 push가 가능
- token의 길이가 짧은 것도 아니고.. 매번 입력할 수 없다
- git의 credential.helper 기능을 이용하면 매번 입력하지 않아도 된다
  - store 옵션을 입력한 뒤에 ID/Token을 한 번 입력하면 그 뒤로 다시 입력하지 않아도 된다
  ```
  git config --global credential.helper store
  git push origin master
  Username for 'https://github.com': yo-young
  Password for 'https://yo-young@github.com':
  ```

## 완료
- 이렇게 아이패드에서 repl.it을 이용하여 코딩과 github 연동까지 가능하도록 설정이 끝났다!
- 이 포스트 또한 아이패드에서 작성되었다


