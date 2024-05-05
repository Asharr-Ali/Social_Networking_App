#ifndef Posts
#define Posts

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Comment;

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
    void inputPost(string);
};
Post::Post()
{
    postID,postDate,postContent,feeling,sharedUser='\0';
    num,activity,postCommentsCount=0;
    postComments=nullptr;
}
void Post::inputPost(string ID)
{
    while(1)
    {
        ifstream postData("Posts.txt");
        if(!postData)
        cout<<"\nPosts File Failed to Open!\n";

        string File;
        postData>>File;
        if(ID==File)
        {
            sharedUser=File;
            postData>>num;
            postData>>postID;
            postData>>postDate;

            string line;
            while(getline(postData,line)&&line!="-2")
            postContent+=line;

            postData>>activity;
            postData>>feeling;

            postData>>postCommentsCount;
        }
    }
}

#endif