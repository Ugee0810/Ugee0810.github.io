---
title:      Unity VR Making Body(바디 리깅 구현하기)
date:       "2022-09-15"
categories: ["Unity", "Unity VR"]
tags:       ["Unity", "Unity VR"]
# pin:        true
---

통상적으로 모든 3D 캐릭터에게 적용이 가능함

사용 중인 유니티 버전이 2019.2 버전 이상이어야 한다.

프로젝트에 이용할 3D 캐릭터를 준비한다.

예시에서는 'Space Robot Kyle'에셋을 사용한다.

![image](https://user-images.githubusercontent.com/85896566/192690399-b42735f3-14b7-4733-9689-fc15f6098db2.png)

또 'Animation Rigging'패키지를 설치한다.

![image](https://user-images.githubusercontent.com/85896566/192690167-8c097721-5bf8-475b-8be5-e35a8501219b.png)

3D 캐릭터의 메쉬 데이터와 골격, 애니메이션이 포함되어 있다.

![image](https://user-images.githubusercontent.com/85896566/192690755-b153692b-ce39-4df1-8e1a-291f409fefe1.png)

관절의 각 부위를 회전하는 건 가능하다.

![image](https://user-images.githubusercontent.com/85896566/192690953-d18ae242-bd4c-4161-b921-a9d4b6d29a79.png)

하지만 애니메이션 리깅 패키지가 없다면 트랜스폼을 변경했을 때 관절이 분리되는 문제가 발생한다.

![image](https://user-images.githubusercontent.com/85896566/192691081-4c6bc3a1-8212-40a8-b62e-bb210668abb7.png)

모든 관절이 정상이라면 이제 최상위 부모로 돌아가 Rig Builder 스크립트를 가져온다.

![image](https://user-images.githubusercontent.com/85896566/192691272-dc19c23c-2596-450e-891d-7dbdf1dadd32.png)

아래에 새로 생긴 애니메이터 컴포넌트를 이용하므로 애니메이션 컴포넌트는 삭제해준다.

![image](https://user-images.githubusercontent.com/85896566/192691405-67477f69-077f-4e2d-8d67-5a4989fa7e9e.png)

그리고 캐릭터의 뼈대 구조를 더 나은 방식으로 표시하는 Bone Renderer 스크립트를 컴포넌트로 불러온다.

![image](https://user-images.githubusercontent.com/85896566/192691616-a1df5bbb-d5f9-4dda-8dd9-99279b13772b.png)

사용 방법은 아래의 트랜스폼 배열에 모든 관절들을 적용한다.

![image](https://user-images.githubusercontent.com/85896566/192691785-8b8e63bd-3bf6-4abe-9c2b-936ee17782aa.png)

![image](https://user-images.githubusercontent.com/85896566/192691948-b0f85423-fe1d-4e17-b2d3-a5a85d51ed6b.png)

이렇게 관절 구조가 연결되어 있는 모습을 확인할 수 있다.

![image](https://user-images.githubusercontent.com/85896566/192692158-a45e3dd1-e6b4-417f-b1e8-575589538aab.png)

이후 최상위 부모에게 빈 오즈젝트를 VR Constraints(VR 제약조건)이라는 이름으로 생성해준다. 그리고 컴포넌트로 Rig 스크립트를 넣어주고, 부모의 Rig Builder 컴포넌트에 드래그&드랍해준다.

![image](https://user-images.githubusercontent.com/85896566/192692522-dabf94f4-f198-4fae-a8d2-a4a8b6183e46.png)
![image](https://user-images.githubusercontent.com/85896566/192692610-ab5cd011-6f0e-48c6-98fe-01e2eefb34f2.png)
![image](https://user-images.githubusercontent.com/85896566/192692766-2f7b21b2-c2a3-4a8f-93fa-7e08cf6a0841.png)

또, VR Constraints의 하위로 빈 오젝트를 만들어 아래와 같이 세팅해준다. 이것이 이동을 담당해주는 구서 요소가 된다.

![image](https://user-images.githubusercontent.com/85896566/192692901-1d6aedc0-f126-4aa4-8b3a-9b87e32246b6.png)

이제 컴포넌트에 하나씩 추가 해주는데, 좌물쇠를 걸어두고 씬 뷰에 표시된 관절선 중 필요한 관절을 클릭해서 확인한다.

![image](https://user-images.githubusercontent.com/85896566/192693378-d91e710c-a63b-4142-922b-41a8764a4bff.png)

아래의 타겟과 힌트 트랜스폼이 남았다. 먼저 Right Arm IK의 하위로 빈 오브젝트 두 개를 생성해준다.

![image](https://user-images.githubusercontent.com/85896566/192693639-6941b000-c10c-4f15-9960-37764187491d.png)

타겟 개체를 선택하고 Shift를 누른 상태로 대상을 배치 할 뼈를 선택합니다.

![image](https://user-images.githubusercontent.com/85896566/192693860-2c286f41-09c4-428c-9348-5aaafaa6e40b.png)

이젠 애니메이션 리깅 단계입니다. 아래의 속성을 클릭하면 타겟 게임 오브젝트와 손 뼈의 위치가 일치하는 것을 볼 수 있습니다. 힌트 게임 오브젝트도 오른쪽 팔꿈치와 같이 잡고 똑같은 작업을 해줍니다.

![image](https://user-images.githubusercontent.com/85896566/192693965-b4a3939f-0a16-4c87-be41-a8f29d57c043.png)

![image](https://user-images.githubusercontent.com/85896566/192694034-d8e0ca72-991d-4d66-b059-5fbc7bd0af4b.png)

![image](https://user-images.githubusercontent.com/85896566/192694269-fadab3f7-a7c8-4085-9b7f-caf40a6d6012.png)

이제 플레이 해봅니다. 타겟과 힌트의 트랜스폼을 변경하면 붙은 관절들이 같이 움직이는 걸 볼 수 있습니다.

![image](https://user-images.githubusercontent.com/85896566/192694441-d6513884-bdca-4a8f-b753-0c100b23a9c8.png)

성공했다면 이제 왼쪽 팔도 동일하게 적용 하면 됩니다.

![image](https://user-images.githubusercontent.com/85896566/192694957-ceb02dfb-03ea-48d7-8140-0fb29ac5ad09.png)

이 단계에서 다리에도 동일한 작업을 수행하고 애니메이션을 사용할 수 있습니다.

이번엔 머리를 구성할 차례입니다. 머리를 구성하게 된 다면 훨씬 자유로운 느낌을 줄 수 있습니다.

VR Constraints의 하위로 Head Constraint 이름의 빈 오브젝트를 생성한 뒤 Multi Parent Constraint 스크립트를 컴포넌트로 추가해줍니다.

![image](https://user-images.githubusercontent.com/85896566/192695622-8ca3db39-b7c5-4b55-92d8-347fa535b334.png)

마찬가지로 좌물쇠를 걸고 헤드를 찾아 제약 오브젝트에 걸어줍니다.

![image](https://user-images.githubusercontent.com/85896566/192695754-e2b18764-4723-43d9-907d-f8ada4ca23cd.png)

Source Objects에는 자신(Head Constraint가 들어갑니다.)

이후 Head와 같이 잡고 Align Transform 해줍니다.

![image](https://user-images.githubusercontent.com/85896566/192696277-ab9e7e18-565c-42e5-b391-23d965fdf0fe.png)

하지만 아직 머리가 한 없이 한 방향으로 돌아간다거나 팔 관절과 자연스러운 운동이 안되는 문제가 있습니다.

부모에게 돌아가 VRRig스크립트를 생성해줍니다.

```c#
/// VRRig.cs
using UnityEngine;

public class VRRig : MonoBehaviour
{
    // Add Call Add 제약을 위한 두 개의 실행 가능한 필록 전송 변수
    public Transform headConstraint;

    // 머리와 몸체 사이의 초기 위치 차이가 될 집합 변수
    public Vector3 headBodyOffset;

    private void Start()
    {
        // 최초에 위치 변환을 해준다.
        headBodyOffset = transform.position - headConstraint.position;
    }

    private void Update()
    {
        // 머리 위치에 따라 몸체는 수시로 변화한다.
        // 머리의 위치에 오프셋을 추가한 포지션 값을 부모에게 전달한다.
        transform.position = headConstraint.position + headBodyOffset;

        // 이 부분은 3D 캐릭터의 헤드 축에 따라서 수시로 변경되어야 한다.
        // Robot Kyle의 경우 머리는 정면이 녹색(y)축이므로 걸음에 up을 넣어준다.
        transform.forward = Vector3.ProjectOnPlane(headConstraint.up, Vector3.up).normalized;
    }
}
```

스크립트를 적용하고 플레이 해봅니다.

![image](https://user-images.githubusercontent.com/85896566/192697999-86bf3cb5-ad98-4062-b0a3-84fb6bcd37a4.png)

그렇게 되면 한없이 앞으로 달려가는 걸 볼 수 있습니다. 하지만 이 것이 정상적으로 완성된 모습입니다. 왜냐하면 머리와 함께 몸을 움직였기 때문입니다.

앞으로 해결해야 할 부분은 항상 머리의 위치를 조정하고 나중에 컨트롤러와 플레이어 세트와 일치하도록 해야합니다.

스크립트를 다음과 같이 변경합니다.

```c#
/// VRRig.cs
using UnityEngine;

// 직렬화를 통해 다른 클래스도 인스펙터창에서 확인
[System.Serializable]
public class VRMap
{
    // VR 타겟이라는 VR 변환을 위해 실행 가능한 클래스 4가지
    public Transform vrTarget;
    public Transform rigTarget;
    public Vector3 trackingPositionOffset;
    public Vector3 trackingRotationOffset;

    public void Map()
    {
        rigTarget.position = vrTarget.TransformPoint(trackingPositionOffset);
        rigTarget.rotation = vrTarget.rotation * Quaternion.Euler(trackingRotationOffset);
    }
}

public class VRRig : MonoBehaviour
{
    public VRMap head;
    public VRMap leftHand;
    public VRMap rightHand;

    // Add Call Add 제약을 위한 두 개의 실행 가능한 필록 전송 변수
    public Transform headConstraint;

    // 머리와 몸체 사이의 초기 위치 차이가 될 집합 변수
    public Vector3 headBodyOffset;

    private void Start()
    {
        // 최초에 위치 변환을 해준다.
        headBodyOffset = transform.position - headConstraint.position;
    }

    private void Update()
    {
        // 머리 위치에 따라 몸체는 수시로 변화한다.
        // 머리의 위치에 오프셋을 추가한 포지션 값을 부모에게 전달한다.
        transform.position = headConstraint.position + headBodyOffset;

        // 이 부분은 3D 캐릭터의 헤드 축에 따라서 수시로 변경되어야 한다.
        // Robot Kyle의 경우 머리는 정면이 녹색(y)축이므로 걸음에 up을 넣어준다.
        transform.forward = Vector3.ProjectOnPlane(headConstraint.up, Vector3.up).normalized;

        head.Map();
        leftHand.Map();
        rightHand.Map();
    }
}
```

이후 컴포넌트에서 연결해주고 나서 연결할 때 XRI 기준으로 아래와 같이 하면 될 거 같다. 나중엔 오프셋에 넣어서 만들면 될 거 같다.

![image](https://user-images.githubusercontent.com/85896566/192700278-acb25cd0-5155-48d1-8ae8-97266a82cef6.png)

아래의 사진은 본체에 가려서 앞을 못 보는 것을 오프셋으로 조정하는 것이고, 또한 목이 돌아가 있는 부분도 모델 기준으로 회전값을 넣은 것이다. 그리고 손도 자연스럽게 보정해준 값이다.

![image](https://user-images.githubusercontent.com/85896566/192700838-942d731f-c9ac-4ede-bee0-8ffd0951503b.png)

![image](https://user-images.githubusercontent.com/85896566/192701083-33eb3d51-ca95-4f1c-9a4c-c56a11379c73.png)

아직 개선할 부분으로 캐릭터 팔이 다 뻗을 수 있도록 실제 팔 길이와 캐릭터의 팔 길이를 맞춰주어야 합니다. 이는 캐릭터의 크기를 키우는 방법으로 해결할 수 있습니다. 스크립트를 아래와 같이 수정하면 더 자연스러운 결과를 볼 수 있습니다.

```c#
using UnityEngine;

// 직렬화를 통해 다른 클래스도 인스펙터창에서 확인
[System.Serializable]
public class VRMap
{
    // VR 타겟이라는 VR 변환을 위해 실행 가능한 클래스 4가지
    public Transform vrTarget;
    public Transform rigTarget;
    public Vector3 trackingPositionOffset;
    public Vector3 trackingRotationOffset;

    public void Map()
    {
        rigTarget.position = vrTarget.TransformPoint(trackingPositionOffset);
        rigTarget.rotation = vrTarget.rotation * Quaternion.Euler(trackingRotationOffset);
    }
}

public class VRRig : MonoBehaviour
{
    public VRMap head;
    public VRMap leftHand;
    public VRMap rightHand;

    // Add Call Add 제약을 위한 두 개의 실행 가능한 필록 전송 변수
    public Transform headConstraint;

    // 머리와 몸체 사이의 초기 위치 차이가 될 집합 변수
    public Vector3 headBodyOffset;

    public int turnSmoothness;

    private void Start() 
    {
        // 최초에 위치 변환을 해준다.
        headBodyOffset = transform.position - headConstraint.position;
    }

    private void Update()
    {
        // 머리 위치에 따라 몸체는 수시로 변화한다.
        // 머리의 위치에 오프셋을 추가한 포지션 값을 부모에게 전달한다.
        transform.position = headConstraint.position + headBodyOffset;

        // 이 부분은 3D 캐릭터의 헤드 축에 따라서 수시로 변경되어야 한다.
        // Robot Kyle의 경우 머리는 정면이 녹색(y)축이므로 걸음에 up을 넣어준다.
        transform.forward = Vector3.Lerp(transform.forward, Vector3.ProjectOnPlane(headConstraint.up, Vector3.up).normalized, Time.deltaTime * turnSmoothness);

        head.Map();
        leftHand.Map();
        rightHand.Map();
    }
}
```

## 결과
하체는 2부에서 제작할 예정 필요에 따라 할 수도~?
![image](https://user-images.githubusercontent.com/85896566/192703491-0f29e55a-ad92-44f6-b843-5087c0c48005.png)


# 참고 사이트
- [Valem - VR에서 바디를 만드는 방법 - 1부](https://youtu.be/tBYl-aSxUe0)