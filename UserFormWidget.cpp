#include "UserFormWidget.hpp"

void UserFormWidget::_submit() {
  UserInfo newValue;
  newValue.firstName = firstNameEdit_->text();
  newValue.lastName = lastNameEdit_->text();
  valueChanged_.emit(newValue);
}

UserFormWidget::UserFormWidget(){
  setStyleClass("user-info-form");
  setContentAlignment(Wt::AlignmentFlag::Center);

  firstNameEdit_ = addNew<Wt::WLineEdit>();
  firstNameEdit_ -> setPlaceholderText(Wt::WString("Имя"));
  lastNameEdit_ = addNew<Wt::WLineEdit>();
  lastNameEdit_ -> setPlaceholderText(Wt::WString("Фамилия"));
  Wt::WPushButton *button = addNew<Wt::WPushButton>("Сохранить");

  button->clicked().connect([this]{_submit();});
}

// public signal
Wt::Signal<UserInfo>& UserFormWidget::valueChanged() { 
  return valueChanged_;
};
