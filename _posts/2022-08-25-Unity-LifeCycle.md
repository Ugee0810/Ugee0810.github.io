# Unity LifeCycle(유니티 생명주기)

## ※ 참고 사이트

- [Unity Documentation (스크립팅 개념 - 이벤트 함수의 실행 순서)](https://docs.unity3d.com/kr/2021.3/Manual/ExecutionOrder.html)

---

<br>

## ※ Unity LifeCycle(유니티 생명주기)

![image](https://user-images.githubusercontent.com/110334366/186574114-1d8fdebe-e0cd-4697-940f-027cd1f26be6.png)

---

<br>

## ※ 생명주기별 주의할 점 | 최적화

    - Find()는 최대한 사용하지 않는다.
    - 'GetComponent'는 Update()에서 사용하지 않도록 한다. 반면, Start()에선 성능 저하가 덜하므로 사용해도 된다.