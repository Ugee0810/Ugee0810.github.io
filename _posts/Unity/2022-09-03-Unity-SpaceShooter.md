---
title:      위키북스 절대강좌! 유니티 책 따라가기
date:       "2022-09-03"
categories: ["Unity"]
tags:       ["Unity"]
# pin:        true
---
---

![image](https://user-images.githubusercontent.com/85896566/188261890-7183879c-3e2a-4e5e-968d-57762a68f64a.png)

# ※ 01장 : 유니티 엔진의 소개(생략)
<br>

---

# ※ 02장 : 게임 개발 준비
## 이 책에서 개발할 게임 소개 및 개발 순서
이 책을 통해 개발할 게임은 3인칭 시점 슈팅(TPS, Third Person Shooting) 게임이다.

개발 순서
1. 게임 개발 환경 설정
2. 게임에서 사용할 리소스 내려받기 및 설치
3. 게임의 배경이 되는 스테이지 제작
4. 주인공의 이동 및 공격 기능 구현
5. 적 캐릭터 생성 및 추적 기능 구현
6. 주인공과 적 캐릭터 간의 공격 및 피격 기능 구현
7. 게임 매니저 및 오브젝트 풀링 구현

## 프로젝트 생성
유니티 허브
- 새 프로젝트 생성 : 3D / SpaceShooter
- 기존 프로젝트 관리
- 유니티 라이센스 등록

유니티 버전
- Unity 2021.3.9f1(LTS)

## 유니티 에디터의 환경설정
### 레이아웃
![image](https://user-images.githubusercontent.com/85896566/188261465-37a8c1c0-7a0b-40ef-b0c6-3e4e7f5b8d37.png)

내가 사용하는 커스텀이다.

프로젝트와 하이러키, 인스펙터 이동 동선이 가까워서 좋다.

### 프로젝트 뷰의 칼럼
![image](https://user-images.githubusercontent.com/85896566/188261570-0866032f-f0e5-4a3e-bb9b-e9b8815d5c45.png)

보통 'One Column Layout'를 사용한다.

Sprite나 Metarial 등을 볼 땐 'Two Column Layout'이 편했다.

## 프로젝트 뷰의 체계적인 관리
프로젝트 뷰는 게임 개발에 사용하는 모든 리소스가 저장되는 곳이므로, 개발을 진행할수록 많은 리소스가 쌓이므로 혼란이 생긴다. 그러므로 처음부터 체계적으로 관리하는 게 중요하다.

![image](https://user-images.githubusercontent.com/85896566/188261764-c890fb5e-f716-4f08-b1bc-e1200d18b1cc.png)

## 캐릭터 모델 임포트하기
이 책에선 MADFINGER Games - ShadowGun:Deadzone 게임의 에셋을 사용한다.

- [깃허브 저장소에서 내려받기](https://github.com/indieGameMaker/UnityBook)

### 유니티 패키지를 통한 리소스 설치
![image](https://user-images.githubusercontent.com/85896566/188262072-98dac32d-7b10-4b91-9717-11b141d944df.png)

프로젝트 뷰에 드래그 & 드랍으로 패키지를 임포트한다.

## Asset Store
에셋 스토어는 다양한 리소스를 사고팔 수 있는 오픈마켓이다.

※ 라이센스를 주의하며 설치할 것

![image](https://user-images.githubusercontent.com/85896566/188262160-22845a88-aed5-47ca-aa6b-ffea6b9f7810.png)

### 무료 리소스 내려받기
설치 목록
- Yughues Free Metal Materials
- Skybox Volume 2 (Nebula)
- Barrel

![image](https://user-images.githubusercontent.com/85896566/188262190-c06a8d52-9a8c-4714-9068-34401e848f95.png)

![image](https://user-images.githubusercontent.com/85896566/188262271-4fb6d3b6-1069-47e0-8a8f-e42cdb727602.png)

![image](https://user-images.githubusercontent.com/85896566/188262305-f60fe45a-a698-4a0f-ac74-36671a14abf7.png)

이후 패키지 매니저에서 내려 받기

## 정리
게임 개발에 필요한 여러 가지 에셋을 설치했다.

유니티의 장점 중 하나인 에셋 스토어에서는 많은 무료 에셋을 제공한다.

![image](https://user-images.githubusercontent.com/85896566/188262620-aded7a34-65fb-4290-82d6-f14f830c6b27.png)

<br>

---

# ※ 03장 : 게임 스테이지 제작
## 바닥 생성 및 배치
게임의 배경이 도는 스테이지를 제작할 때 먼저 작업하는 것 중 하나가 바로 바닥인 Floor다.

보통 유니티에서 제공하는 원시 모델(Primitive Model) 중 Plane 또는 Cube를 사용한다.

트랜스폼 스케일 값 1단위는 1m로 디자인 되어있다.

※ 오브젝트를 생성하면 항상 포지션 값을 확인 후 리셋하는 습관을 기른다.

아래의 설정을 하면 자동으로 월드 좌표 원점으로 설정해준다.

![image](https://user-images.githubusercontent.com/85896566/188262916-49434042-7d39-404a-bca5-644fefa5feeb.png)

![image](https://user-images.githubusercontent.com/85896566/188263017-67cda7ef-4090-4c13-9bdf-dfa70790ad78.png)

## Texture(텍스처)
텍스처(Texture)란 3D 모델의 표면에 매핑시킬 이미지 파일을 지칭한다.

텍스처의 크기는 가로 세로가 2ⁿ(예: 256x256, 1024x1024) 형태일 때 압축을 지원하며, 속도가 가장 빠르다.

특히 모바일 플랫폼에서 속도를 향상시키고 싶다면 반드시 2ⁿ(POT, Power Of Two) 형태의 텍스처를 사용해야 한다.

### 텍스처의 해상도 조절
![image](https://user-images.githubusercontent.com/85896566/188291697-887b7984-075d-4ac0-8f0f-bb5dcb948d5f.png)

- 해상도를 줄일 수록 용량이 크게 줄어든다.
- 프로젝트를 진행할 때 대상 플랫폼을 명확히 설정하고 임포트한 텍스처의 품질을 어떻게 관리할 것인지 미리 결정해야 한다.
- 따라서 프로젝트 진행 중 임포트한 텍스처는 바로 적절한 품질로 설정하는 작업을 병행해야 최적화 작업이 수월하다.

## Material(머티리얼)
3D 모델에 텍스처를 적용하려면 3D 모델과 텍스처 사이에 반드시 Metarial이 필요하다.

머티리얼은 3D 모델에 적용할 텍스처의 다양한 속성을 설정하는 역할을 한다.

즉, "어떤 텍스처를, 어떤 간격으로 반복하고, 표면의 재질은 어떻게 표현하느냐" 등의 속성을 설정한다.

### 머티리얼의 자동 적용
※ 객체에 텍스처를 적용하는 방법은 두 가지가 있다.

1.드래그 & 드랍
- 적용 시 자동으로 "Matarials" 폴더 생성

![image](https://user-images.githubusercontent.com/85896566/188292237-015ab30f-6784-45dc-9c9f-8e6288de1760.png)
- 텍스처와 머티리얼이 여러 폴더에 산재
- 텍스처가 어떤 절차를 걸쳐서 메시에 연결되는지 명확히 알아야하므로 초보자에겐 권장하지 않음

### 머티리얼 생성
2.텍스처 슬롯 바로 옆에 있는 브라우저 버튼을 클릭해 직접 선택
- "Matarials" 폴더를 만들고, 아래의 절차대로 머티리얼을 생성한다.

![image](https://user-images.githubusercontent.com/85896566/188292281-ad2bfd11-8aea-45b2-9120-01f7d81ec296.png)
- 머티리얼의 작명 방법은 개발자들마다 다른데, "m", "mt"와 같은 Prefix나 Postfix를 붙이기도 한다.

### Albedo, Normal Map 적용
드래그 & 드랍 또는 브라우저 버튼을 클릭하여 Albedo와 Normal Map에 연결해준다.

![image](https://user-images.githubusercontent.com/85896566/188292384-ec7cdf33-e35c-4ed5-abd0-c57dfc7718e5.png)

브라우저 버튼 왼쪽 네모 칸을 Ctrl+Click 하면 프리뷰를 볼 수 있다.

![image](https://user-images.githubusercontent.com/85896566/188292427-e01e9b36-c631-4686-abf4-b01c0f253b46.png)

### 머티리얼 적용 방법
※ 완성된 머티리얼을 적용하는 방법 또한 두 가지가 있다.
- 하이러키의 객체나, 씬 뷰에 배치된 객체에게 오브젝트 뷰에서 드래그 & 드랍
- 적용할 객체를 선택한 후 인스펙터에서 Matarials 속성에 드래그 & 드랍

![image](https://user-images.githubusercontent.com/85896566/188292505-a404abea-382a-492e-9b97-71846e98390a.png)

#### TIP - Mesh Filter, Mesh Renderer Component
애니메이션이 적용되지 않은 3D 모델은 반드시 메쉬 필터와 메쉬 렌더러 컴포넌트가 있다.

Mesh Filter
- 해당 모델의 3차원 형상 정보인 메시 데이터를 가지고 있다.

Mesh Renderer
- Mesh Filter의 메시 데이터를 기반으로 화면에 렌더링을 처리한다.

또한 유니티에서 제공하는 "~ Renderer" 계열의 컴포넌트는 반드시 Materials 속성이 있다.

이는 텍스처 정보를 가진 머티리얼을 연결하는 속성임을 의미한다.

### 타일링 속성
머티리얼의 기능 가운데 텍스처를 욕실의 타일처럼 반복시키는 기능이 있다.

인스펙터 뷰에 Tiling 속성의 X, Y값의 n당 n번 패턴 반복화 한다는 것이다.

![image](https://user-images.githubusercontent.com/85896566/188292619-d0800ebf-31bd-4c2b-bbd6-ae4f7b8c082a.png)

#### TIP - Main Maps, Secondary Maps
Secondary Maps 섹션의 속성값을 변경 했다가 변화가 없다고 혼동하지 않도록 유의.

Secondary Maps 섹션은 3D 모델의 특정 부분을 좀 더 세밀하게 표현하기 위한 텍스처를 적용하는 영역이다.

![image](https://user-images.githubusercontent.com/85896566/188292645-331aafa8-a153-4411-9844-5ea236d943b0.png)

### 프리뷰의 다양한 기능
![image](https://user-images.githubusercontent.com/85896566/188292708-5df2f833-3b66-47f9-80d6-f3fc0db1b25a.png)

![image](https://user-images.githubusercontent.com/85896566/188292780-7b02de90-f796-4e33-b492-8936e2b8c366.png)

- 확대, 최소화 가능
- 구체 뿐만 아니라 다양한 물체로 적용된 모습을 볼 수 있다.
- 광원의 유/무에 따른 모습
- 3점(케밥 메뉴)에선 별도의 윈도우 창으로 분리해 볼 수 있다.

## Shader(셰이더) 및 PBS(물리 기반 셰이딩)
셰이더는 렌더링할 때 픽셀의 농담, 색조, 명암을 결정하는 프로그래밍 방식을 말한다.

쉽게 표현하면, 화면에 텍스처를 표현할 때 재질감 또는 효과를 표현하는 기능이다.

셰이더 프로그래밍은 DirectX, OpenGL에 따라 서로 다른 언어로 구현되고 3D 그래픽스의 이론적인 배경을 많이 알아야 할 정도로 깊이 있는 지식을 요구하는 분야이다.

유니티는 셰이더 프로그래밍 지식이나 경험이 없더라도 내장 셰이더(Built in Shader)를 제공해줘 손쉽게 사용할 수 있다.

2017년 부터 공개된 물리 기반 셰이딩(PBS, Physically-Based Shading)은 물체가 가진 고유의 특성에 맞게 재질을 표현하는 것으로, 현실세계에 존재하는 돌, 나무, 유리, 플라스틱, 금속 등과 같은 재질감을 하난의 셰이더에서 표현할 수 있게 설계돼 있다.

- Metallic Value Charts
![image](https://user-images.githubusercontent.com/85896566/188292824-2d081fd5-1b22-486e-891e-089ba859efc7.png)

- Specular Value Charts
![image](https://user-images.githubusercontent.com/85896566/188292826-ee8fe37b-657c-451b-b9e7-2136987a459b.png)

유니티의 Standard Shader의 몇 가지 중요한 Matarial Parameters는 다음과 같다.

### 렌더링 모드
![image](https://user-images.githubusercontent.com/85896566/188293024-217d63fd-f45b-42ac-8620-59d75a9520c2.png)

|Rendering Mode 옵션|설명|
|---|---|
|Opaque(불투명)|기본값으로 불투명한 텍스처를 표현하는 옵션이다. 투명한 부분이 전혀 없는 Solid 객체에 적합하다.|
|Cutout(그물망 표현)|불투명한 부분과 투명한 부분을 동시에 표현하는 옵션이다. 주로 풀, 그물망 등을 표현할 떄 적합하다.|
|Fade(홀로그램 효과)|투명 속성값을 가진 객체를 페이드 아웃시키는 옵션으로, 페이드 인/아웃을 애니메이션 처리할 수 있다. 불투명한 객체를 부분적으로 페이드 아웃시킬 수 있어 홀로그램 효과를 구현할 수 있다.|
|Transparent(투명)|투명한 플라스틱 또는 유리와 같은 재질을 표현하는 옵션이다.|

### Albedo(알베도)
Albedo는 빛을 반사하는 정도를 말하며, 반사율이라고도 한다.

일반적으로 가장 기본이 되는 텍스처를 연결하는 속성이다.

### Metallic(메탈릭)
Metallic은 객체 표면에 금속의 재질을 표현하기 위한 텍스처다.

슬라이드가 1에 가까워질수록 금속 재질에 가까워진다.

### Normal Map(노멀 맵)
Normal Map은 표면의 세밀한 입체감이나 질감을 표현하기 위한 텍스처의 일종으로 3D 모델링으로 많은 Polygon을 소모하지 않고 같은 효과를 낼 수 있다. 수치가 커질수록 거친 음영효과를 낸다.

### Height Map(하이트 맵)
Height Map은 텍스처로 높낮이를 표현하는 것으로, 노멀 맵과 비슷한 기능을 하지만, 좀 더 돌출시켜 뒤에 있는 사물을 가리는 Occlusion 효과를 낼 수 있다. 슬라이더로 돌출되는 높이를 설정할 수 있다.

### Occlusion(오클루전)
Occlusion은 흑백의 텍스처로 간접조명에 의해 생기는 명암을 더욱 뚜렷이 표시해 사물의 입체감과 깊이감을 살리는 데 사용한다. Occlusion에 사용할 텍스처는 일반적으로 3D 모델링 툴 또는 서드파티 툴에서 추출한다.

### Emission(이미션)
Emission은 스스로 빛을 방출하는 속성을 말한다. 속성값을 변경하면 객체의 표면에서 방출되는 빛의 강도와 빛의 색상을 설정할 수 있는 항목이 나타난다. 또한 하단에 전역 조명에 반영하기 위한 옵션이 나타난다.

### Detail Mask(디테일 마스크)
Detail Mask는 Secondary Maps에 적용할 마스크를 설정하는 텍스처 슬롯이다. 특정 부분만 좀 더 세부적인 텍스처를 표현할 때 사용한다.

#### Info - Standard Shader 세부 정보
유니티의 Standard Shader에 대한 세부 정보는 Unity Documents에서 볼 수 있다.
- [Unity Documents](https://docs.unity3d.com/kr/current/Manual/shader-StandardShader.html)

![image](https://user-images.githubusercontent.com/85896566/188293296-4733085e-90b3-4bd2-b43e-d83e0e4fb071.png)

## Prefab(프리팹)
Prefab의 사전적 의미는 조립식 주택 또는 미리 부품을 만들어 놓고 현장에서는 조립만 하는 건축 기법을 의미한다. 유니티에선 자주 사용하는 객체를 미리 부품처럼 만들어 놓고 재사용할 수 있게 하는 것이다.

프리팹을 복제해서 만든 Clone 객체의 속성은 원본과 일치한다. 따라서 원본 프리팹을 수정하면 그 Clone에게도 수정 사항이 일괄적으로 적용되는 특성이 있다.

100개의 Clone들을 일일이 수정해줄 필요 없이 원본만 수정하면 되는 강력한 기능이다.

### Nested Prefab, 중첩 프리팹
Unity 2018.3 버전부터 지원하기 시작한 Nested Prefab 기능은 프리팹 하위에 다른 프리팹을 추가할 수 있는 기능이다.

- 프리팹 하위에 프리팹을 추가할 수 있기 때문에 개발 효율성을 높인다.
- OOP 개념의 상속이 가능하다. 다른 프리팹을 상속받아 다양한 기능을 추가할 수 있다.
- 프리팹 모드 기능으로 프리팹만 수정할 수 있는 별도의 인터페이스를 제공한다.

### 벽 만들기
Floor 객체의 네 군데 모서리에 배치할 벽을 프리팹으로 만들어 배치하자.

![image](https://user-images.githubusercontent.com/85896566/188293706-ac749403-5a7b-4e09-a74e-9f2f64b82452.png)

머티리얼도 생성한다.

#### TIP - 모바일 최적화 셰이더
자동으로 설정되는 Standard 셰이더는 고품질을 내기 위한 셰이더이기에 모바일 플랫폼에서는 무겁다.

따라서 좀 더 가벼운 "Bumped Diffuse"를 선택해 셰이더를 수정한다.

![image](https://user-images.githubusercontent.com/85896566/188293761-e9359ab9-ccb9-4aac-8c24-b886b71fb0d5.png)

![image](https://user-images.githubusercontent.com/85896566/188293787-719bf82e-971a-4e7d-b928-b4ae073d0514.png)

![image](https://user-images.githubusercontent.com/85896566/188293821-9905b3f9-0323-4680-98b3-5aa4b7247063.png)

아직까진 음영이나 표면의 흠집 같은 세밀함이 표현되지 않는다.

Floor처럼 노멀 맵도 적용해보자.

![image](https://user-images.githubusercontent.com/85896566/188293853-a130964a-62f3-42e5-8329-8b8392a128ac.png)

지금 이 셰이더에선 스페큘러 속성(빛을 반사하는 속성)이 표현되지 않기 때문에 금속 재질을 표현하지 못하는 것은 아쉬운 부분이다.

Legacy Shader/Bumped Specular로 변경해서
Main Color, Specular Color, Shininess 등의 속성을 수정해 재질감을 표현해보자.

![image](https://user-images.githubusercontent.com/85896566/188293924-21ccb24a-3988-4272-b113-d35ef7402a7e.png)

### 프리팹 생성
하이러키 뷰에서 프로젝트 뷰로 드래그 & 드롭하면 같은 이름으로 프리팹이 생성된다.

만약 프리팹 원본이 삭제되어 인스턴스가 끊어진 경우 Clone 객체들은 붉은색 이름으로 바뀌는데, 이 땐 [Prefab] -> [Unpack Completely]를 선택한다.

![image](https://user-images.githubusercontent.com/85896566/188294006-54014407-8611-4d5e-8947-86d2921004cd.png)

### 프리팹의 복제 및 네이밍
객체 복사는 복사할 객체를 지정하고 Ctrl + D를 누르면 넘버링이 붙으며 복제된다.

![image](https://user-images.githubusercontent.com/85896566/188294087-785aedd3-c03c-446a-b25d-5b26285daff6.png)

#### TIP - 복제 네이밍 형식 변경
네이밍 형식은 [Project Settings] -> [Editor]의 "Numbering Scheme"의 "Game Object Naming"을 변경한다.

![image](https://user-images.githubusercontent.com/85896566/188294101-75c58b80-1f50-4e61-aa2e-13a150aeab29.png)

### Snapping(스내핑) 기능
객체가 객체에 붙이기 쉽도록 표면 스내핑(Surface Snapping)과 정점 스내핑(Vertex Snapping) 기능을 제공한다.

사용하려면 Move Tool(W)을 선택해야 한다.

- Vertex Snapping
  - 메시의 꼭짓점과 꼭짓점을 붙이는 기능
  - 먼저 객체간 거리를 벌려준다.

  ![image](https://user-images.githubusercontent.com/85896566/188294201-1ba8f2bb-222f-4dd6-87c3-4dc51d363234.png)

  - 꼭짓점으로 커서를 옮긴 후 (V)키를 누른 상태로 드래그 & 드롭으로 이동 후 객체간 스내핑이 완료되면 (V)키를 릴리스한다.

  ![image](https://user-images.githubusercontent.com/85896566/188294249-0475728f-3b94-49d7-b8eb-057555644548.png)

나머지 벽도 완료된 모습

![image](https://user-images.githubusercontent.com/85896566/188294303-ffaddf34-8369-48cd-ad01-76a5e0fbee6b.png)

## Light(조명)
게임의 분위기와 완성도가 완전히 달라질 수도 있을 만큼 중요한 요소이다. 설치할수록 시각적인 효과는 커지지만, 조명을 처리하기 위한 렌더링 부하는 늘어날 수 밖에 없다. 따라서 최소한의 조명으로 시각적인 효과와 게임 수행 속도 사이의 균형을 맞추는 데 항상 신경 써야 한다.

유니티는 게임의 속도를 저하하지 않고 실시간 조명의 효과를 낼 수 있는 라이트매핑 및 라이트 프로브 기능을 제공한다. 그 내용은 본문 11장에 있다.

유니티가 제공하는 조명은 크게 네 가지가 있다.

### Directional Light
![image](https://user-images.githubusercontent.com/85896566/188294439-d741311c-b089-43cf-b48f-9c4a7636e118.png)

- 전체 화면에 균일한 빛을 비춘다. (태양과 같은 조명)
- 위치는 어디에 있든 관계 없지만(보통 y는 100) 빛을 비추는 각도에 따라 그림자의 방향과 길이가 달라진다.
- 실시간 조명 중에서 가장 비용이 적게 드는 조명이다.

### Point Light
![image](https://user-images.githubusercontent.com/85896566/188294453-31e0394c-9f44-48aa-8e41-d701ac04d330.png)

- 일반 전구와 같은 성격(위치한 좌표 기준 360˚)
- 전역 조명이 아니므로 Range 속성으로 범위 조절

### Spot Light
![image](https://user-images.githubusercontent.com/85896566/188294493-3cde1b63-5812-4e1d-bfcc-d4f01a090566.png)

- Corn 모양의 조명(손전등)
- 실시간 처리 비용이 가장 비싸다.
- 빛이 뻗어 나가는 각도를 조절할 수 있는 Spot Angle 속성이 있다.

### Area Light
![image](https://user-images.githubusercontent.com/85896566/188294870-ea52e9b1-b559-4ae4-a13f-2de2edd55543.png)

![image](https://user-images.githubusercontent.com/85896566/188294884-38c568d3-6b9f-42b8-b430-3e53648b7aa4.png)

- 사각형, 원 형태의 조명으로, 한쪽 면에서 빛을 발하는 조명
- Lighting View에서 라이트맵을 Bake해야만 확인할 수 있다. 따라서 유일하게 실시간 조명이 아니다.
- 주로 간접 조명으로 이용

## 실시간 라이트매핑 기능
유니티는 백그라운드로 라이트맵을 베이킹할 수 있는 기능을 제공한다. 개발 중에 조명의 효과를 볼 수 있어 반복적인 작업에 매우 편리하다.

### Lighting Setting 에셋
먼저 라이팅 뷰에서 해당 씬의 조명 속성을 저장하는 Lighting Settings 에셋을 생성해야 한다.

![image](https://user-images.githubusercontent.com/85896566/188294929-516416fe-d85d-4826-9333-71a9c24d1c66.png)

보관은 Scene 폴더에서 하는 게 적절하다.

### Auto Generate 옵션
라이팅 뷰의 아래에 있는 [Auto Generate] 옵션을 체크하면 실시간 라이트맵을 베이크한다.

![image](https://user-images.githubusercontent.com/85896566/188294951-7bc080a7-943c-4385-8ef3-696a8cf3223a.png)

정식적인 내용은 11장에서...

## 하늘 표현 방식
게임에서 하늘을 표현하는 대표적인 방식으로는 Skybox와 SkyDome이 있다.
- Skybox
  - 카메라가 볼 수 있는 하늘의 여섯 방면(left, front, right, back, top, bottom)의 이미지를 Cube 형태로 배치해 표현한다.

- Skydome
  - 돔 형태이 메시에 하늘의 이미지 텍스처를 입혀 구현한다.

### 6 sided skybox(6방면 스카이박스)
먼저 머티리얼을 생성하고, 셰이더의 콤보 박스에서 [Skybox] -> [6sided]를 선택한다. 이후에 준비한 텍스처들을 연결한다.

![image](https://user-images.githubusercontent.com/85896566/188295083-b7b8f124-1118-4580-b1eb-fe764f08f108.png)

### 스카이박스 적용
완성된 Skybox 머티리얼을 라이팅 뷰의 Environment 탭에서 Skybox Material 속성에 드래그 & 드랍한다. 또는 단순히 씬 뷰의 빈 공간에 드래그 & 드랍해도 된다.

![image](https://user-images.githubusercontent.com/85896566/188295111-a0bbf8f2-1fd7-4d90-86e9-3bf3b0bd4162.png)

### Procedural Skybox(프로시저럴 스카이박스)
- 텍스처를 적용하지 않고 하늘의 색상, 대기 농도, 노출(밝기), 태양의 위치와 크기 등을 설정 가능
- 유니티 프로젝트를 처음 열었을 때 이 스카이박스가 적용되어 있다.
- Default-Skybox는 여러가지 설정값을 변경할 수 없으므로 별도의 머티리얼로 만들어야 함

머티리얼 적용 방법은 아까와 같이 셰이더 콤보 박스에서 [Procedural]을 선택한다.

아래의 표는 프로시저럴 스카이박스의 속성별 기능이다.

|속성|설명|
|---|---|
|Sun|None : 태양 이미지를 표시하지 않음<br>Simple : 태양 주변에 헤일로(Halo) 처리를 하지 않음<br>High Quality : 태양 주변에 헤일로 처리|
|Sun Size|태양 이미지 크기 조절|
|Sun Size Convergence|태양 주변의 퍼지는 빛의 범위를 조절 (High Quality일 때만 표시됨)|
|Almosphere Thickness|대기 농도 : 청명하거나 탁한 정도를 조절|
|Sky Tint|하늘 색상 조절|
|Ground|대지 색상 조절|
|Exposure|노출 조절|

![image](https://user-images.githubusercontent.com/85896566/188295365-d571e7c2-d65d-40f3-a464-e388f401a442.png)

태양 위치를 변경하는 부분은 라이팅 뷰의 Environment 탭에서 Sun Source 속성에 기본 생성된 Directional light의 위치와 각도를 변경하면 된다.

![image](https://user-images.githubusercontent.com/85896566/188295459-32d85af5-41f0-415d-a99a-d046667e90f2.png)

### Cubemap Skybox(큐브맵 스카이박스)
이 방식은 먼저 큐브맵을 생성한 후 하늘을 표현한다. 큐브맵은 6 sided skybox와 마찬가지로 6장의 텍스처가 필요하며 주변 환경을 반사하는 효과에 주로 사용한다.

이 스카이박스를 적용하려면 여섯 방면의 이미지가 한 장의 텍스처에 있어야 하며, Texture Type을 Cubemap으로 설정해야 한다.

다만 한 장의 텍스처에 여섯 방면의 이미지를 합칠 때는 다음과 같은 세 가지 방식으로 작업해야 한다.

|매핑 타입| 이미지 형태|
|---|---|
|6 Frame Layout(Cube Environment)|여섯 방면의 이미지를 평면으로 배치|
|Latitude-Longitude(Cylindrical)|파노라마 이미지로 실린더 형태의 이미지|
|Mirrored Ball(Spheremap)|구체(Sphere) 이미지|

#### TIP - 큐브맵 정보
큐브맵 생성에 관한 자세한 내용은 다음 페이지를 참조한다.

- [Unity Documents](https://docs.unity3d.com/Manual/class-Cubemap.html)

![image](https://user-images.githubusercontent.com/85896566/188295724-4b4759c0-2b5b-455f-81a7-573ff0d1874d.png)

#### Info - 여섯 방면 스카이박스의 DrawCall(드로우콜) 소모량
6 sided skybox는 6개의 텍스처를 사용하므로 기본적으로 6 드로우콜을 소모하지만, 큐브맵 스카이박스와 프로시저럴 스카이박스는 1 드로우콜만 소모하므로 좋은 대안이 될 수 있다. 또한 Sky Dome 역시 1장의 텍스처를 사용할 경우 1 드로우콜만 소모하므로 드로우콜을 낮출 수 있다는 장점이 있다.

하지만 게임의 특성에 따라 카메라가 볼 수 있는 최대거리(Far clipping Plane)를 제한해야 할 때는 Sky Dome 방식을 적용하는 것은 적합하지 않을 수 있다.

## 정리
이번 장에서는 게임의 무대가 되는 스테이지를 제작했다.

<br>

---

# ※ 04장 : 주인공 캐릭터 제작
## 3D 모델 불러오기
3D 모델을 씬 뷰 또는 하이러키 뷰로 드래그 & 드랍하여 배치

Transfrom의 Position값이 원점(0, 0, 0)인지 확인할 것

![image](https://user-images.githubusercontent.com/85896566/188297777-86d0b117-d4de-4da9-a807-6809be21297d.png)

## 유니티 엔진의 개발 방식
유니티는 2가지 개발 방식을 지원한다.
- 컴포넌트 기반의 개발(CBD, Component Based Development)
- 데이터 기반의 개발(DOTS, Data Oriented Technology Stack)
  - 멀티스레드 기반
  - 초보자가 접하기에는 어렵다.
  - 개발 중인 기능이 많아 안정화 버전이 나올 때까지는 상용으로 사용하기에 위험부담이 크다.

### 컴포넌트 기반의 개발 방식
CBD 방식은 일종의 소프트웨어 개발 방법론으로, 독립적인 기능 단위로 컴포넌트를 제작한 다음 필요한 기능을 조립하는 방식을 말한다.

이 개발 방식의 장점은 컴포넌트의 재사용이 가능하고 높은 생산성이다.

컴포넌트는 인스펙터 뷰에서 확인할 수 있다.

그 중에서 어느 객체라도 Transform 컴포넌트는 유일하게 삭제할 수 없다.

트랜스폼 컨포넌트는 해당 게임오브젝트의 3차원 위치, 각 축에 대한 각도 및 스케일 속성을 가진다. 따라서 3차원 공간에서 어떤 객체가 존재하려면 이러한 정보가 반드시 있어야 하므로 삭제할 수 없는 컴포넌트이다.

## C# 스크립트
유니티의 엔진의 코어 부분은 C++로 제작됐고 초기 버전에서는 자바스크립트 문법을 차용한 UnityScript를 지원했지만, 2017년 부터 C# 언어만 지원한다.

C#은 C++, 자바 언어의 장점을 차용한 Managed Language(메모리 자동 연산 언어)로써 국내외를 막론하고 많이 사용되는 인기 있는 언어이다.

고급 문법은 이 책에선 다루지 않는 거 같다.

### 스크립트 코드 에디터
나는 주로 Visual Studio 2022를 개발 도구로 사용한다.

블로그 포스팅은 마크다운 프리뷰어 익스텐션을 사용하기 위해 VSCode를 사용한다.

### 추천하는 코드 에디터
VS20xx, VSCode, JetBrains Rider 등을 유니티 개발에 추천하고 있다.

### 코드 에디터 변경
Preferences의 [External Tools] 섹션의 External Script Editor에서 서드파티 에디터를 선택한다.

![image](https://user-images.githubusercontent.com/85896566/188298218-246be729-5668-47dc-8823-c87af080bd85.png)

만약 VSCode를 스크립트 에디터로 사용한다면 코드 자동완성 기능을 사용하기 위해 C# 확장 패키지를 설치해야 한다.

- [바로가기](https://code.visualstudio.com/docs/other/unity)

### C# 스크립트 생성


### 유니티의 주요 이벤트 함수
### 이벤트 함수의 호출 순서
## 키보드 입력값 받아들이기
### InputManager
### GetAxis 함수
### 스크립트 적용 방식
### GetAxisRaw 함수
## 캐릭터의 이동
### Vector3 구조체
### 정규화 벡터
### 컴포넌트 캐시 처리
### Translate 함수
### Time.dletaTime
### public, private 접근 제한자
### 인스펙터 뷰에 노출된 변수의 우선순위
### private 변수의 인스펙터 뷰 노출
### 벡터의 덧셈 연산
## 캐릭터 회전 - Rotate
### 씬 뷰에서 가상 카메라의 이동
## 애니메이션
### 애니메이션 클립
### 애니메이션 적용
### 애니메이션 블렌딩
## 무기 장착
## 그림자
### 실시간 그림자
### 메시를 이용한 그림자
## Level Of Detail 설정
### LOD Group Component
## Follow Camera 로직
### Vecotr3.Lerp, Vector3.Slerp
### Vector3.SmoothDamp
### Target Offset 적용
## 정리

<br>

---

# ※ 05장 : 총 발사 로직
## 총알 모델 준비
## Rigidbody Component
## Physics Manager(물리 엔진 속성 설정)
## Collider Component
### Box Collider
### Sphere Collider
### Capsule Collider
### Mesh Collider
### Wheel Collider
### Terrain Collider
## 충돌 감지 조건
## 충돌 이벤트
## Tag 이용
### OnCollisionEnter 콜백 함수
### CompareTag 함수
### Bullet의 프리팹 전환
## 총알 발사 로직
### 총알의 발사 위치
### 런 모드에서 수정한 속성
### 기즈모의 활용
### 스크립트 작성 방식
## Trail Renderer(총알 발사 궤적 효과)
### Trail Renderer
### 프리팹의 변경 내용 조회 및 저장
## 파티클 활용하기
### 충돌 지점과 법선 벡터
### Quaternion
## 폭발 효과 및 폭발력 생성
### Scale Factor
### 하이러키 뷰의 간략화
## Mesh Renderer(텍스처 변경)
### 폭발력 적용하기 - AddExplosionForce
### OverlapSPhereNonAlloc
## Audio
### AudioListener, AudioSource Component
### 오디오 파일 임포트 및 설정
### 오디오 임포트 옵션 - Load Type
### 오디오 임포트 옵션 - Compression Format
### 총소리 구현
## 총구 화염 효과 - Muzzle Flash
### 코루틴 함수
### MuzzleFlash의 블링크 효과
### MuzzleFlash의 텍스처 오프셋 변경
### 코루틴의 응용 - 임계치
## 정리

<br>

---

# ※ 06장 : 적 캐릭터 제작
## 유한 상태 머신의 정의
## 메카님
### 적 캐릭터 3D 모델 임포트
### 메카님 애니메이션으로 전환
### 애니메이션 클립 속성
### 애니메이션 리타게팅
### Animator Component
## 애니메이터 컨트롤러
### 스테이트 전이와 파라미터
## 내비게이션 - 적 캐릭터의 순찰 및 추적
### 내비게이션 설정 - Navigation Static Flag
### 내비메시 베이크
### NavMeshAgent Component
## 유한 상태 머신 구현
### 적 캐릭터의 상태 체크
### 적 캐릭터의 행동 구현
### 애니메이션 동기화
### 몬스터 공격 루틴
### 몬스터 피격 리액션
## 혈흔 효과
### Resources 폴더
## 적 캐릭터의 공격 능력
### OnTriggerEnter 콜백 함수
## 특정 레이어 간의 충돌 감지
## 본 구조의 최적화
## 몬스터 공격 중지
### 애니메이션의 재생 속도 조절
## 사용자 정의 이벤트 - Delegate
### 델리게이트
### 주인공의 사망 이벤트 처리
## 몬스터의 사망 처리
### Root Transform Position
## 정리

<br>

---

# ※ 07장 : 유니티 UI 시스템
## 유니티 UI 구현 형태
### IMGUI
### UI Toolkit
### Unity UI
### UI 리소스 준비
## Canvas 객체
### EventSystem 객체
### Canvas 객체의 Component
## Canvas Component
### Screen Space - Overlay
### Screen Space - Camera
### World Space
## Rect Transform Component
## 앵커 프리셋
### 기본 앵커 프리셋
### Alt 키 조합의 앵커 프리셋
### Shift 키 조합의 앵커 프리셋
### Alt + Shift 키 조합의 앵커 프리셋
### anchoredPosition 속성
### Anchors 속성
## Image Component
### Simple
### Sliced
### Tiled
### 텍스처의 Wrap Mode
### Filled
## RawImage Component
## Button Component
### Transition 속성
### Navigation
### Button Event
## Text Component
## 스크립트에서 버튼 이벤트 처리하기
### 람다식
## TextMesh Pro
### TextMesh Pro의 필수 리소스 설치
### Text - TextMesh Pro
### TextMesh Pro의 한글 처리
### KS X 1001 규격의 한글 2350자
## 생명 게이지 구현
## 정리

<br>

---

# ※ 08장 : 게임 매니저
## 적 캐릭터의 출현 로직
### SpawnPointGroup 생성
### GameManager 객체 생성
### Invoke, InvokeRepeate 함수
## 싱글턴 디자인 패턴
## 오브젝트 풀링
## 스코어 UI 구현
### Playerprefs를 활용한 스코어 저장
## 정리

<br>

---

# ※ 09장 : 레이캐스트 활용
## 레이캐스트
### DrawRay
### Raycast, RaycastHit
## 정리

<br>

---

# ※ 10장 : 내비게이션 고급 기법
## 동적 장애물
### NavMeshObstacle Component
## Off Mesh Link Generation
## 사용자 정의 Off Mesh Link
## 자연스러운 회전 처리
## Area Mask의 활용
### 경로의 가중치
## 정리

<br>

---

# ※ 11장 : 라이트매핑 및 라이트 프로브
## 전역 조명
## 조명 모드
### Realtime 모드
### Mixed 모드
### Baked 모드
## 라이트매핑
### Generate Lightmap UVs Option
### Lightmap Static 플래그
### 라이팅 뷰
### Progressive 라이트매퍼
### 라이팅 뷰의 Environment
### Baked 라이트매핑
### 라이트맵 베이크
### Area Light
## 라이트 프로브
### Light Probe Group
### Anchor Override
## 정리

<br>

---

# ※ 12장 : 씬 관리
## Scene 분리
## Scene 병합
## Multi Scene Edit
## 정리

<br>

---

# ※ 13장 : 오클루전 컬링
## 컬링 방식
### 프리스텀 컬링
### 거리 비례에 의한 컬링
### 오클루전 컬링
## 오클루전 컬링 실습
### Occluder Static, Occludee Static
## 정리

<br>

---

# ※ 14장 : Input System
## 레거시 Input 클래스
## 새로운 Input System의 특징
### Input System의 구조
### Input System의 환경 설정
### Input System 패키지 설치
### Active Input Handling
### 테스트 환경 제작
### Input Action 에셋
### Control Schemes
### Action Map 및 Action 생성
### 바인딩 속성 설정
### 이동 동작의 바인딩 추가
### 공격 동작의 액션과 바인딩 추가
## Player Input Component
### Action 속성
### Behavior 속성
### Behavior - Send Messages Option
### Behavior - Invoke Unity Events Option
### Behavior - Invoke C Sharp Events
### Direct Binding
## Input Debug
## 정리
  
<br>

---

# ※ 15장 : 포톤 클라우드를 활용한 네트워크 게임