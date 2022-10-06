---
title:      Unity Firebase Setting(유니티 파이어베이스 연동하기)
date:       "2022-10-04"
categories: ["Unity", "Firebase"]
tags:       ["Unity", "Firebase"]
# pin:        true
---

# 파이어베이스 유니티 SDK 임포트
## 준비물
- [파이어베이스 유니티 SDK 다운로드(1.7GB)](https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqa0FLOXh0YlV3WFBKVUIxX0hRQWEzZlZPdHhVZ3xBQ3Jtc0trVERQbjVkN3hwbGRnSTQyMTBNWTRSMkZWYmZUSk5Ec3ZWRXpHSnJBV1Z3S1JCa0Y2c0tMQU1hU0FrNE1UOElvblhaZjZpMWZtdGVTbm4xeUgtVkJDT2prSV9PWXNycE04OGdOY3JrbzNibkVGSU1Xbw&q=https%3A%2F%2Ffirebase.google.com%2Fdownload%2Funity%3Fhl%3Dko&v=0QY_W-7PSbI)

링크에서 다운 받고 압축을 해제한다.

유니티 2019버전 이상이라면 dotnet4의 폴더의 SDK를 사용한다.

이 중에서 계정 인증을 사용하기 위해 **'FirebaseAuth.unitypackage'** 을 프로젝트에 임포트한다.

![image](https://user-images.githubusercontent.com/85896566/193715664-c001e555-bfe2-4741-8572-6ef3469c1fa2.png)

## 플랫폼 세팅
Ctrl + Shift + B를 눌러 빌드 세팅을 열어주고 안드로이드로 플랫폼 스위치해준다.

![image](https://user-images.githubusercontent.com/85896566/193715853-9f0acb21-b13f-44cc-b894-a8bcb3d8ca72.png)

## 식별자 확인
파이어베이스 측에서 우리 프로젝트를 인식하려면 식별자가 필요하다.

플레이어 세팅 ---> 안드로이드 설정에 패키지 네임을 홈페이지의 앱 등록란에 기입해준다.

![image](https://user-images.githubusercontent.com/85896566/193720340-7ddbd5a7-12f3-466c-9949-5d9cdd86965f.png)

파이어베이스 측에서 신뢰할 수 있도록 앱 서명도 필요하다.

![image](https://user-images.githubusercontent.com/85896566/193720519-23233077-cece-44bd-9b49-c2526cc93aa9.png)
![image](https://user-images.githubusercontent.com/85896566/193720723-b94a899c-456a-45af-b436-7606985a81c0.png)

**※ 중요**

패스워드와 Alias 패스워드는 절대 잊으면 안됨!!


# 프로젝트 생성
홈페이지에 접속해 로그인 후 콘솔로 이동

- [Firebase Console 이동](https://console.firebase.google.com/)

![image](https://user-images.githubusercontent.com/85896566/193714435-439b88c1-9c97-4988-9ded-9e9f01851b4e.png)

- 프로젝트 추가
- 프로젝트 이름은 대/소 구분 안해도 된다.
- 구글 애널리틱스는 사용 안해도 된다.

![image](https://user-images.githubusercontent.com/85896566/193714538-aa268050-cf02-42c0-97bb-47e4b74b15f4.png)

- 프로젝트 내부에 접속하면 유니티 아이콘 클릭

![image](https://user-images.githubusercontent.com/85896566/193714735-2b9ba453-c38a-4a4d-a530-44dff48d3e8b.png)

- 앱 등록 과정에서 서비스할 플랫폼을 선택해준다.
- 이 과정은 나중에 다시 할 수 있으므로 한 플랫폼은 나중에 서비스 할 예정이라면 지금 안해도 된다.

![image](https://user-images.githubusercontent.com/85896566/193714860-27ae0681-bf57-43b6-935d-36eda0f98049.png)

앱 등록 과정 이후

파이어베이스에 접근하기 위한 인증 키, ID 등이 들어있는 .json 파일을 유니티 프로젝트에 임포트한다. SDK가 설치되어 있다면 이 .json파일을 자동으로 감지해서 변형해준다.

![image](https://user-images.githubusercontent.com/85896566/193721263-1b119c01-a3c5-4d65-92f8-ac9d7ffbc9d6.png)

이 과정은 이미 2단계 이전에 했으므로 다음으로 넘어간다.

![image](https://user-images.githubusercontent.com/85896566/193721461-12d81a38-dda9-4be3-a636-f8c206f6c13c.png)

구글 파이어베이스 계정 인증 관련 서비스를 빌드하기 위해 다시 콘솔로 이동 후 아래의 사진으로 이동한다.

![image](https://user-images.githubusercontent.com/85896566/193750489-8c289e8f-7fcf-499e-95d7-b43237ec6f37.png)

이후 서비스 할 방법을 선택한다.

![image](https://user-images.githubusercontent.com/85896566/193750701-07dc1208-6378-4650-80be-8d8877882e71.png)

그리고 파이어베이스가 신뢰 가능한 앱인지 확인할 수 있도록 디지털 지문을 기입해주어야 한다.

![image](https://user-images.githubusercontent.com/85896566/193750925-b405c2d9-5fc8-478f-9f74-fd8e5913c2e1.png)

디지털 지문을 추가하기 위해 윈도우의 경우 파워쉘, IOS는 터미널을 열어준다.

경로는 본인이 지정한 .keystore로 한다.

![image](https://user-images.githubusercontent.com/85896566/193751191-5930e8c0-fffc-4256-84e5-c8df79c615c0.png)

![image](https://user-images.githubusercontent.com/85896566/193751598-f4705620-7639-440b-bac3-0d6bc1e9be4b.png)
![image](https://user-images.githubusercontent.com/85896566/193751736-3ad29b2f-2807-4623-a01f-91cce1c1e523.png)

```
keytool -list -v -alias ugee -keystore ugee.keystore
```

![image](https://user-images.githubusercontent.com/85896566/193752086-fac025ab-7dce-447b-9a0f-847d6dfe843a.png)

디지털 지문을 등록 후 최신 .json 파일을 다운받고 기존에 넣어 둔 파일을 지우고 교체한다.
![image](https://user-images.githubusercontent.com/85896566/193752574-b6e7f1d3-17ad-4e97-950d-e72cd2d69710.png)

이후에 컬렉션이나 사용자를 생성하는 로직을 통해 관리한다.

# 참고 사이트
- [유니티 멀티플레이어 네트워크 게임 한방에 만들기 (포톤 + 파이어베이스) 3/10](https://youtu.be/rABO1NFQ_PE)