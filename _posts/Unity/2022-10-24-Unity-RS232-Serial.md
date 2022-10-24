---
title:      Unity RS232 Serial(유니티 RS232 시리얼 통신)
date:       "2022-10-24"
categories: ["Unity", "RS232"]
tags:       ["Unity", "RS232"]
# pin:        true
---

# ※ Api Compatibility Level 설정
![image](https://user-images.githubusercontent.com/85896566/197428374-ee0de774-07a4-4672-a0df-b2dd4dbe00a0.png)

Project Setting - Player - Other Settings - Configuration - Api Compatibility Level - **.NET Framework**

# ※ DemoSerialCommuncation.cs
```c#
using UnityEngine;
using System;
using System.IO.Ports;

public class DemoSerialCommuncation : MonoBehaviour 
{ 
    SerialPort m_SerialPort = new SerialPort("COM3", 9600, Parity.None, 8, StopBits.One); 
    string m_Data = null; 

    void Start() 
    { 
        m_SerialPort.Open(); 
    } 

    private void Update() 
    { 
        try 
        { 
            if (m_SerialPort.IsOpen) 
            { 
                m_Data = m_SerialPort.ReadLine(); 
                m_SerialPort.ReadTimeout = 30; 
            } 
        } 

        catch (Exception e) 
        { 
            Debug.Log(e); 
        } 
    } 

    void OnApplicationQuit() 
    { 
        m_SerialPort.Close(); 
    } 
}
```

# ※ 참고 사이트
- [코더 제로 - [유니티 시리얼통신] RS232 시리얼 통신](https://coderzero.tistory.com/entry/%EC%9C%A0%EB%8B%88%ED%8B%B0-%EC%8B%9C%EB%A6%AC%EC%96%BC%ED%86%B5%EC%8B%A0-RS232-%EC%8B%9C%EB%A6%AC%EC%96%BC-%ED%86%B5%EC%8B%A0)