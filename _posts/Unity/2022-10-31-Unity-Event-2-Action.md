---
title:      Unity Event 2 - Action
date:       "2022-10-31"
categories: ["Unity"]
tags:       ["Unity"]
# pin:        true
---

# ※ Practical Environment
- Unity Editor Version - 2021.3.11f1

<br>

# ※ Intro
## **Action**
- 입력, 리턴 값이 없는 델리게이트 타입

코딩을 하다보면 "리턴값이 void 이고 입력값이 없는 함수형"을 델리게이트로 사용할 일이 많습니다.

그래서 처음부터 이런 타입을 Using System 내부에 만들어 놓았는데 이것을 Action이라고 합니다.

즉 단순히 델리게이트를 편하게 사용하기 위한 단축키 라고 생각하시면 되겠네요.

<br>

# ※ Apply
## 1번째 방법(대리자)
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System; // <--- Action 클래스를 사용하기 위해 필수 선언

public class Action : MonoBehaviour
{
    // delegate void Action(); --> 이 부분이 using System 내부에 구현되어 있습니다.
    Action work;

    void Start ()
    {
        // MoveBricks() 라고 하면 함수가 실행되는 것이므로 MoveBricks 라고 적습니다.
        work += MoveBricks;
        work += DigIn;
    }

    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
            work();
    }

    void MoveBricks()
    {
        Debug.Log("벽돌을 옮겼다.");
    }

    void DigIn()
    {
        Debug.Log("땅을 팠다.");
    }
}
```

## 2번째 방법(람다식) <--- 추천
```c#
using System // <--- 역시 Action 클래스를 사용하기 위해 필수 선언
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Target : MonoBehaviour // <--- 오리진 클래스에서 실행될 타겟 클래스
{
    public static Action target; // <--- 액션 클래스 필드 선언
    
    void Awake()
    {
        target = () => { }; // <--- 람다식 사용

        target = () =>
        {
            Mission();
            Text();
        };
    }

    public void Mission()
    {
        Debug.Log("미션 성공");
    }

    public void Text()
    {
        Debug.Log("여러 개도 가능~!");
    }
}

```

<br>

# ※ Reference Site
- [유니티 이벤트 완벽하게 이해하기 4 - 액션과 람다 함수](https://daebalstudio.tistory.com/entry/%EC%95%A1%EC%85%98%EA%B3%BC-%EB%9E%8C%EB%8B%A4-%ED%95%A8%EC%88%98-%EC%99%84%EB%B2%BD%ED%95%98%EA%B2%8C-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0?category=698562)
- [오늘코딩 - [유니티꿀팁] 다른 스크립트의 함수를 쉽게 가져오는 방법](https://youtu.be/3lBuHT3HM-Q)