#include "TextEditWidget.hpp"

void TextEditWidget::_setText() {
  title_->setText("Hello " + nameEdit_->text());
}

TextEditWidget::TextEditWidget(const std::string& initValue){
  setContentAlignment(Wt::AlignmentFlag::Center);
  title_ = addNew<Wt::WText>("You entered "+initValue);
  nameEdit_ = addNew<Wt::WLineEdit>();
  Wt::WPushButton *button = addNew<Wt::WPushButton>("Save name");

  button->clicked().connect([this]{_setText();});
}

