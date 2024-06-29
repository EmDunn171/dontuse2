//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "goiabaTestApp.h"
#include "goiabaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
goiabaTestApp::validParams()
{
  InputParameters params = goiabaApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

goiabaTestApp::goiabaTestApp(InputParameters parameters) : MooseApp(parameters)
{
  goiabaTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

goiabaTestApp::~goiabaTestApp() {}

void
goiabaTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  goiabaApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"goiabaTestApp"});
    Registry::registerActionsTo(af, {"goiabaTestApp"});
  }
}

void
goiabaTestApp::registerApps()
{
  registerApp(goiabaApp);
  registerApp(goiabaTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
goiabaTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  goiabaTestApp::registerAll(f, af, s);
}
extern "C" void
goiabaTestApp__registerApps()
{
  goiabaTestApp::registerApps();
}
