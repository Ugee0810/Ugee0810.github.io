---
title:      Unity XR | Android Build Setting(유니티 XR 안드로이드 최적화)
date:       "2022-10-14"
categories: ["Unity", "XR Interaction Toolkit"]
tags:       ["Unity", "XR Interaction Toolkit"]
# pin:        true
---

# ※ 유니티 모바일 텍스쳐 압축연구 ETC2, PVRTC, ASTC
- [맨텀](https://mentum.tistory.com/583)

# ※ Compute Skinning
Meshskinning.SkinOnGPU

렌더링 전 버텍스당 스키닝을 각 프레임마다 재계산하는데, 이 폴리곤이 많아지면 연산부담도 증가하게 됨.

이 연산은 CPU에서 처리하는데 Unity에서 옵션값을 통해 GPU에게 할당할 수도 있음

Player Settings > Player > Other Settings > Compute Skinning

해당 값이 활성 > GPU 연산, 비활성 > CPU 연산

언뜻 보면 GPU에게 맡기면 빠를거 같지만 모바일 환경은 GPU 사양이 제한되어 있어, 병목 원인에 따라 선택해야 함

CPU로 연산하면 SIMD라는 아키텍처를 이용해 고속연산을 수행하기 때문에 모바일 환경이라면 비활성 하는게 이득

하지만 프레임 드랍의 원인이 CPU라면 GPU에게 처리하도록 하는게 더 나은 방법

*단, GPU 스키닝 연산은 OpenGL ES2에서는 지원되지 않음. DX11과 OpenGL ES3에서만 유효 (지원여부는 바뀔수있다)

# ※ 점진적 가비지 수집(incremental garbage collection)
유니티의 가비지콜렉터는  Boehm–Demers–Weiser garbage collector를 사용한다. 

https://www.hboehm.info/gc/

가비지콜렉터가 가비지 수집을 수행할때 프로그램 코드 실행 및 CPU 메인스레드를 중지하며 전체 힙을 검사한다(stop-the world garbage collection) 힙의 모든 오브젝트를 처리한 이후에 어플리케이션 실행을 재개함으로 성능에 영향을 미치는 gc 스파이크(중단으로 인해 프로파일러 윈도우의 그래프에서 나타나는 큰 스파이크)가 발생한다.

incremental mode는 가비지콜렉터가 힙의 모든 오브젝트들을 처리하기 위해 긴 중단을 한번만 수행하는 대신에 작업부하를 여러 프레임으로 분할하여 어플리케이션 실행을 더 짧게 중단하는것을 의미한다. 

유니티에서 incremental mode는 기본적으로 활성화되어있으며 project settings의 player configuration에서 활성화 및 비활성화할수있다.

가비지수집을 더 빠르게 만들지않지만 여러 프레임에 작업부하를 분산하기때문에 gc 스파이크 및 gc 관련 성능 스파이크를 줄일수있다.

# 참고 사이트
- [흔적남기기](https://shkim0811.tistory.com/12)
- [창작블로그](https://learnandcreate.tistory.com/917)
- [맨텀](https://mentum.tistory.com/583)