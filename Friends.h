#ifndef Friends
#define Friends

#include<string>
#include<fstream>

#include "Pages.h"
#include "Posts.h"

using namespace std;

class Post;
class Page;
class User;

class Friend
{
    private:
    string ID;
    string firstName;
    string lastName;
    Post** userPosts;
    string* postsID;
    int postsCount;

    public:
    Friend();
    void GetNameFromFile(string);
    void ReadFriendData(string);
    void userPostsDisplay();
};
Friend::Friend()
{
    ID,firstName,lastName='\0';
    userPosts,postsID=nullptr;
}
void Friend::GetNameFromFile(string id)
{
    ifstream searchData("Users.txt");

    if(!searchData)
    cout<<"\nUser File Failed to Open!";

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
void Friend::ReadFriendData(string id)
{
    ifstream userData("Users.txt");

    if(!userData)
        cout<<"\n Users File Failed to Open!\n";

    string File;

    while(1)
    {
        userData>>File;

        if(id==File)
        {
            ID=File;
            userData>>firstName;
            userData>>lastName;

            Post currentUser;
            postsCount=currentUser.postsCount(id);
            userPosts=new Post*[postsCount];

            for (int j=0;j<postsCount;j++)
                userPosts[j]=new Post;  

            ifstream postsData("Posts.txt");
            if(!postsData)
                cout<<"\nPosts File Failed to Open!\n";

            for (int i=0;i<postsCount;i++)
                userPosts[i]->inputPostByUserID(id,postsData);

            postsData.close();

            break;
        }
    }
    userData.close();
}
void Friend::userPostsDisplay()
{
    for (int i=0;i<postsCount;i++)
    {
        userPosts[i]->displayPost();
        cout<<"\n\n";
    }
}

#endif