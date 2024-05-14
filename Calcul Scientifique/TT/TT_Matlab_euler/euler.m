function euler()
clear all
f=inline('-150*yy+30','yy');

y0=1/5;


h=[0.02,0.01,0.001];

for j=1:3
    for t=0:h(j):1
        
        y=EEx(y0,h(j),t,f);
    end
    hold on
    plot(y)
end
legend('h=0.02','h=0.01','h=0.001')
end