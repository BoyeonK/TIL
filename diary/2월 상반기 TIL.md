### 2월 상반기

#### 알고리즘 회고하기 전에...

1. 코드부터 갈기지 말것.
   
   - 설계를 먼저 하고, 올바른 방법인지 판단이 선 이후에 코드를 적는것이
     오히려 더 빠르고 정확하다.
   
   - 드러운 문제들은 여러가지 구현을 요구한다.
     단계별로 잘게 잘라서, 하나씩 디버그해가면서 천천히 구현해도 늦지 않는다.
     디버그없이 쭉 갈겨버리면 나중에 크게 피 볼 수 있다. 아니, 피 본다.

2. 계산 횟수는, 왠만하면 100만을 넘기지 않을 것.
   
   - 아무리 많아도 1000만은 절대 넘기지 않게 문제가 설계된다.
   
   - 이유는 모르겠는데... 경험상 100만번 플러스 마이너스의 계산 횟수를 요구하는 경우가 많다...
     주어진 data의 크기를 보고 역으로 어떤 풀이법을 사용해야 할지 감을 잡을 수도 있다.



- STL
  
  - map? unordered_map?
    
    - map
      
      - 내부적으로 Red-Black Tree를 사용함.
      
      - unordered_map보다 적은 메모리 사용.
      
      - 탐색, 요소제거, 요소추가 -> `O(logN)`
    
    - unordered_map은 해시테이블을 사용함.
      
      - 내부적으로 Hash Table을 사용함.
      
      - 탐색, 요소제거, 요소 추가 -> `O(1)` ~ `O(N)` 이지만,
        요소가 어지간히 많은 게 아니라면 (해시 충돌이 심한경우) `O(1)` 으로 봐도 무방.
    
    - iterator?
      
      - STL안에서 사용할 수 있는 반복자이다.
        `find()`와 같은 메서드를 사용했을 때, 리턴값으로 주어진다.
      
      - 이 iterator는 마치, 해당 요소값에 대한 포인터를 다루는 것과 거의 동일한 방법으로 사용할 수 있다.
  
  - tuple
    
    - `auto [a, b, c]` 와 같은 Structured Binding은 C++17 이후부터 가능하다.
    
    - `make_tuple()`과 `tie()`를 사용하자.
  
  - vector
    
    - 생성자 안에 요소를 어떻게 생성할지 생성자를 적을 수 있다.... 무슨말이냐면
      `vector<vector<int>> vec(10, vector<int>(10, -1));` 과 같은 방법으로 1줄만으로 초기화된 2차원 벡터를 생성할 수 있다.
      
      

- 조합

- 이분탐색

       
