function F = F(f,k,i,p)
%calcul numerique des integrales
U=[0,0,0,0,1/4,2/4,3/4,1,1,1,1];
[V,~,~] = Vunique(U);
%init des differents coefficients utilisé dans la formule de Simpson 
a=V(k);
b=V(k+1);
Na=BasisFuns(a,p,U);
Nb=BasisFuns(b,p,U);
Nab=BasisFuns((a+b)/2,p,U);
%calcul numerique à l'aide de la formule de Simpson
F=((b-a)/6)*(f(a)*Na(i)+ 4*(f((a+b)/2)*Nab(i)) + f(b)*Nb(i));
end

