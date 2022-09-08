---
title:      C# Grammar#03 | for(반복 구문) vs foreach(배열 반복문)
date:       "2022-09-08"
categories: ["C#", "04.Data Structure"]
tags:       ["C#", "Grammar", "Unity"]
# pin:        true
---

# for(반복 구문)
C# for 문은 루프 안에 있는 문장들을 반복적으로 실행할 때 사용한다. for 루프는 일반적으로 카운터 변수를 이용해 일정 범위 동안 for 루프 안의 블럭을 실행한다.

다음 예제는 0부터 9까지 총 10번 콘솔 출력을 반복하는 코드이다.

```c#
class Program
{
    static void Main(string[] args)
    {
        // for 루프
        for (int i = 0; i < 10; i++)
        {
           Console.WriteLine("Loop {0}", i);
        }
    }
}
```

---

# foreach(배열 반복문)
```c#
int[] arr = new int[10] {1 , 2, 3, 4, 5, 6, 7, 8, 9, 10 };

foreach(int value in arr) {
	Console.WriteLine("{0}", value);
}
```
하나의 요소로서 ```value```를 선언해주었고 in 뒤에는 순회할 자료형을 쓴다. 

대표적으로 배열이나 List, ArrayList 등을 많이 사용하게 된다.


위 예제처럼 아주 간단하다면 편리함을 크게 못느낄수도 있지만 배열의 요소를 많이 사용한다면

for문으로 arr[i] 처럼 사용하는 것보다는 foreach에서 처럼 사용하는 것이 직관적이며 도움이 될 수 있다.

---

# for vs foreach
C#에서 for와 foreach를 비교하는 것은 흔히 **성능적 측면**과 **코드 가독성 측면**을 고려하는데, 성능적 측면은 for가 경우에 따라 약간 빠를 수 있지만 대부분의 경우 성능적 차이는 크지 않으며, foreach는 for보다 훨신 간결한 코드를 제공한다는 장점이 있다.

특히, 루프에서 가장 많이 사용되는 C# 배열(array)의 경우, foreach가 내부적인 최적화를 거쳐 for 루프와 동일한 성능이므로 더 간결한 foreach를 사용할 것을 권장한다. 예를 들어, 2차배열, 3차배열 등의 다중 배열을 처리할 경우, for루프는 배열 차수만큼 여러번 루프를 돌려야 하지만, foreach는 아래와 같이 단순히 한 루프 문장으로 이를 처리할 수 있어 편리하다.

```c#
static void Main(string[] args)
{
    // 3차배열 선언
    string[,,] arr = new string[,,] { 
            { {"1", "2"}, {"11","22"} }, 
            { {"3", "4"}, {"33", "44"} }
    };

    //for 루프 : 3번 루프를 만들어 돌림
    for (int i = 0; i < arr.GetLength(0); i++)
    {
        for (int j = 0; j < arr.GetLength(1); j++)
        {
            for (int k = 0; k < arr.GetLength(2); k++)
            {
                Debug.WriteLine(arr[i, j, k]);
            }
        }
    }

    //foreach 루프 : 한번에 3차배열 모두 처리
    foreach (var s in arr)
    {
        Debug.WriteLine(s);
    }
}
```

---

# 참고 사이트
- [1commit1zerocoke](https://jinuk97-dev.tistory.com/4)
- [예제로 배우는 C# 프로그래밍](https://www.csharpstudy.com/CSharp/CSharp-looping.aspx)