---
title:      C# Object Oriented Programming#04 | 은닉성(=캡슐화) + 프로퍼티와 get/set, 레코드, 무명형식
date:       "2022-11-01"
categories: ["C#", "02.Object Oriented Programming"]
tags:       ["C#", "Object Oriented Programming"]
# pin:        true
---

# ※ 은닉성(=캡슐화)
> 클래스를 사용자에게 필요한 최소의 기능만 노출하고 내부를 감추는 것

## 캡슐화가 잘 된 클래스의 특징
- 클래스의 이름만으로 제공하는 기능을 대략적으로 파악 가능
- 외부로 제공해야 할 기능만 노출

## 접근 제한자
- ```public``` : 클래스 안/밖 접근가능
- ```protected``` : 클래스 안에서 접근가능. 파생 클래스에서는 접근 가능
- ```private``` : 클래스 안에서 접근가능
- ```internal``` : 같은 어셈블리에 있는 코드에서 public, 다른 어셈블리에 대해 private
- ```protected internal``` : 같은 어셈블리에 있는 코드에서 protected, 다른 어셈블리에 대해 private
- ```private protected``` : 같은 어셈블리에 있는 클래스에서 상속받은 클래스 내부에서만 접근가능

이하 접근 제한자로 수식하지 않은 멤버는 ```private```로 지정됨(생략 가능)

    .NET에서의 어셈블리 : EXE 또는 DLL 형식의 C#파일.
    일반적으로 1개의 파일 (EXE/DLL모듈)로 구성된 어셈블리 사용.

## getter / setter
일반적으로 필드는 public으로 설정하지 않음. 대신 getter, setter를 통해 접근

아래 코드는 메소드로 선언된 형태의 getter와 setter를 보인다.

```c#
namespace FirstProgram {
    class Something
    {
        private int a = 5;
        public int getA()
        {
            return a;
        }
        public void setA(int a)
        {
            this.a = a;
        }
    }
    
    class Program {
        static void Main(string[] args) {
           Something some = new Something();
            Console.WriteLine(some.getA()); // 5

            some.setA(10);
            Console.WriteLine(some.getA()); // 10
        }
    }
}

```
<br>

# ※ 프로퍼티(property)
## 프로퍼티를 활용한 getter, setter의 재정의
아래 코드는 property문법을 활용한 getter와 setter를 보인다.

```c#
namespace FirstProgram {
    class Something
    {
        private int a = 5;
        public int A
        {
            get { return a; }
            set { a = value; } // 암묵적으로 매개변수를 value로 정함
        }
    }
    
    class Program {
        static void Main(string[] args) {
            Something some = new Something();
            Console.WriteLine(some.A); // get / 출력 5 

            some.A = 53;
            Console.WriteLine(some.A); // get / 출력 53
        }
    }
}
```

## 자동구현 프로퍼티
아래 코드는 위 코드의 class Something과 동일한 내용이다.

```c#
    class Something
    {
        public int A { get; set; } = 5;
    }
```

## 프로퍼티를 활용한 초기화

객체 생성시 프로퍼티 문법으로 초기화할 수 있다.

```c#
namespace FirstProgram {
    class Something
    {
        public int A { get; set; } = 0;
    }
    
    /* 자동구현 프로퍼티가 아닌 프로퍼티에도 동작함
    class Something
    {
        private int a = 0;

        public int A { 
            get { return a; }
            set { a = value; } 
        }
    }
    */
    
    class Program {
        static void Main(string[] args) {
            // Something some = new Something <-- 생성자 명시적호출 안해도 된다.
            Something some = new Something()
            {
                A = 535353
            };
            Console.WriteLine(some.A); // 535353

            some.A = 53;
            Console.WriteLine(some.A); // 53
        }
    }
}
```

## 초기화 전용 자동 구현 프로퍼티
어떤 프로퍼티가 초기화 이후 값이 변경되지 않도록 설정할 수 있다.

set 대신 init이 들어간 경우, set 하려고 하면 컴파일에러 발생

    오류 CS8852 초기값 전용 속성 또는 인덱서 'Something.Strstr'은(는) 개체 이니셜라이저 또는 인스턴스 생성자나 'init' 접근자의 'this' 또는 'base'에만 할당할 수 있습니다.

```c#
namespace Program {
    class Something
    {
        public string Strstr { get; init; }
        public int Intint { get; init; }
    }
    
    class Program {
        static void Main(string[] args) {
            Something some1 = new Something() { Strstr = "one", Intint = 1 };
            Something some2 = new Something() { Strstr = "two", Intint = 2 };
            Something some3 = new Something() { Strstr = "three", Intint = 3 };

            Console.WriteLine($"{some1.Strstr,-10} {some1.Intint}"); // one        1
            Console.WriteLine($"{some2.Strstr,-10} {some2.Intint}"); // two        2
            Console.WriteLine($"{some3.Strstr,-10} {some3.Intint}"); // three      3

            // compile error occurs
            // some1.Strstr = "set set";
        }
    }
}
```

<br>

# ※ 레코드(record)
- class와 비슷하게 생긴 것으로 ```record```가 있다.
- 값을 담는 용도의 클래스처럼 활용할 수 있다.
- 컴파일 시에 복사, 비교, 출력을 위한 기본 생성 코드(메소드)가 추가된다.

```record```를 .Equals로 비교하면 값을 비교한다.

```with {}```로 일부 프로퍼티의 값을 바꾸어 **깊은복사**할 수 있다.

```c#
namespace Program {
    class ClassSomething
    {
        public string Strstr { get; init; }
        public int Intint { get; init; }
    }
    record RecordSomething
    {
        public string Strstr { get; init; }
        public int Intint { get; init; }
    }
    
    class Program {
        static void Main(string[] args) {
            ClassSomething c1 = new ClassSomething() { Strstr = "one", Intint = 1 }; 
            ClassSomething c2 = new ClassSomething() { Strstr = "one", Intint = 1 }; 
            Console.WriteLine($" {"class",-10} {c1.Strstr,-10} {c1.Intint}");// class one        1
            Console.WriteLine($" {"class",-10} {c2.Strstr,-10} {c2.Intint}"); // class one        1
            Console.WriteLine(c1.Equals(c2)); // False : 주소값 비교

            RecordSomething r1 = new RecordSomething() { Strstr = "two", Intint = 2 };
            RecordSomething r2 = new RecordSomething() { Strstr = "two", Intint = 2 };
            Console.WriteLine($" {"record", -10} {r1.Strstr,-10} {r1.Intint}");// record     two        2
            Console.WriteLine($" {"record",-10} {r2.Strstr,-10} {r2.Intint}"); // record     two        2
            Console.WriteLine(r1.Equals(r2)); // True : 프로퍼티 값 비교

            
            RecordSomething r3 = r1;
            RecordSomething r4 = r1 with { Strstr = "another" }; // r1을 깊은복사하고 Strstr값을 바꿈
            Console.WriteLine($" {"record",-10} {r1.Strstr,-10} {r1.Intint}");// record     two        2
            Console.WriteLine($" {"record",-10} {r3.Strstr,-10} {r3.Intint}");// record     two        2
            Console.WriteLine($" {"record",-10} {r4.Strstr,-10} {r4.Intint}");// record     another    2
        }
    }
}
```

<br>

# ※ 무명형식
형식의 선언과 동시에 객체를 할당한다.

무명형식의 프로퍼티에 할당된 값은 읽기전용이다.

```c#
namespace Program {
    class Program
    {
        static void Main(string[] args)
        {
            var anonymous = new 
            { 
                Name = "wonjin", 
                Jobs = new string[] 
                { 
                    "Student", "Labeler", "Developer" 
                } 
            };
            Console.WriteLine($"{anonymous.Name} {anonymous.Jobs}"); 
            // wonjin System.String[]

            foreach (var job in anonymous.Jobs)
            {
                Console.Write($"{job} "); // Student Labeler Developer
            }
        }
    }
}
```

<br>

# ※ 참고 사이트
- [공부하는 식빵맘](https://ansohxxn.github.io/c%20sharp/ch5-3/)
- [yiwonjin - C#프로그래밍 07 : 은닉성(캡슐화) + 프로퍼티, 레코드](https://velog.io/@yiwonjin/C%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D-07-%EC%9D%80%EB%8B%89%EC%84%B1%EC%BA%A1%EC%8A%90%ED%99%94-%ED%94%84%EB%A1%9C%ED%8D%BC%ED%8B%B0-%EB%A0%88%EC%BD%94%EB%93%9C)
- [어셈블리의 뜻과 접근제한자에 대한 설명](https://docs.microsoft.com/ko-kr/dotnet/csharp/programming-guide/classes-and-structs/access-modifiers)
- [C# 프로퍼티 사용하는 이유](https://www.codentalks.com/t/topic/8849)
- [개체 이니셜라이저를 사용하여 생성자 명시적호출 없이 프로퍼티 초기화](https://docs.microsoft.com/ko-kr/dotnet/csharp/programming-guide/classes-and-structs/how-to-initialize-objects-by-using-an-object-initializer)
- [Class의 Equals() 메소드가 참조를 비교한다고 판단한 근거](https://stackoverflow.com/questions/49997893/equal-for-class-objects-in-c-sharp)
- [C# 9 record에 대한 토론](https://forum.dotnetdev.kr/t/c-9-record/291/9)