% Declaration parametres
a = 1; % Coef enonce

m = 500;  % Nombre de point en espace
h = 1/m; % Pas en espace
c = 0.7;

A = 0; % Borne inf espace
B = 1; % Borne supp espace

tmax = c/h; % Nombre de point de temps = temps max

%Schema avec u_01


x = linspace(A, B, m);
u0 = u_01(x);
sol = schema_num('u_01', m, c, tmax);

x_ = x-c*h*tmax;
x_periodique = mod(x_ - A, B - A) + A;
u_ana = u_01(x_periodique);


figure(1);
hold on;
plot(x, sol)
plot(x, u0, 'k--')
plot(x, u_ana)
xlabel('x')
title('Schema num')
legend('Solution numerique', 'Condition initiale u_01', 'Solution analytique')
hold off;


%Schema avec u_02

x = linspace(A, B, m);
u0 = u_02(x);
sol2 = schema_num('u_02', m, c, tmax);

x_ = x-c*h*tmax;
x_periodique = mod(x_ - A, B - A) + A;
u_ana2 = u_02(x_periodique);

figure(2);
hold on;
plot(x, sol2)
plot(x, u0, 'k--')
plot(x, u_ana2)
xlabel('x')
title('Schema num')
legend('Solution numerique', 'Condition initiale u_02', 'Solution analytique')
hold off;

% Calcul des erreurs :

MSE_u1 = 1/length(sol)*(sum(u_ana.^2 - sol.^2)) %0.0038

MSE_u2 = 1/length(sol2)*(sum(u_ana2.^2 - sol2.^2)) %0.0213

%Conclusion : 

%On peut voir que les solution numérique subisse une diffusion (amplitude "aplatie" ), 
% ainsi qu'une dispertion (décalage des courbes de la solution numérique et de la solution final exacte).
%le parametre c influence sur la dispertion et la diffusion.
% On peut voir aussi que la 2ème à une erreur bien plus éléver car nos schema ne peuvent pas garder les discontinuité.
