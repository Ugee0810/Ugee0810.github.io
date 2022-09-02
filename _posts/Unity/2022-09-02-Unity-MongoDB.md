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

# MongoDB in Unity
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

## 로그인 구현

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

## 데이터베이스 가져오기

```c#
public class MongoDBCtrl : MonoBehaviour
{
    // 데이터베이스 가져오기
    const string DATABASE_NAME =
        "TestDB";

    IMongoDatabase db;

    void Get_DataBase()
    {
        db = client.GetDatabase(DATABASE_NAME);
    }
}
```

## 콜렉션 가져오기

```c#
public class MongoDBCtrl : MonoBehaviour
{
    // 이번엔 콜렉션이 하나이므로 전역변수로 가져오기(DB 안에선 여러 콜렉션이 있을 땐 내부 함수에서 가져오는걸 권장)
    // GameData Class의 형태로 생성

    IMongoCollection<GameData> db_col;

    void Get_Collection()
    {
        db_col = db.GetCollection<GameData>("TestDB.TestDB.col");
    }
}
```

```c#
// GameData.cs - 구조체로 콜렉션의 내용을 추가
public class GameData
{
    // MongoDB 내에서 관리하는 객체
    public ObjectId id { get; set; }
    public string name { get; set; }
}
```

## 전체 세팅 코드

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using MongoDB.Bson;
using MongoDB.Driver;

// 클라이언트 내부 -> 데이터베이스
// 데이터베이스 내부 -> 콜렉션

public class MongoDBCtrl : MonoBehaviour
{
    // 커넥트(User) 정보 가져오기
    const string MONGO_URI = 
        "mongodb+srv://User:User@cluster0.lsm0ujc.mongodb.net/?retryWrites=true&w=majority";

    MongoClient client;

    void DB_Login()
    {
        client = new MongoClient(MONGO_URI);
    }


    // 데이터베이스 가져오기
    const string DATABASE_NAME =
        "TestDB";

    IMongoDatabase db;

    void Get_DataBase()
    {
        db = client.GetDatabase(DATABASE_NAME);
    }


    // 이번엔 콜렉션이 하나이므로 전역변수로 가져오기(DB 안에선 여러 콜렉션이 있을 땐 내부 함수에서 가져오는걸 권장)
    // GameData Class의 형태로 생성
    IMongoCollection<GameData> db_col;

    void Get_Collection()
    {
        db_col = db.GetCollection<GameData>("TestDB.TestDB.col");
    }



    private void Start()
    {
        DB_Login();
        Debug.Log(client);

        Get_DataBase();
        Debug.Log(db);

        Get_Collection();
        Debug.Log(db_col);
    }
}
```

## Insert

```c#
public class MongoDBCtrl : MonoBehaviour
{
    void db_Insert(string name, int score)
    {
        GameData _GameData = new GameData(); // 빈 데이터
        _GameData.name  = name;
        _GameData.score = score;

        db_col.InsertOne(_GameData);
    } 
}
```

### name 필드를 중복 안되도록 C#에서 제한하기

```c#
public class MongoDBCtrl : MonoBehaviour
{
    bool db_exist(string name)
    {
        BsonDocument _bson = new BsonDocument { { "name", name} };
        List<GameData> user_list = db_col.Find(_bson).ToList();
        GameData[] user_data = user_list.ToArray();
        if (user_data.Length == 0) return false; // 데이터가 없다면 false
        return true;
    }

    void DB_Insert(string name, int score )
    {
        // MongoDB 내에서 name필드에 중복이 있는지 검사
        if (db_exist(name))
        {
            Debug.Log("Name is Exist : " + name);
            return;
        }

        GameData _GameData = new GameData(); // 빈 데이터
        _GameData.name = name;
        _GameData.score = score;

        db_col.InsertOne(_GameData);
    }
}
```

![image](https://user-images.githubusercontent.com/110334366/188057535-15c0a5c4-58c8-4cf0-b37a-6586f92ac3c8.png)

## Search

```c#
public class MongoDBCtrl : MonoBehaviour
{
    void DB_All_View()
    {
        List<GameData> user_List = db_col.Find(user => true).ToList(); // 콜렉션을 리스트화 한다.
        GameData[] user_Data = user_List.ToArray(); // 최적화를 위해 List 자료형 -> 배열로 변환
        for (int i = 0; i < user_Data.Length; i++)
        {
            Debug.Log(
            user_Data[i].name
            + " : " +
            user_Data[i].score
            );
        }
    }
}    
```

![image](https://user-images.githubusercontent.com/110334366/188055103-6753da9c-cf55-4cb6-8a39-a90b07903b51.png)

![image](https://user-images.githubusercontent.com/110334366/188055042-d7b44024-9183-42ae-ac61-c5cac5808210.png)

## Remove
