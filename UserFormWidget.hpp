#pragma once
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <string>

struct UserInfo{
  Wt::WString firstName;
  Wt::WString lastName;
};

class UserFormWidget: public Wt::WContainerWidget{
  public:
    UserFormWidget();
    Wt::Signal<UserInfo>& valueChanged();
  private:
    Wt::WLineEdit *firstNameEdit_;
    Wt::WLineEdit *lastNameEdit_;
    void _submit();

    Wt::Signal<UserInfo> valueChanged_;
};
