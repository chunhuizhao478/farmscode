#include "farmscodeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
farmscodeApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

farmscodeApp::farmscodeApp(InputParameters parameters) : MooseApp(parameters)
{
  farmscodeApp::registerAll(_factory, _action_factory, _syntax);
}

farmscodeApp::~farmscodeApp() {}

void 
farmscodeApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<farmscodeApp>(f, af, s);
  Registry::registerObjectsTo(f, {"farmscodeApp"});
  Registry::registerActionsTo(af, {"farmscodeApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
farmscodeApp::registerApps()
{
  registerApp(farmscodeApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
farmscodeApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  farmscodeApp::registerAll(f, af, s);
}
extern "C" void
farmscodeApp__registerApps()
{
  farmscodeApp::registerApps();
}
