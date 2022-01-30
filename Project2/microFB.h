//-----------------------------------------------------------------------------
// 
//      2020112377 ��ǻ�Ͱ������� ��μ�
//
//		Project02 - Micro Facebook.   microFB.h
// 
// 
//-----------------------------------------------------------------------------

#include <iostream>
#include <list>
#include <hash_map>
#include <fstream>
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS

using namespace std;
using namespace stdext;

class Person
{
public:
    // Constructor
    Person(const string& newName)
    {
        name = newName;
    }

    string name;		//the name of person.

    list<Person> friendLnk;		//friend list

    friend class Facebook;
};

class Facebook
{
private:
    hash_map<string, Person> hashMap; //keyŸ���� string(�̸�), valueŸ���� Person��ü

public:

    // Constructor
    Facebook();

    // Destructor
    ~Facebook();

    // Operator
    void createPerson(const string& newName);							//command 'P'
    void beFriend(const string& name1, const string& name2);	//command 'F'
    void unFriend(const string& name1, const string& name2);	//command 'U'
    void printFriend(const string& name1);					//command 'L'
    bool isFriend(const string& name1, const string& name2);	//command 'Q'

    void fileWrite();

    // For Test
    void showAll();
};