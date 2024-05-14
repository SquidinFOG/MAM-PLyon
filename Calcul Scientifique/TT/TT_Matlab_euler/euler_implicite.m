function euler_implicite()
clear all

eps=10e-10;
y0=1/5+eps;
h=[0.02,0.01,0.001];

for j=1:3
    for t=0:h(j):1
        y=EIm(y0,h(j),t,-150,30);
    end
    hold on
    plot(y)
end
legend('h=0.02','h=0.01','h=0.001')
end