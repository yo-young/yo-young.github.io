  - [2.5 HTTP](#25-http)
    - [2.5.1 HTTP/1.0](#251-http10)
    - [2.5.2 HTTP/1.1](#252-http11)
    - [2.5.3 HTTP/2.0](#253-http20)
    - [2.5.4 HTTPS](#254-https)
    - [2.5.5 HTTP/3](#255-http3)
  ---
## 2.5 HTTP

- 애플리케이션 계층의 프로토콜
- 웹 서비스 통신에 사용

### 2.5.1 HTTP/1.0

- 한 연결당 하나의 요청을 처리
    
    ### RTT 증가
    
    - 서버로부터 파일을 가져올 때마다 3-way handshake를 시도하기 때문에 RTT 증가
    
    ### RTT의 증가를 해결하기 위한 방법
    
    - 이미지 스플리팅
        - 다수의 이미지가 합쳐있는 하나의 이미지를 다운로드
        - 이를 기반으로 background-image의 position을 이용하여 이미지를 표기
    - 코드 압축
        - 개행 문자, 빈 칸을 제거하여 코드의 크기를 최소화
    - 이미지 Base64 인코딩
        - 이미지파일을 64진법으로 이루어진 문자열로 인코딩
    - 서버와의 연결을 열고 이미지에 대해 요청할 필요가 없음
    - 37%정도 크기가 더 커질 수 있음

### 2.5.2 HTTP/1.1

- 한 번 TCP 초기화를 한 이후 keep-alive 옵션으로 다수의 파일을 송수신
- keep-alive는 1.1부터 표준화되어 기본 옵션으로 설정
- HTTP 문서안에 포함된 다수의 리소스를 처리하려면 요청할 리소스 개수에 비례해서 대기 시간이 길어질 수 있음
    
    ### HOL Blocking(Head Of Line Blocking)
    
    - 네트워크에서 같은 queue에 있는 패킷이 그 첫 번째 패킷에 의해 지연될 때 발생하는 성능 저하 현상
    
    ### 무거운 헤더 구조
    
    - HTTP/1.1의 헤더에는 쿠키 등 많은 메타데이터를 포함

### 2.5.3 HTTP/2.0

- SPDY 프로토콜에서 파생된 HTTP/1.x 보다 지연 시간을 줄이고 응답 시간이 빠름
- Multiplexing, 헤더 압축, 서버 푸시, 요청의 우선순위 처리를 지원하는 프로토콜
    
    ### Multiplexing
    
    - 다수의 스트림을 사용하여 송수신
    - 특정 스트림의 패킷이 손실되어도 해당 스트림에만 영향
    - 한 스트림 내에서도 독립된 프레임을 조각내 송수신한 후 다시 조립
    - 이를 통해 HOL Blocking 문제를 해결
    
    ### 헤더 압축
    
    - 허프만 코딩
        - 문자열을 문자 단위로 쪼개 빈도수를 세어 빈도가 높은 정보는 적은 비트 수를 사용하여 표현
    - 서버 푸시
        - HTTP/1.1에서는 클라이언트가 서버에 요청을 해야 파일 다운로드 가능
        - 클라이언트 요청 없이 서버가 바로 리소스 푸시 가능

### 2.5.4 HTTPS

- HTTP/2는 HTTPS 위에서 동작
- 애플리케이션 계층과 전송 계층 사이에 신뢰 계층인 SSL/TLS 계층을 넣은 신뢰할 수 있는 HTTPS 요청
- 통신 암호화
    
    ### SSL/TLS
    
    - SSL(Secure Socket Layer)은 SSL 1.0부터 시작해서 SSL 2.0, 3.0, TLS(Transport Layer Protocol) 1.0, TLS 1.3까지 버전이 올라가며 마지막으로 TLSㄹ로 명칭 변경
    - 보통 SSL/TLS로 많이 불림
    - 전송 계층에서 보안을 제공하는 프로토콜
    - 클라이언트와 서버가 통신할 때 SSL/TLS를 통해 제 3자가 도청/변조하지 못하도록 함
    - TLS 1.3은 사용자가 사이트에 재방문한다면 보안 세션을 만드는 통신이 필요 없음(0-RTT)
    - 보안 세션을 기반으로 암호화
        
        ### 보안 세션
        
        - 보안이 시작되고 끝나는 동안 유지되는 세션
        - SSL/TLS는 handshake를 통해 보안 세션을 생성
        - 클라이언트와 서버가 키 공유 and 인증, 인증 확인 등의 단 한번의 1-RTT 후 데이터 송수신
        
        [http://www.plantuml.com/plantuml/svg/VP312e9048RlFiNSenUG2CEC8EWYTFAow6yERAFCJf54xvwIbv8wxl9_7n-J17DgrukFKiyGe-MQSkWDIZ6zl_RmlgN7ue0-RvpY6Ks3OJf1CMswpdFfZ5kXhJCN7Li3APyRYoVXp5D89gNsdQ7AxWO90nmAIQ76zIZ3n-C4vRelPCV2eK4rA_wPuL6FZT_WwY-PGAhXBYy0](http://www.plantuml.com/plantuml/svg/VP312e9048RlFiNSenUG2CEC8EWYTFAow6yERAFCJf54xvwIbv8wxl9_7n-J17DgrukFKiyGe-MQSkWDIZ6zl_RmlgN7ue0-RvpY6Ks3OJf1CMswpdFfZ5kXhJCN7Li3APyRYoVXp5D89gNsdQ7AxWO90nmAIQ76zIZ3n-C4vRelPCV2eK4rA_wPuL6FZT_WwY-PGAhXBYy0)
        
        - 클라이언트에서 Cypher suites를 서버에 전달하면 서버는 cypher suite의 암호화 알고리즘 리스트를 제공할 수 있는지 확인
        - 제공할 수 있다면 서버에서 클라이언트로 인증서를 보내는 인증 메커니즘 시작
        - 이후 해싱 알고리즘 등으로 암호화된 데이터 송수신 시작
        
        ### Cypher suite
        
        - 프로토콜, AEAD 사이퍼 모드, 해싱 알고리즘이 나열된 5개의 규약
            - TLS_AES_128_GCM_SHA256
            - TLS_AES_256_GMC_SHA384
            - TLS_CHACHA20_POLY1305_SHA256
            - TLS_AES_128_CCM_SHA256
            - TLS_AES_128_CCM_8_SHA256
        
        ### AEAD 사이퍼 모드
        
        - AEAD(Authenticated Encryption with Associated Data)는 데이터 암호화 알고리즘
        
        ### 인증 메커니즘
        
        - CA(Certificate Authorities)에서 발급한 인증서를 기반
        - 안전한 연결을 시작하는데 필요한 ‘공개키’를 클라이언트에 제공
        - 사용자가 접속한 서버가 신뢰할 수 있는 서버임을 보장
        - 인증서는 서비스 정보, 공개키, finger print, 디지털 서명 등으로 구성
        - 신뢰성이 엄격하게 공인된 기업들만 CA에 참여 가능
        
        ### 암호화 알고리즘
        
        - 키 교환 암호화 알고리즘 : 대수곡선 기반의 ECDHE 또는 모듈식 기반의 DHE를 사용
        - Diffie-Hellman 방식을 근간으로 개발
            
            ### Diffie-Hellman 키 교환 암호화 알고리즘
            
            - 암호키를 교환하는 방법
            
            $$
            y=g^x mod\ p
            $$
            
            - g, p, y만 알고 있다면 x를 구하기 어렵다는 원리에 기반
                1. 공개 값 공유
                2. 각자의 비밀 값과 혼합
                3. 혼합 값 공유
                4. 각자의 비밀 값과 혼합
                5. 공통의 암호키 생성
        
        ### 해싱 알고리즘
        
        - 데이터를 추정하기 힘든 작고 섞여있는 조각으로 만드는 알고리즘
        - SSL/TLS는 SHA-256, SHA-384을 사용
            
            ### SHA-256 알고리즘
            
            - 해시 함수의 결과값이 256비트
            - 임의의 데이터를 입력으로 받아 256비트의 데이터로 변환
    
    ### SEO에도 도움이 되는 HTTPS
    
    - SEO(Search Engine Optimization) : 검색엔진 최적화
    - 구글은 SSL 인증서를 강조, 사이트내 모든 요소가 동일하다면 HTTPS 서비스를 하는 사이트가 SEO 순위가 높을 것이라고 발표
    - 캐노니컬 설정
        - `<link rel="canonical" href=" https://example.com/page2.php " />`
    - 메타 설정
        - html 파일의 가장 윗부분인 메타를 잘 설정해야 함
    - 페이지 속도 개선
        - 구글의 PageSpeedInsights에서 페이지 속도 리포팅을 받을 수 있음
    - 사이트맵 관리
    
    ### HTTPS 구축 방법
    
    - 직접 CA에서 구매한 인증키를 기반으로 HTTPS 서비스를 구축
    - 서버 앞단의 HTTPS를 제공하는 로드밸런서로 구축
    - HTTPS를 제공하는 CDN으로 구축

### 2.5.5 HTTP/3

- QUIC라는 계층 위에서 작동
- TCP 기반이 아닌 UDP 기반으로 작동
    
    ### 초기 연결 설정 시 지연 시간 감소
    
    - TCP 기반이 아니므로 3-way handshake를 사용하지 않음
    - 첫 연결 설정에 1-RTT만 소요
    - 클라이언트가 서버에 신호를 주고 서버가 응답하면 바로 본 통신을 시작
    - 순방향 오류 수정 메커니즘(FEC, Forward Error Correction)이 적용
    - 전송 패킷이 손실되었다면 수신 측에서 에러를 검출하고 수정하는 방식
    - 열악한 네트워크 환경에서도 낮은 패킷 손실률