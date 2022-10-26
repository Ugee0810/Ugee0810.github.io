---
title:      Unity Arduino Serial(유니티 아두이노 시리얼 통신)
date:       "2022-10-21"
categories: ["Unity", "Arduino"]
tags:       ["Unity", "Arduino"]
# pin:        true
---

# ※ 닷넷 4.0 이상 설정하기
System.IO.Ports 네임스페이스를 사용하기 위해 변경 해주어야 한다.

![image](https://user-images.githubusercontent.com/85896566/197150489-4b6eca3d-a59f-43b5-8a5a-09f22938d924.png)

# ※ 스크립트
아래의 스크립트는 피에조 스피커의 프리퀀시를 8개로 받고 유니티 앱에서 지정된 키보드에 따라 계이름 소리를 출력한다.

```c#
/// [UNITY]Arduino.cs

using UnityEngine;
/// using System.IO.Ports 선언
using System.IO.Ports;

public class Arduino : MonoBehaviour
{
    /// 시리얼 포트 생성
    /// 포트 번호, 비트레이트를 맞춰준다. 뒷 부분은 우노 기준의 설정
    SerialPort SerialPort1 = new SerialPort("COM4", 9600, Parity.None, 8, StopBits.One);

    void Start()
    {
        /// 시리얼 포트 연결 시도
        SerialPort1.Open();
    }

    /// 인풋 받은 문자열에 따라 연결된 시리얼 포트에게 문자열로 송신한다.
    void Update()
    {
        switch (Input.inputString)
        {
            case "A":
            case "a":
                Debug.Log("press A");
                SerialPort1.WriteLine("A");
                break;
            case "S":
            case "s":
                Debug.Log("press S");
                SerialPort1.WriteLine("S");
                break;
            case "D":
            case "d":
                Debug.Log("press D");
                SerialPort1.WriteLine("D");
                break;
            case "F":
            case "f":
                Debug.Log("press F");
                SerialPort1.WriteLine("F");
                break;
            case "G":
            case "g":
                Debug.Log("press G");
                SerialPort1.WriteLine("G");
                break;
            case "H":
            case "h":
                Debug.Log("press G");
                SerialPort1.WriteLine("H");
                break;
            case "J":
            case "j":
                Debug.Log("press J");
                SerialPort1.WriteLine("J");
                break;
            case "K":
            case "k":
                Debug.Log("press K");
                SerialPort1.WriteLine("K");
                break;
        }
    }

    /// 앱이 종료되면 시리얼 통신도 종료
    void OnApplicationQuit()
    {
        SerialPort1.Close();
    }
}
```


```c
/// [Arduino]

/// 피에조 스피커 핀 식별자 지정
int piezo_pin = 3;
/// 멜로디 프리퀀시
int melody_freq[8] = { 262, 294, 330, 349, 392, 440, 494, 523 };

void setup() 
{
  /// 시리얼 통신 시작
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop()
{
  while(Serial.available())
  {
    char data = Serial.read();
    switch(data)
    {
    case 'A':
      C_(0);
      break;
    case 'S':
      D_(0);
      break;
    case 'D':
      E_(0);
      break;
    case 'F':
      F_(0);
      break;
    case 'G':
      G_(0);
      break;
    case 'H':
      A_(0);
      break;
    case 'J':
      B_(0);
      break;
    case 'K':
      CC_(0);
      break;
    }
  }
}

void C_(int ms)
{
  tone(piezo_pin, melody_freq[0], 200);
  delay(ms);
}

void D_(int ms)
{
  tone(piezo_pin, melody_freq[1], 200);
  delay(ms);
}

void E_(int ms)
{
  tone(piezo_pin, melody_freq[2], 200);
  delay(ms);
}

void F_(int ms)
{
  tone(piezo_pin, melody_freq[3], 200);
  delay(ms);
}

void G_(int ms)
{
  tone(piezo_pin, melody_freq[4], 200);
  delay(ms);
}

void A_(int ms)
{
  tone(piezo_pin, melody_freq[5], 200);
  delay(ms);
}

void B_(int ms)
{
  tone(piezo_pin, melody_freq[6], 200);
  delay(ms);
}

void CC_(int ms)
{
  tone(piezo_pin, melody_freq[7], 200);
  delay(ms);
}
```

버튼의 경우 나는 OnClick()에 직접 매핑하지 않고, 이벤트 리스너로 받아 처리했다.