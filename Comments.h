#ifndef Comments
#define Comments

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Comment
{
    public:
    string postID;
    string commentedBy;
    string commentContent;

    Comment();
    void inputComment(string,ifstream&);
};
Comment::Comment()
{
    postID,commentedBy,commentContent='\0';
}
void Comment::inputComment(string postId,ifstream& Data)
{
    while(1)
    {
        string File;
        Data>>File;

        if(File==postId)
        {
            File=postID;
            Data>>commentedBy;

            string line;
            getline(Data,line);
            getline(Data,commentContent);

            break;
        }
    }
}

#endif