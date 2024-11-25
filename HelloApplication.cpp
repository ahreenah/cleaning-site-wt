#include "HelloApplication.hpp"

HelloApplication::HelloApplication(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
    messageResourceBundle().use("messages"); 
    setTitle("Demo app 01");
    useStyleSheet("styles.css");


    root()->addNew<TextEditWidget>("text");

    // testing localized text from resources
    Wt::WString messageFromResources = Wt::WString::tr("start");
    root()->addNew<Wt::WText>(messageFromResources.toUTF8());

    auto userInfoContainer_ = root()->addNew<Wt::WContainerWidget>();
    userInfoContainer_ -> setStyleClass("user-info-container");

    // form to get user info
    userForm_ = userInfoContainer_->addNew<UserFormWidget>();
    auto onUserChange = [this](UserInfo userInfo){
        userInfo_->showInfo(userInfo);
        userInfoTemplate_->showInfo(userInfo);
    };
    userForm_->valueChanged().connect(onUserChange);

    // first wigdet to show user info
    userInfo_ = userInfoContainer_->addNew<UserInfoDisplayWidget>(); 

    // second wigdet to show user info
    userInfoTemplate_ = userInfoContainer_->addNew<UserInfoTemplateDisplayWidget>(); 
}
