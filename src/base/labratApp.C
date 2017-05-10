#include "labratApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<labratApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

labratApp::labratApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  labratApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  labratApp::associateSyntax(_syntax, _action_factory);
}

labratApp::~labratApp()
{
}

// External entry point for dynamic application loading
extern "C" void labratApp__registerApps() { labratApp::registerApps(); }
void
labratApp::registerApps()
{
  registerApp(labratApp);
}

// External entry point for dynamic object registration
extern "C" void labratApp__registerObjects(Factory & factory) { labratApp::registerObjects(factory); }
void
labratApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void labratApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { labratApp::associateSyntax(syntax, action_factory); }
void
labratApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
