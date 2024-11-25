#include "UserInfoDisplayWidget.hpp"

UserInfoDisplayWidget::UserInfoDisplayWidget(){
  setContentAlignment(Wt::AlignmentFlag::Center);
  setStyleClass("user-info-display");

  addNew<Wt::WText>("Пример, использующий простые виджеты");

  auto firstNameContainer_ = addNew<Wt::WContainerWidget>();
  firstNameContainer_ -> addNew<Wt::WText>("Имя:");
  firstName_ = firstNameContainer_ -> addNew<Wt::WText>("");
    
  auto lastNameContainer_ = addNew<Wt::WContainerWidget>();
  lastNameContainer_ -> addNew<Wt::WText>("Фамилия:");
  lastName_ = lastNameContainer_ -> addNew<Wt::WText>("");

}

void UserInfoDisplayWidget::showInfo(UserInfo userInfo){
  lastName_ -> setText(userInfo.lastName);
  firstName_ -> setText(userInfo.firstName);
}
