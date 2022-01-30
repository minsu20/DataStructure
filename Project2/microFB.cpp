//-----------------------------------------------------------------------------
// 
//      2020112377 컴퓨터공학전공 김민수
//
//		Project02 - Micro Facebook.   microFB.cpp
// 
// 
//-----------------------------------------------------------------------------

#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include <iostream>
#include <string>
#include <list> //list stl
#include <hash_map> //hash_map stl
#include <algorithm>
#include "microFB.h"

using namespace std;
using namespace stdext;

bool operator==(const Person& p1, const Person& p2)         // Person class에 대한 연산자 Overloading
{
    if (p1.name == p2.name)
        return true;
    else
        return false;
}


Facebook::Facebook()
{
    //생성자
}

//--------------------------------------------------------------------

Facebook::~Facebook()
{
    hashMap.clear(); //소멸자
}

//--------------------------------------------------------------------

void Facebook::createPerson(const string& newName)							//command 'P'
{
    Person* newPerson = new Person(newName);    //Person 객체 생성
    hash_map<string, Person>::iterator findPerson = hashMap.find(newName); //key가 newName인 요소 찾기

    if (findPerson == hashMap.end())    //이름이 없었으면
    {
        hashMap.insert(hash_map<string, Person>::value_type(newName, *newPerson));     //hash_map에 삽입.
    }
    else     //이름이 이미 존재하면
        cout << "Same name person already exists." << endl;
}

//--------------------------------------------------------------------

void Facebook::beFriend(const string& name1, const string& name2)		//command 'F' :친구 맺기
{
    hash_map<string, Person>::iterator findPerson1 = hashMap.find(name1);
    hash_map<string, Person>::iterator findPerson2 = hashMap.find(name2); //key가 name1, name2 인 요소 찾기

    if (name1 == name2) //name1과 name2가 같은 경우
        cout << "The name is the same" << endl;
    else if (findPerson1 == hashMap.end())           //name1 없는 경우
        cout << "Couldn't find " << name1 << endl;
    else if (findPerson2 == hashMap.end())           //name2 없는 경우
        cout << "Couldn't find " << name2 << endl;
    else if (isFriend(name1, name2)==true)          //이미 친구인 경우
    {
        cout << "They are already friends" << endl;
    }
    else
    { //first-key, second-value
        findPerson1->second.friendLnk.push_back(findPerson2->second);    //findPerson1의 value의 friendLnk에 findPerson2의 value삽입
        findPerson2->second.friendLnk.push_back(findPerson1->second);    //findPerson2의 value에 friendLnk에 findPerson1의 value삽입
    }
}

//--------------------------------------------------------------------

void Facebook::unFriend(const string& name1, const string& name2)		//command 'U' :친구 끊기
{
    hash_map<string, Person>::iterator findPerson1 = hashMap.find(name1); 
    hash_map<string, Person>::iterator findPerson2 = hashMap.find(name2); //key가 name1, name2 인 요소 찾기

    list<Person>::iterator findFriend1;     
    list<Person>::iterator findFriend2;        //반복자 선언

    if (name1 == name2)
        cout << "The name is the same" << endl;

    else
    {
            if (findPerson1 == hashMap.end())                     //name1 없는 경우
                cout << "Couldn't find " << name1 << endl;
            else if (findPerson2 == hashMap.end())           //name2 없는 경우
                cout << "Couldn't find " << name2 << endl;

        else
        { //name1, name2 있는 경우
            for (findFriend1 = findPerson1->second.friendLnk.begin(); findFriend1 != findPerson1->second.friendLnk.end(); findFriend1++)
            { //findPerson1의 value의 friendLnk 처음부터 끝까지 검사
                if (findFriend1->name == name2)
                { //name2를 가진 이름이 있으면
                    for (findFriend2 = findPerson2->second.friendLnk.begin(); findFriend2 != findPerson2->second.friendLnk.end(); findFriend2++)
                    { //findPerson2의 value의 friendLnk 처음부터 끝까지 검사
                        if (findFriend2->name == name1)
                        { //name1을 가진 이름이 있으면 (서로 친구인지 확인)
                            findPerson1->second.friendLnk.erase(findFriend1);  //person1의 friendLnk에서 person2 제거
                            findPerson2->second.friendLnk.erase(findFriend2);  //person2의 friendLnk에서 person1 제거
                            return;
                        }
                    }
                }
            }
        }
    }
}

//--------------------------------------------------------------------

void Facebook::printFriend(const string& fname)						//command 'L' :친구 검색
{
    hash_map<string, Person>::iterator iter;   
    list<Person>::iterator iter_f;  //iterator 선언부

    iter = hashMap.find(fname);    //key가 fname 인 요소 찾기

    if (iter == hashMap.end())           //없는 경우
        cout << "Couldn't find " <<fname<< endl;
    else
    {
        for (iter_f = iter->second.friendLnk.begin(); iter_f != iter->second.friendLnk.end(); iter_f++)     
        { //iter의 value의 friendLnk처음부터 끝까지 검사
            cout << iter_f->name << " "; //friendLnk에 있는 원소(이름) 모두 출력
        }
    }
}

//--------------------------------------------------------------------

bool Facebook::isFriend(const string& name1, const string& name2)		//command 'Q' 친구인지 확인 Y/N
{
    hash_map<string, Person>::iterator findPerson1 = hashMap.find(name1); 
    hash_map<string, Person>::iterator findPerson2 = hashMap.find(name2);  //key가 name1, name2 인 요소 찾기
    list<Person>::iterator findFriend1;        
    list<Person>::iterator findFriend2; //iterator 선언부


    if (name1 == name2) { //이름이 같은 경우
        cout << "The name is the same" << endl;
        return false;
    }

    else
    {
        if (findPerson1 == hashMap.end())                     //name1 없는 경우
        {
            cout << "Couldn't find " << name1 << endl;
            return false;
        }
        else if (findPerson2 == hashMap.end())           //name2 없는 경우
        {
            cout << "Couldn't find " << name2 << endl;
            return false;
        }
        else
        {//name1, name2 있는 경우
            for (findFriend1 = findPerson1->second.friendLnk.begin(); findFriend1 != findPerson1->second.friendLnk.end(); findFriend1++)
            { //findPerson1의 value의 friendLnk 처음부터 끝까지 검사
                if (findFriend1->name == name2)
                {//name2를 가진 이름이 있으면
                    for (findFriend2 = findPerson2->second.friendLnk.begin(); findFriend2 != findPerson2->second.friendLnk.end(); findFriend2++)
                    {//findPerson2의 value의 friendLnk 처음부터 끝까지 검사
                        if (findFriend2->name == name1)
                        {//name1을 가진 이름이 있으면
                            return true; //친구이다
                        }
                    }
                }
            }
        }
    }
}

ofstream writeFile; //쓸 목적의 파일 선언    

void Facebook::fileWrite() {//종료하기 누르면  파일에 저장	
    hash_map<string, Person>::iterator iterPerson;
    list<Person>::iterator iterFriend;


    writeFile.open("input.txt");
    if (writeFile.is_open()) { //파일 열기
        for (iterPerson = hashMap.begin(); iterPerson != hashMap.end(); iterPerson++)
        {
            writeFile << "Person: "<<iterPerson->first<<"---Friends: ";
            for (iterFriend = iterPerson->second.friendLnk.begin(); iterFriend != iterPerson->second.friendLnk.end(); iterFriend++)
            { //iter의 value의 friendLnk처음부터 끝까지
                writeFile << iterFriend->name << "  "; //friendLnk에 있는 원소(이름) 모두 출력
            }
            writeFile << endl;
        }
    }
    else {
        cout << "   파일을 출력할 수 없습니다. " << endl;
    }
    writeFile.close(); //파일 닫기
}


