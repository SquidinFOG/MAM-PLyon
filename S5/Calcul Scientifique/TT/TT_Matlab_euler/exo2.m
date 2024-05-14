%initialisation du probleme
f= @(l,r)[ (l*(0.05-(0.0005*r))) ; (r*((0.0005*l)-0.2)) ];
h=0.001;
l0=1500;
r0=100;

%discretisation et application du shéma d'euler explicite
for t=0:h:600
        y=EEx2D([l0,r0],h,t,f);
end

%tracé des courbes
hold on
plot(y(1,:))
plot(y(2,:))
legend('population de lapins','population de renards')

%fonction du shema d'euler explicite en 2D.
function y=EEx2D(y0,h,T,f)
N=floor(T/h);
y(:,1) = y0(:);

for i=1:N
y(:,i+1) = y(:,i) + h*f(y(1,i),y(2,i));
end
end
