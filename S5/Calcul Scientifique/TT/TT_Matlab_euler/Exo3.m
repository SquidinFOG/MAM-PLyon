%initialisation du probleme
f= @(h,z,n)[ ( -0.01*h*z ) ; ( 0.01*h*z + 0.02*n - 0.005*h*z) ; (0.005*h*z - 0.02*n ) ];
h=0.3;
h0=500;
z0=10;
n0=0;

%discretisation et application du shéma d'euler explicite
for t=0:h:500
        y=EEx3D([h0,z0,n0],h,t,f);
        t
end

%tracé des courbes
hold on
plot(y(1,:))
plot(y(2,:))
plot(y(3,:))
legend('population d humains','population de zombies','population de zombies neutralisés')


%fonction du shema d'euler explicite en 3D.
function y=EEx3D(y0,h,T,f)
N=floor(T/h);
y(:,1) = y0(:);

for i=1:N
y(:,i+1) = y(:,i) + h*f(y(1,i),y(2,i),y(3,i));
end
end
