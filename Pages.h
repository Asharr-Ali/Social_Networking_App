#ifndef Pages
#define Pages

#include<iostream>
#include<string>
#include<fstream>

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
    void inputPage(string*);
};
Page::Page()
{
    pageID,pageName,createdBy='\0';
    pageFollowers,pagePosts=nullptr;
    pageFollowersCount,pagePostsCount=0;
}
void Page::inputPage(string* pagesIDs)
{
    int size=sizeof(pagesIDs);

    for (int i=0;i<size;i++)
    {
        while(1)
        {
            ifstream pageData("Pages.txt");
            if(!pageData)
            cout<<"\nPage File failed to Open!\n";

            string File;
            pageData>>File;
            
            if(pagesIDs[i]==File)
            {
                pageData>>pageID;
                pageData>>createdBy;

                string line;
                while(getline(pageData,line)&&line!="-2")
                pageName+=line;

                pageData>>pageFollowersCount;
                pageFollowers=new string[pageFollowersCount];
                for (int i=0;i<pageFollowersCount;i++)
                {
                    string Data;
                    pageData>>Data;
                    pageFollowers[i]=Data;
                }

                pageData.close();
                break;
            }
        }
    }
}

#endif