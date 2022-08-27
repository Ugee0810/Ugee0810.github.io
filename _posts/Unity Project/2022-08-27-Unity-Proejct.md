---
title:      프로젝트 진행 과정 -1-
date:       "2022-08-27"
categories: ["Unity"]
tags:       ["Unity"]
# pin:        true
---

스크립트 세분화

스크립트 별 역할, 기술 정리란 게시

RequireComponent 속성을 사용하여 오디오 매니저에게 오디오 소스 속성 종속

```C#
[RequireComponent(typeof(AudioSource))]
```