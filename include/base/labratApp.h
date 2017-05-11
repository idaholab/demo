#ifndef LABRATAPP_H
#define LABRATAPP_H

#include "MooseApp.h"

class labratApp;

template <>
InputParameters validParams<labratApp>();

class labratApp : public MooseApp
{
public:
  labratApp(InputParameters parameters);
  virtual ~labratApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* LABRATAPP_H */
