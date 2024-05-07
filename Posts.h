#ifndef Posts
#define Posts

#include<iostream>
#include<string>
#include<fstream>

#include "Comments.h"

using namespace std;

class Post
{
    public:
    int num;
    string postID;
    string postDate;
    string postContent;
    int activity;
    string feeling;
    string sharedUser;
    Comment** postComments;
    int postCommentsCount;

    Post();

    void GetNameFromFile(string);
    int postsCount(string);
    void inputPostByUserID(string,ifstream&);
    void inputPostByPostID(string ,ifstream&);
    void inputCommentsOfPost();
    void displayPost();
};
Post::Post()
{
    postID,postDate,postContent,feeling,sharedUser='\0';
    num,activity,postCommentsCount=0;
    postComments=nullptr;
}
void Post::GetNameFromFile(string id)
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
int Post::postsCount(string ID)
{
    int postsCount=0;
    ifstream postData("Posts.txt");
    if(!postData)
        cout<<"\nPosts File Failed to Open!\n";   

    string File;
    while(getline(postData,File))
    {
        postData>>File;

        if(ID==File)
        postsCount++;
    }
    postData.close();    
    return postsCount;
}
void Post::inputPostByUserID(string ID,ifstream& postData)
{
    while(1)
    {
        string File;
        postData>>File;

        if(ID==File)
        {
            sharedUser=File;
            postData>>postID;
            postData>>num;
            postData>>postDate;
            postData>>activity;
            postData>>postCommentsCount;

            string line;
            getline(postData,line);
            getline(postData,postContent);

            if(num!=1)
                getline(postData,feeling);

            inputCommentsOfPost();
            break;
        }
    }
}
void Post::inputPostByPostID(string ID,ifstream& postData)
{
    while(1)
    {
        string File;
        postData>>File;

        if(ID==File)
        {
            postData>>sharedUser;
            postData>>postID;
            postData>>num;
            postData>>postDate;
            postData>>activity;
            postData>>postCommentsCount;

            string line;
            getline(postData,line);
            getline(postData,postContent);

            if(num!=1)
                getline(postData,feeling);

            inputCommentsOfPost();
            break;
        }
    }
}
void Post::inputCommentsOfPost()
{
    ifstream commentsData("Comments.txt");
        if(!commentsData)
            cout<<"\nComment File Failed to Open!";

        postComments=new Comment* [postCommentsCount]; 
        for (int i=0;i<postCommentsCount;i++)
            postComments[i]=new Comment;

        for (int j=0;j<postCommentsCount;j++)
            postComments[j]->inputComment(postID,commentsData);

        commentsData.close();
}
void Post::displayPost()
{
    if(num!=1)
    {
        if(activity==1)
        {
            GetNameFromFile(sharedUser);
            cout<<" is feeling "<<feeling<<"\t"<<postDate<<"\n"<<" ---"<<postContent;
        }
        else if(activity==2)
        {
            GetNameFromFile(sharedUser);
            cout<<" is thinking about "<<feeling<<"\t"<<postDate<<"\n"<<" ---"<<postContent;
        }
        else if(activity==3)
        {
            GetNameFromFile(sharedUser);
            cout<<" is making "<<feeling<<"\t"<<postDate<<"\n"<<" ---"<<postContent;
        }
        else if(activity==4)
        {
            GetNameFromFile(sharedUser);
            cout<<" is celebrating "<<feeling<<"\t"<<postDate<<"\n"<<" ---"<<postContent;
        }
    }
    else 
    {
        GetNameFromFile(sharedUser);
        cout<<" shared a post "<<"\t"<<postDate<<"\n"<<" ---"<<postContent;
    }
    for (int i=0;i<postCommentsCount;i++)
    {
        cout<<"\n\t\t\t";
        postComments[i]->displayComment();
    }   
} 

#endif