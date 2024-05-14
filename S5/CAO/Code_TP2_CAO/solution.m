function u = solution(t,f,alpha,beta,p,U,V,munique)
%calcul de la solution approche
%Init
Usol=MatGlob(p,U,munique)\SecondMembre(f,alpha,beta,p,U,munique);
N=BasisFuns(t,p,U);
u=0;
%test pour savoir dans quel interval on se situe afin de ne pas calculer
%les differentes nurbs non nul.
if t < V(2) 
        u = u + alpha*N(1);
        for i=2:4
            u = u + Usol(i-1)*N(i);
        end
elseif t < V(3)
        for i=1:4
        u = u + Usol(i)*N(i);
        end
elseif t < V(4)
        for i=1:4
        u = u + Usol(i+1)*N(i);
        end
elseif t <V(5)
        u = u + beta*N(4);
        for i=1:3
            u = u + Usol(i+2)*N(i);
        end
end
end

