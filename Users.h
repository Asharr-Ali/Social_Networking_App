#ifndef Users
#define Users

#include<string>
#include<fstream>

using namespace std;

class Posts;
class Pages;

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
    Pages** pagesLiked;
    int pagesLikedCount;
    Posts** userPosts;
    public:
    User();
    bool CheckAccountExistence(string);
    void GetNameFromFile(string);
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

    if(!userData)
    cout<<"\nFile Failed to Open!";

    string File;
    while(1)
    {
        userData>>File;
        if(id==File)
        {
            ID=File;
            userData>>firstName;
            userData>>lastName;
            userData>>pagesLikedCount;
            
            pagesLiked=new Pages* [pagesLikedCount];
            for (int i=0;i<pagesLikedCount;i++)
            pagesLiked[i]=new Pages;

  userData.close();
        }
    }
}

#endif