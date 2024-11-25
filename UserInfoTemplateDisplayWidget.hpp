#pragma once
#include <Wt/WContainerWidget.h>
#include <Wt/WTemplate.h>
#include "UserFormWidget.hpp"
#include <Wt/WText.h>
#include <string>


class UserInfoTemplateDisplayWidget: public Wt::WContainerWidget{
  public:
    UserInfoTemplateDisplayWidget();
    void showInfo(UserInfo userInfo);
  private:
    Wt::WTemplate* userInfoTemplate_;
    Wt::WText *firstName_;
    Wt::WText *lastName_;
};
