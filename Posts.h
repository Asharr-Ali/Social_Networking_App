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
    int postsCount(string);
    void inputPost(string,ifstream&);
};
Post::Post()
{
    postID,postDate,postContent,feeling,sharedUser='\0';
    num,activity,postCommentsCount=0;
    postComments=nullptr;
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
void Post::inputPost(string ID,ifstream& postData)
{
    while(1)
    {
        string File;
        postData>>File;

        if(ID==File)
        {
            sharedUser=File;
            postData>>num;
            postData>>postID;
            postData>>postDate;
            postData>>activity;
            postData>>postCommentsCount;

            string line;
            getline(postData,line);
            getline(postData,postContent);

            if(num!=1)
                getline(postData,feeling);

            ifstream commentsData("Comments.txt");
            if(!commentsData)
                cout<<"\nComment File Failed to Open!";

            postComments=new Comment* [postCommentsCount]; 
            for (int i=0;i<postCommentsCount;i++)
                postComments[i]=new Comment;

            for (int j=0;j<postCommentsCount;j++)
                postComments[j]->inputComment(postID,commentsData);

            commentsData.close();

            break;
        }
    }
}

#endif