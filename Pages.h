#ifndef Pages
#define Pages

#include<iostream>
#include<string>
#include<fstream>

#include "Posts.h"

using namespace std;

class Post;

class Page
{
    public:
    string pageID;
    string pageName;
    string createdBy;
    string* pageFollowers;
    int pageFollowersCount;
    Post** pagePosts;
    int pagePostsCount;

    Page();

    void GetNameFromFile(string);
    void inputPage(string);
    void displayAnyPage(string);
    void displayPagePosts();

    ~Page();
};
Page::Page()
{
    pageID,pageName,createdBy='\0';
    pageFollowers,pagePosts=nullptr;
    pageFollowersCount,pagePostsCount=0;
}
void Page::GetNameFromFile(string id)
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
void Page::inputPage(string pageID)
{
    ifstream pageData("Pages.txt");
    if(!pageData)
        cout<<"\nPage File failed to Open!\n";

    string IDtoFind=pageID;    

    while(1)
    {
        string File;
        pageData>>File;

        if(IDtoFind==File)
        {
            pageID=File;
            pageData>>createdBy;

            string line;
            getline(pageData,line);
            getline(pageData,pageName);

            pageData>>pageFollowersCount;
            pageFollowers=new string[pageFollowersCount];
            for (int i=0;i<pageFollowersCount;i++)
            {
                string Data;
                pageData>>Data;
                pageFollowers[i]=Data;
            }

            Post currentUser;
            pagePostsCount=currentUser.postsCount(IDtoFind);
            
            pagePosts=new Post*[pagePostsCount];
            for (int j=0;j<pagePostsCount;j++)
                pagePosts[j]=new Post;  

            ifstream postsData("Posts.txt");
            if(!postsData)
                cout<<"\nPosts File Failed to Open!\n";

            for (int i=0;i<pagePostsCount;i++)
                pagePosts[i]->inputPostByUserID(IDtoFind,postsData);

            postsData.close();
            break;
        }
    }
    pageData.close();
}
void Page::displayAnyPage(string pageID)
{
    cout<<"\n\n\n-----------------------------Required Page-----------------------------\n";
    cout<<"\t\t\t";
    GetNameFromFile(pageID);

    cout<<"\nCreated By:";
    GetNameFromFile(createdBy);

    cout<<"\n\nFollowers are:\n";
    for(int i=0;i<pageFollowersCount;i++)
    {
        cout<<"\t";
        GetNameFromFile(pageFollowers[i]);
    }
    cout<<"\n\n\n";
    displayPagePosts();
    cout<<"\n\n---------------------------------------------------------------------\n";
}
void Page::displayPagePosts()
{
    for(int i=0;i<pagePostsCount;i++)
    {
        pagePosts[i]->displayPost();
        cout<<"\n\n";
    }
}
Page::~Page()
{
    delete[]pageFollowers;

    for(int i=0;i<pagePostsCount;i++)
       delete[] pagePosts[i];

    delete[]pagePosts;
}

#endif