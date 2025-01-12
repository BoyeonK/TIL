### 복습용 연습장 레포입니당

2025 1 3th

- 문자열 인코딩 CP949, UTF-16, UTF-8

2025 1 2th

- COMMAND 패턴 (JobQueue)

- Jinja2를 이용한 코드 작성 자동화

- TLS
  
  - TLS를 활용하여 Thread-safe한 방법으로 `::WSASend`해보기

- `static`함수 안의 `static`변수 선언 이유

- `char`와 `unsigned char`

- 스마트포인터
  
  - `shared_ptr`, `weak_ptr`
  - `enable_shared_from_this<_Ty>`, `shared_from_this()`
  - `static_pointer_cast<_Ty>()`

- 알고싶지 않았던, 직접 박아봐야 아는 유형별 에러들...
  
  - 별도의 .md파일로 분류하고, 고통받을 때 마다 업데이트 할 예정

2025 1 1th

- Forwarding Reference

- placement new

- object pool
  
  - LockFree 방식의 연결리스트 (considering ABA problem)
  - 메모리 정렬 (`alignas()`, `_aligned_malloc_()`, `_aligned_free_()`)

- google protobuf
  
  - vcpkg를 사용해서 라이브러리 설치하기
  - cmake로 빌드하기
  - PB파일을 만들고 내장함수들을 다뤄보기

- winsock2 TCP통신
  
  - socket 연결 및 blocking방식으로 `send` `recv`
  - overlapped I/O
  - IOCP 모델 활용

- Functor

- std::function, 람다함수

2024 12 4th

- 멀티쓰레드
  
  - thread, Mutex 객체
  - Future 객체
  - Custom Mutex 클래스 구현

- ::VirtualAlloc 함수를 활용한 할당자

- static_cast, reinterpret_cast, dynamic_cast
