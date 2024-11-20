#include "HelloApplication.hpp"

HelloApplication::HelloApplication(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
    setTitle("Demo app 01");

    root()->addNew<TextEditWidget>("text");
}
