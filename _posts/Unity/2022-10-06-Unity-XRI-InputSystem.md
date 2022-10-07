---
title:      XRI Input Action Custom Binding
date:       "2022-10-06"
categories: ["Unity", "XR Interaction Toolkit"]
tags:       ["Unity", "XR Interaction Toolkit"]
# pin:        true
---

XR Interaction Toolkit을 공부하면서, Action-Based와 Device-Based의 차이점 등을 공부하다 보니, Action-Based가 전반적으로 범용성이 크고 XRI 개발자들도 추천하고 있었다,

그래서 현재 진행중인 프로젝트도 Action-Based Controller로 변경했다. 하지만 잘 사용하던 XRInputManager.cs에서 액션 컨트롤러가 매핑되지 않던 것이다.

알고 보니 XRController 클래스는 Device-Based에서만 사용이 가능했던 것이었다.. 당연히 XRStatics.GetFeature 메서드를 사용하는 부분도 문제가 있을 것이므로 버튼 매핑하는 부분을 Action-Based가 바인딩하는 방법인 Input System으로 바꿔준다.

# 기존 바인딩 방법
Device-based를 사용할 때 사용하던 코드이다.
- [Will9371/Playcraft](https://github.com/Ugee0810/Unity-Template-character-controller-for-Unity-projects)

이 제작자의 바인딩 코드 모듈을 사용 했었다.

```c#
using System;
using UnityEngine;
using UnityEngine.Events;
using UnityEngine.XR;
using UnityEngine.XR.Interaction.Toolkit;

public class XRInputManager : MonoBehaviour
{
    [SerializeField] XRController controller;
    [SerializeField] XRBinding[] bindings;

    private void Update()
    {
        foreach (var binding in bindings)
            binding.Update(controller.inputDevice);
    }
}

[Serializable]
public class XRBinding
{
    [SerializeField] XRButton button;
    [SerializeField] PressType pressType;
    [SerializeField] UnityEvent OnActive;

    bool isPressed;
    bool wasPressed;

    public void Update(InputDevice device)
    {
        device.TryGetFeatureValue(XRStatics.GetFeature(button), out isPressed);
        bool active = false;

        switch (pressType)
        {
            case PressType.Continuous: active = isPressed; break;
            case PressType.Begin: active = isPressed && !wasPressed; break;
            case PressType.End: active = !isPressed && wasPressed; break;
        }

        if (active) OnActive.Invoke();
        wasPressed = isPressed;
    }
}

public enum XRButton
{
    Trigger,
    Grip,
    Primary,
    PrimaryTouch,
    Secondary,
    SecondaryTouch,
    Primary2DAxisClick,
    Primary2DAxisTouch
}

public enum PressType
{
    Begin,
    End,
    Continuous
}

public static class XRStatics
{
    public static InputFeatureUsage<bool> GetFeature(XRButton button)
    {
        switch (button)
        {
            case XRButton.Trigger: return CommonUsages.triggerButton;
            case XRButton.Grip: return CommonUsages.gripButton;
            case XRButton.Primary: return CommonUsages.primaryButton;
            case XRButton.PrimaryTouch: return CommonUsages.primaryTouch;
            case XRButton.Secondary: return CommonUsages.secondaryButton;
            case XRButton.SecondaryTouch: return CommonUsages.secondaryTouch;
            case XRButton.Primary2DAxisClick: return CommonUsages.primary2DAxisClick;
            case XRButton.Primary2DAxisTouch: return CommonUsages.primary2DAxisTouch;
            default: Debug.LogError("button " + button + " not found"); return CommonUsages.triggerButton;
        }
    }
}
```

# Action-Based
먼저 XRI 기본 세팅 에셋의 'XRI Default Input Actions' 오브젝트를 살펴보자. InputActionReference 클래스 구조로 Input System을 이용하는 것으로 보인다.

![image](https://user-images.githubusercontent.com/85896566/194319688-e22edab8-ad1e-4c54-8fed-38de16cab4bf.png)

새로운 Action Map을 만들어 준다. 이름은 Game이다. 그리고 하위의 액션으로 Pause라는 이름을 만들고 + 버튼을 눌러 바인딩을 추가한다.

![image](https://user-images.githubusercontent.com/85896566/194319544-abe4b01a-527f-4a34-a8a4-90a20d682c58.png)


![image](https://user-images.githubusercontent.com/85896566/194320436-8f622cd6-3ad5-4f68-a52d-8e3e9d1f2418.png)

나는 오큘러스 퀘스트2 기준으로 A, X 버튼과 키보드 'P'로 바인딩을 추가했다.

이제 이벤트 핸들러로 스크립트를 구성한다.

나의 경우 기존에 GameManager.cs에서 인풋 바인드로 일시정지 함수를 실행 했으므로 이번에도 게임 매니저에서 스크립팅 한다.

```c#
    /// 필드에 선언
    [Header("[InputActionReference]")]
    public InputActionReference gamePause = null;

    ...

    // [Onclick] 로비 ---> 인게임
    public void BtnPlay()
    {
        if (!TutorialManager.instance.isTutorial)
        {
            isStart = true;
            isRayState = false;
            /// 여기서 XRI_InGamePause() 이벤트 핸들러를 켜준다.
            gamePause.action.started += XRI_InGamePause;
        }
    }

    ...

    /// 콜백 함수는 여기, 실행 전 조건을 걸어둠으로 인게임 중에만 작동한다.
    // [XRI Input Action Binding(Primary Buuton)] 인게임 ---> 일시정지
    public void XRI_InGamePause(InputAction.CallbackContext context)
    {
        if (isStart && !isPause && !TutorialManager.instance.isTutorial)
        {
            isPause = true;
            isRayState = true;

            // Music Paused UI On
            uiPause.SetActive(true);

            // 플레이 중 노래 일시 정지
            Time.timeScale = 0;
            musicPlayed.Pause();
        }
    }

    ...

    /// 콜백 함수 종료 시점 1
    // [Onclick] 일시정지 ---> 메인
    public void BtnPauseBackLobby()
    {
        if (isStart && isPause)
        {
            [중략...]

            gamePause.action.started -= XRI_InGamePause;
        }

    /// 콜백 함수 종료 시점 2
    // [Event] 인게임 종료
    public void InGameEnd()
    {
        [중략...]

        gamePause.action.started -= XRI_InGamePause;
    }
```

게임 매니저에 만들어 둔 InputActionReference 잊지 않고 맵핑하기~
![image](https://user-images.githubusercontent.com/85896566/194322232-232d5b2d-2cea-4195-a6f0-a408a5b0a160.png)

# 결과
![image](https://user-images.githubusercontent.com/85896566/194322906-67ad1332-fc0e-40f3-a5a2-83da34234f4a.png)

# 참고 사이트
- [xr-controller-action-based/docs.unity3d.com](https://docs.unity3d.com/Packages/com.unity.xr.interaction.toolkit@2.0/manual/xr-controller-action-based.html)
- [Custom Input Actions for Unity XR](https://youtu.be/jOn0YWoNFVY)