---
title:      Unity URP-Based Water Shader(Feat.Boat Attack) (유니티 URP 모바일 최적화 물 셰이더 간단 적용)
date:       "2022-10-28"
categories: ["Unity"]
tags:       ["Unity"]
# pin:        true
---

# ※ Practical Environment
- Github
- Unity Editor Version - 2021.3.11f1
- Package
  - Universal RP(Ver 12.1.7)

<br>

# ※ Intro
![image](https://user-images.githubusercontent.com/85896566/198624694-1b6131c6-006d-4658-9ccd-60b93e7797bd.png)

![image](https://user-images.githubusercontent.com/85896566/198626376-5523093f-f7a9-4b05-9160-0ff604676530.png)

## ※ Boat Attack 프로젝트 특징
- Unity Universal RP 사용
- 모바일 최적화, 낮은 폴리, LOD
- C# 작업 부력 시스템
- 시네머신 카메라 설정
- 셰이더 그래프 사용
- 볼륨 블렌딩을 사용한 포스트 프로세싱 v3
- SRP 콜백 을 통한 평면 반사를 위한 맞춤형 범용 RP 렌더링
- WaterFX 및 Caustics에 대한 사용자 지정 SciptableRenderPass 사용
- 현지 패키지(WIP)의 Gerstner 기반 물 시스템
- [데모 영상 보기](https://drive.google.com/file/d/1PTNdhnqbhzSWUCfAinIefP5cfr6Dezuw/view)

## ※ Unity Korea - [튜토리얼] Boat Attack Water System
![image](https://user-images.githubusercontent.com/85896566/198627592-755d2d1a-2ea7-40fd-83eb-4648a1c1302e.png)

- [재생목록 바로가기](https://www.youtube.com/watch?v=LyiRALUOQqo&list=PL412Ym60h6uvBOpPSP-tcnINt971OD7ZC)

![image](https://user-images.githubusercontent.com/85896566/198628286-e94efb47-1d65-4358-874c-86d653d3090f.png)

작동 원리와 물 셰이더 프로그래밍, 코드 해석의 도움을 받을 수 있습니다.

<br>

# ※ Apply
적용 방법은 매우매우 쉽습니다.

> ![image](https://user-images.githubusercontent.com/85896566/198604996-4ef172f6-4583-48f8-bd81-7ee31b1cc524.png)
> 
> - _Boat Attack Project_
>
> - [https://github.com/Verasl/BoatAttack](https://github.com/Verasl/BoatAttack)
>
> 위의 URL에 접속하여 프로젝트를 Fork합니다.

> ![image](https://user-images.githubusercontent.com/85896566/198606658-ede370c8-afe4-4fa8-b84c-f89b19c0196a.png)
>
> ![image](https://user-images.githubusercontent.com/85896566/198610288-98e7dc1c-e7a7-4010-bdd7-4db6ae6cf27f.png)
> 
> - _Github Desktop_
>
> Fork한 프로젝트를 Clone해줍니다.

> ![image](https://user-images.githubusercontent.com/85896566/198612927-7c769214-fec5-4696-b0e0-2ccf8349d175.png)
>
> - _Packages Folder_
>
> Clone한 프로젝트의 패키지 폴더에 진입하면 **'com.verasl.water-system'** 폴더가 있습니다. 이것이 물 셰이더를 사용할 수 있도록 별도로 커스텀 패키징한 폴더입니다.
>
> 이 폴더를 적용할 프로젝트의 Packages 폴더에 복사하고 유니터 에디터로 돌아갑니다.

> ![image](https://user-images.githubusercontent.com/85896566/198613639-f6ad0ad3-b1b3-4d36-9d2a-8389dd03cd33.png)
>
> ![image](https://user-images.githubusercontent.com/85896566/198613898-deee2c32-b1e3-4a24-a57e-be2a389446fd.png)
> 
> - _패키지 설치 확인_

> ![image](https://user-images.githubusercontent.com/85896566/198619026-3f24f97e-c423-42d8-be41-e4799674a4ff.png)
>
> ![image](https://user-images.githubusercontent.com/85896566/198619596-d3866210-9e7e-4b5f-aa9a-cf49831cd911.png)
>
> - _Error_
>
> 적용 했을 때 이런 에러가 발생한다면 Dependencies 아래의 요구되는 3개의 내장 패키지가 설치되어 있는지 확인 후 설치합니다. **보통 URP 템플릿으로 프로젝트를 실행하면 오류는 뜨지 않습니다.**
>
> - **Mathematics**
> - **Burst**
> - **Render-Pipelines Universal(Universal RP)**

> ![image](https://user-images.githubusercontent.com/85896566/198616325-57f8b948-509b-4422-9e1f-c37ef43f8fb2.png)
>
> - _적용 방법 1 (추천)_
>
> Packages -> Boat Attack Water System -> **SeaVisual** 프리팹을 하이어라키로 드래그 & 드랍

> ![image](https://user-images.githubusercontent.com/85896566/198615498-987e9091-47d4-4bfc-b394-8f521f532757.png)
>
> ![image](https://user-images.githubusercontent.com/85896566/198615809-aa0ce432-5f43-4e8c-89b8-95f3bab9f54d.png)
>
> - _적용 방법 2_
>
> 빈 오브젝트를 생성한 뒤  **'water'** 스크립트를 컴포넌트에 추가해줍니다. 혹시 씬 뷰에 적용되지 않았다면 오브젝트를 재활성화 해줍니다.

- 주의 : 셰이더는 y가 0기준으로 정상 작동하므로 이 기준에 맞추어 오브젝트들의 y값을 조정해야합니다.

- [Unity Korea - 내 URP 프로젝트로 물 시스템 가져오기. 모바일 플랫폼을 위한 물 표현 (6/6)](https://youtu.be/QKcPR00HQn4)

추가 설정이나 사용법은 위의 영상 4분15초부터 보시는걸 추천드립니다.

![image](https://user-images.githubusercontent.com/85896566/198629863-edfc28c0-be6e-45a2-a165-a22953be37d5.png)

마지막으로 위 사진의 **'Always Refresh**를 체크하면  씬 뷰를 실시간으로 새로고침 해줍니다.

<br>

# ※ Reference Site
- [Github Unity-Technologies / Boat Attack Project](https://github.com/Verasl/BoatAttack)
- [Universal Render Pipeline (7.1) Manual](https://docs.unity3d.com/Packages/com.unity.render-pipelines.universal@7.1/manual/index.html)
- [Unity Korea - 내 URP 프로젝트로 물 시스템 가져오기. 모바일 플랫폼을 위한 물 표현 (6/6)](https://youtu.be/QKcPR00HQn4)