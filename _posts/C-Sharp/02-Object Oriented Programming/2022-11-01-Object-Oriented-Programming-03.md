---
title:      C# Object Oriented Programming#03 | 상속성, sealed 키워드, 부모/자식 클래스 형식변환, is/as 연산자, object
date:       "2022-11-01"
categories: ["C#", "02.Object Oriented Programming"]
tags:       ["C#", "Object Oriented Programming"]
# pin:        true
---

# ※ 상속
클래스는 다른 하나의 클래스로부터 유산을 물려받을 수 있음 (=상속받을 수 있음)

다중상속은 지원하지 않는다. (동시에 2개 이상의 클래스를 상속받는 것)

- 부모 클래스(기반 클래스) : 상속해주는 클래스
- 자식 클래스(파생 클래스) : 상속 받는 클래스

```c#
namespace Program {
    public class Person
    {
        public string Gender { get; set; } = "Unknown";
        public string doubleStr (string str)
        {
            return $"{str}{str}";
        }
    }
    public class Student : Person // Person클래스를 상속
    {
        public string Dept { get; set; } = "Unknown";
        public int Grade { get; set; } = 0;
    }

    class Program
    {
        static void Main(string[] args)
        {
            Person person = new Person()
            {
                Gender = "female"
            };
            Console.WriteLine(person.Gender); // female
            Console.WriteLine(person.doubleStr(person.Gender)); // femalefemale

            Student student = new Student()
            {
                Gender = "male",
                Dept = "CE",
                Grade = 2
            };
            Console.WriteLine(student.Gender); // male
            Console.WriteLine(student.doubleStr(student.Dept)); // CECE
            Console.WriteLine(student.Grade); // 2
        }
    }
}
```

<br>

# ※ sealed 키워드
```sealed``` 키워드를 붙여 클래스가 상속되지 않도록 하거나, 메소드가 자식클래스에서 오버라이드 되지 않도록 할 수 있다.

## 클래스 상속 제한
아래 코드는 sealed설정된 클래스를 상속하려고 해 오류가 발생한다.

    오류 CS0509 'Wonjin': sealed 형식 'Student'에서 파생될 수 없습니다.

```c#
public class Person
{
    public string Gender { get; set; } = "Unknown";
    public string doubleStr (string str)
    {
        return $"{str}{str}";
    }
}

public sealed class Student : Person // Person클래스를 상속
{
    public string Dept { get; set; } = "Unknown";
}

class Wonjin : Student // <-- 컴파일오류 CS0509
{
    // something
}
```

## 메소드 오버라이드 제한
virtual 메소드를 오버라이드한 메소드의 오버라이드를 제한할 수 있다.

아래 코드는 sealed 설정된 메소드를 오버라이드 하려 시도해 컴파일 오류가 발생한다.

    CS0239 'Wonjin.SaySomething(string)': 상속된 'Student.SaySomething(string)' 멤버는 봉인되어 있으므로 재정의할 수 없습니다.

<br>

# ※ 부모/자식 클래스 형식변환
- 부모에 자식 대입 (암시적변환)
- 자식에 부모 대입 (명시적변환) : 런타임에러 발생 가능

## 암시적 형변환
암시적 형변환은 메소드 오버로드의 대안으로 사용할 수 있다.

이 때, 부모 클래스의 배열은 자식 클래스를 원소로 가질수 있다.

```c#
namespace Program
{
    class SayMachine
    {
        public void SayGender(Person obj)
        {
            obj.SaySomething(obj.Gender);
        }
    }

    class Person
    {
        public string Gender { get; set; } = "Unknown";
        public void SaySomething(string str)
        {
            Console.WriteLine(str);
        }
    }
    class Student : Person
    {
        public string Dept { get; set; } = "CE";
    }
    class Wonjin : Student
    {
        public string Name { get; set; } = "wonjinLee";
    }

    class Program
    {
        static void Main(string[] args)
        {
            Student student = new Student() { Gender = "female" };
            Wonjin wonjin = new Wonjin() { Gender = "male" };

            Person[] persons = new Person[] { student, wonjin };

            SayMachine sayMachine = new SayMachine();
            foreach (Person person in persons)
            {
                sayMachine.SayGender(person);
                // female
                // male
            }
        }
    }
}
```

<br>

# ※ is, as 연산자
## as 연산자
형식변환 연산자와 동일하게 동작하나, 변환 실패 시 런타임 에러가 발생하지 않음. 대신 객체 참조에 null 대입.

## is 연산자
객체가 해당 형식이 맞는지 검사하여 true, false 반환

```c#
class Person {
    public string Gender { get; set; } = "Unknown";
}
class Student : Person {
    public string Dept { get; set; } = "Unknown";
}
class Wonjin : Student {
    public string Name { get; set; } = "Unknown";
}

class Program {
    static void Main(string[] args)
    {
        Person person1 = new Person();
        Person person2 = new Student();
        Student student = new Student();
        Wonjin wonjin = new Wonjin();
            
        // as연산자
        student = person1 as Student; // person1객체를 Student클래스로 형변환
        if(student != null) { /* 여긴 올일이없다*/ }
        else
        {
            Console.WriteLine("student는 null"); // 출력됨
        }

        student = person2 as Student; // person2객체를 Student클래스로 형변환
        if (student != null)
        {
            Console.WriteLine("student는 person2"); // 출력됨
        }
        else { /* 여긴 올일이없다*/ }

        // is연산자
        if (person2 is Wonjin) { /* 여긴 올일이없다*/ }
        if (wonjin is Person)
        {
            Console.WriteLine("wonjin은 Person");  // 출력됨
        }
    }
}
```

<br>

# ※ 부모/자식 클래스 생성자, 종료자
자식클래스를 생성한 경우, 아래 순서로 실행된다.
1. 부모클래스의 생성자 실행
2. 자식클래스의 생성자 실행
3. 자식클래스의 종료자 실행
4. 부모클래스의 종료자 실행

```c#
class Person
{
    public Person (int a)
    {
        Console.WriteLine($"Person 생성자, 매개변수 a = {a}");
    }
    ~Person ()
    {
        Console.WriteLine("Person 종료자");
    }
}
class Student : Person
{
    public Student(int a, int b) : base(a)
    {
        Console.WriteLine($"Student 생성자, 매개변수 b = {b}");
    }
    ~Student() {
        Console.WriteLine("Student 종료자");
    }
}

class Program
{
    static void Test()
    {
        Student student = new Student(53, 53535353);
    }
    static void Main(string[] args)
    {
        Test();
        GC.Collect();
        GC.WaitForPendingFinalizers();
        /*
        Person 생성자, 매개변수 a = 53
        Student 생성자, 매개변수 b = 53535353
        Student 종료자
        Person 종료자
        */
    }
}
```

<br>

# ※ object
```object``` 클래스는 모든 클래스의 부모이다.

아래 코드와 같이 Object클래스로 정의되어있다.

```c#
public class Object
{
    public virtual bool Equals();
    public virtual int GetHashCode();
    public Type GetType();
    public virtual string ToString();
}
```

<br>

# ※ 참고 사이트
- [yiwonjin - C#프로그래밍 08 : 상속성](https://velog.io/@yiwonjin/C%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D-08-%EC%83%81%EC%86%8D%EC%84%B1)