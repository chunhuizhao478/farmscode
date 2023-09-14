#pragma once

#include "CZMComputeLocalTractionTotalBase.h"

class SlipWeakeningTurkeyBranch : public CZMComputeLocalTractionTotalBase
{
public:
  static InputParameters validParams();
  SlipWeakeningTurkeyBranch(const InputParameters & parameters);

protected:
  /// method computing the total traction and its derivatives
  void computeInterfaceTractionAndDerivatives() override;

  const VariableValue & _Dc;

  Real _area;

  const VariableValue & _nodal_area;

  const MaterialProperty<Real> & _density;

  const MaterialProperty<RankTwoTensor> & _rot;

  const VariableValue & _disp_slipweakening_x;
  const VariableValue & _disp_slipweakening_neighbor_x;
  const VariableValue & _disp_slipweakening_y;
  const VariableValue & _disp_slipweakening_neighbor_y;

  const VariableValue & _reaction_slipweakening_x;
  const VariableValue & _reaction_slipweakening_neighbor_x;
  const VariableValue & _reaction_slipweakening_y;
  const VariableValue & _reaction_slipweakening_neighbor_y;

  const VariableValue & _disp_slipweakening_x_old;
  const VariableValue & _disp_slipweakening_neighbor_x_old;
  const VariableValue & _disp_slipweakening_y_old;
  const VariableValue & _disp_slipweakening_neighbor_y_old;

  const VariableValue & _mu_s;
  const VariableValue & _mu_d;

  const VariableValue & _tria_area;
  const VariableValue & _tria_area_neighbor;
 
  const VariableValue & _ini_shear_sts;
  const VariableValue & _ini_normal_sts;

};