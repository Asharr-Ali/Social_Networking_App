#ifndef Users
#define Users

#include<string>
#include<fstream>

#include "Pages.h"
#include "Posts.h"
#include "Friends.h"

using namespace std;

class Post;
class Page;
class Friend;

class User
{
    private:
    string ID;
    string firstName;
    string lastName;
    string* friendsID;
    Friend** friendsList;
    int friendsCount;
    string* likedPagesID;
    Page** pagesLiked;
    int pagesLikedCount;
    Post** userPosts;
    string* postsID;
    int postsCount;

    public:
    User();
    bool CheckAccountExistence(string);
    void GetNameFromFile(string);
    void ReadDataFromFile(string);
};
User::User()
{
    ID,firstName,lastName='\0';
    friendsID,friendsList,likedPagesID,pagesLiked,userPosts,postsID=nullptr;
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
void User::ReadDataFromFile(string id)
{
    ifstream userData("Users.txt");
    ifstream friendsData("Friends.txt");

    if(!userData)
        cout<<"\n Users File Failed to Open!\n";
    if(!friendsData)
        cout<<"\n Friends File Failed to Open!\n";

    string File;
    string line;
    int lineNumber=0,lineNumber1=0;

    while(getline(userData,line))
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
           
            for (int i=0;i<pagesLikedCount;i++)
                pagesLiked[i]->inputPage(likedPagesID,i);

            Post currentUser;
            postsCount=currentUser.postsCount(id);
            userPosts=new Post*[postsCount];

            for (int j=0;j<postsCount;j++)
                userPosts[j]=new Post;  

            ifstream postsData("Posts.txt");
            if(!postsData)
                cout<<"\nPosts File Failed to Open!\n";

            for (int i=0;i<postsCount;i++)
                userPosts[i]->inputPost(id,postsData);

            postsData.close();

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

            friendsList=new Friend* [friendsCount];
            for (int i=0;i<friendsCount;i++)
                friendsList[i]=new Friend;

            for (int j=0;j<friendsCount;j++)
                friendsList[j]->ReadFriendData(friendsID[j]);

            break;
        }
    }
    userData.close();
    friendsData.close();
}

#endif