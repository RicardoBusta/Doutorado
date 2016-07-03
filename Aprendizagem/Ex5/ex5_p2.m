%clear all

load ex6data2.mat

%plotData(X,y);

C=1;
e = 1e-3;
step = 5;
sigma = 0.2;
model = svmTrain(X,y,C,@gaussianKernel,sigma,e,step);

visualizeBoundary(X,y,model,sigma);