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
    void inputPage(string*,int);
    void displayAnyPage();
    void displayPagePosts();
};
Page::Page()
{
    pageID,pageName,createdBy='\0';
    pageFollowers,pagePosts=nullptr;
    pageFollowersCount,pagePostsCount=0;
}
void Page::inputPage(string* pagesIDs,int i)
{
    ifstream pageData("Pages.txt");
    if(!pageData)
        cout<<"\nPage File failed to Open!\n";

    string IDtoFind=pagesIDs[i];    

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
                pagePosts[i]->inputPost(IDtoFind,postsData);

            postsData.close();
            break;
        }
    }
    pageData.close();
}
// hello
void Page::displayAnyPage()
{
    string newID;
    cout<<"\nEnter Any Page ID you want to see:";
    getline(cin,newID);
}
void Page::displayPagePosts()
{
    for(int i=0;i<pagePostsCount;i++)
    {
        pagePosts[i]->displayPost();
        cout<<"\n\n";
    }
}

#endif