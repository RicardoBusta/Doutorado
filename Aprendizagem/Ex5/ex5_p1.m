clear all

load ex6data1.mat

c1 = find(y);
c2 = find(y-1);
plot(X(c1,1),X(c1,2),'r.','markersize',15);
hold on
plot(X(c2,1),X(c2,2),'b.','markersize',15);

%tarefa 1: treinar e plotar

model = svmTrain(X, y, 1, @linearKernel);

visualizeBoundaryLinear(X, y, model);