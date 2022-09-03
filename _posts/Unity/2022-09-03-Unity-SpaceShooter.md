---
title:      위키북스 절대강좌! 유니티 책 따라가기
date:       "2022-09-03"
categories: ["Unity"]
tags:       ["Unity"]
# pin:        true
---

# 01장 유니티 엔진의 소개(생략)
# 02장 게임 개발 준비
## 이 책에서 개발할 게임 소개 및 개발 순서
## 프로젝트 생성
## 유니티 에디터의 환경설정
### 레이아웃
### 프로젝트 뷰의 칼럼
## 프로젝트 뷰의 체계적인 관리
## 캐릭터 모델 임포트하기
### 유니티 패키지를 통한 리소스 설치
## 에셋 스토어
### 무료 리소스 내려받기
## 정리
# 03장 게임 스테이지 제작
## 바닥 생성 및 배치
## 텍스처
### 텍스처의 해상도 조절
## 머티리얼
### 머티리얼의 자동 적용
### 머티리얼 생성
### Albedo, Normal Map 적용
### 머티리얼 적용 방법
### 타일링 속성
### 프리뷰의 다양한 기능
## 셰이더 및 물리 기반 셰이딩
### 렌더링 모드
### 알베도
### 메탈릭 속성
### 노멀 맵
### 하이트 맵
### 오클루전
### 이미션
### 디테일 마스크
## 프리팹
### 네스티드 프리팹
### 벽 만들기
### 프리팹 생성
### 프리팹의 복제 및 네이밍
### 스내핑 기능
## 조명
### Directional Light
### Point Light
### Spot Light
### Area Light
## 실시간 라이트매핑 기능
### Lighting Setting 에셋
### Auto Generate 옵션
## 하늘 표현 방식
### 6방면 스카이박스
### 스카이박스 적용
### 프로시저럴 스카이박스
### 큐브맵 스카이박스
## 정리
# 04장 주인공 캐릭터 제작
## 3D 모델 불러오기
## 유니티 엔진의 개발 방식
### 컴포넌트 기반의 개발 방식
## C# 스크립트
### 스크립트 코드 에디터
### 추천하는 코드 에디터
### 코드 에디터 변경
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
# 05장 총 발사 로직
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
# 06장 적 캐릭터 제작
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
# 07장 유니티 UI 시스템
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
# 08장 게임 매니저
## 적 캐릭터의 출현 로직
### SpawnPointGroup 생성
### GameManager 객체 생성
### Invoke, InvokeRepeate 함수
## 싱글턴 디자인 패턴
## 오브젝트 풀링
## 스코어 UI 구현
### Playerprefs를 활용한 스코어 저장
## 정리
# 09장 레이캐스트 활용
## 레이캐스트
### DrawRay
### Raycast, RaycastHit
## 정리
# 10장 내비게이션 고급 기법
## 동적 장애물
### NavMeshObstacle Component
## Off Mesh Link Generation
## 사용자 정의 Off Mesh Link
## 자연스러운 회전 처리
## Area Mask의 활용
### 경로의 가중치
## 정리
# 11장 라이트매핑 및 라이트 프로브
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
# 12장 씬 관리
## Scene 분리
## Scene 병합
## Multi Scene Edit
## 정리
# 13장 오클루전 컬링
## 컬링 방식
### 프리스텀 컬링
### 거리 비례에 의한 컬링
### 오클루전 컬링
## 오클루전 컬링 실습
### Occluder Static, Occludee Static
## 정리
# 14장 Input System
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
# 15장 포톤 클라우드를 활용한 네트워크 게임