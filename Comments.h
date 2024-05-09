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

    void GetNameFromFile(string);
    void inputComment(string,ifstream&);
    void displayComment();
    void AddComment(string,string);

    ~Comment();
};
Comment::Comment()
{
    postID,commentedBy,commentContent='\0';
}
void Comment::GetNameFromFile(string id)
{
    ifstream searchData("Display.txt");

    if(!searchData)
    cout<<"\nDisplay  File Failed to Open!";

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
void Comment::displayComment()
{
    GetNameFromFile(commentedBy);
    cout<<" wrote: "<<commentContent;
}
void Comment::AddComment(string postId,string userId)
{
    ofstream Data("Comments.txt",ios::app);
    cout<<"\nPOst ID:"<<postId;
    if(!Data)
      cout<<"\nComment File Failed to Open!";

    Data<<"\n\n"<<postId<<"  "<<userId<<"\n";

    cin.ignore();
    cout<<"\nEnter Comment plz:\t";
    string comment;
    getline(cin,comment);

    Data<<comment;

    cout<<"\nComment SuccessFully Added!\n";

    Data.close();
}
Comment::~Comment()
{ }

#endif