#include "msrthApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
msrthApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

msrthApp::msrthApp(InputParameters parameters) : MooseApp(parameters)
{
  msrthApp::registerAll(_factory, _action_factory, _syntax);
}

msrthApp::~msrthApp() {}

void
msrthApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"msrthApp"});
  Registry::registerActionsTo(af, {"msrthApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
msrthApp::registerApps()
{
  registerApp(msrthApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
msrthApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  msrthApp::registerAll(f, af, s);
}
extern "C" void
msrthApp__registerApps()
{
  msrthApp::registerApps();
}
