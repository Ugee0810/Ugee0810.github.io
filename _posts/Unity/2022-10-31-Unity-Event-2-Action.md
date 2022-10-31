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
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
 
public class ActionAndRamda : MonoBehaviour
{
    // delegate void Action(); --> 이 부분이 using System 내부에 구현되어 있습니다.
    Action work;
 
    void Start ()
    {
        // MoveBricks() 라고 하면 함수가 실행되는 것이므로 MoveBricks 라고 적습니다.
        work += MoveBricks; 
        work += DigIn;
    }
 
    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
            work();
    }
 
    void MoveBricks()
    {
        Debug.Log("벽돌을 옮겼다.");
    }
 
    void DigIn()
    {
        Debug.Log("땅을 팠다.");
    }
}
```

<br>

# ※ Reference Site
- [유니티 이벤트 완벽하게 이해하기 4 - 액션과 람다 함수](https://daebalstudio.tistory.com/entry/%EC%95%A1%EC%85%98%EA%B3%BC-%EB%9E%8C%EB%8B%A4-%ED%95%A8%EC%88%98-%EC%99%84%EB%B2%BD%ED%95%98%EA%B2%8C-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0?category=698562)