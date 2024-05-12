#ifndef Users
#define Users

#include<string>
#include<fstream>

#include "Pages.h"
#include "Posts.h"
#include "Friends.h"

using namespace std;

class Post;
class Page;
class Friend;

class User
{
    private:
    string ID;
    string firstName;
    string lastName;
    string* friendsID;
    Friend** friendsList;
    int friendsCount;
    string* likedPagesID;
    Page** pagesLiked;
    Page* viewPage=new Page;
    int pagesLikedCount;
    Post** userPosts;
    string* postsID;
    int postsCount;

    public:
    User();

    bool CheckAccountExistence(string);
    void GetNameFromFile(string);
    void ReadDataFromFile(string);
    void viewHomePage();
    void viewTimeLine();
    void viewFriendList();
    void viewLikedPages();
    void viewAnyPage();
    void viewAnyPost();
    void AddCommentOnPost();
    void displayLikedPeople();
    void shareMemory();
    void viewMemories();
    void LikePost();

    ~User();
};
User::User()
{
    ID,firstName,lastName='\0';
    friendsID,friendsList,likedPagesID,pagesLiked,userPosts,postsID=nullptr;
    friendsCount,pagesLikedCount=0;
}
bool User::CheckAccountExistence(string in)
{
    ifstream readData("Users.txt");

    if(!readData)
    cout<<"\nFile Failed to Open!";

    string file;
    while(getline(readData,file))
    {
        readData>>file;
        if(file==in)
            return true;
    }
    readData.close();
    return false;
}
void User::GetNameFromFile(string id)
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
void User::ReadDataFromFile(string id)
{
    ifstream userData("Users.txt");
    ifstream friendsData("Friends.txt");

    if(!userData)
        cout<<"\n Users File Failed to Open!\n";
    if(!friendsData)
        cout<<"\n Friends File Failed to Open!\n";

    string File;
    string line;
    int lineNumber=0,lineNumber1=0;

    while(getline(userData,line))
    {
        userData>>File;
        lineNumber++;

        if(id==File)
        {
            ID=File;
            userData>>firstName;
            userData>>lastName;
            userData>>pagesLikedCount;

            likedPagesID=new string[pagesLikedCount];
            for (int i=0;i<pagesLikedCount;i++)
            {
                string Data;
                userData>>Data;
                likedPagesID[i]=Data;
            }
            
            pagesLiked=new Page* [pagesLikedCount];
            for (int i=0;i<pagesLikedCount;i++)
                pagesLiked[i]=new Page;
           
            for (int i=0;i<pagesLikedCount;i++)
                pagesLiked[i]->inputPage(likedPagesID[i]);

            Post currentUser;
            postsCount=currentUser.postsCount(id);
            userPosts=new Post*[postsCount];

            for (int j=0;j<postsCount;j++)
                userPosts[j]=new Post;  

            ifstream postsData("Posts.txt");
            if(!postsData)
                cout<<"\nPosts File Failed to Open!\n";

            for (int i=0;i<postsCount;i++)
                userPosts[i]->inputPostByUserID(id,postsData);

            postsData.close();

            while(getline(friendsData,line)&&lineNumber1<lineNumber)
                lineNumber1++;

            if(lineNumber1==lineNumber) 
            {
                friendsData>>friendsCount;
                friendsID=new string [friendsCount];

                for (int i=0;i<friendsCount;i++)
                {
                    string Data;
                    friendsData>>Data;
                    friendsID[i]=Data;
                }
            }
            friendsList=new Friend* [friendsCount];
            for (int i=0;i<friendsCount;i++)
                friendsList[i]=new Friend;

            for (int j=0;j<friendsCount;j++)
                friendsList[j]->ReadFriendData(friendsID[j]);

            break;
        }
    }
    userData.close();
    friendsData.close();
}
void User::viewHomePage()
{
    cout<<"\n\n\n-------------------------------Homepage---------------------------------------------\n\n\n";
    for (int j=0;j<pagesLikedCount;j++)
        pagesLiked[j]->displayPagePosts();   

    for (int i=0;i<postsCount;i++)
    {
        userPosts[i]->displayPost();
        cout<<"\n\n";
    }

    for(int k=0;k<friendsCount;k++)
        friendsList[k]->userPostsDisplay();

    cout<<"-----------------------------------------------------------------------------------\n\n\n";
}
void User::viewTimeLine()
{
    cout<<"\n\n\n-------------------------------Timeline---------------------------------------------\n\n\n";   
    for (int i=0;i<postsCount;i++)
    {
        userPosts[i]->displayPost();
        cout<<"\n\n";
    }
    cout<<"-----------------------------------------------------------------------------------\n\n\n";
}
void User::viewFriendList()
{
    cout<<"\n\n\n-------------------------------Friends List-------------------------------------\n";
    if(friendsCount!=0)
    {
        for (int i=0;i<friendsCount;i++)
        {
            cout<<"\n"<<friendsID[i]<<" - ";
            GetNameFromFile(friendsID[i]);
        }
    }
    else 
        cout<<"\nUser has no Friends!\n";

    cout<<"\n\n--------------------------------------------------------------------------\n";
}
void User::viewLikedPages()
{
    cout<<"\n\n\n-------------------------------Liked Pages List-------------------------------------\n";
    if(pagesLikedCount!=0)
    {
        for (int i=0;i<pagesLikedCount;i++)
        {
            cout<<"\n"<<likedPagesID[i]<<" - ";
            GetNameFromFile(likedPagesID[i]);
        }
    }
    else 
        cout<<"\nUser has no Liked Pages!\n";

    cout<<"\n\n--------------------------------------------------------------------------\n";
}
void User::viewAnyPage()
{
    string input;
    cout<<"\nEnter any Page ID:\t";
    cin.ignore();
    getline(cin,input);

    viewPage=new Page;

    viewPage->inputPage(input);
    viewPage->displayAnyPage(input);
}
void User::viewAnyPost()
{
    string input;
    cout<<"\nEnter any Post ID:\t";
    cin>>input;

    Post viewPost;

    ifstream postsData("Posts.txt");
    if(!postsData)
        cout<<"\nPosts File Failed to Open!\n"; 

    viewPost.inputPostByPostID(input,postsData);

    cout<<"\n\n\n----------------------Required Post-----------------------------\n\n";
    viewPost.displayPost();
    cout<<"\n\n-----------------------------------------------------------------";

    postsData.close();
}
void User::AddCommentOnPost()
{
    string input;
    cout<<"\n\nEnter Post ID in post-x form on which you want to Comment:\t";
    cin>>input;

    Comment Add;

    int PostCommentCount=Add.GetPostCommentsCount(input);
    cout<<"Count:"<<PostCommentCount;
    if(PostCommentCount<=10)
       Add.AddComment(input,ID);
    else 
       cout<<"\nMaximum Comments Limit Reached!";
}
void User::displayLikedPeople()
{
    string input;
    cout<<"\nEnter post ID you want to view People who Liked it:\t";
    cin.ignore();
    getline(cin,input);

    cout<<"\n\n\n--------------------------------Liked People-----------------------\n\n";
    Like currentUser;
    currentUser.inputLike(input);
    currentUser.displayLikedPeople();
    cout<<"\n\n\n---------------------------------------------------------------------";
}
void User::shareMemory()
{
    string input,text;
    cout<<"\nEnter post ID you want to Share as a Memory:\t";
    cin>>input;

    cin.ignore();
    cout<<"\nEnter Text you want to Share:\t";
    getline(cin,text);

    ofstream MemoriesData("Memories.txt",ios::app);

    if(!MemoriesData)
       cout<<"\nMemories File Failed to open!";

    MemoriesData<<"\n\n"<<ID<<" "<<input<<" "<<"1-Year-Ago"<<"\n"<<text;

    MemoriesData.close();

    cout<<"\n\nSuccessfully Shared as Memory!\n";
}
void User::viewMemories()
{
    cout<<"\n\n\n-----------------------Current User Memories---------------------\n\n";
    ifstream MemoriesData("Memories.txt");

    if(!MemoriesData)
       cout<<"\nMemories File Failed to open!";

    string File,PostID;
    while(MemoriesData>>File)
    {
        if(File==ID)
        {
            MemoriesData>>PostID;
            MemoriesData>>File;
            cout<<"\n"<<File;
            getline(MemoriesData,File);
            getline(MemoriesData,File);

            cout<<"\n\t---"<<File<<"\n\n";

            break;
        }
    }
    MemoriesData.close();

    Post viewPost;

    ifstream postsData("Posts.txt");
    if(!postsData)
        cout<<"\nPosts File Failed to Open!\n"; 

    viewPost.inputPostByPostID(PostID,postsData);
    viewPost.displayPost();

    postsData.close();  
}
void User::LikePost()
{
    string input;
    cout<<"\nEnter Post ID you want to Like:\t";
    cin>>input;

    ifstream inputFile("Likes.txt");
    if (!inputFile)
       cout<<"\nLikes File Failed to open!";

    ofstream tempFile("temp.txt");
    if (!tempFile) 
        cout<< "\nFailed to create temporary file!";

    string word;
    while (inputFile >> word) 
    {
        if(word==input)
        {
            tempFile<<word<<" ";

            int totalLikes;
            inputFile>>totalLikes;

            if(totalLikes<=10)
            {
                totalLikes++;
                tempFile<<totalLikes<<" ";

                string File;
                while(inputFile>>File)
                {
                    if(File=="-1")
                    {
                        tempFile<<ID<<" "<<"-1"<<"\n";
                        break;
                    }
                    tempFile<<File<<" ";
                }
            }
            else 
              cout<<"\n\nMaximum Likes Limit Reached!";
        }
        else
        {
            if(word!="-1")
               tempFile << word << " ";
            else 
               tempFile<<"-1"<<"\n";
        } 
    }

    inputFile.close();
    tempFile.close();

    remove("Likes.txt");
    rename("temp.txt", "Likes.txt");

    cout << "\n\tLike Added Successfully!";
}
User::~User()
{
    delete[]friendsID;
    delete[]likedPagesID;
    delete[]postsID;
    delete[]viewPage;

    for(int i=0;i<friendsCount;i++)
        delete[] friendsList[i];

    delete[]friendsList;

    for(int j=0;j<pagesLikedCount;j++)
       delete[] pagesLiked[j];

    delete[]pagesLiked;

    for(int k=0;k<postsCount;k++)
       delete[] userPosts[k];

    delete[]userPosts;
}

#endif