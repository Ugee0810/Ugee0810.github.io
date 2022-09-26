---
title:      C# Data Structure#01 | Collections 자료구조 정리
date:       "2022-09-07"
categories: ["C#", "04.Data Structure"]
tags:       ["C#", "Data Structure", "Unity"]
# pin:        true
---

# 자료구조의 중요성
자료구조는 데이터를 메모리에 저장하는것입니다.

데이터량이 많을 때 목적에 맞는 자료구조를 사용하지 않으면 엄청난 비용(속도, 메모리 낭비)의 손실을 가져오거나 심지어 프로그램, 서버가 다운될 수도 있습니다.

데이터가 빈번하게 추가되거나 선입선출 등의 우선순위가 있거나 특정 값(Key)로 데이터를 뽑아올 경우가 있거나 등의 목적에 따라 자료구조를 선택적으로 사용해 주어야 합니다.

# C# 자료구조 정리

|Generic|Non-Generic|Multi-Thread 동기화 옵션 사용|용도|
|---|---|---|---|
|```Dictionary<TKey,TValue>```|Hashtable|```ConcurrentDictionary<TKey,TValue>```<br>```ReadOnlyDictionary<TKey,TValue>```<br>```ImmutableDictionary<TKey,TValue>```|Key로 빠르게 데이터를 조회할때 사용<br>Key와 Value 로 데이터가 저장됨|
|```List<T>```|Array<br>ArrayList|```ImmutableList<T>```<br>```ImmutableArray```|데이터가 저장된 순서(인덱스)를 빠르게 탐색함|
|```Queue<T>```|Queue|```ConcurrentQueue<T>```<br>```ImmutableQueue<T>```|FIFO(선입 선출) 방식으로 항목 사용|
|```Stack<T>```|Stack|```ConcurrentStack<T>```<br>```ImmutableStack<T>```|LIFO(후입 선출) 방식으로 데이터 사용|
|```SortedList<TKey,TValue>```|SortedList|```ImmutableSortedDictionary<TKey,TValue>```<br>```ImmutableSortedSet<T>```|입력된 순서와 상관없이 Key값으로 정렬됨|
|```LinkedList<T>```|지원안함|지원안함|데이터 등록, 삭제가 빈번하게 일어날때|
|```ObservableCollection<T>```|지원안함|지원안함|목록에 데이터를 넣거나 뺄때 알람을 표시해줌|
|```HashSet<T>```<br>```SortedSet<T>```|지원안함|```ImmutableHashSet<T>```<br>```ImmutableSortedSet<T>```|중복된 데이터를 저장하지 않을때<br>(수학에서 집합 사용 시)|

# C# 자료구조 구성도
![image](https://user-images.githubusercontent.com/85896566/188787743-37a6adf0-c341-450f-bef6-edf8a5c49b0e.png)


# Unity3D에서의 콜렉션
Unity3D에서는 배열을 포함한 “콜렉션” 이라고 불리우는 다양한 자료형들을 지원한다.

- 내장형 배열(Built-in Array)
- ArrayList
- HashTable
- Generic List
- Generic Dictionary
- 2차원 배열

모든 타입의 자료형들에는 다음과 같은 공통점이 있다.

- 모든 자료형은 객체(Object)를 저장할 수 있고, 이를 꺼내서 읽는 것이 가능하다.
- 자료형의 크기를 알 수 있다.
- 모든 자료형은 아니지만 대부분의 자료형에 대해서는 임의의 위치에 자료형을 삽입하거나 삭제하는 것이 가능하며 정렬하는 것도 가능하다.
- 자료형들은 별도의 루프를 통해서 순회하는 것이 가능하다.
 
다음은 앞에서 언급한 자료형에 대한 설명이다.

## 1.내장형 배열(Built-in Array)
Unity의 JS 및 C# 에서 모두 사용이 가능한 기본적인 배열 타입의 자료형이 바로 내장형 배열이다.
내장형 배열은 배열을 선언할 때 크기를 함께 설정하기 때문에 고정된 크기를 가지며 매우 빠른 처리가 가능하다. 이 때문에 내장형 배열은 코드에서 빠른 처리를 해야 하고, 자료의 크기(개수)를 알고 있는 경우에는 선택 할 수 있는 가장 좋은 자료형이다.
 
만약 다양한 개수의 아이템들을 저장해야 하는 경우라도 최대 크기를 알고 있거나 결정할 수 있는 경우라면 내장형 배열을 사용하는 것이 좋다.예를 들어 슈팅 게임에서 총알을 한번에 최대 50개까지만 발사할 수 있다면, 크기가 50인 내장형 내열을 사용해서 사용하지 않는 공간은 null로 채우는 방법을 사용하면 된다.
또한 내장형 배열은 Unity 의 Inspector 윈도우 창에 표시할 수 있다.
때문에 Unity 에디터를 이용해서 편집이 필요한 자료형이라면 내장형 자료형을 사용하는 것이 편리하다.
 
Unity 의 Get… 함수를 통해서 리턴되는 배열형은 모두 내장형 배열이다.예를 들어 GetComponentInChildren 함수가 리턴하는 컴포넌트 들은 내장형 배열을 사용해서 저장할수 있다.
 
```c#
//declaration
TheType[] myArray = new TheType[lengthOfArray];
 
//declaration example using ints
Int[] myNumbers = new int[10];
 
//declaration example using GameObjects
GameObject[] enemies = new GameObject[16];
 
// get the length of the array
int howBig = myArray.Length;
 
// set a value at position i
myArray[i] = newValue;
 
//get a value from position i
TheType thisValue = myArray[i];
```
 
## 2.ArrayList
ArrayList는 .NET 의 자료형으로 Javascript 배열과 매우 유사하다. 다만 JS 뿐만 아니라 C#에서도 사용이 가능하다, 하지만 크기가 역시 동적이기 때문에 자료의 삽입 및 삭제시 ArrayList의 크기가 변경될 수 있다. 내장형 배열과 비교하면 속도가 떨어진다.
 
```c#
//declaration
ArrayList myArrayList = new ArrayList();// add an item to the end of the array.
myArrayList.Add(anItem);
//change the value stored at position i
myArrayList[i] = newValue;
//retrieve an item from position i
TheType thisItem = (TheType) myArrayList[i];
//removes an item from position i
myArrayList.RemoveAt(i);
//get the number of items in the ArrayList
Var howBig = myArray.length;  
``` 

## 3.Hash Table
해시테이블은 각각의 아이템이 KEY 와 VALUE 으로 구성된 자료형으로 빠른 검색이 필요한 경우에 요긴하게 사용할 수 있는 것이 장점이다.주어진 KEY 로 검색하게 되면 VALUE을 리턴하는 방식이다.ArrayList와 마찬가지로 해쉬테이블 역시 얻어 온 값에 대한 형변환(type casting)이 필요하다.

```c#
//declaration
Hashtable myHashtable = new Hashtable();
 
//insert or change the value for the given key
myHashtable[anyKey] = newValue;
 
//retrieve a value for the given key
ValueType thisValue = (valueType)myHashtable[theKey];
 
//get the number of items in the Hashtable
Int howBig = myHashtable.Count;
 
//remove the key & value pair from the Hashtable, for the given key.
myHashtable.Remove(theKey);
```
 
## 4.Generic List
Unity3D엔진은 3.0 버전부터 iOS에서 .NET 의 제너릭 자료형을 지원한다.또한 3.0 버전부터는 Javascript에서도 이 제너릭 콜렉션을 사용할 수 있게 되었다.
 
제너릭 리스트는 제너릭 콜렉션에 속한 자료형으로 동적인 크기를 가지며, 임의의 위치에 자료형의 삽입과 삭제가 가능하는 점에서 Javascript 배열 및 ArrayList 와 유사하다.제너릭 리스트와 이들 자료형과의 가장 큰 차이점이라면 제너릭 리스트는 자료형을 선언 할 떄 자료형의 타입을 지정한다는 점이다. 그리고 사용 할 때에는 선언시 지정한 자료형만을 삽입하거나 삭제할 수 있다.
그러므로 다음과 같은 특징을 가지게 된다.
- 명시적인 형변환을 할 필요가 없다.
- ArrayList 보다 빠르다.
 
이러한 특징을 잘 이해해서 만약에 사용하고자 하는 자료의 형을 미리 알고 있는 경우에는 ArrayList 보다 제너릭 리스트를 사용하는 것이 훨씬 유리하다.
제너릭 리스트는 System.Collections 에 기본적으로 포함되어 있지 않기 때문에 제너릭 리스트를 사용하는 경우에는 명시적으로 using System.Collections.Generic 선언이 필요하다.

```c#
//declaration
List<Type> myList = new List<Type>();
//a real-world example of declaring a List of ‘ints’
List<int> someNumbers = new List<int>();
 
//a real-world example of declaring a List of “GameObjects”
List<GameObject> enemies = new List<GameObject>();
 
//add an item to the end of the List.
myList.Add(theItem);
 
//change the value in the List at position i
myList[i] = newItem;
 
//retrieve the item at position i
Type thisItem = List[i];
 
//remove the item from position i
myList.RemoveAt(i);
```

## 5.Generic Dictionary (제너릭 딕셔너리)
제너릭 리스트와 마찬가지로 Unity 3.0 버전부터 iOS 와 JS에서도 사용이 가능한 제너릭 콜렉션 이다.
제너릭 리스트가 ArrayList와 유사한 반면, 제너릭 딕셔너리는 해쉬테이블과 유사하다고 볼수 있다.제너릭 리스트 처럼 Generic Dictionary도 선언시 아이템의 타입을 명시적으로 선언해 주어야 하며, 제너릭 리스트가 ArrayList에 비해 빠른 속도를 나타내는 것처럼 제너릭 딕셔너리도 일반 딕셔너리에 비해 동적인 형변환에 드는 시간이 없기 때문에 더욱 빠르게 작동한다.
Using 선언 하는 것은 잊지 말기
 
```c#
// declaration
Dictionary<KeyType,ValueType> myDictionary = new Dictionary<KeyType,ValueType>();
 
//and a real-world declaration example(where “person” is a custom class);
Dictionary<string,Person> myContacts = new Dictionary<string,Person>();
 
//insert or change the value for the given key
myDictionary[anyKey] = newValue;
//retrieve a value for the given key
ValueType thisValue = myDictionary[theKey];
//get the number of items in the Hashtable
Int howBig = myDictionary.count;
//remove the key & value pair ifrom the Hashtable, for the given key.
myDictionary.Remove(theKey);
```
 
## 6.2차원 배열(2D Array)
내장형 배열, Javascript 배열, ArrayList, 제너릭 리스트 및 제너릭 딕셔너리가 1차원인 자료형인 반면에 2차원 배열은 제목 그대로 2차원을 지원하는 배열 자료형이다.

게임에서는 타일 인덱스를 저장하기 위한 레벨의 맵 데이터가 이러한 다차원 배열의 예에 속한다. 다차원 배열은 크게 두 종류로 구분할 수 있다.

첫번째는 말 그대로 다차원 배열이 경우로 이 경우에는 ```myArray[x][y]```에서와 같이 고정된 x와 y값의 크기가 필요하다.

다른 것으로는 jagged 배열이 있는데, 이 경우에는 실제로는 다차원이 아니지만 일차원의 배열을 다차원처럼 사용하는 방법이다. ```myArray[x + y*width];``` 맵 데이터의 예와 같이 실제 다차원 배열을 사용하는 것이 훨씬 직관적인 경우가 있지만 다차원 배열을 중첩해서 사용하는 등의 경우에는 퍼포먼스에 영향을 미칠 수 있기 때문에 직관적이지 않더라도 퍼포먼스를 고려한다면 일차원 배열을 확장하거나 변형해서 사용하는 편이 좋다.
 
```c#
//Declaration
//a 16x 4 array of stringsstring[,] myArray = new string[16,4];
 
//and a real-world declaration example( where ‘Tile’ is a user-created custom class):
 
//creat an array to hold a map of 32x32 tiles
Tile[,] map = new Tile[32,32];
 
//set the value at a given location in the arraymyArray[x,y] = newValue;
 
//retrieve a value from a given location in the array.
ValueType thisValue = myArray[x,y];
 
//get the length of 1st dimension of the arrayint width = myArray.GetUpperBound(0);
//get the length of 2nd dimension of the array
Int length = myArray.GetUpperBound(1);
```

<br>

---

# 참고 사이트
- [tutorials_korea](https://blog.naver.com/tutorials_korea/221610337593)
- [kimseunghyun76 - Unity3D에서의 Collections 콜렉션 자료형](https://kimseunghyun76.tistory.com/301)