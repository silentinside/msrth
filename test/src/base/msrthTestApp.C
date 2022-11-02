//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "msrthTestApp.h"
#include "msrthApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
msrthTestApp::validParams()
{
  InputParameters params = msrthApp::validParams();
  return params;
}

msrthTestApp::msrthTestApp(InputParameters parameters) : MooseApp(parameters)
{
  msrthTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

msrthTestApp::~msrthTestApp() {}

void
msrthTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  msrthApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"msrthTestApp"});
    Registry::registerActionsTo(af, {"msrthTestApp"});
  }
}

void
msrthTestApp::registerApps()
{
  registerApp(msrthApp);
  registerApp(msrthTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
msrthTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  msrthTestApp::registerAll(f, af, s);
}
extern "C" void
msrthTestApp__registerApps()
{
  msrthTestApp::registerApps();
}
