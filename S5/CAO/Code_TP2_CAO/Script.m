clc
clear 
%init
U=[0,0,0,0,1/4,2/4,3/4,1,1,1,1];
[V,munique,S] = Vunique(U);
p=3;
f=@(x)(2);
alpha=0;
beta=0;
%test solution manufacturer 
Solutionmanufact(p,f,alpha,beta,U,V,munique)