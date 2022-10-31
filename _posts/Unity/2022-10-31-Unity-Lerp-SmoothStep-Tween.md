---
title:      Unity Mathf.Lerp, Slerp, Tween, SmoothStep(유니티 선형 보간, 구면 선형 보간의 정확한 사용법, Tween과 SmoothStep)
date:       "2022-10-31"
categories: ["Unity"]
tags:       ["Unity"]
# pin:        true
---

# ※ Practical Environment
- Unity Editor Version - 2021.3.11f1

<br>

# ※ Intro
유니티의 Vector3 에는 Lerp, Slerp라는 함수가 있다.

두 함수 모두 선형보간을 해서 두 지점사이의 위치를 계산하는 함수지만 두 함수 사이에는 큰 차이가 있다.

그리고 이 차이를 이해하려면 우선 선형 보간과 구면 선형 보간의 차이를 이해해야 한다.

## 선형 보간 (Linear interpolate)
![image](https://user-images.githubusercontent.com/85896566/198969164-dcd68aa1-0050-478f-b4f0-e3c9e94496c8.png)

두 지점을 선형으로 연결해서 두 지점사이의 위치를 파악하는 방법이다.

유니티에서 사용할 때는 a와 b 지점 사이의 길이를 1로 두고, f값에 따라 그에 비례한 위치를 Vector3로 반환한다고 생각하면 된다.

## 구면 선형 보간 (Spherically interpolate)
![image](https://user-images.githubusercontent.com/85896566/198969188-423da823-ff4a-4e93-bb7e-d69590af6652.png)

구면 선형 보간은 두 지점 사이의 위치를 파악한다는 것은 같지만, 곡선으로 파악하기 때문에 선형 보간보다 조금 더 어렵다.

사실 아까 보았던 선형보간을 벡터로 설명하자면 이런 그림이다.

이러한 보간 방법은 평면 위에서는 정확하게 작동하지만, 만약 a와 b가 평평한 면이 아닌, 곡면 위의 점이라면 이야기가 달라진다.

우리의 키가 수천Km로 커지거나, 지구의 반경이 매우 작아져서 어린왕자의 별같이 변했다고 가정해보자.

![image](https://user-images.githubusercontent.com/85896566/198969355-bd9d03b4-76e9-47b8-a7dd-d7c9d2d03c58.png)

a는 서울이고, b는 런던이다. 우리는 서울부터 런던까지의 길이를 선형보간 해서 3등분을 하고, 걸어가기로 했다.

그렇다면 우리는 첫 날과 마지막 날은 쉬엄쉬엄 간다고 해도 두 번째 날 하루종일 걸어도 계획한 거리만큼 걸어갈 수 없을지도 모른다. 왜냐하면 우리는 곡면위에 있기 때문에 선형적인 보간으로는 실제 거리를 정확하게 나눌 수 없기 때문이다.

그래서 등장한 개념이 구면 선형 보간이다.

단순히 a와 b 두 점 사이의 거리를 나눠서 위치를 얻는 것이 아닌, a와 b가 구체평면 위에 위치한다고 가정한 후, 호의 거리를 선형적으로 보간해서 위치를 얻어내는 것이다.

그러므로 구면 선형 보간을 하는 경우, a와 b사이의 직선 거리를 보간하지 않고, a와 b사이에 포물선이 만들어진 후 그 포물선 위를 보간하는 것이다.

 
### 정리
- 선형 보간 => 평평한 면 위 
- 구면 선형 보간 => 구면 위

<br>

# ※ Apply
많은 사람들이 UI등의 부드러운 움직임을 위해 Lerp를 제대로 사용하지 않고 있다.

```c#
using UnityEngine;

public class FollowCamera : MonoBehaviour
{
    public Transform startPosition;
    public Transform endPosition;

    private void Start()
    {
        this.transform.position = startPosition.position;
    }

    private void Update()
    {
        this.transform.position = Vector3.Lerp(this.transform.position, endPosition.position, 10 * Time.deltaTime);
    }
}
```

보통의 사람들은 이런 식으로 Time.deltaTime 등을 사용해 UI를 목표 지점까지 도달하게 한다.

그러나 만약 정확히 0.5초가 경과했을 때 지정된 위치에 도달하게 하려면 어떻게 해야할까?

위의 코드를 통해 수정하려면 겨우겨우 여러 조건문을 사용하여 맞추어야 할 것이다. 하지만 결국 그 마저도 정확하지 않고 미세한 오차가 있을 수 밖에 없다.

또한 수정할 때마다 또 계산하는데 그 만큼 소요 시간이 증가한다.

그래서 요즘은 대부분 에셋스토어에서 'Tween'을 검색하면 나오는 에셋들로 편하게 선형 보간을 사용하고 있다.

![image](https://user-images.githubusercontent.com/85896566/198971197-b8557e10-df23-4068-8dd9-80c09a8f2b5e.png)

그럼 이제부터 Vector3를 통해 Lerp를 살펴본다.

![image](https://user-images.githubusercontent.com/85896566/198971062-9de7f13b-242e-452e-bf19-fcb542398747.png)

인자의 1, 2번째인 시작 좌표를 0, 끝 좌표를 1로 취급하고 3번째 인자인 보간 값 0~1에 따라 위치 값을 결정한다.

아래의 사진은 3번째 인자를 0.5로 두었을 때의 예시이다. 정확하게 절반의 위치를 알 수 있다.

![image](https://user-images.githubusercontent.com/85896566/198971564-b1fa8f35-fbea-4fa4-826a-11bba692d536.png)

```c#
using UnityEngine;

public class FollowCamera : MonoBehaviour
{
    public Transform startPosition;
    public Transform endPosition;

    private void Start()
    {
        this.transform.position = startPosition.position;
    }

    private void Update()
    {
        this.transform.position = Vector3.Lerp(this.transform.position, endPosition.position, 10 * Time.deltaTime);
    }
}
```

그럼 다시 이 코드를 이해하면 Time.dletaTime(기본 값 0.02f)에 10을 곱해 0.2f가 됩니다. 이것부터 사실 문제가 됩니다.

두 번재 문제는 시작 좌표가 고정된 좌표가 아닌 단순한 현재 위치를 값으로 넣었기 때문에 시작 좌표가 매번 달라지게 됩니다.

![image](https://user-images.githubusercontent.com/85896566/198972172-5938f319-00b7-45cb-a31f-efe563589895.png)

위 사진처럼 한 프레임에서 0.2f 위치로 보간되었을 때 시작 좌표가 변경되게 되는 것입니다. 그럼 다음 프레임에선 사진의 0좌표를 시작 좌표의 기준이 되어 또 부정확한 0.2f의 거리를 보간하게 됩니다.

![image](https://user-images.githubusercontent.com/85896566/198972629-77060d0b-1202-42ad-93d4-41e279413cbc.png)

![image](https://user-images.githubusercontent.com/85896566/198972665-8e9ca7b9-1e91-42cf-8f84-eff28d1bbc98.png)

따라서 정확한 계산을 위해 코드를 수정해야합니다. 먼저 시작 좌표를 변경합니다. 지금의 위치가 아닌 고정된 위치(startPosition.position)로 변경합니다. 이 시작 좌표는 항사 변하지 않도록 하는 게 중요합니다.

위의 코딩에선 start와 end 게임 오브젝트를 만들어주어 public으로 할당해주었습니다.

두 번째로 보간 값을 수정합니다.

```c#
using UnityEngine;

public class FollowCamera : MonoBehaviour
{
    public Transform startPosition;
    public Transform endPosition;

    // 진행될 총 시간 (public으로 접근을 설정해 에디터에서 수정하도록 함)
    public float lerpTime = 0.5f;
    // 경과 카운트
    float currentTime = 0f;

    private void Start()
    {
        this.transform.position = startPosition.position;
    }

    private void Update()
    {
        currentTime += Time.deltaTime;

        if (currentTime >= lerpTime)
        {
            currentTime = lerpTime;
        }
        // currentTime / lerpTime <--- 프레임마다 0부터 1까지 서서히 증가하는 형태
        this.transform.position = Vector3.Lerp(startPosition.position, endPosition.position, currentTime / lerpTime);
    }
}
```

아까 전 코드는 시작 지점이 현재 위치였고, Time.dletaTime을 이용해 보간하다 보니 도착 지점에 가까워질 수록 서서히 느려졌었습니다. 이젠 고정된 좌표에서 보간값이 항상 일정하기 때문에 일정한 등속을 유지합니다.

만약 아까 전 처럼 도착 지점에 가까워질 수록 느려지게 하고 싶다면 어떻게 해야할까요?

여기선 SmoothStep이라는 수학적인 원리를 사용합니다. 아래의 주소에 들어가서 수식을 참고할 수 있습니다.

## ※ SmoothStep
- [How to Lerp like a pro](https://chicounity3d.wordpress.com/2014/05/23/how-to-lerp-like-a-pro/)

![image](https://user-images.githubusercontent.com/85896566/199003909-f65a3ae1-5556-47a3-a34e-44cdd150556f.png)

노란색으로 표시한 부분을 복사하여 사용해줍니다.

빨간 줄로 표시되어 있는 부분부터 시작 좌표입니다.


```c#
using UnityEngine;

public class FollowCamera : MonoBehaviour
{
    public Transform startPosition;
    public Transform endPosition;

    // 진행될 총 시간
    float lerpTime = 0.5f;
    // 경과 카운트
    float currentTime = 0f;

    private void Start()
    {
        this.transform.position = startPosition.position;
    }

    private void Update()
    {
        currentTime += Time.deltaTime;

        if (currentTime >= lerpTime)
            currentTime = lerpTime;

        float t = currentTime / lerpTime;

        t = t * t * t * (t * (6f * t - 15f) + 10f);

        this.transform.position = Vector3.Lerp(startPosition.position, endPosition.position, t);
    }
}
```

float형 t를 생성하여 기존 보간값을 저장하고 SmoothStep을 전개한 t를 보간 값에 적용합니다.

```c#
using System.Collections;
using UnityEngine;
using UnityEngine.UI;

public class FollowCamera : MonoBehaviour
{
    public Transform startPosition;
    public Transform endPosition;

    Button btn;

    // 진행될 총 시간
    float lerpTime = 0.5f;
    // 경과 카운트
    float currentTime = 0f;

    private void Start()
    {
        this.transform.position = startPosition.position;
        
        // OnClick() Lambda
        btn.onClick.AddListener(() => { StartCoroutine(LerpTest()); });
    }

    IEnumerator LerpTest()
    {
        currentTime += Time.deltaTime;
        if (currentTime >= lerpTime) currentTime = lerpTime;
        float t = currentTime / lerpTime;
        t = t * t * t * (t * (6f * t - 15f) + 10f);
        this.transform.position = Vector3.Lerp(startPosition.position, endPosition.position, t);
        yield return null;
    }
}
```

최종 코드입니다. Update()에서 매 프레임마다 돌려주는 것 보다 코루틴으로 만들어 특정 이벤트에 의해 실행해주는 방식이 선호되기 때문에 이 코드에선 Button 컴포넌트의 OnClick() 리스너에 람다식으로 매핑해주었습니다.

<br>

# ※ Reference Site
- [오늘코딩 - [유니티] Lerp를 프로처럼 사용하는 방법](https://youtu.be/_QOvSLCXm7A)
- [[유니티] Lerp 와 Slerp 의 차이 - 선형 보간, 구면 선형 보간](https://gnaseel.tistory.com/14)
- [How to Lerp like a pro](https://chicounity3d.wordpress.com/2014/05/23/how-to-lerp-like-a-pro/)