---
title:      VR Keyboard | Unity Tutorial for Oculus Quest(유니티 XR 키보드 만들기)
date:       "2022-10-04"
categories: ["Unity", "VR"]
tags:       ["Unity", "VR"]
# pin:        true
---

# 준비물 세팅
아래의 패키지를 프로젝트에 임포트
- [Download VR Button Package](https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbXRKQkFFQUFVZzZoWkZVR3ZjMXZ2Zk5YWWpqUXxBQ3Jtc0tsLWN6Q1RzNy1qRk8tZjJqbkpfU2lvUGdxN3RUUFdHMXhfZUxtZmlSUlZCTEhPMGx6dXJjX1RsUzNUZXpJWjJhTldBSUxtaHdkbnRMajMzV2hDMFJ0dDJPVGRVc3RPTzRrT2wxbDY1OVRjdWEzUmtUQQ&q=https%3A%2F%2Fwww.realary.com%2Fyt%2FVRButton.unitypackage&v=PyKW9kecyqg)

![image](https://user-images.githubusercontent.com/85896566/193779707-f641a962-53c5-48c3-8bec-9466e8a4b6f7.png)

## 레이어 지정
아래 사진처럼 네 개의 레이어 지정

### Tags and Layers
- Hands
- Interactive
- Typing Hands
- Keyboard

![image](https://user-images.githubusercontent.com/85896566/193780989-7f807c04-ea95-4893-8870-1cd704db2fa2.png)

### Physics
![image](https://user-images.githubusercontent.com/85896566/193781800-b910df6e-b24f-4bec-a5c5-d1c468b75543.png)

# 키보드 제작
## 오브젝트 추가
- 빈 오브젝트(Keyboard)
  - 3D Cube(Board) 생성 후 포지션 (1, 0.05, 0.4) 지정, Gray 머티리얼 적용

![image](https://user-images.githubusercontent.com/85896566/193782384-713072dc-455c-422d-9223-b7c23c083008.png)

- 빈 오브젝트(Buttons)
  - 빈 오브젝트(Normal)
    - 빈 오브젝트(Numbers)
      - 프리팹(Square Button) ---> 포지션 y 0.03 / 언팩하기 / 이름 변경(KeyboardButton)
- 빈 오브젝트(Typing Area)

![image](https://user-images.githubusercontent.com/85896566/193783114-885f4a0a-9176-4e5f-9a3f-7916b6e870ac.png)

![image](https://user-images.githubusercontent.com/85896566/193957739-18ce2ec9-65af-4068-9267-e595b5719d53.png)

KeyboardButton 자식으로 Text 생성

![image](https://user-images.githubusercontent.com/85896566/193958181-26ece224-fe4f-44af-9a4d-e7ef08543690.png)

캔버스와 텍스트 인스펙터 변경

![image](https://user-images.githubusercontent.com/85896566/193959838-a9f1443a-8728-418e-bd27-d3b5eb7094f2.png)
![image](https://user-images.githubusercontent.com/85896566/193959936-698f7392-06b6-4531-b136-dd644bc5124f.png)
![image](https://user-images.githubusercontent.com/85896566/193960106-8991a812-b599-4054-94fb-e52054025c95.png)

캔버스를 Press 하위로 이동

![image](https://user-images.githubusercontent.com/85896566/193960233-9b92d5ca-066f-49df-8a15-ec8be0c50ec1.png)

Collider 오브젝트 컴포넌트에 기존 On Release() 이벤트 삭제

![image](https://user-images.githubusercontent.com/85896566/193960401-43ca9985-066c-458d-bde7-b5225c55cdbd.png)

- Keyboard.cs ---> Keyboard 오브젝트에 지정
```c#
using UnityEngine;
using TMPro;

public class Keyboard : MonoBehaviour
{
    public TMP_InputField inputField;
    public GameObject normalButtons;
    public GameObject capsButtons;

    bool caps;

    private void Start()
    {
        caps = false;
    }

    public void InsertChar(string c)
    {
        inputField.text += c;
    }

    public void DeleteChar()
    {
        if (inputField.text.Length > 0)
        {
            inputField.text = inputField.text.Substring(0, inputField.text.Length - 1);
        }
    }

    public void InsertSpace()
    {
        inputField.text += " ";
    }

    public void CapsPressed()
    {
        if (!caps)
        {
            normalButtons.SetActive(false);
            capsButtons.SetActive(true);
            caps = true;
        }
        else
        {
            normalButtons.SetActive(true);
            capsButtons.SetActive(false);
            caps = false;
        }
    }
}
```

- KeyboardButton.cs ---> KeyboardButton 오브젝트에 지정
```c#
using TMPro;
using UnityEngine;

public class KeyboardButton : MonoBehaviour
{
    Keyboard Keyboard;
    TextMeshProUGUI buttonText;

    private void Start()
    {
        Keyboard = GetComponentInParent<Keyboard>();
        buttonText = GetComponentInChildren<TextMeshProUGUI>();
        if (buttonText.text.Length == 1)
        {
            NameToButtonText();
            GetComponentInChildren<ButtonVR>().onRelease.AddListener(delegate { Keyboard.InsertChar(buttonText.text); });
        }
    }

    public void NameToButtonText()
    {
        buttonText.text = gameObject.name;
    }
}
```

- TypingArea.cs ---> Typing Area 오브젝트에 지정
```c#
using UnityEngine;

public class TypingArea : MonoBehaviour
{
    public GameObject leftHand;
    public GameObject RightHand;
    public GameObject LeftTypingHand;
    public GameObject RightTypingHand;

    private void OnTriggerEnter(Collider c)
    {
        GameObject hand = c.gameObject;
        if (hand == null)
            return;
        if (hand == leftHand)
            LeftTypingHand.SetActive(true);
        else if (hand == RightHand)
            RightTypingHand.SetActive(true);
    }

    private void OnTriggerExit(Collider c)
    {
        GameObject hand = c.gameObject;
        if (hand == null)
            return;
        if (hand == leftHand)
            LeftTypingHand.SetActive(false);
        else if (hand == RightHand)
            RightTypingHand.SetActive(false);
    }
}
```

KeyboardButton 오브젝트 프리팹화

![image](https://user-images.githubusercontent.com/85896566/193970589-5c25e62d-bb1d-4072-8658-957b79b48518.png)

### 숫자 자판 만들기
아래의 1번 포지션부터 x -0.06씩 10번까지 생성

![image](https://user-images.githubusercontent.com/85896566/193979614-7792a262-10c7-414f-8e7c-9fd042597255.png)

### 문자 자판 만들기
Numbers 오브젝트를 복사한 Letter 오브젝트 생성 후 빈 오브젝트(Row 1) 만들어서 버튼들을 하위로 넣는다.

![image](https://user-images.githubusercontent.com/85896566/193988965-45e89ec3-81f3-4d30-ba4a-e9a189ac7000.png)

y -0.6씩 더해서 각각 이름을 변경한다.

![image](https://user-images.githubusercontent.com/85896566/193990176-6e8b41a4-18df-46bb-ba81-71a9f932bed8.png)

실행 화면

![image](https://user-images.githubusercontent.com/85896566/193990211-d2202f76-80c7-4532-8886-12c2d19402fd.png)

normal 하위에 있던 numbers를 빼준다.

![image](https://user-images.githubusercontent.com/85896566/193990435-6922a106-48fb-4c45-9565-81a585b638bd.png)

### 대/소문자 변환 자판 만들기
normal을 복사하고 복사한 오브젝트의 이름은 'Cpas'로 변경한다.

이후 네임도 대문자로 변경 ---> 실행해본다.

![image](https://user-images.githubusercontent.com/85896566/193990743-ae873780-8a05-4dc7-96be-2cb6fe8a7bac.png)

캡스락 변경 버튼을 만든다.

프로젝트 뷰로 빼 두었던 'KeyboardButton' 프리팹을 normal 하위에 불러오고 언팩한다.

이름은 'Caps Button'으로 변경 후 포지션(-0.4, 0.03, 0.04) / 스케일 (2, 1, 1)로 변경한다.

텍스트도 길어지므로 텍스트 스케일만 (0.5, 1, 1)로 변경해준다.

![image](https://user-images.githubusercontent.com/85896566/193991451-314628f0-6ac7-4485-9720-5607b788854d.png)

그리고 하위 collider의 On Release() 이벤트에 KeyboardCapsPressed()를 매핑한다.

![image](https://user-images.githubusercontent.com/85896566/193991727-4d018312-5044-4670-b8a1-d6990fc45ab3.png)

### Delete 자판 만들기
대/소문자 변환 자판을 복사한다. 포지션은 (0.34, 0.03, 0.04) / 콜라이더에 Keyboard.DeleteChar()를 맵핑한다.

![image](https://user-images.githubusercontent.com/85896566/193992225-56d82deb-3f5e-48b3-a023-c43e33e27175.png)
![image](https://user-images.githubusercontent.com/85896566/193992307-990ea99c-b22a-489f-9be0-d3df8b950ce7.png)

### Space 자판 만들기
Delete 변환 자판을 복사한다. 포지션은 (-0.06, 0.03, -0.14) / 콜라이더에 Keyboard.InsertSpace()를 맵핑한다.
![image](https://user-images.githubusercontent.com/85896566/193992743-70434b5a-f1fe-4ace-91bf-2af6e7ed3d67.png)
![image](https://user-images.githubusercontent.com/85896566/193992777-07589953-f7e4-46bd-9e06-0818edb6c6e0.png)

지금까지의 최종 오브젝트의 모습과 Keyboard 매핑이다.

![image](https://user-images.githubusercontent.com/85896566/193993210-b17b9820-8a37-4120-81fe-0b09277178b3.png)

### 타이핑 필드 만들기
- Typing Area
  - 3D Cube(Typing Collider)의 스케일은 Board의 스케일을 복사해서 붙여 넣어 준다.

  ![image](https://user-images.githubusercontent.com/85896566/193993591-5963753e-8c69-4183-9a51-d12fa57a0fae.png)

Typing Collider의 컴포넌트 중 메쉬 필터와 렌더러를 삭제하고 박스 콜라이더 사이즈가 5를 초과하지 않을 범위로 늘려준다. 그리고 isTrigger를 체크해준다.(사진에는 언체크 되어있음)

![image](https://user-images.githubusercontent.com/85896566/193995866-05b7c0a3-0ea0-483e-aaec-c783b0237c63.png)

이후 부모부터 키보드 레이어로 설정, 타이핑 에어리어 레이어는 인터렉티브로 설정

![image](https://user-images.githubusercontent.com/85896566/193996212-0ed5165c-23ff-4b43-8be0-84120b3128cd.png)
![image](https://user-images.githubusercontent.com/85896566/193996277-248f6a5a-9aee-4cc6-81ce-4c9060622ebd.png)

### 모니터 만들기
인풋필드가 중요하므로 UI 캔버스 / 이미지/ 인풋필드를 배치한 뒤 키보드의 스크립트에 매핑한다.

![image](https://user-images.githubusercontent.com/85896566/193997265-26cfef58-08f4-4720-bf42-196ee11f2f59.png)

### 매핑
동영상에선 OVR SDK를 이용하지만 나는 XRI 기반 프로젝트를 제작하고 있으므로 이제부턴 다른 방법으로 진행한다.

먼저 핸드 콘트롤러 부모에게 Hands 레이어를 지정한다.

![image](https://user-images.githubusercontent.com/85896566/193998200-977f59f9-2d5a-40ea-9e08-4183d108ac79.png)

이후 빈 오브젝트를 핸드 콘트롤러 자식으로 만들고 콜라이더 지점을 만든 뒤 타이핑 핸드 레이어를 지정한다. 마지막으로 비활성화해준다.

![image](https://user-images.githubusercontent.com/85896566/193998112-9abf718b-7125-43e6-bf20-0603d8f990fe.png)

이후 매핑

![image](https://user-images.githubusercontent.com/85896566/193998674-3209666b-3987-477b-b51c-f8c224e2b63f.png)

### 나머지 설정
- Caps 오브젝트는 비활성화 해준다.
- Typing Area에 Rigidbody를 넣어주고 중력 언체크, 키네마틱 체크한다.
- 키보드 버튼 프리팹 내부에서 콜라이더를 그림과 같이 변경해준다.

![image](https://user-images.githubusercontent.com/85896566/193999129-aa135e0d-33e2-4e30-915d-4f829e3825b0.png)

# 결과
![image](https://user-images.githubusercontent.com/85896566/194004230-0707e2b8-35ef-4042-b65e-aee8b428c7da.png)

# 참고 사이트
- [VR Keyboard | Unity Tutorial for Oculus Quest](https://youtu.be/PyKW9kecyqg)