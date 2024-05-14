function euler_pertube()
clear all
f=inline('-150*yy+30','yy');
eps=10e-10;
y0=1/5+eps;
%h=[0.02,0.01,0.001];
h=[0.013,0.014];

for j=1:2
%for j=1:3
    for t=0:h(j):1
        y=EEx(y0,h(j),t,f);
    end
    hold on
    plot(y)
end

%legend('h=0.02','h=0.01','h=0.001')
legend('h=0.013','h=0.014')
end