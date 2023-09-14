#include "CompVar.h"

registerMooseObject("farmscodeApp", CompVar);

InputParameters
CompVar::validParams()
{
  InputParameters params = AuxKernel::validParams();

  params.addRequiredCoupledVar("coupled","Nonlinear Variable that needed to be taken time derivative of");

  return params;
}

CompVar::CompVar(const InputParameters & parameters)
  : AuxKernel(parameters),
  
  _coupled_val(coupledValue("coupled"))

{
}

Real
CompVar::computeValue()
{
  return _coupled_val[_qp];
}