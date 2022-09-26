---
title:      C# Data Structure#03 | Multidimensional Arrays(다차원 정적 배열)
date:       "2022-09-07"
categories: ["C#", "04.Data Structure"]
tags:       ["C#", "Data Structure"]
# pin:        true
---

# Multidimensional Arrays(다차원 배열)
```c#
int [,] arr = new int [2, 3] { {1, 2, 3}, {4, 5, 6} };
int [,] arr2 = new int [,] { {1, 2, 3}, {4, 5, 6} };
int [,] arr3 = { {1, 2, 3}, {4, 5, 6} };

arr[0, 0] = 1;
arr[1, 2] = 6;

for(int i = 0; i < arr.GetLength(0); i++)
    for(int j = 0; j < arr.GetLength(1); j++)
```

- C# 에선 ```arr[a, b]``` 이런식으로도 표현할 수 있다.
  - 물론 ```arr[a][b]``` 표현도 가능하다.

> 다차원 배열에선 ```GetLength()```로 쓰자.

- arr.Length() - 배열의 전체 원소 개수. 2 * 3 = 6
- arr.GetLength(0) - 행의 개수. 2
- arr.GetLength(1) - 열의 개수. 3

```c#
int [][] a new int[3][];
a[0] = new int[3];
a[1] = new int[6];
a[2] = new int[2];

a[0][0] = 1;
```

위와 같이 열의 크기를 나중에 정할 수도 있다. 행마다 배열의 크기가 다르게도 할 수 있다.

---

# 참고 사이트
- [공부하는 식빵맘](https://ansohxxn.github.io/c%20sharp/ch8-1/)