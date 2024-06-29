#include "goiabaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
goiabaApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

goiabaApp::goiabaApp(InputParameters parameters) : MooseApp(parameters)
{
  goiabaApp::registerAll(_factory, _action_factory, _syntax);
}

goiabaApp::~goiabaApp() {}

void
goiabaApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<goiabaApp>(f, af, s);
  Registry::registerObjectsTo(f, {"goiabaApp"});
  Registry::registerActionsTo(af, {"goiabaApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
goiabaApp::registerApps()
{
  registerApp(goiabaApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
goiabaApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  goiabaApp::registerAll(f, af, s);
}
extern "C" void
goiabaApp__registerApps()
{
  goiabaApp::registerApps();
}
