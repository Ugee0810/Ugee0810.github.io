---
title:      MongoDB Cloud in Unity
date:       "2022-09-02"
categories: ["Unity"]
tags:       ["Unity"]
# pin:        true
---

# MongoDB Atlas Database - Cloud DBaaS for MongoDB
MongoDB는 자체적으로 서버를 구축해야하지만, 하위 플러그인으로 아틀라스DB를 사용하면 더 간단하게 무료로 구축 가능하다.

# MongoDB 프로젝트 생성 후 구축
![image](https://user-images.githubusercontent.com/110334366/188042035-9d0bdd04-df1c-4f82-8dc1-ec275f07982e.png)

# Setup in Unity
다운 받은 MongoDB Plugin을 에셋 폴더에 Import한다.

'MongoDBCtrl.cs' 생성 후 선언

```c#
using MongoDB.Bson;
using MongoDB.Driver;
```

커넥션 주소를 정수 문자열로 받는다.
![image](https://user-images.githubusercontent.com/110334366/188044008-ddb15fbe-1b6a-40cc-a017-57621a7d21d2.png)

```c#
// xxx:xxx 아이디:비밀번호
const string MONGO_URI = "mongodb+srv://User:User@cluster0.lsm0ujc.mongodb.net/?retryWrites=true&w=majority";
```

로그인 구현
```c#
public class MongoDBCtrl : MonoBehaviour
{
    // 커넥트 정보 
    const string MONGO_URI = 
        "mongodb+srv://User:User@cluster0.lsm0ujc.mongodb.net/?retryWrites=true&w=majority";

    MongoClient client;

    void DB_Login()
    {
        client = new MongoClient(MONGO_URI);
    }


    private void Start()
    {
        DB_Login();
        Debug.Log(client);
    }
}
```