---
title:      C# Data Structure#06 | Dictionary
date:       "2022-09-07"
categories: ["C#", "03.Data Structure"]
tags:       ["C#", "Data Structure"]
# pin:        true
---

# Dictionary
> dic[```Key```] = ```Value```, ```Key```를 통하여 접근하여 그에 대응하는 ```Value```를 불러올 수 있다.

- ```using System.Collections.Generic;``` using 선언 필수
- 얘도 클래스이기 때문에 Dictionary 타입의 객체를 생성하면 **참조를 하게 된다는 의미**가 된다.
  - ```new```를 사용하여 생성해야 함.
- 해시 테이블을 사용하기 때문에 매우 빠르다.
  - 공간을 미리 많이 차지하고 있기 때문에 공간 면에선 비효율적일 수 있다.
  - 메모리를 내주고 성능을 취한다.

```c#
    class Monster
    {
        public Monster(int id) { this.id = id; }
        public int id;
    }

    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<int, Monster> dic = new Dictionary<int, Monster>();
        }
    }
```

## 추가 : ```Add(Key, Value)```
```c#
Dictionary<int, Monster> dic = new Dictionary<int, Monster>();

dic.Add(1, new Monster());
dic[5] = new Monster(5);  // Key 5 가 새롭게 생김
```

- 추가 방법
  - ```Add``` 사용
    - ```Add(Key, Value)```
  - ```[]``` 사용
    - 기존에 없는 Key에 Value 를 대입해도 추가가 된다.

## Value 가져오기 : ```TryGetValue(Key, out)```
```c#
Dictionary<int, Monster> dic = new Dictionary<int, Monster>();

for(int i = 0; i < 10; i++)
    dic.Add(i, new Monster(i));

Mionster mon = dic[5]; // ⭕
Mionster mon2 = dic[154]; // ❌ 154는 없는 Key이기 때문에 리턴 값이 없다. 따라서 런타임 에러 발생.

Mionster mon3;
bool found = dic.TryGetValue(154, out mon3); // ⭕ mon3에 154 키에 해당하는 값이 저장된다.
```

- Value 가져오는 방법
  - ```[]``` 사용
    - 없는 Key로 접근하여 Value를 받아오려 할 경우 런타임 에러가 발생할 수 있다.
  - ```TryGetValue(Key, out)```
    - 해당 Key가 Dictionary에 존재한다면 Value를 ```out``` 키워드 붙은 변수에 저장하고 (원본 저장, 참조) True를 리턴한다.
    - 해당 Key가 Dictionary에 존재하지 않는다면 False를 리턴하고 ```mon``` 변수는 ```null``` 상태로 남을 것이다.

## 삭제 : ```Remove(Key)```, ```Clear()```
```c#
Dictionary<int, Monster> dic = new Dictionary<int, Monster>();

for(int i = 0; i < 10; i++)
    dic.Add(i, new Monster(i));

dic.Remove(7);  // 해당 key에 해당하는 정보 삭제.
dic.Clear();
```

## 검색 : ```ContainsKey(Key)```
```c#
Dictionary<int, Monster> dic = new Dictionary<int, Monster>();

if (dic.ContainsKey(3))
    Console.WriteLine("3 Key가 존재합니다");
```

- ```ContainsKey(Key)```
  - 해당 키가 Dictionary 안에 있다면 True, 없다면 False.

---

# 참고 사이트
- [공부하는 식빵맘](https://ansohxxn.github.io/c%20sharp/ch8-3/)