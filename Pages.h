#ifndef Pages
#define Pages

class Page
{
    public:
    string pageID;
    string pageName;
    string CreatedBy;
    string** pageFollowers;
    int pageFollowersCount;
    Posts** pagePosts;
    int pagePostsCount;

    Page();
    ~Page();
};
Page::Page()
{
    pageID,pageName,CreatedBy='\0';
    pageFollowers,pagePosts=nullptr;
    pageFollowersCount,pagePostsCount=0;
}

#endif