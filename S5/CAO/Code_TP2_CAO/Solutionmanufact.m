function [] = Solutionmanufact(p,f,alpha,beta,U,V,munique)
%Test de notre solution approché par la technique des solutions
%manufacturee

%Solution manufacturee 
x=linspace(0,1,500);
uexa=-x.*(x-1);

%Discretisation
u=zeros(500,1);
W=linspace(V(1),V(5),500);
%calcul de la solution approche
for j=1:length(W)
    u(j)=solution(W(j),f,alpha,beta,p,U,V,munique);
end

%plot des courbes differentes courbes
hold on
plot(x,u)
plot(x,uexa)
end

