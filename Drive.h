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
    cout<<"\t\t\tWelcome to Social Networking App!";
    int choice;
    cout<<"\nPress 1 to Sign In!\nPress 2 to Sign Up!\n";
    cin>>choice;
    
    if (choice==1)
    {
        User currentUser;
        cout<<"\nEnter Existing Account ID\n";
        string input;
        cin.ignore();
        getline(cin,input);

        if(currentUser.CheckAccountExistence(input))
        {
            cout<<"\n\n\t\tAccount Existed!\n";
            currentUser.GetNameFromFile(input);
            cout<<" successfully set as Current User!\n";

            currentUser.ReadDataFromFile(input);

                /*int choice;
                cout<<"\nPress 1 to view Friend List:";
                cin>>choice;

                if(choice==1)
                currentUser.viewFriendList();*/

                //currentUser.viewHomePage();
                //currentUser.viewTimeLine();
                //currentUser.viewLikedPages();
                //currentUser.viewAnyPage();
                //currentUser.viewAnyPost();
                
        }
        else 
        {
            cout<<"\nAccount does not Exist!\nYou need to Sign Up!\n";
        }
    }
}

#endif