#ifndef Likes
#define Likes

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Like
{
    public:
    string postID;
    string* likedBy;
    int likesCount;

    Like();

    void GetNameFromFile(string);
    void inputLike(string);
    void displayLikedPeople();

    ~Like();
};
Like::Like()
{
    postID='\0';
    likedBy=nullptr;
    likesCount=0;
}
void Like::GetNameFromFile(string id)
{
    ifstream searchData("Display.txt");

    if(!searchData)
    cout<<"\nDisplay File Failed to Open!";

    string File;

    while(1)
    {
        searchData>>File;

        if(id==File)
        {
            while(searchData>>File && File!="-1")
                cout<<File<<" ";
                
            break;
        }
    }
    searchData.close();
}
void Like:: inputLike(string In)
{
    ifstream likeData("Likes.txt");

    if(!likeData)
       cout<<"\nLikes File Failed to Open!";

    string File;

    while(1)
    {
        likeData>>File;

        if(File==In)
        {
            postID=File;

            likeData>>likesCount;
            likedBy=new string[likesCount];
            for(int i=0;i<likesCount;i++)
               likeData>>likedBy[i];

            break;
        }
    }

    likeData.close();
}
void Like::displayLikedPeople()
{
    for(int i=0;i<likesCount;i++)
    {
        cout<<"\n"<<likedBy[i]<<" - ";
        GetNameFromFile(likedBy[i]);
    }
}
Like::~Like()
{ 
    delete[]likedBy;
}

#endif