---
title:      Unity AR Vuforia Model Target
date:       "2022-11-10"
categories: ["Unity"]
tags:       ["Unity"]
# pin:        true
---

# ※ Practical Environment
- Unity Editor Version - 2021.3.11f1
- Packages
  - Vuforia Engine AR(10.11.3)
  - 

<br>

# ※ Intro

<br>

# ※ Apply
## ※ Vuforia SDK 다운로드
- [Vuforia SDK Download](https://developer.vuforia.com/downloads/sdk)
위 사이트에 들어가 회원가입 하고 유니티 SDK를 내려 받는다.

![image](https://user-images.githubusercontent.com/85896566/201097331-e8dde618-bf52-46ca-a36e-e8a1661548db.png)

## ※ 라이센스 추가
뷰포리아 라이센스 키를 등록하지 않으면 어플리케이션 구동 시 타겟을 인식못하거나 아예 카메라가 구동하지 않을 수 있다고 합니다.

- [Vuforia Licenses Page](https://developer.vuforia.com/vui/develop/licenses/)

위 사이트 들어가서 새로운 프로젝트를 만들고 키 값 복사하기

![image](https://user-images.githubusercontent.com/85896566/201099957-78881963-9925-4417-b851-a07c3b317f61.png)

유니티 앱을 열어 Vuforia SDK를 설치했다면 아래의 사진처럼 나올 것이다. AR 카메라를 꺼낸다.

![image](https://user-images.githubusercontent.com/85896566/201100879-94e4a3e4-4603-4095-a7ef-27ce45106953.png)

이후 아래의 사진 따라 홈페이지에 있는 키 값을 붙여넣는다.

![image](https://user-images.githubusercontent.com/85896566/201101181-0b2d973e-f63b-470b-a2fe-d08b0af91562.png)

![image](https://user-images.githubusercontent.com/85896566/201101387-c46a35e4-5e39-4aa5-abec-473df27ec782.png)

이로써 기본 세팅은 완료 !

## ※ 모델 타겟 생성 프로그램 설치
- [Vuforia Model Target Generator Download](https://developer.vuforia.com/downloads/tool)
위 사이트에 들어가 알맞은 플랫폼 설치

![image](https://user-images.githubusercontent.com/85896566/201099490-30f6f3e5-7ac7-45be-9fd7-98434dccfbce.png)

![image](https://user-images.githubusercontent.com/85896566/201100432-20acebf6-3237-424e-bf80-389fb9ed8196.png)

![image](https://user-images.githubusercontent.com/85896566/201102684-ea640f2e-fef6-4777-abd6-f7dc3d6a0f3b.png)

설치 후 로그인하면 위와 같은 화면이다. 체크해둔 곳을 클릭해 생성하거나 불러온다.

이후 사용법은 아래의 링크 참고

- [Vuforia Developer Library - How to Create a Model Target](https://library.vuforia.com/model-targets/how-create-model-target)

## ※ 유니티로 타겟 모델링 가져오기
먼저 유니티 프로젝트 상단에서 아래의 사진처럼 찾아가 임포트한다.

![image](https://user-images.githubusercontent.com/85896566/201105793-a33bd45d-1705-4028-b8cd-b1b10ecf02ca.png)

생성기 프로그램에서 타겟을 생성했다면 ```Target Name/dataset``` 폴더에 유니티 패키지가 있을 것이다. 이를 임포트 한다.

![image](https://user-images.githubusercontent.com/85896566/201106046-5d2830d6-88b1-448a-8d19-18e27031f89b.png)

![image](https://user-images.githubusercontent.com/85896566/201106487-0c033145-5214-44a1-b2c6-6994e2e426b9.png)

![image](https://user-images.githubusercontent.com/85896566/201106662-a718a511-0dcc-41d2-95a8-ad8d4952d92e.png)

큐브를 생성하여 실제 사물과 트래킹 됐을 때 바운딩 될 수 있도록 테스트한다.

![image](https://user-images.githubusercontent.com/85896566/201107798-f80183c6-89ad-43b7-adda-a87004a5f331.png)

실물 테스트가 끝났다면 바운딩 하려고 준비해둔 모델링 파일을 유니티에 가져온다.

![image](https://user-images.githubusercontent.com/85896566/201108604-ce1a0bc2-9596-4d90-ab17-c9519e46a207.png)

큐브 대신 들어가고 사이즈를 적절하게 조절하기

![image](https://user-images.githubusercontent.com/85896566/201109333-98838934-6f24-4a72-9914-6ab9bc46185a.png)

이제 플랫폼을 변경해서 테스트해보면 성공할 것이다.

혹시 고급 타겟 뷰를 사용하려면 아래의 문서를 참조하면 알 수 있다.

- [고급 모델 대상 데이터베이스](https://library.vuforia.com/model-targets/advanced-model-target-databases)

<br>

# ※ Reference Site
- [Augmented Startups - Vuforia Model Targets Tutorial in Unity 2020.1 - Iron Man AR Car Detection](https://youtu.be/NAJII2p_LQs)
- [[Unity] 뷰포리아(Vuforia) SDK (1) - 설치 / 라이센스 키 등록](https://eunjin3786.tistory.com/318)