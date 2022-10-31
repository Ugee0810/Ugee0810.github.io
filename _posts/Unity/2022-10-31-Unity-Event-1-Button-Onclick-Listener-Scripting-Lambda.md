---
title:      Unity Event 1 - Button Onclick Listener Scripting + Lambda(유니티 이벤트 1 - 버튼 스크립트로 매핑하기 (온클릭 리스너) + 람다식)
date:       "2022-10-31"
categories: ["Unity"]
tags:       ["Unity"]
# pin:        true
---

# ※ Practical Environment
- Unity Editor Version - 2021.3.11f1

<br>

# ※ Intro
## 버튼에 이벤트 할당하기
유니티에서 UI에 동작을 할당 할 때는 간편하게 인스펙터에서

버튼 컴포넌트에 노출되어있는 UnityEvent에 할당하는 방법이 있다.
 

쉽고 간편해서 많은 유니티 튜토리얼에서 사용되는 방법이지만,

이 방법은 두 가지 단점이 있다.


1. 할당된 메서드가 visual studio에서 레퍼런스 참조가 안되며,

2. 미리 할당해놔야하기 때문에 동적으로 버튼의 동작을 바꿀 수 없다. 

<br>

# ※ Apply
## AddListener로 버튼에 이벤트 할당하기
때문에 이를 해결하기 위해 Button에 onClick.AddListener(델리게이트) 형식으로 메서드를 할당하는 방법이 있다.


### 인자가 없는 메서드 예시
```c#
void Awake()
{
    // 인자가 없는경우 바로 메소드 이름으로 넘겨주면됨.
    button.onClick.AddListener(PressBtnClose);
}
    
void PressBtnClose() // 인자가 없는 메소드
{

}
```

### 인자가 있는 메서드 예시
```c#
void Awake()
{
    // 인자가 있는 경우 람다 식이나 델리게이트를 사용
    button.onClick.AddListener(() => OpenTab(0));
    button.onClick.AddListener(delegate { OpenTab(0); });
}

void PressBtnTab(int tabIndex) // 인자가 있는 메소드
{
}
```

<br>

# ※ 주의사항
for 문 루프 + 람다식으로 Add Listener를 할 경우, 클로저 문제가 발생하여 제대로 할당이 되지 않을 우려가 있다.

## * 문제는 무엇인가?
버튼을 배열로 선언해놓고

for문에서 AddListener로 할당하려고 했는데, 

모두 마지막 값으로 초기화되는 현상이 있었다.

for (int i = 0; i < Btns.Length; i++)
{
    Btns[i].onClick.AddListener(() => PressBtnSelectGame(i));
}
 

0, 1, 2 .. 순서대로 초기화되는 것이 아니다.

## * Closure Problem
람다식은 실제 실행되기 전에는 참조형태로 가지고있는데,

for문을 돌리면서 같은 변수인 i를 계속 줬기 때문에 마지막 값으로 통일된 것.

이를 closure problem이라고 부른다.

## * 해결방법
아래와 같이 수정하면 된다. (혹은 각각을 직접 숫자를 넣어 하드코딩으로 써주자)

```c#
for (int i = 0; i < Btns.Length; i++)
{
    int temp = i; // Closure 문제때문에 복사해서 사용한다.
    Btns[temp].onClick.AddListener(() => PressBtnSelectGame(temp));
}
```

<br>

# ※ 후기
나 또한 진행중인 프로젝트에서 for문으로 람다식을 돌리려고 했지만 모두 마지막 버튼 이벤트로만 매핑이 되는 것이었다.(클로저)

그래서 나의 해결 방법으로는 int 인자를 받는 함수를 만들어 람다식을 만들어주고 그 함수를 for문으로 돌렸더니 정상적으로 되는 것이었다.

```c#
        // Btn Mode - Panel Speed, Music Length, Obstacle
        void BtnModes(int i) { btnModes[i].onClick.AddListener(() => OnClick_Mode(btnModes[i], btnModes, infoImages, infoTmp_Text, sFX[0])); }
        for (int i = 0; i < btnModes.Length; i++)
            BtnModes(i);
```

# ※ Reference Site
- [Unity UI Button onClick.AddListener 활용하기](https://mentum.tistory.com/379)
- [for 문에서 AddListener 람다식은 주의해야한다. (AddListener for loop)](https://mentum.tistory.com/343)