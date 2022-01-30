//-----------------------------------------------------------------------------
// 
//      2020112377 ��ǻ�Ͱ������� ��μ�
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

bool operator==(const Person& p1, const Person& p2)         // Person class�� ���� ������ Overloading
{
    if (p1.name == p2.name)
        return true;
    else
        return false;
}


Facebook::Facebook()
{
    //������
}

//--------------------------------------------------------------------

Facebook::~Facebook()
{
    hashMap.clear(); //�Ҹ���
}

//--------------------------------------------------------------------

void Facebook::createPerson(const string& newName)							//command 'P'
{
    Person* newPerson = new Person(newName);    //Person ��ü ����
    hash_map<string, Person>::iterator findPerson = hashMap.find(newName); //key�� newName�� ��� ã��

    if (findPerson == hashMap.end())    //�̸��� ��������
    {
        hashMap.insert(hash_map<string, Person>::value_type(newName, *newPerson));     //hash_map�� ����.
    }
    else     //�̸��� �̹� �����ϸ�
        cout << "Same name person already exists." << endl;
}

//--------------------------------------------------------------------

void Facebook::beFriend(const string& name1, const string& name2)		//command 'F' :ģ�� �α�
{
    hash_map<string, Person>::iterator findPerson1 = hashMap.find(name1);
    hash_map<string, Person>::iterator findPerson2 = hashMap.find(name2); //key�� name1, name2 �� ��� ã��

    if (name1 == name2) //name1�� name2�� ���� ���
        cout << "The name is the same" << endl;
    else if (findPerson1 == hashMap.end())           //name1 ���� ���
        cout << "Couldn't find " << name1 << endl;
    else if (findPerson2 == hashMap.end())           //name2 ���� ���
        cout << "Couldn't find " << name2 << endl;
    else if (isFriend(name1, name2)==true)          //�̹� ģ���� ���
    {
        cout << "They are already friends" << endl;
    }
    else
    { //first-key, second-value
        findPerson1->second.friendLnk.push_back(findPerson2->second);    //findPerson1�� value�� friendLnk�� findPerson2�� value����
        findPerson2->second.friendLnk.push_back(findPerson1->second);    //findPerson2�� value�� friendLnk�� findPerson1�� value����
    }
}

//--------------------------------------------------------------------

void Facebook::unFriend(const string& name1, const string& name2)		//command 'U' :ģ�� ����
{
    hash_map<string, Person>::iterator findPerson1 = hashMap.find(name1); 
    hash_map<string, Person>::iterator findPerson2 = hashMap.find(name2); //key�� name1, name2 �� ��� ã��

    list<Person>::iterator findFriend1;     
    list<Person>::iterator findFriend2;        //�ݺ��� ����

    if (name1 == name2)
        cout << "The name is the same" << endl;

    else
    {
            if (findPerson1 == hashMap.end())                     //name1 ���� ���
                cout << "Couldn't find " << name1 << endl;
            else if (findPerson2 == hashMap.end())           //name2 ���� ���
                cout << "Couldn't find " << name2 << endl;

        else
        { //name1, name2 �ִ� ���
            for (findFriend1 = findPerson1->second.friendLnk.begin(); findFriend1 != findPerson1->second.friendLnk.end(); findFriend1++)
            { //findPerson1�� value�� friendLnk ó������ ������ �˻�
                if (findFriend1->name == name2)
                { //name2�� ���� �̸��� ������
                    for (findFriend2 = findPerson2->second.friendLnk.begin(); findFriend2 != findPerson2->second.friendLnk.end(); findFriend2++)
                    { //findPerson2�� value�� friendLnk ó������ ������ �˻�
                        if (findFriend2->name == name1)
                        { //name1�� ���� �̸��� ������ (���� ģ������ Ȯ��)
                            findPerson1->second.friendLnk.erase(findFriend1);  //person1�� friendLnk���� person2 ����
                            findPerson2->second.friendLnk.erase(findFriend2);  //person2�� friendLnk���� person1 ����
                            return;
                        }
                    }
                }
            }
        }
    }
}

//--------------------------------------------------------------------

void Facebook::printFriend(const string& fname)						//command 'L' :ģ�� �˻�
{
    hash_map<string, Person>::iterator iter;   
    list<Person>::iterator iter_f;  //iterator �����

    iter = hashMap.find(fname);    //key�� fname �� ��� ã��

    if (iter == hashMap.end())           //���� ���
        cout << "Couldn't find " <<fname<< endl;
    else
    {
        for (iter_f = iter->second.friendLnk.begin(); iter_f != iter->second.friendLnk.end(); iter_f++)     
        { //iter�� value�� friendLnkó������ ������ �˻�
            cout << iter_f->name << " "; //friendLnk�� �ִ� ����(�̸�) ��� ���
        }
    }
}

//--------------------------------------------------------------------

bool Facebook::isFriend(const string& name1, const string& name2)		//command 'Q' ģ������ Ȯ�� Y/N
{
    hash_map<string, Person>::iterator findPerson1 = hashMap.find(name1); 
    hash_map<string, Person>::iterator findPerson2 = hashMap.find(name2);  //key�� name1, name2 �� ��� ã��
    list<Person>::iterator findFriend1;        
    list<Person>::iterator findFriend2; //iterator �����


    if (name1 == name2) { //�̸��� ���� ���
        cout << "The name is the same" << endl;
        return false;
    }

    else
    {
        if (findPerson1 == hashMap.end())                     //name1 ���� ���
        {
            cout << "Couldn't find " << name1 << endl;
            return false;
        }
        else if (findPerson2 == hashMap.end())           //name2 ���� ���
        {
            cout << "Couldn't find " << name2 << endl;
            return false;
        }
        else
        {//name1, name2 �ִ� ���
            for (findFriend1 = findPerson1->second.friendLnk.begin(); findFriend1 != findPerson1->second.friendLnk.end(); findFriend1++)
            { //findPerson1�� value�� friendLnk ó������ ������ �˻�
                if (findFriend1->name == name2)
                {//name2�� ���� �̸��� ������
                    for (findFriend2 = findPerson2->second.friendLnk.begin(); findFriend2 != findPerson2->second.friendLnk.end(); findFriend2++)
                    {//findPerson2�� value�� friendLnk ó������ ������ �˻�
                        if (findFriend2->name == name1)
                        {//name1�� ���� �̸��� ������
                            return true; //ģ���̴�
                        }
                    }
                }
            }
        }
    }
}

ofstream writeFile; //�� ������ ���� ����    

void Facebook::fileWrite() {//�����ϱ� ������  ���Ͽ� ����	
    hash_map<string, Person>::iterator iterPerson;
    list<Person>::iterator iterFriend;


    writeFile.open("input.txt");
    if (writeFile.is_open()) { //���� ����
        for (iterPerson = hashMap.begin(); iterPerson != hashMap.end(); iterPerson++)
        {
            writeFile << "Person: "<<iterPerson->first<<"---Friends: ";
            for (iterFriend = iterPerson->second.friendLnk.begin(); iterFriend != iterPerson->second.friendLnk.end(); iterFriend++)
            { //iter�� value�� friendLnkó������ ������
                writeFile << iterFriend->name << "  "; //friendLnk�� �ִ� ����(�̸�) ��� ���
            }
            writeFile << endl;
        }
    }
    else {
        cout << "   ������ ����� �� �����ϴ�. " << endl;
    }
    writeFile.close(); //���� �ݱ�
}


