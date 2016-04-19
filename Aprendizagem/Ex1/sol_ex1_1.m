#questão 1: plotar
data = csvread("./ex1data1.txt");

x = data(:,1);
y = data(:,2);

scatter(x,y)