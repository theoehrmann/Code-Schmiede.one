clear

data = xlsread("dragForce.xlsx");  % Read the data set from solidworks flow parametric study

var = data(1:end, :)';  % All variable data

% Objective function for 3rd degree polynomial:
objFun = @(X)(7.2437*X(1)^3 - 2.9382*X(1)^2*X(2) + 5.0056*X(1)^2*X(3) + 0.22582*X(1)^2*X(4) - 12.7035*X(1)^2 + 1.137*X(1)*X(2)^2 + 0.59577*X(1)*X(2)*X(3) - 2.4402*X(1)*X(2)*X(4) + 3.1492*X(1)*X(2) + 1.2925*X(1)*X(3)^2 + 1.7242*X(1)*X(3)*X(4) - 7.9573*X(1)*X(3) + 3.2366*X(1)*X(4)^2 - 3.0567*X(1)*X(4) + 5.5251*X(1) + 1.0648*X(2)^3 - 0.25228*X(2)^2*X(3) - 1.2136*X(2)^2*X(4) - 0.59942*X(2)^2 + 0.38827*X(2)*X(3)^2 + 2.1843*X(2)*X(3)*X(4) - 1.0236*X(2)*X(3) - 2.6107*X(2)*X(4)^2 + 3.8929*X(2)*X(4) - 2.2586*X(2) - 0.24884*X(3)^3 + 0.10684*X(3)^2*X(4) - 2.4825*X(3)^2 + 4.2108*X(3)*X(4)^2 - 5.4927*X(3)*X(4) + 2.8746*X(3) - 2.0372*X(4)^3 + 1.2778*X(4)^2 - 0.16949*X(4) + 47.9438);

%x0 = [0.5 0.5 0.5 0.5];  % Initial point for design variables
%x0 = [0 0 0 0];
x0 = [1 1 1 1];

A = [ -1 0 0 0;  % Linear constraints
    1 0 0 0;
    0 -1 0 0;
    0 1 0 0;
    0 0 -1 0;
    0 0 1 0;
    0 0 0 -1;
    0 0 0 1];

b = [0, 1, 0, 1, 0, 1, 0, 1];  % Inequality constraints

nonlcon = [];  % Non-linear constraints

Aeq = [];  % Linear equality constraints
beq = [];

lb = [ 0 0 0 0];  % Lower and upper bound of normalised data
ub = [ 1 1 1 1];

nvar = 4;  % No. variables 

% Optimisation options
options = optimoptions( 'fmincon', 'Display', 'iter', 'Algorithm', 'sqp');  % Gradient
%options = optimoptions( 'ga', 'ConstraintTolerance', 1e-8, 'PlotFcn', @gaplotbestf);  %GA

% Optimised gradient based
tic
[x, fval] = fmincon(objFun,x0,A,b,Aeq,beq,lb,ub,nonlcon, options);
fminTime = toc;

% Optimised genetic algorithm
tic
%[x, fval] = ga(objFun,nvar,A,b,Aeq,beq,lb,ub,nonlcon,options);
gaTime = toc;
