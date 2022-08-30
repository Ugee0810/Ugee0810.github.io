---
title:      TimeScale을 이용한 일시정지 기능 만들기
date:       "2022-08-30"
categories: ["Unity"]
tags:       ["Unity"]
# pin:        true
---

# Time.timeScale
Project Setting - Time의 Time Scale과 동일

![image](https://user-images.githubusercontent.com/110334366/187327789-0b5af8be-af9c-4005-847e-ee4e9a5206ee.png)


통상적인 게임 속도는 1이다.

그러므로 1을 0으로 바꾼다면 일시 정지가 된다.

```C#
Time.timeScale = 0;
```

타임 스케일을 0으로 두고 메뉴 UI가 나왔을 때 메뉴를 선택하는 작동 등은 가능하다.

0.5를 한다면 2분의 1 속도를 연출할 수 있다.(슬로우모션)

게임의 연산 중 시간의 변화에 따라 연산이 되는 부분들을 제어하게 될 수 있는 것 같다.

이걸로 프로젝트에선 게임 진행 중에 패널과 시간 등을 멈추게 하고 Pause UI 출력해 봐야겠다!

<br>

---

# 참고 사이트
- [Technical Artist의 기록](https://mgtul.tistory.com/86)