function A = a(k,i,j,p,U,V)
%calcul de a par la formule de Simpson
a=V(k);
b=V(k+1);
%init des differents coefficients utilisé dans la formule de Simpson 
Na=dBasisFuns(a,p,U);
Nb=dBasisFuns(b,p,U);
Nab=dBasisFuns((a+b)/2,p,U);
%formule de Simpson
A=((b-a)/6)*(Na(i)*Na(j)+ 4*(Nab(i)*Nab(j)) + Nb(i)*Nb(j));
end

