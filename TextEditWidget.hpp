#pragma once
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <string>

class TextEditWidget: public Wt::WContainerWidget{
  public:
    TextEditWidget(const std::string& initValue);
    Wt::Signal<Wt::WString>& textChanged();
  private:
    Wt::WText *title_;
    Wt::WLineEdit *nameEdit_;
    void _setText();

    Wt::Signal<Wt::WString> textChanged_;
};
