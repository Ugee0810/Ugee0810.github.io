---
title:      MongoDB Cloud in Unity
date:       "2022-09-02"
categories: ["Unity"]
tags:       ["Unity"]
# pin:        true
---

# MongoDB Atlas Database - Cloud DBaaS for MongoDB
MongoDB는 자체적으로 서버를 구축해야하지만, 하위 플러그인으로 아틀라스DB를 사용하면 더 간단하게 무료(512MB)로 구축 가능하다.

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

## ＃Get Connect(User) Info : Login

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

## ＃Get Database Info

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

## ＃Get IMongoCollection<Field_Data>

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

## ＃Insert : 필드 추가
```c#
    void db_Insert(string name, int score)
    {
        GameData _GameData = new GameData(); // 빈 데이터
        _GameData.name  = name;
        _GameData.score = score;

        db_col.InsertOne(_GameData);
    }
```

### ＃name 필드가 중복되지 되도록 C#에서 제한하고 생성하기
```c#
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

    bool db_exist(string name)
    {
        BsonDocument _bson = new BsonDocument { { "name", name } };
        List<GameData> user_list = db_col.Find(_bson).ToList();
        GameData[] user_data = user_list.ToArray();
        if (user_data.Length == 0) return false; // 데이터가 없다면 false
        return true;
    }
```

![image](https://user-images.githubusercontent.com/110334366/188057535-15c0a5c4-58c8-4cf0-b37a-6586f92ac3c8.png)

## ＃Search : 필드 검색
```c#
    void DB_All_View()
    {
        List<GameData> user_list = db_col.Find(user => true).ToList(); // 콜렉션을 리스트화 한다.
        GameData[] user_data = user_list.ToArray(); // 최적화를 위해 List 자료형 -> 배열로 변환
        for (int i = 0; i < user_data.Length; i++)
        {
            Debug.Log(user_data[i].name + " : " + user_data[i].score);
        }
    }
```

하지만 위의 방법은 보안은 좋지 않으므로 아래의 코드처럼 한 번 BsonDocumen를 거쳐 생성한다.

```c#
    void DB_Find(string name)
    {
        BsonDocument _bson = new BsonDocument { { "name", name } };
        List<GameData> user_list = db_col.Find(_bson).ToList();
        GameData[] user_data = user_list.ToArray();
        for (int i = 0; i < user_data.Length; i++)
        {
            Debug.Log(user_data[i].name + " : " + user_data[i].score);
        }
    }
```

![image](https://user-images.githubusercontent.com/110334366/188055103-6753da9c-cf55-4cb6-8a39-a90b07903b51.png)

![image](https://user-images.githubusercontent.com/110334366/188055042-d7b44024-9183-42ae-ac61-c5cac5808210.png)

## ＃Remove : 필드 삭제
사용 시 주의할 점 : Undo기능이 없으므로 신중하게 삭제해야 한다.

(보통의 서비스들은 1년의 복구기간을 준다. 하지만 이건 아님)

- DeleteOne() Method
- DeleteMany() Method

```c#
    // 한 필드만 삭제
    void DB_Remove(string name) 
    {
        BsonDocument _bson = new BsonDocument { { "name", name} };

        db_col.DeleteOne(_bson);
    }

    // 동일 name의 필드들을 삭제
    void DB_Removes(string name)
    {
        BsonDocument _bson = new BsonDocument { { "name", name} };

        db_col.DeleteMany(name);
    }

    // 전체 필드 삭제
    void DB_Remove_All()
    {
        BsonDocument _bson = new BsonDocument {}; // <- 모든 선택

        db_col.DeleteMany(_bson);
    }
```

## ＃Update : 필드 갱신
```c#
    void DB_Update(string name, int score)
    {
        BsonDocument _bson_search = new BsonDocument { { "name", name } }; // 조회
        BsonDocument _bson_update = new BsonDocument { { "name", name }, { "score", score } }; // Update

        db_col.FindOneAndUpdate(_bson_search, _bson_update);
    }
```

# 전체 코드
## ＃MongoDBCtrl.cs
```c#
/// <summary>
/// 클라이언트 내부 → 데이터베이스
/// 데이터베이스 내부 → 콜렉션
/// </summary>

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using MongoDB.Bson;
using MongoDB.Driver;


public class MongoDBCtrl : MonoBehaviour
{
    // Get Connect(User) Info
    const string MONGO_URI = 
        "mongodb+srv://song:song@cluster0.qs1ppkp.mongodb.net/?retryWrites=true&w=majority";
    MongoClient client;

    // Get Database Info
    const string DATABASE_NAME = 
        "TestDB";
    IMongoDatabase db;

    // - 예습에선 콜렉션이 하나이므로 전역변수로 관리
    // - DB 안에선 여러 콜렉션이 있을 땐 내부 함수에서 가져오는걸 권장
    // - GameData Class의 형태로 생성
    IMongoCollection<GameData> db_col;

    private void Start()
    {
        First();
        Debug.Log("=====:Action:=====");
        //DB_Find("song");
        //DB_All_View();
        //DB_Insert("ugi", 1);
        //DB_Remove("song");
    }

    void First()
    {
        DB_Login();
        Get_DataBase();
        Get_Collection();

        Debug.Log("=====:접속 정보:=====");
        Debug.Log("Client : " + client);
        Debug.Log("DataBase Name : " + db);
        Debug.Log("Data Collection : " + db_col);
    }
    void DB_Login()       { client = new MongoClient(MONGO_URI); }
    void Get_DataBase()   { db = client.GetDatabase(DATABASE_NAME); }
    void Get_Collection() { db_col = db.GetCollection<GameData>("TestDB.col"); }

    void DB_Insert(string name, int score)
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

    bool db_exist(string name)
    {
        BsonDocument _bson = new BsonDocument { { "name", name } };
        List<GameData> user_list = db_col.Find(_bson).ToList();
        GameData[] user_data = user_list.ToArray();
        if (user_data.Length == 0) return false; // 데이터가 없다면 false
        return true;
    }

    void DB_All_View()
    {
        List<GameData> user_list = db_col.Find(user => true).ToList(); // 콜렉션을 리스트화 한다.
        GameData[] user_data = user_list.ToArray(); // 최적화를 위해 List 자료형 -> 배열로 변환
        for (int i = 0; i < user_data.Length; i++)
        {
            Debug.Log(user_data[i].name + " : " + user_data[i].score);
        }
    }

    void DB_Find(string name)
    {
        // 데이터를 주고 받는 일은 json으로 보내어 보안을 강화한다.
        BsonDocument _bson = new BsonDocument { { "name", name } };
        List<GameData> user_list = db_col.Find(_bson).ToList();
        GameData[] user_data = user_list.ToArray();
        for (int i = 0; i < user_data.Length; i++)
        {
            Debug.Log(user_data[i].name + " : " + user_data[i].score);
        }
    }

    void DB_Remove(string name) // 한 필드만 삭제
    {
        BsonDocument _bson = new BsonDocument { { "name", name } };

        db_col.DeleteOne(_bson);
    }

    void DB_Removes(string name) // 동일 name의 필드들을 삭제
    {
        BsonDocument _bson = new BsonDocument { { "name", name } };

        db_col.DeleteMany(name);
    }

    void DB_Remove_All() // 전체 필드 삭제
    {
        BsonDocument _bson = new BsonDocument { }; // <- 모든 선택

        db_col.DeleteMany(_bson);
    }

    void DB_Update(string name, int score)
    {
        BsonDocument _bson_search = new BsonDocument { { "name", name } }; // 조회
        BsonDocument _bson_update = new BsonDocument { { "name", name }, { "score", score } }; // Update

        db_col.FindOneAndUpdate(_bson_search, _bson_update);
    }
}
```

## ＃GameData.cs
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using MongoDB.Bson;
using MongoDB.Driver;

// GameData.cs - 구조체로 콜렉션의 내용을 추가
public class GameData
{
    // MongoDB 내에서 관리하는 객체
    public ObjectId id { get; set; }  // 필드의 고유 Index
    public string name { get; set; }
    public int score { get; set; }
}

```