---
title:      Unity Custom Hierarchy for Unity Ver1.2.0 (Feat.Febucci) (유니티 하이어라키 꾸미기)
date:       "2022-10-28"
categories: ["Unity"]
tags:       ["Unity"]
# pin:        true
---

# ※ Practical Environment
- Unity Editor Version - 2021.3.11f1

<br>

# ※ Intro
> ![image](https://user-images.githubusercontent.com/85896566/198589295-5c21e8a7-182c-416f-8e58-d42ed43c436a.png)
>
> ![febucci-custom-hierarchy-for-unity-preview](https://user-images.githubusercontent.com/85896566/198591516-06674245-88c1-4bb3-9dcb-91900490415a.gif)
>
> - _Preview_

> ![image](https://user-images.githubusercontent.com/85896566/198589322-626da257-768e-47f1-bd6d-bca393a533a4.png)
>
> - _트리 뷰_
>
> "트리 뷰"는 부모와 자식의 중첩 수준을 이해하는 데 도움이 됩니다( 이 구문은 이 컨텍스트 외부에서 의미가 없습니다.)
> 
> "가지"의 수와 모든 색상을 지정할 수 있습니다(배열이 끝나면 색상이 다시 반복됩니다.)

> ![image](https://user-images.githubusercontent.com/85896566/198589330-ffce603a-1b3b-46ef-8ceb-37d48ebe4c35.png)
>
> - _아이콘_
>
> 게임오브젝트의 컴포넌트 아이콘은 스크립트 "기즈모"를 수정하지 않고도 계층에서 직접 시각화할 수 있습니다.
>
> ScriptableObject를 통해 스크립트에 텍스처를 할당하여 작동하며 상속된 클래스에서도 작동합니다. 게임 오브젝트의 장면 아이콘을 시각화할 수도 있습니다.

> ![image](https://user-images.githubusercontent.com/85896566/198589346-8216dfa6-e6b2-4850-8f3b-d566f6a15654.png)
>
> - _분리 기호_
>
> 'EditorOnly' 태그를 사용하여 씬의 계층 구조를 분리하고 색상을 지정할 수 있습니다. (빌드에서 제거되는 태그)

> ![image](https://user-images.githubusercontent.com/85896566/198589363-ea52b365-f209-4305-b6c6-2b4293609768.png)
>
> - _교대 라인_
>
> 이 기능은 한 줄과 다음 줄을 구별하는 데 도움이 됩니다. 항상 그렇듯이 이 항목에서도 색상과 강도를 수정할 수 있습니다.

<br>

# ※ Apply
> ![image](https://user-images.githubusercontent.com/85896566/198586003-2ffa3b73-bcc6-4caa-90e3-73ad5274f73d.png)
>
> - _Package Manager_
>
> Package Manager - Add package from git URL...

> ![image](https://user-images.githubusercontent.com/85896566/198586454-5e77c568-4490-45a1-b4e7-e05f000bdf2f.png)
>
> - _Add package from git URL..._
> 
> ```
> https://github.com/febucci/unitypackage-custom-hierarchy.git
> ```
>
> 입력 후 Add하여 인스톨

> ![image](https://user-images.githubusercontent.com/85896566/198587372-4ea473d1-e341-4fc4-b483-aaa899ccc040.png)
>
> - _설치된 모습_

> ![image](https://user-images.githubusercontent.com/85896566/198587532-5cd72eae-a356-436d-8042-4c982702849a.png)
>
> ![image](https://user-images.githubusercontent.com/85896566/198587587-1fbb0924-7953-4a37-bbcd-bb9e13289bad.png)
>
> - _Plugin Create_


> ![image](https://user-images.githubusercontent.com/85896566/198587913-995d8bee-615e-4d9a-bc34-1576d999a416.png)
>
> - _Project View_
>
> 'HierarchyData'가 제대로 생성되었고 이 곳에서 여러가지 커스텀이 가능하다.
> 
> 간혹 프로젝트를 재설치하거나 이동한 후엔 커스텀 하이어라키 기능이 해제될 때가 있다.
>
> 그럴 땐 이 'HierarchyData' 다시 클릭해주면 활성화된다.

> ![image](https://user-images.githubusercontent.com/85896566/198588052-dd5540ac-64f5-487c-bf30-ad4fa75aa2a7.png)
>
> - _적용된 사진_
>
> 더 자세한 내용이 궁금하다면 [문서](https://www.febucci.com/2020/10/custom-hierarchy-for-unity/) 참조

<br>

# ※ Reference Site
- [febucci / unitypackage-custom-hierarchy](https://github.com/febucci/unitypackage-custom-hierarchy.git)
- [Coco Code - Organise and colorise your hierarchy! - UNITY TIPS and ASSETS #1](https://youtu.be/Gma7IXPj4wI)
- [Documentation Page](https://www.febucci.com/2020/10/custom-hierarchy-for-unity/)