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

# 레이어 지정
아래 사진처럼 네 개의 레이어 지정

## Tags and Layers
- Hands
- Interactive
- Typing Hands
- Keyboard

![image](https://user-images.githubusercontent.com/85896566/193780989-7f807c04-ea95-4893-8870-1cd704db2fa2.png)

## Physics
![image](https://user-images.githubusercontent.com/85896566/193781800-b910df6e-b24f-4bec-a5c5-d1c468b75543.png)

# 키보드 제작
## 오브젝트 추가
- 빈 오브젝트(Keyboard)
  - 3D Cube(Board) 생성 후 포지션 (1, 0.05, 0.4) 지정, Gray 머티리얼 적용

![image](https://user-images.githubusercontent.com/85896566/193782384-713072dc-455c-422d-9223-b7c23c083008.png)

- 빈 오브젝트(Buttons)
  - 빈 오브젝트(Normal)
    - 빈 오브젝트(Numbers)
      - 프리팹(Square Button)
- 빈 오브젝트(Typing Area)

![image](https://user-images.githubusercontent.com/85896566/193783114-885f4a0a-9176-4e5f-9a3f-7916b6e870ac.png)

2:34


# 참고 사이트
- [VR Keyboard | Unity Tutorial for Oculus Quest](https://youtu.be/PyKW9kecyqg)