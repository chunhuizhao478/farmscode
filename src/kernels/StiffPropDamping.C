#include "StiffPropDamping.h"
#include "ElasticityTensorTools.h"

registerMooseObject("farmscodeApp", StiffPropDamping);

InputParameters
StiffPropDamping::validParams()
{
  InputParameters params = StressDivergenceTensors::validParams();
  params.addClassDescription(
      "Compute Stiffness Proportional Damping Residual");

  params.addParam<Real>("q", 0.1, "Ratio Factor to assign magnitude of stiffness proportional damping term");
  params.addParam<Real>("inc", 0.0, "increment formulation");

  return params;
}

StiffPropDamping::StiffPropDamping(const InputParameters & parameters)
  : StressDivergenceTensors(parameters),
  
  //Get stress tensor from previous time step (older == previous time step in Explicit Time Integration Scheme)
  _stress_older(getMaterialPropertyOlderByName<RankTwoTensor>(_base_name + "stress")),

  //Get stress tensor from current time step
  _stress_old(getMaterialPropertyOldByName<RankTwoTensor>(_base_name + "stress")),
  
  //Get stress tensor from current time step
  _stress(getMaterialPropertyByName<RankTwoTensor>(_base_name + "stress")),
  
  //Ratio factor 
  _q(getParam<Real>("q")),

  _inc(getParam<Real>("inc"))

{
}

Real
StiffPropDamping::computeQpResidual()
{

  Real residual = 0.0;

  //residual += _q*(_stress[_qp].row(_component)-_stress_older[_qp].row(_component)) * _grad_test[_i][_qp];

  //Step-over
  if ( _inc == 0 ){
    residual += _q*(_stress[_qp].row(_component)-_stress_older[_qp].row(_component)) * _grad_test[_i][_qp];
  }
  else{
    residual += _q*(_stress_old[_qp].row(_component)-_stress_older[_qp].row(_component)) * _grad_test[_i][_qp];
  }

  return residual;
}



