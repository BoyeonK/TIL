### 복습용 연습장 레포입니당

2025 1 2th

- 스마트포인터
  
  - shared_ptr, weak_ptr
  
  - enable_shared_from_this<_Ty>, shared_from_this()
  
  - static_pointer_cast<_Ty>()

- 알고싶지 않았던 유형별 에러들...
  
  - 라이브러리에서 구현부를 제대로 구현하지 않은 경우 (LNK2001)
  
  - 런타임 라이브러리 설정이 파일마다 통일되지 않은 경우 (LNK2038)
  
  - share_ptr로 유효하지 않은 객체를 래핑했을 경우 (memory.h)
  
  - 대입 연산자로 값을 변경할 수 없는 값을 대입 연산자로 조작하려 한 경우

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
