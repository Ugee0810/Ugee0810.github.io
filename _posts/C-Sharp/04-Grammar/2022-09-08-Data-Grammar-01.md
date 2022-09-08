---
title:      C# Grammar#01 | Switch
date:       "2022-09-08"
categories: ["C#", "04.Data Structure"]
tags:       ["C#", "Grammar", "Unity"]
# pin:        true
---

# Switch
- if - else 반복 줄임
- 가독성 높임
- switch(n) 인수로는 기본적으로 정수와 문자를 넣을 수 있음
  - 최근 C# 에서는 다른 타입의 객체도 넣을 수 있게끔 개선됐다.

```c#
int choice = 0;

switch(choice)
{
    case 0:
        Console.WriteLine("가위");
        break;
    case 1:
        Console.WriteLine("바위");
        break;
    case 2:
        Console.WriteLine("보");
        break;
    default:
        Console.WriteLine("다 실패");
        break;
}
```

- ```break```에 걸리지 않으면 해당된 ```case```에서부터 쭉쭉 다 실행한다. 해당 ```case```만 실행 시킬 것이라면 ```break``` 꼭 명시.
  - break는 switch문을 벗어나는 것에 해당한다.
- ```switch```문으로 표현 한 것은 항상 ```if-else```문으로도 표현할 수 있지만 그 반대는 항상 성립되는 것은 아니다. ```switch```는 **값에 따른 분기에만 한정 됨.** 따라서 간단한 분기의 경우 가독성 좋은 ```switch```를 권장. 복잡한 조건 분기의 경우 ```if-else```문 사용하기.
- ```switch```문의 ```case``` 값으로는 **일반 변수가 들어갈 순 없다.**
  - 상수 리터럴이나 ```const``` 상수가 들어가야 한다.
  - 즉 실행 중에 값이 바뀔 수 있는 변수는 들어갈 수 없다.
  - 이와 달리 ```if-else```문은 조건문에도 일반 변수를 사용할 수 있다.
  
  ```c#
  int ROCK = 1; const int PAPER = 2;

  switch(choice)
  {
    case ROCK:  // ❌ 에러! case 엔 컴파일타임에 메모리가 결정되는 상수가 들어와야 한다.
      break;
    case PAPER: // ⭕ const 상수이므로 문제 없다.
      break;
  }
  ```

---

# 참고 사이트
- [공부하는 식빵맘](https://ansohxxn.github.io/c%20sharp/ch2-1/)
- [Chameleon Studio](https://chameleonstudio.tistory.com/42)