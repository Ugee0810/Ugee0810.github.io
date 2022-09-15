---
title:      OnEnable 함수를 이용한 점수 시스템 구현
date:       "2022-09-15"
categories: ["Unity"]
tags:       ["Unity"]
# pin:        true
---

# OnEnable()의 특징
```c#
    private void OnEnable()
    {
        // 게임 오브젝트 또는 스크립트가 Enable될 때마다 호출
        // 주로 사용자 정의 이벤트 연결에 사용
        // Coroutine으로 실행 불가능
    }
```

현재 프로젝트에선 양 쪽 컨트롤러의 트리거 유무에 따라 패널을 활성화/비활성화 하는 스크립트를 사용하고 있다. 다만 이 함수는 Update()에서 돌고 있기 때문에 스코어나 콤보 시스템을 동일한 if문에 적용하기엔 무리가 있다.

```c#
    void Check()
    {
        if (GameManager.instance.isSensorLeft && GameManager.instance.isSensorRight)
        {
            panelCheck.SetActive(true);
        }
        else if (GameManager.instance.isSensorLeft == false || GameManager.instance.isSensorRight == false)
            panelCheck.SetActive(false);
    }
```

이 스크립트는 활성화/비활성화 되는 오브젝트에 내장되어 있음.

```c#
public class PanelDestroy : MonoBehaviour
{
    private void OnTriggerEnter(Collider c)
    {
        if (c.gameObject.tag == "TRIGGER PANEL")
        {
            Destroy(c.gameObject);
        }
    }
}
```

그리고 그 오브젝트에 아래의 스크립트도 추가해준다.

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ScoreSystem : MonoBehaviour
{
    public static ScoreSystem instance;

    public GameObject scoreObj;
    Text textScore;
    int score = 0;

    private void Awake()
    {
        instance = this;
        textScore = scoreObj.GetComponent<Text>();
    }

    private void OnEnable()
    {
        IncreaseScore();
    }

    private void Start()
    {
        if (GameManager.instance.isStart)
        {
            SetText();
        }
    }

    public void IncreaseScore()
    {
        score += 1000;
        SetText();
    }

    public void SetText()
    {
        textScore.text = score.ToString();
    }
}

```

# 결과
![image](https://user-images.githubusercontent.com/85896566/190289442-81bd8eab-43e3-43ba-a83d-73e185c79358.png)

# Kcal 구현
내 프로젝트에선 스코어와 같이 소모된 칼로리도 제공해주어야 하므로 비슷한 로직으로 만들어준다.

```c#
public class ScoreSystem : MonoBehaviour
{
    public static ScoreSystem instance;


    public GameObject scoreObj;
    Text textScore;
    int score = 0;

    public GameObject kcalObj;
    Text textKcal;
    float kcal = 0;


    private void Awake()
    {
        instance = this;


        textScore = scoreObj.GetComponent<Text>();
        textKcal  = kcalObj.GetComponent<Text>();
    }

    private void OnEnable()
    {
        IncreaseScore();
        IncreaseKcal();
    }

    private void Start()
    {
        if (GameManager.instance.isStart)
        {
            SetScore();
            SetKcal();
        }
    }


    public void IncreaseScore()
    {
        score += 1000;
        SetScore();
    }

    public void SetScore()
    {
        textScore.text = score.ToString();
    }


    public void IncreaseKcal()
    {
        kcal += 0.4f;
        SetKcal();
    }

    public void SetKcal()
    {
        textKcal.text  = kcal.ToString();
    }
}
```

하지만 이렇게 실수형인 float 형을 선언하면 아래 사진과 같이 소수점 자리가 길게 나타난다.

![image](https://user-images.githubusercontent.com/85896566/190293570-b6232ce6-9070-4c6d-8b4e-079aeb959999.png)

소수점 자리 수를 지정하여 해결한다.

```c#
ToString("F")
ToString("F0") // 소수점을 표기하고싶지 않으면
ToString("F1") // 소수점 첫째자리까지 표기하고싶으면
ToString("F2") // 소수점 둘쨰자리까지 표기하고싶으면
```

# 전체 코드
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ScoreSystem : MonoBehaviour
{
    public static ScoreSystem instance;


    public GameObject scoreObj;
    Text textScore;
    int score = 0;

    public GameObject kcalObj;
    Text textKcal;
    float kcal = 0;


    private void Awake()
    {
        instance = this;


        textScore = scoreObj.GetComponent<Text>();
        textKcal  = kcalObj.GetComponent<Text>();
    }

    private void OnEnable()
    {
        IncreaseScore();
        IncreaseKcal();
    }

    private void Start()
    {
        if (GameManager.instance.isStart)
        {
            SetScore();
            SetKcal();
        }
    }


    public void IncreaseScore()
    {
        score += 1000;
        SetScore();
    }

    public void SetScore()
    {
        textScore.text = score.ToString();
    }


    public void IncreaseKcal()
    {
        kcal += 0.4f;
        SetKcal();
    }

    public void SetKcal()
    {
        textKcal.text  = kcal.ToString("F1");
    }
}
```

# 결과
![image](https://user-images.githubusercontent.com/85896566/190296818-8f6a8ba2-1851-4fe2-9d7f-62cdbee291d1.png)

# 참고 사이트
- [C# 소수점 자리수 정리](https://td7studios.tistory.com/entry/C-%EC%86%8C%EC%88%98%EC%A0%90-%EC%9E%90%EB%A6%AC%EC%88%98-%EC%A0%95%EB%A6%AC)