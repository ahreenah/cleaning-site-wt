#include "WebComponentWidget.hpp"

class IdGenerator{
  static int currentId;
  public:
  static int getId(){
    IdGenerator::currentId ++;
    return IdGenerator::currentId;
  }
};
int IdGenerator::currentId = 0;

WebComponentWidget::WebComponentWidget(std::string tagName, std::map<std::string, std::string> initialParams)
  :events_(this,"events"){
    auto jsElementContainer = addWidget(std::make_unique<Wt::WContainerWidget>());
    jsElementContainer->addWidget(std::make_unique<Wt::WText>(
      std::format("<{}></{}>",tagName,tagName)
    ));

    componentNumberId = IdGenerator::getId();
    std::string componentId = std::format("componentId{}",componentNumberId);
    jsElementContainer->setId(componentId);
    
    std::string paramsCode("");
    for (auto const& keyValue : initialParams){
      paramsCode.append(std::format("webComponentRef{}.setAttribute(\"{}\",\"{}\");", componentNumberId, keyValue.first, keyValue.second));
    }
    paramsCode.append(std::format("webComponentRef{}.setAttribute(\"component-number-id\",\"{}\");", componentNumberId, componentNumberId));
    
    doJavaScript(
      std::format(
        "const webComponentWrapperRef{} = document.getElementById(\"{}\");"
        "const webComponentRef{} = webComponentWrapperRef{}.querySelector(\"{}\");"
        "window.webComponentRef{} = webComponentRef{};"
        "window.callFromComponent{} = (argument)=>/*here goes body*/{}{}{}/*here body ends*/"
        "{}"// setting params
      , componentNumberId,componentId, componentNumberId, componentNumberId,tagName,componentNumberId,componentNumberId,componentNumberId,"{",events_.createCall({"JSON.stringify(argument)"}),"};",paramsCode)
    );
}

void WebComponentWidget::setAttribute(std::string attributeName, std::string attributeValue){
    doJavaScript(
        std::format(
          "webComponentRef{}.setAttribute(\"{}\",\"{}\");",
          componentNumberId, attributeName, attributeValue
        )
    );
}
