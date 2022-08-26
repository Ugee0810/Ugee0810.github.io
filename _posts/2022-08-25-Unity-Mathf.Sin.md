---
title:      Mathf.Sin()곡선을 이용해 간단한 물결 애니메이션 구현하기
date:       "2022-08-25"
categories: ["2022.08", "Unity"]
tags:       ["Unity"]
# pin:        true
---

# y = sin x

    다양한 수학 공식을 알고 있다면, 복잡한 애니메이션을 쉽게 구현할 수 있다.
    ※ 보통 에셋스토어에도 있음

sin 곡선의 공식을 이용해 위/아래 또는 좌/우로 부드럽게 움직이는 곡선 애니메이션 적용

![image](https://user-images.githubusercontent.com/110334366/186622466-7e481e38-4ba4-44da-bad6-a29a066a2782.png)

# 카메라가 이동 때 마다 물결 애니메이션 구현

```C#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraMove : MonoBehaviour
{
    float sin_val = 0;

    void Sin_wave_Compute() // y = Sin x (곡선 함수)
    {
        float _ry = Mathf.Sin(sin_val); // 3.14
        sin_val += 0.01f;
        m_cam.transform.Translate(0, _ry * 0.005f, 0);
    }

    public Camera m_cam;

    private void Update()
    {
        if (Input.GetKey(KeyCode.D))
        {
            m_cam.transform.position += m_cam.transform.right * Time.deltaTime * 2.0f;
            Sin_wave_Compute();
        }

        if (Input.GetKey(KeyCode.A))
        {
            m_cam.transform.position += -m_cam.transform.right * Time.deltaTime * 2.0f;
            Sin_wave_Compute();
        }

        if (Input.GetKey(KeyCode.W))
        {
            m_cam.transform.Translate(0, 0, Time.deltaTime * 2.0f);
            Sin_wave_Compute();
        }

        if (Input.GetKey(KeyCode.S))
        {
            m_cam.transform.Translate(0, 0, -Time.deltaTime * 2.0f);
            Sin_wave_Compute();
        }
    }
}
```