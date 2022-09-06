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
- 프로젝트 폴더 설정
- 사용할 리소스 설치

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
- 스테이지 디자인
- 스카이박스 적용

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
프로젝트 뷰 우클릭 [Create] -> [C# Script] 선택

스크립트 네임은 클래스명이 된다.

프로젝트 뷰의 스크립트 파일 이름을 변경하면 클래스명은 수동으로 변경해주어야 컴파일 에러가 나지 않는다.

![image](https://user-images.githubusercontent.com/85896566/188548878-6e37fdfa-95bd-4ecb-868a-9636e63ee827.png)

### 유니티의 주요 이벤트 함수(P.122)
유니티의 생명주기(Life Cycle)에 대한 내용은 본 블로그의 다른 게시물에 정리되어 있다.
- [바로가기](https://ugee99.github.io/posts/Unity-LifeCycle/)

### 이벤트 함수의 호출 순서
```c#
    private void Awake()
    {
        // 주로 게임의 상태 값, 변수의 초기화에 사용
        // 가장 처음 1회 실행
        // 스크립트가 비활성화돼 있어도 실행된다.
        // Coroutine으로 실행 불가능
    }

    private void Start()
    {
        // Awake() -> OnEnable() -> Start()
        // Update함수 호출 전에 호출
        // Coroutine으로 실행 가능
    }

    private void Update()
    {
        // 프레임마다 호출
        // 호출 간격이 불규칙적임
        // 화면의 렌더링 주기와 일치
        // 주로 게임의 핵심 로직을 작성
    }

    private void LateUpdate()
    {
        // Update 함수가 종료된 후 호출
        // 모든 Update()가 호출되고 나서 한 번씩 호출
        // 주로 Update()에서 전처리가 끝난 후 실행해야 하는 로직에 사용
    }

    private void FixedUpdate()
    {
        // 일정한 간격으로 호출(Default 0.02/s)
        // 물리 엔진의 계산 주기와 일치
    }

    private void OnEnable()
    {
        // 게임 오브젝트 또는 스크립트가 Enable될 때마다 호출
        // 주로 사용자 정의 이벤트 연결에 사용
        // Coroutine으로 실행 불가능
    }
    
    private void OnDisable()
    {
        // 게임 오브젝트 또는 스크립트가 Disable될 때 호출
        // 주로 이벤트 연결을 종료할 때 사용
        // Coroutine으로 실행 불가능
    }
```

## 키보드 입력값 받아들이기
유니티에서 제공하는 Input Class는 외부(키보드, 마우스, 조이패드 등)에서 들어오는 입력값을 관리하는 클래스다. InputSystem의 내용은 14장에서 따로 다룬다.

### InputManager
![image](https://user-images.githubusercontent.com/85896566/188550882-7e4b6a8a-80f3-489d-825c-b792c4475899.png)

키본적으로 정의되어 있는 내용도 있고, 추가도 가능하다.

### GetAxis()
미리 설정한 키 조합의 반환값 가져오는 함수.

```c#
    private void Update()
    {
        float h = Input.GetAxis("Horizontal"); // -1.0f ~ 0.0f ~ +1.0f
        float v = Input.GetAxis("Vertical");   // -1.0f ~ 0.0f ~ +1.0f 

        Debug.Log("h : " + h);
        Debug.Log("v : " + v);
    }
```

![image](https://user-images.githubusercontent.com/85896566/188551483-3303abd6-baa4-4d1e-b441-2329bf659627.png)

### 스크립트 적용 방식
- Scene View에 적용할 객체에게 스크립트를 드래그 & 드랍
- 하이러키 뷰의 적용할 객체에게 스크립트를 드래그 & 드랍
- 적용할 객체의 인스펙터 뷰에 스크립트를 드래그 & 드랍(권장)
- 적용할 객체의 인스펙터 뷰에서 Add Component로 스크립트 검색

#### TIP - 잘못 추가된 에셋을 찾는 방법
![image](https://user-images.githubusercontent.com/85896566/188551938-5e9f8a02-3b51-4ca4-8b5e-83d1ef5a894f.png)

![image](https://user-images.githubusercontent.com/85896566/188551969-9497974f-190c-4586-8d80-564955b34a6a.png)

스크립트 뿐만 아니라 모든 에셋(머티리얼, 프리팹, 리소스 등)도 이와 같은 방법으로 조회 가능하다.

#### Info - Input에 정의되지 않은 축 이름을 사용했을 때 발생하는 오류
![image](https://user-images.githubusercontent.com/85896566/188552232-9e13a7d6-a365-4594-ae97-080d0df640dc.png)

스크립트에서 InputManager에 정의된 키 값의 이름을 문자열로 받게 되면 컴파일 에러가 발생하지 않는다.

따라서 이와 같은 에러가 발생하면 대/소문자, 띄어쓰기 등을 확인할 것.

### GetAxisRaw()
Input.GetAxis("Horizontal")는 -1.0f ~ +1.0f 사이의 연속적인 값을 반환한다. 따라서 부드러운 이동이 필요할 때는 GetAxis()를 사용한다. 하지만 키보드 입력값에 따라 방향을 즉시 바꾸거나 속도를 변경해야할 땐Input.GetAxisRaw("Horizontal")를 사용해야 한다. GetAxisRaw는 불연속적인(이산, Discrete) -1.0f, 0.0f, +1.0f의 세 가지 값만 변환한다.

## 캐릭터의 이동
유니티에서 어떤 물체를 이동시키거나 회전시키는 방법은 2가지로 분류할 수 있다.
- 모든 게임오브젝트에 있는 Transform Component의 Position, Rotation 속성값을 변경하는 것
- 유니티 엔진에 내장된 물리 엔진을 이용해 물리적인 힘(Force) 또는 회전력(Torque)를 가해 변경시키는 것

쉽게 말해
- Tranform Component를 이용
- 물리 엔진(PhysX, Box2D)을 사용

애니메이션으로도 이동 및 회전을 할 수 있다. 하지만 이것 역시 Transform Component의 속성값을 연속적으로 기록한 것을 재생하는 것이기 때문에 Transform Component를 이용하는 방법이다.

아래의 코드는 Player - '이동 로직 추가'이다.

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerCtrl : MonoBehaviour
{
    private void Update()
    {
        float h = Input.GetAxis("Horizontal"); // -1.0f ~ 0.0f ~ +1.0f
        float v = Input.GetAxis("Vertical");   // -1.0f ~ 0.0f ~ +1.0f 

        // Transform Component Position 속성값 변경
        transform.position += new Vector3(0, 0, 1);
    }
}
```

누적 대입 연산자로 인해 프레임마다 z축만 +1되는 코드이다.

### Vector3 구조체
유니티에서 3차원 좌표에 대한 개념을 익히려면 Vector3 구조체에 대해 알아야 한다. 이는 3차원 벡터와 좌푯값을 저장하기 위한 용도로 사용되며, 다음 코드는 Vector3 구조체의 일부분이다. 3차원 x, y, z 값이 float로 선언된 것과 방향을 지시하는 약칭(Shorthand)를 볼 수 있다.

```c#
public struct Vector3 : IEquatable<Vector3>, IFormattable
    {
        public const float kEpsilon = 1E-05f;

        public const float kEpsilonNormalSqrt = 1E-15f;

        //
        // 요약:
        //     X component of the vector.
        public float x;

        //
        // 요약:
        //     Y component of the vector.
        public float y;

        //
        // 요약:
        //     Z component of the vector.
        public float z;

        private static readonly Vector3 zeroVector = new Vector3(0f, 0f, 0f);

        private static readonly Vector3 oneVector = new Vector3(1f, 1f, 1f);

        private static readonly Vector3 upVector = new Vector3(0f, 1f, 0f);

        private static readonly Vector3 downVector = new Vector3(0f, -1f, 0f);

        private static readonly Vector3 leftVector = new Vector3(-1f, 0f, 0f);

        private static readonly Vector3 rightVector = new Vector3(1f, 0f, 0f);

        private static readonly Vector3 forwardVector = new Vector3(0f, 0f, 1f);

        private static readonly Vector3 backVector = new Vector3(0f, 0f, -1f);
        [중략...]
```

다음 표에 제시된 것은 Vector3 구조체의 여러 속성 중에서 자주 사용되는 속성이다.

|속성|설명|
|---|---|
|magnitude|벡터의 길이(read only)|
|normalized|크기가 1인 벡터, 정규화 벡터(read only)|
|sqrMagnitude|벡터의 길이의 제곱(read only)|
|x|벡터의 x 성분(3차원 공간의 x 좌표|
|y|벡터의 y 성분(3차원 공간의 y 좌표|
|z|벡터의 z 성분(3차원 공간의 z 좌표|

### Normalized Vector(정규화 벡터)
Vector는 크기와 방향을 나타낼 수 있는 데이터 타입으로, 그 중 각 축의 크기가 1인 벡터를 정규화 벡터(Normalized Vector)라 한다. 즉, 방향만 표시하는 벡터라고 생각하면 된다.

Vector3 구조체에서 제공하는 방향을 가리키는 정규화 벡터는 다음과 같다.

|Shorthand|의미|
|---|---|
|Vector3.forward|Vector3(0, 0, 1)|
|Vector3.back|Vector3(0, 0, -1)|
|Vector3.left|Vector3(-1, 0, 0)|
|Vector3.right|Vector3(1, 0, 0)|
|Vector3.up|Vector3(0, 1, 0)|
|Vector3.down|Vector3(0, -1, 0)|
|Vector3.one|Vector3(1, 1, 1)|
|Vector3.zero|Vector3(0, 0, 0)|

![image](https://user-images.githubusercontent.com/85896566/188555682-09b0c0b8-c8f6-48eb-986d-8342b5b6fcff.png)

유니티는 왼손 좌표계를 사용한다.

따라서 Vector3.forward가 z축 +1이라는 것을 이해할 수 있다.

```c#
    private void Update()
    {
        float h = Input.GetAxis("Horizontal"); // -1.0f ~ 0.0f ~ +1.0f
        float v = Input.GetAxis("Vertical");   // -1.0f ~ 0.0f ~ +1.0f
                                               
        // 정규화 벡터를 사용한 코드
        transform.position += /*전진 방향*/Vector3.forward * /*속력*/1;
    }
```

### 컴포넌트 캐시 처리
Update()의 사용엔 항상 최적화에 주의를 기울여야 한다. 조금이라도 부하가 걸리는 함수나 잘못된 로직은 피해야 한다. 특히 프레임마다 Transform Component에 접근하는 이동 방식은 바람직하지 않다.

앞서 Update()내에서 Transform Component의 멤버 변수 transform을 사용했는데, 이를 미리 변수에 담아 두고 해당 변수에 접근하는 방식이 미세하지만 빠르다. 따라서 컴포넌트의 캐시 처리란 스크립트에서 접근해야 할 컴포넌트를 Awake()나 Start()에서 미리 변수에 할당한 후에 그 변수를 통해 접근하는 것을 말한다.

```c#
public class PlayerCtrl : MonoBehaviour
{
    Transform tr;

    private void Start()
    {
        // Transform Component를 추출해 변수에 대입
        tr = GetComponent<Transform>();
    }
    [중략...]
}
```

#### Info - GetComponent 함수의 사용법
```c#
tr = GetComponent<Transform>();
tr = GetComponent("Transform") as Transform;
tr = (Transform)GetComponent(typeof(Transform));
```

위에 열거한 방법은 모두 같은 의미이다.

또, Start()에서 tr 변수에 할당하는 구문은 아래 코드를 축약한 것이다.

C#에서 this는 해당 클래스(스크립트)를 뜻함.

```c#
tr = this.gameobject.GetComponent<Transform>();

"이 스크립트가 포함된 게임 오브젝트가 가진 여러 컴포넌트 중에서 Transform 컴포넌트를 추출해 tr 변수에 저장한다."
```

### Translate()
이 함수는 게임 오브젝트의 이동 처리를 편하게 할 수 있는 함수로서, 함수의 원형은 다음과 같다.

```c#
void Translate(Vector3 direction, [Space relativeTo])
```

이 함수로 Transform Component의 Position 속성값을 계산해 이동하는 복잡한 방식의 코딩을 예방할 수 있다.

Translate()의 두 번째 인자는 기준 좌표계인데, 인자를 생략하면 로컬 좌표를 기준으로 한다.
- Space.World(월드 좌표계)
- Space.Self(로컬 좌표계)

이 함수를 이용해 수정한 PlayerCtrl 스크립트는 다음과 같다.
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerCtrl : MonoBehaviour
{
    // 컴포넌트 캐시 처리할 변수
    Transform tr;

    private void Start()
    {
        // Transform Component를 추출해 변수에 대입
        tr = GetComponent<Transform>();
    }

    private void Update()
    {
        float h = Input.GetAxis("Horizontal"); // -1.0f ~ 0.0f ~ +1.0f
        float v = Input.GetAxis("Vertical");   // -1.0f ~ 0.0f ~ +1.0f

        // Translate()를 이용한 이동 로직
        tr.Translate(Vector3.forward * 1);
    }
}
```

### Time.dletaTime
Time.dletaTime은 이전 프레임의 시작 시각부터 현재 프레임이 시작되는 시간의 차(델타)를 말한다. 쉽게 풀이하면 이전 프레임부터 현재 프레임까지 걸린 시간의 차다.

Update()는 프레임에 따라 호출 되는데, 이 횟수가 기기의 성능마다 다르므로 속도가 달라지는 문제가 발생한다. 이 문제는 Time.dletaTime을 곱해주는 것으로 해결할 수 있다.

30프레임은 1/30초, 60프레임은 1/60초를 해주어 프레임 레이트가 서로 다른 기기에서도 개발자가 정한 일정한 속도로 이동시킬 수 있다.

```c#
tr.Translate(Vector3.forward * Time.deltaTime * 1);
```

- Time.deltaTime을 곱하지 않으면 -> 프레임당 지정한 유닛만큼 이동
- Time.deltaTime을 곱하면 -> 초당 지정한 유닛만큼 이동

특히 Update()에 이동 및 회전 로직을 작성했다면 반드시 Time.deltaTime 속성을 사용해야 한다.

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerCtrl : MonoBehaviour
{
    // 컴포넌트 캐시 처리할 변수
    Transform tr;

    public float moveSpeed = 10.0f;

    private void Start()
    {
        // Transform Component를 추출해 변수에 대입
        tr = GetComponent<Transform>();
    }

    private void Update()
    {
        float h = Input.GetAxis("Horizontal"); // -1.0f ~ 0.0f ~ +1.0f
        float v = Input.GetAxis("Vertical");   // -1.0f ~ 0.0f ~ +1.0f

        // Translate()를 이용한 이동 로직
           tr.Translate(v * Vector3.forward * moveSpeed * Time.deltaTime);
        // tr.Translate({전진/후진 변수} * {이동할 방향} * {속도} * Time.deltaTime);
    }
}
```

### public, private 접근 제한자
C#에서 지원하는 접근 제한자는 public, private, protected, internal이 있다. 접근 제한자는 외부 클래스(구조체), 멤버 변수 등의 접근을 허용하는 범위를 지정한다.

|접근 제한자|설명|
|---|---|
|public|외부 클래스(외부 스크립트)에서 접근 가능|
|private|동일 클래스(스크립트 內)에서만 접근 가능. 외부에서는 불가능|
|protected|private과 동일하게 외부에선 접근이 불가능하고, 상속받은 파생 클래스에서만 접근 가능|
|internal|같은 어셈블리에서만 접근 가능. 클래스의 경우 접근 제한자를 생략하면 internal이 기본값으로 설정됨|

유니티에서 public으로 선언한 변수는 인스펙터 뷰의 프로퍼티로 노출돼 값을 직접 수정할 수 있다. 반대로 private 접근 제한자로 설정된 변수는 노출되지 않는다.

### 인스펙터 뷰에 노출된 변수의 우선순위
public으로 접근되는 변수의 변경은 인스펙터 뷰가 우선이다. 즉, 스크립트에선 10의 속도를 주었는데, 인스펙터 뷰에선 20으로 변경했을 때 게임에 적용되는 속도는 20으로 지정되어 있다.

### private 변수의 인스펙터 뷰 노출
인스펙터 뷰의 모드를 디버그 모드로 설정하면 private 변숫값도 확인할 수 있다.

![image](https://user-images.githubusercontent.com/85896566/188562761-eaa1b8b1-7ecf-49e3-8e7d-cdfd27930333.png)

또 다른 방법은 SerializeField 속성(Attribute)을 사용하는 것이다. 이 방법은 디버그 모드가 아니여도 private 접근 지시자의 속성을 유지한 채 인스펙터 뷰에 노출하는 기능이다.

```c#
[SerializeField] Transform tr;
```

### 벡터의 덧셈 연산
이제 플레이어의 좌우 이동을 구현하기 위해 Vector3.right의 +, -값을 곱한다.

```c#
    private void Update()
    {
        float h = Input.GetAxis("Horizontal"); // -1.0f ~ 0.0f ~ +1.0f
        float v = Input.GetAxis("Vertical");   // -1.0f ~ 0.0f ~ +1.0f

        // 전후좌우 이동 방향 벡터 계산
        Vector3 moveDir = (Vector3.forward * v) + (Vector3.right * h);

        // Translate(이동 방향 * 속력 * Time.deltaTime) 이동 로직
        tr.Translate(moveDir * moveSpeed * Time.deltaTime);
    }
```

플레이했을 때 대각선 이동은 빠른 감이 있었다. moveDir 변수는 Vector3 타입으로, 키보드 입력값을 이용해 벡터 연산을 했다. 전진 방향의 벡터와 좌우 방향의 벡터를 덧셈 연산하면 대각선 방향의 벡터가 생성된다. 이 대각선 벡터의 길이는 피타고라스의 정리ˇ에 의해 루트2(약 1.414・・・)임을 알 수 있다.

- 피타고라스의 정리
  ![image](https://user-images.githubusercontent.com/85896566/188564473-78ea0ee1-c225-49af-8880-6e96bd6b9f41.png)

대각선으로 이동할 때 속도가 빨라진 원인이다. 따라서 길이가 1인 벡터로 변환해 방향 성분만 사용해야 한다. 이처럼 길이가 1인 벡터를 '단위 벡터' 또는 '정규화 벡터(Normalized Vector)'라고 앞서 언급했다.

벡터의 방향 성분만 추출하기 위해 정규화 벡터로 변경하려면 Vector3.normalized 속성을 이용해 정규화 벡터값을 사용한다. 즉, Vector3 타입으로 선언한 moveDir 변수는 vormalized 속성을 이용할 수 있다.

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerCtrl : MonoBehaviour
{
    Transform tr; // 컴포넌트 캐시 처리할 변수

    public float moveSpeed = 8.0f;

    private void Start()
    {
        tr = GetComponent<Transform>(); // Transform Component를 추출해 변수에 대입
    }

    private void Update()
    {
        float h = Input.GetAxis("Horizontal"); // -1.0f ~ 0.0f ~ +1.0f
        float v = Input.GetAxis("Vertical");   // -1.0f ~ 0.0f ~ +1.0f
        Vector3 moveDir = (Vector3.forward * v) + (Vector3.right * h); // 전후좌우 이동 방향 벡터 계산
        tr.Translate(moveDir.normalized * moveSpeed * Time.deltaTime); // Translate(이동 방향 * 속력 * Time.deltaTime) 이동 로직
    }
}
```

#### Info - 벡터의 크기와 정규화
벡터의 크기(magnitude)는 Vector3.magnitude 함수를 이용해 가져올 수 있다.

```c#
    private void Start()
    {
        float vec1 = Vector3.Magnitude(Vector3.forward);
        float vec2 = Vector3.Magnitude(Vector3.forward + Vector3.right);
        float vec3 = Vector3.Magnitude((Vector3.forward + Vector3.right).normalized);

        Debug.Log("vec1 : " + vec1);
        Debug.Log("vec2 : " + vec2);
        Debug.Log("vec3 : " + vec3);
    }
```

![image](https://user-images.githubusercontent.com/85896566/188566506-10e63054-257c-4d3f-9960-b9e96fcf7074.png)

## 캐릭터 회전 - Rotate
게임 오브젝트를 회전할 때는 Transform.rotation 속성값을 변경하거나 Rotate 계열의 함수를 사용할 수 있다. 가장 기초적인 Rotate()는 다음과 같은 다양한 인자를 사용할 수 있다.

```c#
- void Rotate(new Vector3 eulerAngles, [Space relativeTo]);
- void Rotate(float xAngle, float yAngle, float zAngle, [Space relativeTo]);
- void Rotate(Vector3 axis, float angle, [Space relativeTo]);
```

다음 코드는 Update()에서 Rotate()의 인자에 Y축에 Time.deltaTime을 곱해서 시계방향으로 회전하는 것을 볼 수 있다. Rotate()의 인자는 모두 다르지만 전부 같은 의미이다.

```c#
void Update()
{
  transform.Rotate(Vector3.up * Time.deltaTime);
  transform.Rotate(0, Time.deltaTime, 0);
  transform.Rotate(Vector3.up, Time.deltaTime);
}
```

PlayerCtrl.cs

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerCtrl : MonoBehaviour
{
    Transform tr; // 컴포넌트 캐시 처리할 변수

    public float moveSpeed = 8.0f;
    public float turnSpeed = 80.0f;

    private void Start()
    {
        tr = GetComponent<Transform>(); // Transform Component를 추출해 변수에 대입
    }

    private void Update()
    {
        float h = Input.GetAxis("Horizontal");
        float v = Input.GetAxis("Vertical");
        float r = Input.GetAxis("Mouse X");

        Vector3 moveDir = (Vector3.forward * v) + (Vector3.right * h); // 전후좌우 이동 방향 벡터 계산
        tr.Translate(moveDir.normalized * moveSpeed * Time.deltaTime); // Translate(이동 방향 * 속력 * Time.deltaTime) 이동 로직
        tr.Rotate(r * Vector3.up * turnSpeed * Time.deltaTime);        // Vector3.up 축을 기준으로 turnSpeed만큼의 속도로 회전
    }
}
```

### 씬 뷰에서 가상 카메라의 이동
씬 뷰의 가상 카메라가 오브젝트를 추적하게 하려면

1. 하이러키 뷰에서 추적할 객체를 선택
2. Shift + F 또는 [Edit] -> [Lock View to Selected]
3. 플레이

![image](https://user-images.githubusercontent.com/85896566/188568795-b3ee7e17-c0ed-4e09-b940-7af97299865c.png)

## Animation
유니티는 Legacy Animation과 Mecanim Animation이라는 두 가지 유형의 애니메이션을 지원한다.
- 레거시 애니메이션 : 하위 호환성을 고려한 애니메이션, 소스 코드로 컨트롤해야 함
- 메카님 애니메이션 : 모션 캡처 애니메이션, 리타게팅ˇ 기능

주인공 캐릭터는 레거시 애니메이션 타입으로 구현하고, 적 캐릭터는 메카님 애니메이션을 적용해보자.

- 리타게팅(Retagetting) : 애니메이션을 재사용하는 기능을 말한다. 6장에서 자세히 소개

![image](https://user-images.githubusercontent.com/85896566/188572525-2b3f37f9-9f7e-40a3-b16b-02892430dd85.png)

|Animation Type 옵션|설명|
|---|---|
|none|애니메이션을 사용하지 않는다.|
|Legacy|하위 호환성을 유지하기 위한 이전 방식의 애니메이션|
|Generic|메카님 애니메이션. 인체형 모델이 아닌 3D 모델에 적용. 리타게팅 불가|
|Humanoid|메카님 애니메이션. 사람과 같이 2족 보행하는 모델에 적용. 리타게팅 가능|

Player는 레거시 애니메이션을 사용하기로 했으니 Legacy로 변경해준다.

#### Info - 메카님 애니메이션 권장
레거시 애니메이션은 하위 호환성을 고려한 유형이기 때문에 유니티사는 특별한 경우가 아니면 메카님 애니메이션을 사용하길 권장함. 하짐나 빠른 속도와 간단한 애니메이션을 동작하는 데는 아직도 레거시 애니메이션이 유용하게 사용되고 있다. 또한, 개발자 포럼에서 레거시 애니메이션은 곧 지원 중단될 것으로 예측하는 개발자들이 있지만, 당분간은 계속 지원할 것으로 예상한다.

하이러키 뷰에 배치되어 있는 Player 객체의 인스펙터 뷰를 보면 Animation 컴포넌트가 추가돼 있다. 이 모델은 레거시 타입으로 설정된 모델을 의미한다.

![image](https://user-images.githubusercontent.com/85896566/188573896-27fcffc3-f238-4e9e-bbec-8135bebc13a5.png)

애니메이션 처리가 된 3D 모델을 씬 뷰에 추가했을 때 Animation Type에 따라 다음과 같이 서로 다른 컴포넌트가 자동으로 추가된다.

- 레거시 애니메이션 : Animation Component
- 메카님 애니메이션 : Animator Component

둘 다 애니메이션과 관련된 컴포넌트지만, 작동 방식이 전혀 다르다. 따라서 3D 모델에 추가된 컴포넌트의 종류를 보고 해당 모델의 애니메이션 유형이 무엇으로 설정됐는지 구별할 수 있어야 한다.

### Animation Clip
애니메이션 클립 : 캐릭터의 걷기, 달리기, 점프, 총 쏘기와 같은 동작을 기록한 파일을 말한다. 그리고 애니메이션 컴포넌트는 애니메이션 클립에 기록된 관절의 위치와 회전 값을 프레임 단위로 재생시키는 역할을 한다.

3D 모델링 툴에서 제작한 애니메이션 클립을 애니메이션 파일로 만드는 방법에는 세 가지 방식이 있다.
1. 모든 애니메이션 클립이 하나의 애니메이션 파일에 들어 있고, 각 애니메이션 클립이 시작 프레임과 종료 프레임을 가지는 방식
2. 위와 동일하게 모든 애니메이션 클립이 하나의 애니메이션 파일에 들어가 있지만, 미리 분리된 경우
3. 애니메이션 클립을 동작별로 분리해 별도의 파일로 생성하는 방식. 이 때 생성된 애니메이션 클립의 파일명은 "모델명@애니메이션 클립명" 형태의 명명 규칙이 적용된다. 애니메이션 클립의 수가 많거나 애니메이션의 수정 작업이 빈번하게 일어날 것으로 예상한다면 이 방식으로 작업하는 것을 추천

### 애니메이션 적용
- 하이러키 뷰의 객체를 적용할 애니메이션 인스펙터 뷰 - 프리뷰에 드래그 & 드랍
- 프로젝트 뷰의 원본 객체를 적용할 애니메이션 인스펙터 뷰 - 프리뷰에 드래그 & 드랍

![image](https://user-images.githubusercontent.com/85896566/188576051-d4c495a3-18ba-43fd-b03a-c7fe737fe78d.png)

애니메이션 클립의 Wrap Mode 속성값 중 'Loop'로 설정한다.

- Loop : 클립의 첫 프레임부터 마지막 프레임까지 계속 반복

![image](https://user-images.githubusercontent.com/85896566/188576783-944f09ab-e790-4516-99cd-3ddff2c3f851.png)

애니메이션 컴포넌트 속성값
- Animation : 실행되면 처음 동작하는 애니메이션 클립을 연결
- Animations[] : 해당 모델이 실행할 수 있는 클립들을 저장(즉, 여기 포함되어 있지 않은 클립은 실행 불가)
- Play Automatically : 게임이 실행되면 자동으로 클립을 재생함(언체크시 스크립팅으로 체크 가능)
- 이하 생략

아래의 코드는 Play Automatically를 언체크하고 스크립트에서 직접 컨트롤 하는 코드이다. 

```c#
public class PlayerCtrl : MonoBehaviour
{
    // 컴포넌트 캐시 처리할 변수
    Transform tr;
    Animation anim;

    [중략...]
    
    private void Start()
    {
        // Component를 추출해 변수에 대입
        tr = GetComponent<Transform>();
        anim = GetComponent<Animation>();

        // 애니메이션 실행
        anim.Play("Idle");
    }

    private void Update()
    {
      [중략...]
    }
}
```

![image](https://user-images.githubusercontent.com/85896566/188578873-49ed1133-34a7-4b72-a76d-0984bce99f6f.png)

이제 주인공 캐릭터를 이동시키면 이동 방향에 적합한 애니메이션을 생성되게 만들어보자.

### Animation Blending
유니티는 현재 수행 중인 애니메이션에서 다른 애니메이션으로 변경될 때 이를 부드럽게 연결해주는 애니메이션 블렌딩 기능을 제공한다.

주인공이 정지 상태일 때는 Idle 애니메이션을 실행하다가 전진하는 경우 자연스럽게 RunF 애니메이션으로 변경되게 해보자.

```c#
    private void Update()
    {
      [중략...]
      PlayerAnim(h, v); // 주인공 캐릭터의 애니메이션 설정
    }

    void PlayerAnim(float h, float v) // 키보드 입력값을 기준으로 동작할 애니메이션 수행
    {
        if      (v >=  0.1f) anim.CrossFade("RunF", 0.25f); // 전진 애니메이션 실행
        else if (v <= -0.1f) anim.CrossFade("RunB", 0.25f); // 후진 애니메이션 실행
        else if (h >=  0.1f) anim.CrossFade("RunR", 0.25f); // 오른쪽 이동 애니메이션 실행
        else if (h <= -0.1f) anim.CrossFade("RunL", 0.25f); // 왼쪽 이동 애니메이션 실행
        else                 anim.CrossFade("Idle", 0.25f); // 정지 시 대기 애니메이션 실행
    }
```

PlayerAnim()는 주인공 캐릭터에 적절한 애니메이션 클립을 재생시키는 역할을 한다. 주인공 캐릭터의 이동 방향을 판단하는 기준인 h와 v 변수를 인자로 넘겨준다. 주인공 캐릭터가 전후/좌우로 움직이는 것을 0을 기준으로 판단할 수 있기 때문이다. 그리고 키보드를 누르지 않아서 0 값이 전달되면 대기 상태인 Idle 애니메이션 클립을 실행한다.

애니메이션 클립을 실행하는 CrossFade()는 두 개의 인자를 받는다. 첫 번째 인자는 변경할 애니메이션 클립의 명칭이며, 두 번째 인자는 다른 애니메이션 클립으로 페이드아웃되는 시간을 의미한다. 이 때 단순히 정해진 시간동안 애니메이션이 변경되는 것이 아니라 애니메이션 키프레임을 보간(Interpolate)해 부드럽게 보정시킨다.

## 무기 장착
무기류를 장착하려면 모델의 Bone 구조를 확인해야 한다. 

![image](https://user-images.githubusercontent.com/85896566/188583052-9d8ff156-357c-4476-af91-8270ed8de9a2.png)

![image](https://user-images.githubusercontent.com/85896566/188583507-2f48b364-a0bb-4ab9-82c2-b9ba1705c51c.png)

무기류를 장착해준다면 처음엔 무기 객체의 Transform 속성값을 리셋해준다.

이후 플레이에서 애니메이션과 무기류의 싱크를 확인하고 부족하다면 Transform을 적절히 변경해준다.

![image](https://user-images.githubusercontent.com/85896566/188584121-56839ffc-a57f-4e74-b290-6dc055170bee.png)

## 그림자
게임에 있어서 입체감을 표현하기 위한 그림자 효과는 매우 중요한 요소다. 이어서 그림자를 표현하는 몇 가지 방법을 소개하고자 한다.

### 실시간 그림자
유니티는 Directional Light, Point Light, Spotlight라는 세 가지 광원에 대해 실시간 그림자(Real Time Shadow)를 지원한다. 하지만 모바일 디바이스의 성능에 따라 실시간 그림자는 처리 비용이 매우 크다.

유니티는 실시간 그림자가 기본으로 적용돼 있으며 Directional Light 속성 중 Shadow Type 옵션으로 설정한다. Shadow Type 속성으로는 No Shadows, Soft Shadows, Hard Shadows로 세 가지 옵션이 있고 각각은 아래의 내용이다.

- No Shadows : 실시간 그림자를 적용하지 않는다.(기본 설정값)
  ![image](https://user-images.githubusercontent.com/85896566/188585485-5fd8de1e-7bbc-48f5-a5c8-8942ddd38399.png)
- Soft Shadows : 실시간 그림자를 표현하지만, 외곽선에 계단 현상이 발생한다.
  ![image](https://user-images.githubusercontent.com/85896566/188585527-2f50d710-cfa8-40cd-8ccb-538bc4c40e16.png)
- Hard Shadows : 부드러운 실시간 그림자를 표현하지만, 가장 많은 부하를 준다.
  ![image](https://user-images.githubusercontent.com/85896566/188585577-352dfa66-8ba8-492f-aba9-8a08b66c1b15.png)

실시간 그림자의 시각적 효과는 매우 탁월하지만, 엔진에 많은 부하를 준다. 따라서 실시간 그림자 효과가 필요 없는 3D 모델은 실시간 그림자 영향에서 제외하는 설정을 빠뜨리지 않아야 한다.

3D 모델은 Mesh Renderer 또는 Skinned Mesh Renderer 중 한 컴포넌트를 반드시 갖고 있다. 그리고 이 두 가지 컴포넌트에는 실시간 그림자와 관련된 Cast Shadows와 Receive Shadows 속성이 있다.

![image](https://user-images.githubusercontent.com/85896566/188586219-ec933ae1-d2a2-4d3b-b9ba-3d2c7c4ae2b4.png)

- Cast Shadows : 빛을 받아서 자신의 그림자를 만들 것인지 결정하는 속성
  |Cast Shadows|Option|
  |---|---|
  |Off|그림자를 만들지 않는다.|
  |On|그림자를 만든다.|
  |Two Sided|백 페이스 컬링을 무시하고 그림자를 양면으로 만든다.|
  |Shadows Only|그림자를 만들지만, 자신은 렌더링하지 않는다. 즉, 화면에 보이지 않는 특성이 있어 그림자 처리만을 위한 로우 폴리 3D 모델에 활용할 수 있다.|
- Receive Shadows : 다른 그림자에 들어갔을 때 표면에 그림자의 영향을 받는지 아닌지

따라서 실시간 그림자의 영향을 받지 않아도 시각적 효과에 크게 상관없는 3D 모델은 이 두가지 옵션을 적절히 설정해 그림자를 생성하지 않게 한다.

#### Info = Cast Shadows 속성의 Two Sided 옵션에 대해
Plane 또는 Quad처럼 단면(Single-Side)만 렌더링 하는 모델은 Cast Shadows 속성을 On으로 하고, 빛을 모델의 뒤쪽(Backface)에서 비추면 그림자가 생성되지 않는다.(두 번째 그림 참고). 이 때 Cast Shadows 속성을 Two Sided로 설정하면 그림자가 생성된다.(세 번째 그림 참고).

![image](https://user-images.githubusercontent.com/85896566/188587747-bbae2429-cb33-4625-bfb4-b270b6a50994.png)

![image](https://user-images.githubusercontent.com/85896566/188588083-1ef86843-19db-4927-a5fa-821e23af1720.png)

![image](https://user-images.githubusercontent.com/85896566/188588158-69088fde-024c-44d2-bc5b-73ad29f8cd21.png)

### 메시를 이용한 그림자
실시간 그림자보다 시각적인 효과는 덜 하지만, 그래도 입체감을 낼 수 있는 가벼운 그림자 처리를 구현할 수 있는 방법. 단순한 평면 메시를 이용하는 방법으로 모바일 게임에서 흔히 볼 수 있는 방식

먼저 객체에 적용된 실시간 그림자가 생성되지 않도록 설정한다. + 무기류

- Cast Shadows - Off
- Receive Shadows - 언체크

![image](https://user-images.githubusercontent.com/85896566/188589022-a3ce0133-733c-4cb1-b6c4-2f951acc4a05.png)

![image](https://user-images.githubusercontent.com/85896566/188589500-307b6a1b-e4e9-4423-b154-70140b185eaf.png)

다음 단계로 그림자를 표시할 메시는 유니티에서 제공하는 Quad를 사용한다. Quad 모델을 생성해 Player에게 자식화한다.
- 콜라이더 컴포넌트 삭제
- 이름 변경
- 준비한 Material 지정
- Material Shader를 [Mobile] -> [Particles] -> [Multiply]로 변경

![image](https://user-images.githubusercontent.com/85896566/188591059-fa12ac74-a614-4127-b851-b4d427ea6328.png)

이 방법은 부하가 적은 방법으로 많이 사용되고 있지만, 스테이지에 굴곡이 있거나 경사로가 있다면 그림자가 다른 메시에 묻혀 제대로 표현되지 않는다는 점도 기억하자.

## Level Of Detail 설정
LOD, Level Of Detail란, 화면을 렌더링하는 카메라로부터 멀리 떨어질수록 낮은 폴리곤으로 변경해 렌더링 부하를 줄여주는 기법이다.

주인공 모델의 3가지 메시는 3단계 LOD로 설정된 메시다.

![image](https://user-images.githubusercontent.com/85896566/188591864-488c4d45-81ff-49f8-a8ca-5c40bfa5a1a2.png)

![image](https://user-images.githubusercontent.com/85896566/188591939-b3a0b748-bc8b-4320-827a-452f36862d1e.png)

![image](https://user-images.githubusercontent.com/85896566/188592027-19ee3a96-c59b-45a3-8e25-e1c9d30e0a34.png)

### LOD Group Component
LOD Group Component는 카메라와 피사체의 거리에 따라 렌더링할 메시를 결정하는 역할을 함
LOD Group Component를 Add한다.

LOD 구간대로 메시를 차례대로 드래그 & 드롭한다. LOD 0구간은 하이 폴리곤이며 숫자가 커질수록 로우 폴리곤 메시를 연결한다.

![image](https://user-images.githubusercontent.com/85896566/188592843-af83f7e3-d156-4d1b-8849-a4ebba3126e8.png)

Culled(Red)는 카메라와의 거리가 아주 멀리 떨어져 화면에서 렌더링하지 않는 구간을 의미한다.

주인공 캐릭터는 대부분 카메라와의 거리가 고정돼있기 때문에 굳이 LOD를 적용할 필요는 없지만, 멀티플레이어 게임에서는 상대편이 멀리 떨어져 있는 내 캐릭터를 봤을 때 LOD가 유용하게 사용될 수 있다. 특히 모바일 게임에서는 렌더링 최적화 기법 가운데 중요하게 꼽는 것 중 하나가 바로 LOD 기능이다.

## Follow Camera 로직
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowCam : MonoBehaviour
{
    // 따라가야 할 대상을 연결할 변수
    public Transform targetTr;
    // Main Camera 자신의 Transform 컴포넌트
    private Transform camTr;

    // 따라갈 대상으로부터 떨어질 거리
    [Range(2.0f, 20.0f)]
    public float distance = 10.0f;

    // Y축으로 이동할 높이
    [Range(0.0f, 10.0f)]
    public float height = 2.0f;

    void Start()
    {
        // Main Camera 자신의 Transform 컴포넌트를 추출
        camTr = GetComponent<Transform>();
    }

    void LateUpdate()
    {
        // 추적해야 할 대상의 뒤쪽으로 distance만큼 이동
        // 높이를 height만큼 이동
        Vector3 pos = targetTr.position
                      + (-targetTr.forward * distance)
                      + (Vector3.up * height);

        // Camera를 피벗 좌표를 향해 회전
        camTr.LookAt(targetTr.position + (targetTr.up));
    }
}
```

[Range(min, max)] 어트리뷰트를 사용하면 다음 라인에 선언한 변수의 입력 범위를 (min, max)로 제한할 수 있고, 인스펙터 뷰에 슬라이드 바를 표시한다.

![image](https://user-images.githubusercontent.com/85896566/188594277-b3c9c9a8-e8c8-4388-abb6-ce0adfa6e83f.png)

LateUpdate()에서 후처리 로직으로 이용한 이유는 Update()의 순서에 플레이어의 이동 로직이 항상 먼저 실행되는 것이 보장되지 않기 때문에 카메라가 떨리는 현상이 발생한다. 따라서 선행된 결괏값을 갖고 후처리 작업을 해야 하므로 LateUpdate()를 이용했다.

Transform.LookAt() 함수는 인자로 Vector3 좌표 또는 Transform 컴포넌트를 전달하면 해당 좌표로 회전시키는 기능을 한다. 먼저 카메라의 위치를 이동시킨 후 따라갈 대상을 향해 카메라의 각도를 회전시키는 역할

### Vecotr3.Lerp, Vector3.Slerp
선형 보간(Linear Interpolation)과 구면 선형 보간(Spherical Linear Interpolation)은 시작점과 끝점 사이의 특정 위치의 값을 추정할 때 사용한다. 이러한 보간 함수는 현재 값을 목푯값으로 변경할 때 갑자기 변경하지 않고 부드럽게 변경시키는 로직에 많이 활용된다.

선형 보간이라는 명칭에서 알 수 있듯이 "선형"은 "직선"을 의미한다. 균일한 속도로 이동시키거나 회전시킬 때 사용한다.

유니티에서는 Lerp 선형 보간 함수를 제공하며 Vector3, Mathf, Quaternion, Color 구조체에서 사용할 수 있다.

매개변수는 Lerp(a, b, t)로, a와 b를 잇는 선을 t를 통해 분할하는 지점을 반환한다. 예를 들어 t값이 0.5라면 a, b의 중간지점을 반환한다.

![image](https://user-images.githubusercontent.com/85896566/188597015-35e390e2-0f85-4768-af40-f2474ef65675.png)

```c#
Vector3.Lerp(시작 좌표, 종료 좌표, t);
Mathf.Lerp(시작 값, 종료 값, t);
Quaternion.Lerp(시작 각도, 종료 각도, t);
```

구면 선형 보간(Spherical Linear Interpolation)은 직선의 형태가 아닌 구면(구체)의 형태로 값을 추론한다. 구면을 따라서 값을 반환하기에 시간 t가 증가할 때 시작점과 종료점은 느리게 증가하고 중간지점은 동일한 시간 대비 이동해야 할 거리가 크기 때문에 빠르게 이동하는 특성이 있다. 따라서 구면 선형 보간은 회전 로직에 사용된다.

![image](https://user-images.githubusercontent.com/85896566/188598037-2aba1e2b-37e1-4e33-bddf-655729cece61.png)

유니티에서 제공하는 구면 선형 보간 함수는 Slerp로 Vector3, Quaternion 구조체에서 사용할 수 있고, 매개변수는 Lerp와 똑같이 가지게 되며 함수의 사용법은 다음과 같다.

```c#
Vector3.Slerp(시작 좌표, 종료 좌표, t);
Quaternion.Slerp(시작 각도, 종료 각도, t);
```

이제 스크립트를 수정한다.

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowCam : MonoBehaviour
{
    // 따라가야 할 대상을 연결할 변수
    public Transform targetTr;
    // Main Camera 자신의 Transform 컴포넌트
    private Transform camTr;

    // 따라갈 대상으로부터 떨어질 거리
    [Range(2.0f, 20.0f)]
    public float distance = 10.0f;

    // Y축으로 이동할 높이
    [Range(0.0f, 10.0f)]
    public float height = 2.0f;

    // 반응 속도
    public float damping = 10.0f;

    void Start()
    {
        // Main Camera 자신의 Transform 컴포넌트를 추출
        camTr = GetComponent<Transform>();
    }

    void LateUpdate()
    {
        // 추적해야 할 대상의 뒤쪽으로 distance만큼 이동
        // 높이를 height만큼 이동
        Vector3 pos = targetTr.position
                      + (-targetTr.forward * distance)
                      + (Vector3.up * height);

        구면 선형 보간함수를 사용해 부드럽게 위치를 변경
        camTr.position = Vector3.Slerp(camTr.position,           // 시작 위치
                                      pos,                       // 목표 위치
                                      Time.deltaTime * damping); // 시간 t

        // Camera를 피벗 좌표를 향해 회전
        camTr.LookAt(targetTr.position + (targetTr.up));
    }
}
```

변경한 코드는 카메라가 이동할 목표 위치를 변수에 저장한 후 Slerp()를 이용해 점진적으로 이동시킨다. 실행해보면 처음 작성했던 코드보다 부드러워진 것을 확인할 수 있다.

### Vector3.SmoothDamp
부드럽게 이동시키는 방법 중 Vector3.SmoothDamp() 함수를 이용하는 방법도 있다. 보통 카메라의 Follow 로직에 많이 사용되며 사용법은 다음과 같다.

```c#
Vector3.SmoothDamp(Vector3 current,
                   Vector3 target,
                   ref Vector3 currentVelocity,
                   float smoothTime,
                   float maxSpeed,
                   float deltaTime);
```

|매개 변수|설명|
|---|---|
|current|시작 위치|
|target|목표 위치|
|currentVelocity|현재 속도|
|smoothTime|목표 위치까지의 도달 시간|
|maxSpeed|최대 속력 제한 값(기본값: 무한대 Mathf.Infinity), 생략 가능|
|deltaTime|프레임 보정을 위한 델타 타임(기본값: Time.deltaTime), 생략 가능|

앞서 작성한 코드에서 구면 선형 보간을 사용한 부분은 주석 처리하고 다음과 같이 수정한다.

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowCam : MonoBehaviour
{
    // 따라가야 할 대상을 연결할 변수
    public Transform targetTr;
    // Main Camera 자신의 Transform 컴포넌트
    private Transform camTr;

    // 따라갈 대상으로부터 떨어질 거리
    [Range(2.0f, 20.0f)]
    public float distance = 10.0f;

    // Y축으로 이동할 높이
    [Range(0.0f, 10.0f)]
    public float height = 2.0f;

    // 반응 속도
    public float damping = 10.0f;

    // SmoothDamp에서 사용할 변수
    private Vector3 velocity = Vector3.zero;

    void Start()
    {
        // Main Camera 자신의 Transform 컴포넌트를 추출
        camTr = GetComponent<Transform>();
    }

    void LateUpdate()
    {
        // 추적해야 할 대상의 뒤쪽으로 distance만큼 이동
        // 높이를 height만큼 이동
        Vector3 pos = targetTr.position
                      + (-targetTr.forward * distance)
                      + (Vector3.up * height);

        // 구면 선형 보간함수를 사용해 부드럽게 위치를 변경
        // camTr.position = Vector3.Slerp(camTr.position,           // 시작 위치
        //                               pos,                       // 목표 위치
        //                               Time.deltaTime * damping); // 시간 t

        // SmoothDamp을 이용한 위치 보간
        camTr.position = Vector3.SmoothDamp(camTr.position, // 시작 위치
                                            pos,            // 목표 위치
                                            ref velocity,   // 현재 속도
                                            damping);       // 목표 위치까지 도달할 시간

        // Camera를 피벗 좌표를 향해 회전
        camTr.LookAt(targetTr.position + (targetTr.up));
    }
}
```

Damping 속성을 0.1로 변경하고 테스트해보면 구면 선형 보간 로직에 사용했던 Damping 변수는 값이 클수록 반응 속도가 빨랐지만 SmoothDamp에서는 목표 지점까지 이동할 때 걸리는 시간으로 사용되기 때문에 반대로 값이 작을수록 반응 속도가 빨라진다.

### Target Offset 적용
지금까지의 코드를 플레이해보면 주인공 캐릭터가 중앙에 위치해 전반 시야가 매우 좁다. 이것은 FollowCam.cs에서 메인 카메라가 플레이어를 향해 LookAt 처리를 해서 플레이어의 피벗 좌표를 바라보기 때문이다. 따라서 LookAt 좌표를 조정해서 전방 시야를 확보해보자.

스크립트를 다음과 같이 수정한다.

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowCam : MonoBehaviour
{
    // 따라가야 할 대상을 연결할 변수
    public Transform targetTr;
    // Main Camera 자신의 Transform 컴포넌트
    private Transform camTr;

    // 따라갈 대상으로부터 떨어질 거리
    [Range(2.0f, 20.0f)]
    public float distance = 10.0f;

    // Y축으로 이동할 높이
    [Range(0.0f, 10.0f)]
    public float height = 2.0f;

    // 반응 속도
    public float damping = 10.0f;

    // 카메라 LookAt의 Offset 값
    public float targetOffset = 2.0f;

    // SmoothDamp에서 사용할 변수
    private Vector3 velocity = Vector3.zero;

    void Start()
    {
        // Main Camera 자신의 Transform 컴포넌트를 추출
        camTr = GetComponent<Transform>();
    }

    void LateUpdate()
    {
        // 추적해야 할 대상의 뒤쪽으로 distance만큼 이동
        // 높이를 height만큼 이동
        Vector3 pos = targetTr.position
                      + (-targetTr.forward * distance)
                      + (Vector3.up * height);

        // 구면 선형 보간함수를 사용해 부드럽게 위치를 변경
        // camTr.position = Vector3.Slerp(camTr.position,           // 시작 위치
        //                               pos,                       // 목표 위치
        //                               Time.deltaTime * damping); // 시간 t

        // SmoothDamp을 이용한 위치 보간
        camTr.position = Vector3.SmoothDamp(camTr.position, // 시작 위치
                                            pos,            // 목표 위치
                                            ref velocity,   // 현재 속도
                                            damping);       // 목표 위치까지 도달할 시간

        // Camera를 피벗 좌표를 향해 회전
        camTr.LookAt(targetTr.position + (targetTr.up * targetOffset));
    }
}
```

실행한 화면이다. 카메라가 플레이어를 향해 다가오고, 캐릭터가 화면 아래쪽에 배치되고 전방 시야가 확보됐다.

![image](https://user-images.githubusercontent.com/85896566/188604709-4ca10931-d865-480f-8dbe-722d0aed5d73.png)

## 정리
- 주인공 3D 모델 임포트
- C# 스크립트 생성 방법
- 키보드 입력값 처리
- 캐랙터의 이동 및 회전
- 애니메이션 처리
- 실시간 그림자와 모바일용 그림자 처리
- LOD 설정
- FollowCamera 로직 구현

게임오브젝트와 컴포넌트 사이의 관계와 기본적인 이동, 회전 기능에 대한 스크립트를 작성해봤다.

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