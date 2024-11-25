#include "UserInfoTemplateDisplayWidget.hpp"

UserInfoTemplateDisplayWidget::UserInfoTemplateDisplayWidget(){
  setContentAlignment(Wt::AlignmentFlag::Center);
  setStyleClass("user-info-html-display");
  addNew<Wt::WText>("Пример, использующий HTML шаблон");

  userInfoTemplate_ = addNew<Wt::WTemplate>(Wt::WString::tr("testTemplate"));
  firstName_ = userInfoTemplate_ -> bindWidget("first-name", std::make_unique<Wt::WText>("здесь будет имя"));
  firstName_-> addStyleClass("disabled");
  lastName_ = userInfoTemplate_ -> bindWidget("last-name", std::make_unique<Wt::WText>("здесь будет фамилия"));
  lastName_-> addStyleClass("disabled");

}

void UserInfoTemplateDisplayWidget::showInfo(UserInfo userInfo){
  lastName_-> removeStyleClass("disabled");
  lastName_ -> setText(userInfo.lastName);
  firstName_-> removeStyleClass("disabled");
  firstName_ -> setText(userInfo.firstName);
}
