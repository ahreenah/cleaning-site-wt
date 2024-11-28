#pragma once
#include "TextEditWidget.hpp"
#include "UserFormWidget.hpp"
#include "UserInfoDisplayWidget.hpp"
#include "UserInfoTemplateDisplayWidget.hpp"
#include "WebComponentWidget.hpp"
#include <Wt/WApplication.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WTemplate.h>
#include <Wt/WText.h>
#include <Wt/Json/Parser.h>
#include <Wt/Json/Object.h>
#include <format>

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


