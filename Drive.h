#ifndef Drive
#define Drive

#include<iostream>
#include<string>

#include "Users.h"

using namespace std;

class SocialNetworkingApp
{
    public:
    SocialNetworkingApp(){}

    static void Run();
};
void SocialNetworkingApp::Run()
{
    cout<<"\n\t\t\tWelcome to Social Networking App!\n";
    int choice;
    
    cout<<"\nPress 1 to Sign In!\n\nChoice:\t";
    cin>>choice;
        
    if (choice==1)
    {
        User* currentUser=new User;
        cout<<"\nEnter Existing Account ID:\t";
        string input;
        cin.ignore();
        getline(cin,input);

        if(currentUser->CheckAccountExistence(input))
        {
            cout<<"\n\n\t\tAccount Existed!\n";
            currentUser->GetNameFromFile(input);
            cout<<" successfully set as Current User!\n";

            currentUser->ReadDataFromFile(input);

            while(1)
            {
                cout<<"\n\n\nPress 1 to view Homepage!"
                    <<"\nPress 2 to view Timeline!"
                    <<"\nPress 3 to view Current User Friends List!"
                    <<"\nPress 4 to view Current User Liked Pages!"
                    <<"\nPress 5 to view Any Page!"
                    <<"\nPress 6 to view Any Post!"
                    <<"\nPress 7 to Add Comment on Post!"
                    <<"\nPress 8 to view People who liked Post!"
                    <<"\nPress 9 to Share Memory!"
                    <<"\nPress 10 to view Memories!"
                    <<"\nPress 11 to Like a Post!"
                    <<"\nPress 0 to Sign Out!\n"
                    <<"\nChoice:\t";

                int choice;
                cin>>choice;

                if(choice==1)
                    currentUser->viewHomePage();
                else if(choice==2)
                    currentUser->viewTimeLine();
                else if(choice==3)
                    currentUser->viewFriendList();
                else if(choice==4)
                    currentUser->viewLikedPages();
                else if(choice==5)
                    currentUser->viewAnyPage();
                else if(choice==6)
                    currentUser->viewAnyPost();
                else if(choice==7)
                    currentUser->AddCommentOnPost();   
                else if(choice==8)
                    currentUser->displayLikedPeople();
                else if(choice==9)
                    currentUser->shareMemory();
                else if(choice==10)
                    currentUser->viewMemories();
                else if(choice==11)
                    currentUser->LikePost();
                else if(choice==0)
                {
                    cout<<"\n\tYou have been Successfully Signed Out!\n\n";
                    break;
                }         
            }
        }
        else 
            cout<<"\nAccount does not Exist!\nYou need to First Sign Up!\n";

        delete[]currentUser;
    }
}

#endif