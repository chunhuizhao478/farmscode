Code Reporsitory for Paper: "Revealing the Dynamic and Episodic Supershear in the Feb 6th 2023 M7.8 Kahramanmaras/Pazarcik Earthquake: near-field records and dynamic rupture modeling"
=====

"farmscode" is a MOOSE-based application.

For more information see: [http://mooseframework.org/create-an-app/](http://mooseframework.org/create-an-app/)

To install and run the example problem:
(1) Install MOOSE: follow the procedure https://mooseframework.inl.gov/getting_started/installation/index.html (We prefer the mambaforge option for Linux and Mac System)

(2) Follow the above options, make sure MOOSE is sucessfully installed by passing all the tests. Then open terimal, move into "projects" folder:

> cd ~/projects

copy the HTTP for this git reporsitory, do git clone to the local:

> git clone https://github.com/chunhuizhao478/ncommpapercode.git 

compile the code (use 8 mpicores as example)

> make -j 8

run the code

> mpirun -np 8 ./ncommpapercode-opt -i code/ncommpaper/main.i

use paraview (or netCDF4-based application) to open the output exodus file

Contact: chunhui3@illinois.edu
