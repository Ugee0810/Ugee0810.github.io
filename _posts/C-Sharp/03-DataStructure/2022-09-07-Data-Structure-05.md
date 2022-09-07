---
title:      C# Data Structure#05 | Multidimensional List(다차원 동적 배열)
date:       "2022-09-07"
categories: ["C#", "03.Data Structure"]
tags:       ["C#", "Data Structure"]
# pin:        true
---

# Multidimensional List(다차원 동적 배열)
불행히도 C#에서 다차원 목록을 선언하는 기본 제공 메서드는 없습니다. 따라서 이 목표를 달성하려면 사용자 정의 접근 방식에 의존해야합니다.

## C#에서List<List<T>>를 사용하여 2D 목록 선언
```List<List<T>>```표기법을 사용하여 목록의 명부를 선언 할 수 있습니다. 여기서 T 는 목록 내의 변수 유형을 지정합니다.

다음 코드 예제는 C#에서 ```List<List<T>>```표기법을 사용하여 2D 목록을 선언하는 방법을 보여줍니다.

```c#
using System;
using System.Collections.Generic;

namespace multidimensional_list
{
    class Program
    {
        static void Main(string[] args)
        {
            List<List<string>> Person = new List<List<string>>();
            for (int i = 0; i < 3; i++)
            {
                List<string> Data = new List<string>();
                Data.Add("Person ");
                Data.Add("Description ");
                Person.Add(Data);
            }
            foreach (var list in Person)
            {
                foreach (var element in list)
                {
                    Console.Write(element);
                }
                Console.WriteLine();
            }
    }
}

Result

Person Description
Person Description
Person Description

```

C#에서 ```List<List<string>>``` 표기법을 사용하여 문자열 변수의 2D 목록 ```Person```을 선언했습니다. 목록에 데이터를 입력하려면 데이터를 다른 ```string``` 변수 목록에 저장 한 다음 ```Person.Add()``` 함수를 사용하여 해당 객체를 ```Person``` 목록에 추가해야합니다. 중첩 루프가있는 목록을 출력합니다. 이 방법의 단점은 2D 배열에서만 작동하며 1 데이터 유형의 요소만 포함 할 수 있다는 것입니다.

## C#에서 클래스 목록을 사용하여 다차원 목록 선언
여러 데이터 형식의 목록을 만들려면 C#에서 클래스 개체 목록을 선언 할 수 있습니다. 아시다시피 class에는 데이터 형식이 다른 여러 변수가 포함될 수 있습니다.

다음 코드 예제는 C#에서 개체 목록을 만들어 2D 목록을 선언하는 방법을 보여줍니다.

```c#
using System;
using System.Collections.Generic;

namespace multidimensional_list
{
    public class Person
    {
        public string Name { get; set; }
        public string Description { get; set; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            List<Person> People = new List<Person>();
            for(int i = 0; i < 3; i++)
            {
                Person p = new Person();
                p.Name = "Person ";
                p.Description = "Description ";
                People.Add(p);
            }
            foreach(var obj in People)
            {
                Console.WriteLine(obj.Name);
                Console.WriteLine(obj.Description);
            }
    }
}

Result

Person
Description
Person
Description
Person
Description
```

C#에서 ```Person``` 클래스 목록을 생성하여 2D 목록 ```People``` 을 선언했습니다. 목록에 데이터를 입력하려면 ```Person``` 클래스의 객체에 데이터를 저장 한 다음 ```People.Add()``` 함수를 사용하여 해당 객체를 ```People``` 목록에 추가해야합니다.

이 접근 방식을 사용하면 목록에 서로 다른 데이터 유형의 여러 요소를 가질 수 있습니다.

## C#에서 튜플 목록을 사용하여 다차원 목록 선언
목록에서 여러 데이터 유형을 사용하고 싶지만 모든 변수를 저장하는 별도의 클래스를 만들고 싶지 않은 경우 튜플 목록을 선언 할 수도 있습니다. C#에서 ```List<(T1, T2)>``` 표기법으로 튜플 목록을 선언 할 수 있습니다. 여기서 T1 및 T2는 각각 튜플의 첫 번째 및 두 번째 요소의 데이터 유형입니다.

다음 코드 예제는 C#에서 튜플 목록으로 다차원 목록을 선언하는 방법을 보여줍니다.

```c#
using System;
using System.Collections.Generic;

namespace multidimensional_list
{
    class Program
    {
        static void Main(string[] args)
        {
            List<(string, string)> Person = new List<(string, string)>();
            for (int i = 0; i < 3; i++)
            {
                Person.Add(("Person", "Description"));
            }
            foreach (var list in Person)
            {
                Console.WriteLine(list);
            }
    }
}

Result

(Person, Description)
(Person, Description)
(Person, Description)
```

C#에서 ```ist<(string, string)>``` 표기법을 사용하여 ```Person``` 튜플 목록을 선언했습니다. ```Person``` 목록에 튜플 형태로 데이터를 입력하고 ```foreach``` 배열 반복문으로 표시합니다.

<br>

---

# 참고 사이트
- [C# 하우투](https://www.delftstack.com/ko/howto/csharp/declare-a-multidimensional-list-in-csharp/)
- [IEnumerable을 C#의 목록으로 변환하는 방법](https://www.delftstack.com/ko/howto/csharp/how-to-convert-an-ienumerable-to-a-list-in-csharp/)
- [C# 목록에서 항목 제거](https://www.delftstack.com/ko/howto/csharp/how-to-remove-item-from-list-in-csharp/)
- [C# 두 목록을 함께 결합](https://www.delftstack.com/ko/howto/csharp/how-to-join-two-lists-together-in-csharp/)
- [C#에서 필드별로 목록 정렬](https://www.delftstack.com/ko/howto/csharp/sort-list-by-field-in-csharp/)