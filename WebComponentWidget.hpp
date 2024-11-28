#pragma once
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WJavaScript.h>
#include <string>
#include <format>


class WebComponentWidget: public Wt::WContainerWidget{
  private: 
    int componentNumberId;
    Wt::JSignal<std::string> events_;
  public:
    WebComponentWidget(std::string tagName, std::map<std::string, std::string> initialParams);
    void setAttribute(std::string attributeName, std::string attributeValue);
    Wt::JSignal <std::string>& events(){return events_;};
};
