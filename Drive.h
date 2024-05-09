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
    cout<<"\t\t\tWelcome to Social Networking App!\n";
    int choice;
    
    cout<<"\nPress 1 to Sign In!\nPress 2 to Sign Up!\n";
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
                    <<"\nPress 8 to view People who liked Post!\t";

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
            }
        }
        else 
            cout<<"\nAccount does not Exist!\nYou need to First Sign Up!\n";

        delete[]currentUser;
    }
}

#endif