#include "HelloApplication.hpp"


HelloApplication::HelloApplication(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
    messageResourceBundle().use("messages"); 
    setTitle("Demo app 01");
    useStyleSheet("styles.css");

    require("test-web-component.js");
    require("color-selector.js");


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

    auto webComponent = root()->addNew<WebComponentWidget>( 
        "test-web-component", 
        (std::map<std::string, std::string>){
          {"theme","green"},
          {"title","I love Elechka"},
          {"subtitle","Very much"}
        }
    );

    Wt::WPushButton *setTitleButton = root()->addNew<Wt::WPushButton>("set new title");
    setTitleButton->clicked().connect([this, webComponent](){
      webComponent -> setAttribute("title","I love my favorite Elechka");
    });
    
    std::vector<std::string> colors = {"green","red"};
    for(std::string color: colors){
      Wt::WPushButton *button = root()->addNew<Wt::WPushButton>(color);
      button->clicked().connect([this, webComponent, color](){
        webComponent -> setAttribute("theme",color);
      });
    }

    webComponent->events().connect([](std::string data){
      std::cout<<"data in app from component event in new events callback"<<data<<std::endl;
    });


    auto colorSelector = root()->addNew<WebComponentWidget>( 
        "color-selector", 
        (std::map<std::string, std::string>){}
    );

    colorSelector->events().connect([webComponent](std::string data){
        std::cout<<"color selector emitted event"<<data<<std::endl;
        Wt::Json::Object eventPayload;
        Wt::Json::parse(data, eventPayload);
        Wt::WString command = eventPayload.get("command");
        if(command==Wt::WString("set-color")){
          Wt::WString color = eventPayload.get("data");
          std::cout<<"new color"<< color<<std::endl;
          webComponent->setAttribute("theme", color.toUTF8());
        }
    });
}
