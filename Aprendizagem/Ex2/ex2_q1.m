
color = ex2data1(:,3);
for i = 1:numel(color)
  color(i) = color(i)*10;
endfor

#color = linspace(1,10,numel(ex2data1(:,1)));

scatter(ex2data1(:,1),ex2data1(:,2),15,color,'d','filled');