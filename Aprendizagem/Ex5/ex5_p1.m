clear all

load ex6data1.mat

%tarefa 1: treinar e plotar

plotData(X,y);

y(37) = 1;

model = svmTrain(X, y, 1, @linearKernel,1e-3,5);

visualizeBoundaryLinear(X, y, model);

%hold off