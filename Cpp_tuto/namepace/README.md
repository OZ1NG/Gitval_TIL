# namespace

## 사용하는 이유

```c++
// foo.h
void Name(){
	std::cout << "FOO.CPP" << std::endl;
}
```
```c++
// goo.h
void Name(){
	std::cout << "GOO.CPP" << std::endl;
}
```


```c++
// main.cpp
#include "foo.h"
#include "goo.h"

void main(){
    Name();
}
```

위의 코드를 컴파일하면 에러가 난다. 함수의 이름이 중복 되었기 때문이다.

C++에서는 위와 같이 서로 다른 행동을 하지만 이름이 같은 함수를 호출하게 되는 경우 에러가 나는 것을 방지하기 위해 namespace 기능이 있다.



## 사용 방법

### namespace 선언
```c++
// foo.h
namespace FOO{ // namespace 이름 : FOO
    void Name(){
    	std::cout << "FOO.CPP" << std::endl;
    }
}
```
위와 같이 namespace안에 함수를 선언해주면 된다.

### namespace 함수 호출
```c++
// main.cpp
#include "foo.h"
#include "goo.h"

void main(){
    FOO::Name(); // FOO의 Name 함수를 사용하겠다는 뜻
}
```

위와 같이 "::"(스코프 분석 연산자:scope resolution operator)를 사용해서 명시해주면 된다.

### using

```C++
//main.cpp
#include <iostream>
using namespace std; // 전역 네임스페이스에 추가, 대충 std namepspace를 생략하겠다는 뜻.

void main(){
    // 기존 : std::cout << "THIS IS NAMESPACE" << std::endl;
    // 수정 후 :
    cout << "THIS IS NAMESPACE" << endl; // std를 생략 가능 해짐.
}
```

위와 같이 **using**을 이용해 특정 네임스페이스를 전역 네임스페이스에 추가해주면, 생략이 가능해진다.

### 전역 네임스페이스란?

기본적으로 전역 변수와 일반 함수들이 정의되는 네임스페이스이다.



## Reference 

https://boycoding.tistory.com/171
