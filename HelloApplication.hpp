#pragma once
#include "TextEditWidget.hpp"
#include "UserFormWidget.hpp"
#include "UserInfoDisplayWidget.hpp"
#include "UserInfoTemplateDisplayWidget.hpp"
#include <Wt/WApplication.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WTemplate.h>
#include <Wt/WText.h>

class HelloApplication : public Wt::WApplication
{
public:
    HelloApplication(const Wt::WEnvironment& env);

private:
    Wt::WLineEdit *nameEdit_;
    Wt::WText *greeting_;
    UserFormWidget *userForm_;
    UserInfoDisplayWidget *userInfo_;
    UserInfoTemplateDisplayWidget *userInfoTemplate_;
};


