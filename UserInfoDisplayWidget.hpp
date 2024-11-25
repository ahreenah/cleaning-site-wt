#pragma once
#include <Wt/WContainerWidget.h>
#include "UserFormWidget.hpp"
#include <Wt/WText.h>
#include <string>


class UserInfoDisplayWidget: public Wt::WContainerWidget{
  public:
    UserInfoDisplayWidget();
    void showInfo(UserInfo userInfo);
  private:
    Wt::WText *firstName_;
    Wt::WText *lastName_;
};
