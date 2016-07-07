clear all
load ex5data1.data

data = ex5data1(:,1:4);
orig_classes = ex5data1(:,5);

function [centers,classes] = step(data,classes,centers,k)
  % Calcular a menor distancia 
  for i = 1:150
    mindist = 999999;
    minindex = -1;
    for c = 1:k
      % Cálculo da distancia
      dif = centers(c,:) - data(i,:);
      dist = dif*dif';
      if dist < mindist
        mindist = dist;
        minindex = c;
      endif % dist
    endfor % c
    classes(i,1) = minindex;
  endfor % i  
 
  for c = 1:k
    pos = find(classes==c);
    centers(c,:) = mean(data(pos,:));
  endfor
 
endfunction

function plotMyData(data,classes,x1,x2)
  hold on
  pos = find(classes==1);
  plot(data(pos,x1),data(pos,x2),'r.','markersize',10);
  pos = find(classes==2);
  plot(data(pos,x1),data(pos,x2),'g.','markersize',10);
  pos = find(classes==3);
  plot(data(pos,x1),data(pos,x2),'m.','markersize',10);
  pos = find(classes==4);
  plot(data(pos,x1),data(pos,x2),'c.','markersize',10);
  pos = find(classes==5);
  plot(data(pos,x1),data(pos,x2),'b.','markersize',10);
endfunction

function plotCenters(centers,col,x1,x2)
  plot(centers(:,x1),centers(:,x2),'o','markersize',15,'LineWidth',2,'MarkerEdgeColor',col);
endfunction

function plot4D(data,classes,centers)
  hold on
  subplot(2,2,1)
  plotMyData(data,classes,1,2);
  plotCenters(centers,'k',1,2);
  subplot(2,2,2)
  plotMyData(data,classes,3,2);
  plotCenters(centers,'k',3,2);
  subplot(2,2,3)
  plotMyData(data,classes,3,4);
  plotCenters(centers,'k',3,4);
  subplot(2,2,4)
  plotMyData(data,classes,1,4);
  plotCenters(centers,'k',1,4);
endfunction 

res = zeros(4,1);

for k = 2:5
%k = 3;
% Sortear k centroides iniciais
  index = randperm(150);
  centers = data(index(1:k),:);
  old_centers = centers;
% Vetor que dira a classe que cada cara pertence
  classes = zeros(150,1);


  [centers,classes] = step(data, classes, centers, k);
  
  condition = true;
  
  while condition
    condition = false;
    diff = centers - old_centers;
    for i = 1:k
      d = diff(i,:);
      dist = d*d';
      if dist > 0.01
        condition = true;
      endif
    endfor
    old_centers = centers;
    [centers,classes] = step(data, classes, centers, k);
  endwhile
  
  eqm = 0;
  
  for i = 1:150
    diff = data(i,:)-centers(classes(i),:);
    dist = diff*diff';
    eqm += dist*dist;
  endfor
  
  eqm /= 150;
  
  res(k-1) = eqm;
  
  %plot4D(data,classes,centers);
  %[centers,classes] = step(data, classes, centers, k);
  %[centers,classes] = step(data, classes, centers, k);
  %[centers,classes] = step(data, classes, centers, k);
endfor % k

plot([2 3 4 5],res,'LineWidth',2);
