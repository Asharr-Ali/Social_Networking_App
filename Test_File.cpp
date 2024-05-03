#ifndef Users
#define Users

#include<iostream>
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
    string** friendsID;
    User** friendsList;
    int friendsCount;
    string** likedPagesID;
    Page** pagesLiked;
    int pagesLikedCount;
    Posts** userPosts;
    public:
    User();
    bool CheckAccountExistence(string);
    void ReadDataFromFile(string);
};
User::User()
{
    ID,firstName,lastName='\0';
    friendsID,friendsList,likedPagesID,pagesLiked,userPosts=nullptr;
    friendsCount,pagesLikedCount=0;
}
bool User::CheckAccountExistence(string in)
{
    ifstream readData;
    readData.open("Users.txt");
    if(!readData)
    cout<<"\nFile Failed to Open!";
    string file;
    while(getline(readData,file))
    {
        readData>>file;
        if(file==in)
            return true;
    }
    return false;
}
void User::ReadDataFromFile(string in)
{
    ifstream userData("Users.txt");

    if (!userData)
    cout<<"\nUnable to open File!\n";

    string File;
    while(1)
    {
        userData>>File;
        if(File==in)
        {
            ID=in;
            userData>>firstName;
            userData>>lastName;
            userData>>pagesLikedCount;

            pagesLiked=new Page* [pagesLikedCount];
            for (int i=0;i<pagesLikedCount;i++)
            pagesLiked[i]=new Page;

            userData.close();

        }
    }

}

#endif