---
title:      Unity Lobby(유니티 로비 서비스, 멀티 플레이어)
date:       "2022-11-24"
categories: ["Unity"]
tags:       ["Unity"]
# pin:        true
---

# ※ Practical Environment
- Unity Editor Version - 2021.3.14f1

<br>

# ※ Intro
## 유니티 로비 서비스(Unity Lobby service)
로비 서비스를 사용하면 게임 세션 전이나 도중에 플레이어를 공개 또는 비공개 로비와 연결할 수 있습니다. 로비 서비스를 사용하여 게임 세션을 시작하기 전에 로비에서 플레이어를 함께 그룹화하거나 호스트 플레이어를 사용할 수 없는 경우 연결 손실을 방지할 수 있습니다.

로비는 플레이어가 게임 세션을 만들고 찾을 수 있도록 공개 로비 와 비공개 로비 를 사용하는 두 가지 주요 흐름을 제공 합니다. 다음은 각각의 기능입니다.

||Public lobbies|Private lobbies|
|---|---|---|
|Discoverable via Query<br>쿼리를 통해 검색 가능|Yes|No|
|Joinable by Quick Join<br>빠른 참여로 참여 가능|Yes|No|
|Joinable by Id<br>아이디로 가입 가능|Yes|Yes|
|Joinable by lobby code<br>로비 코드로 가입 가능|Yes|Yes|

## 공공 로비(Public lobby)
공개 로비를 사용하면 플레이어가 검색 매개변수에 맞는 공개 로비를 생성, 검색 및 참여할 수 있습니다.

## 프라이빗 로비(Private lobby)
비공개 로비에서는 플레이어가 로비 코드를 전송하여 다른 플레이어를 초대할 수 있습니다.

## 빠른 가입(Quick Join)
빠른 참여를 통해 플레이어는 최대한 빨리 게임 세션에 참여할 수 있습니다. 플레이어가 요구 사항을 지정하면 일치하는 로비(사용 가능한 경우)에 즉시 참가합니다. 또한 이 방법을 사용하여 간단한 매치메이킹을 구현하거나 플레이어가 진행 중인 게임에 참여하도록 할 수 있습니다.

<br>

# ※ Apply
## 로비 SDK 설치
Lobby 서비스에 온보딩한 후 다음 단계는 Lobby SDK를 설치하여 에디터에서 사용할 수 있도록 하는 것입니다. ```com.unity.services.lobby``` 라는 Unity 패키지로 제공됩니다.

Unity용 최신 Lobby 패키지를 설치하려면 Unity에서 Window > Package Manager 로 이동합니다.

Package Manager 에서 ```com.unity.services.lobby``` 를 검색 하거나 Unity Registry 를 스크롤하여 Lobby 패키지를 찾습니다.

패키지를 선택하고 설치를 클릭합니다.

## 인증(Authentication)
로비 서비스를 사용하려면 [Unity 인증](https://docs.unity.com/authentication/IntroUnityAuthentication.html) 을 사용하여 본인 인증을 하십시오. Lobby SDK를 사용하여 호출하기 전에 인증 서비스를 [초기화 하고 로그인](https://docs.unity.com/authentication/InitializeSDK.html)해야 합니다. 많은 로그인 방법이 있지만 시작하는 가장 쉬운 방법은 익명 로그인입니다. 시작하려면 [Unity 인증 익명 로그인 가이드](https://docs.unity.com/authentication/Content/UsingAnonSignIn.htm) 를 참조하세요.

## 속도 제한(Rate limits)
로비 서비스는 속도 제한을 사용하여 주어진 시간 내에 API가 수신하는 요청 수를 제한함으로써 네트워크 트래픽을 제어하는 ​​데 도움을 줍니다. 다음 표는 플레이어 및 서비스에 대한 로비 서비스의 각 요청 유형에 대한 속도 제한을 보여줍니다. 서비스는 훨씬 더 많은 제어가 허용되고 한 번에 여러 로비를 관리할 가능성이 높기 때문에 속도 제한이 더 완화됩니다.

|요청 유형|속도 제한|서비스 속도 제한|
|---|---|---|
|Query for lobbies<br>로비 쿼리|초당 요청 1개|초당 요청 100개|
|Create lobbies<br>로비 만들기|6초당 요청 2개|6초당 요청 200개|
|Join lobbies<br>로비에 참여|6초당 요청 2개|6초당 요청 200개|
|Quick Join lobbies<br>빠른 참여 로비|10초당 요청 1개|10초당 요청 100개|
|Get lobbies<br>로비 받기|초당 요청 1개|초당 요청 100개|
|Get joined lobbies<br>로비에 참여하기|30초당 요청 1개|30초당 요청 1개|
|Get hosted lobbies<br>호스팅 로비 받기|10초당 요청 1개|10초당 요청 1개|
|Delete lobbies<br>대기실 삭제|초당 요청 2개|초당 요청 200개|
|Update lobbies<br>로비 업데이트|5초당 요청 5개|5초당 요청 500개|
|Bulk update lobbies<br>대량 로비 업데이트|해당 없음(금지됨)|초당 요청 1개|
|Leave lobbies or remove players<br>로비를 나가거나 플레이어 제거 시|초당 5개 요청|초당 요청 500개|
|Update players<br>플레이어 업데이트|5초당 요청 5개|5초당 요청 500개|
|Heartbeat lobbies<br>하트비트 로비|30초당 요청 5개|30초당 요청 500개|
|Reconnect to lobby<br>로비에 다시 연결|6초당 요청 2개|6초당 요청 200개|

## 로비 관리(Manage lobbies)
- [Unity Lobby Documentation](https://docs.unity.com/lobby/manage-lobbies.html)

로비 만들기, 로비 업데이트 등은 위의 문서 참조


<br>

# ※ Reference Site
- [Unity Lobby Documentation](https://docs.unity.com/lobby/unity-lobby-service.html)