---
title:      C# Data Structure#04 | List(동적 배열)
date:       "2022-09-07"
categories: ["C#", "03.Data Structure"]
tags:       ["C#", "Data Structure"]
# pin:        true
---

# List(동적 배열)
C#에서 ```List```는 동적 배열 = 가변적 크기의 배열(C++에선 ```vector```와 같은 존재)

- ```using System.Collections.Generic;``` using 선언 필수
- 얘도 클래스이기 때문에 ```List``` 타입의 객체를 생성하면 **참조를 하게 된다는 의미**가 된다.
  - ```new```를 사용하여 생성해야 함.
  ```c#
  using System.Collections.Generic;

  List<int> list = new List<int>();  // 빈 상태
  ```

- 빈 상태일 때 없는 인덱스에 접근하면 런타임 에러 예외가 발생한다.
  - 이건 정적 배열(Array)도 동일
- 중간 삽입, 중간 삭제가 효율적이지 않다.
  - 뒤에 있는 원소들이 전부 다 한 칸씩 밀리거나 앞으로 땡겨야 하기 때문이다. 그 과정에서 사본을 생성해야 하는 일도 발생
- List의 접근법은 인덱스 접근이기 때문에 임의 접근은 굉장히 빠르다.

<br>

## Count : 리스트 길이 리턴
```c#
List<int> list = new List<int>();
for (int i = 0; i < 5; i++)
    list.Add(i); // 0 1 2 3 4

Console.WriteLine(list.Count); // 5
```

함수 아니고 프로퍼티다.

<br>

## Add : 후열 삽입
```c#
List<int> list = new List<int>();

list.Add(1); // 원소 1 을 추가.
```

List의 끝에다가 새로운 원소를 추가한다.(C++, vector.push_back())

<br>

## Insert : 중간 삽입
```c#
List<int> list = new List<int>();

for(int i = 0; i < 5; i++)
    list.Add(i); // 0 1 2 3 4

list.Insert(2, 999); // 인덱스2 자리에 원소 999 추가 -> 0 1 999 2 3 4
```

<br>

## Remove : 원소로 search하여 삭제
```c#
List<int> list = new List<int>();

for(int i = 0; i < 5; i++)
    list.Add(i); // 0 1 2 3 4

list.Add(3);  // 0 1 2 3 4 3
list.Remove(3);  // 0 1 2 4 3
```

인수로 넘긴 원소와 동일한 원소들이 있을 수 있지만 가장 처음 만난 원소를 삭제한다. 그리고 삭제에 성공하면 True 리턴, 해당 원소를 찾지 못했다면 False 리턴. ```bool```타입을 리턴한다.

<br>

## RemoveAt : Index로 삭제
```c#
List<int> list = new List<int>();

for(int i = 0; i < 5; i++)
    list.Add(i); // 0 1 2 3 4

list.RemoveAt(0);  // 1 2 3 4
```

인수로 넘긴 인덱스에 해당하는 원소를 삭제한다.

<br>

## Clear : 원소를 전부 삭제 하여 리스트 비우기
```c#
list.Clear();  // 리스트 내의 모든 원소를 싸그리 지운다.
```

<br>

---

# 참고 사이트
- [공부하는 식빵맘](https://ansohxxn.github.io/c%20sharp/ch8-1/)