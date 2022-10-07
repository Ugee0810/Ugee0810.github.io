---
title:      Unity Firebase Error(유니티 파이어베이스 컴파일 에러)
date:       "2022-10-05"
categories: ["Unity", "Firebase"]
tags:       ["Unity", "Firebase"]
# pin:        true
---

유니티에 파이어베이스를 연동하고 실행하던 도중, 다음과 같은 에러가 발생했다.

- [ERROR]'Google.IOSResolver.dll'
- [ERROR]'Firebase.Editor.dll' will not not be loaded due to errors

## 첫 번째 방법(구글 서비스 버전이 맞지 않을 때)
Assets -> External Dependency Manager -> Version Handler -> Update

![image](https://user-images.githubusercontent.com/85896566/194060979-a91ebf8d-809d-4407-9d5b-f9727157fe38.png)

## 두 번째 방법
빌드 세팅에서 안드로이드 플랫폼인지 확인 후 아니라면 스위치

![image](https://user-images.githubusercontent.com/85896566/194063571-823aefb9-0f0a-401e-9881-cee253e3a24f.png)


## 세 번째 방법
Unity Hub에서 IOS를 설치

![image](https://user-images.githubusercontent.com/85896566/194063961-f33c7955-3cc4-4d66-87c2-b48a6670fff9.png)

# 참고 사이트
- [촙촙쓰 - 게임 개발중이오](https://chopchops.tistory.com/6)
- [Google.IOSResolver will not be loaded in 2021.1.11f1 and later](https://forum.unity.com/threads/google-iosresolver-will-not-be-loaded-in-2021-1-11f1-and-later.1128617/#post-8251962)