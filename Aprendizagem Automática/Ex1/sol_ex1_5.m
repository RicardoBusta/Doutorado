data = load("./ex1data3.txt");

x = [ones(numel(data(:,1)),1),data(:,1),data(:,2),data(:,3),data(:,4),data(:,5)];
y = data(:,6);
w = [0,0,0,0,0]

w = inv(x'*x)*x'*y