#ifndef Users
#define Users

#include<string>
#include<fstream>
#include "Pages.h"

using namespace std;

class Posts;
class Page;

class User
{
    private:
    string ID;
    string firstName;
    string lastName;
    string* friendsID;
    User** friendsList;
    int friendsCount;
    string* likedPagesID;
    Page** pagesLiked;
    int pagesLikedCount;
    Posts** userPosts;
    public:
    User();
    bool CheckAccountExistence(string);
    void GetNameFromFile(string);
    void ReadDataFromFile(string);
    void ReadFriendData();
};
User::User()
{
    ID,firstName,lastName='\0';
    friendsID,friendsList,likedPagesID,pagesLiked,userPosts=nullptr;
    friendsCount,pagesLikedCount=0;
}
bool User::CheckAccountExistence(string in)
{
    ifstream readData("Users.txt");

    if(!readData)
    cout<<"\nFile Failed to Open!";

    string file;
    while(getline(readData,file))
    {
        readData>>file;
        if(file==in)
            return true;
    }
    readData.close();
    return false;
}
void User::GetNameFromFile(string id)
{
    ifstream searchData("Users.txt");

     if(!searchData)
    cout<<"\nFile Failed to Open!";

    string File;

    while(1)
    {
        searchData>>File;
        if(id==File)
        {
            searchData>>File;
            cout<<File<<" ";
            searchData>>File;
            cout<<File;
            break;
        }
    }
    searchData.close();
}
void User::ReadFriendData()
{

}
void User::ReadDataFromFile(string id)
{
    ifstream userData("Users.txt");
    ifstream friendsData("Friends.txt");

    if(!userData || !friendsData)
    cout<<"\nFile Failed to Open!";

    string File;
    string line;
    int lineNumber=0,lineNumber1=0;
    while(1)
    {
        userData>>File;
        lineNumber++;
        if(id==File)
        {
            ID=File;
            userData>>firstName;
            userData>>lastName;
            userData>>pagesLikedCount;

            likedPagesID=new string[pagesLikedCount];

            for (int i=0;i<pagesLikedCount;i++)
            {
                string Data;
                userData>>Data;
                likedPagesID[i]=Data;
            }
            
            pagesLiked=new Page* [pagesLikedCount];
            for (int i=0;i<pagesLikedCount;i++)
            pagesLiked[i]=new Page;

            while(getline(friendsData,line)&&lineNumber1<lineNumber)
                lineNumber1++;

            if(lineNumber1==lineNumber) 
            {
                friendsData>>friendsCount;

                friendsID=new string [friendsCount];

                for (int i=0;i<friendsCount;i++)
                {
                    string Data;
                    friendsData>>Data;
                    friendsID[i]=Data;
                }
            }   
            break;
        }
    }
    userData.close();
}

#endif