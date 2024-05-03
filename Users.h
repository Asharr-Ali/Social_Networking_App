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
    void ReadDataFromFile();
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
void User::ReadDataFromFile()
{
    ifstream userData("Users.txt");
}

#endif