function SM = SecondMembre(f,alpha,beta,p,U,munique)
%calcul du second membre
Iinterval=IEN(p,munique);
[V,munique,~] = Vunique(U);
b=zeros(munique,1);
%calcul des coeff
for k=1:munique-1
    I=Iinterval(k,:);
    %calcul des coeff généraux
    for i=1:length(Iinterval)
        if (I(i)~=0)   
            SM(I(i)) = SM(I(i)) + F(f,k,i,p);
        end   
    end
    %retrait des coeff dependant de alpha et beta
    for i=max(k-p-1,1):k
        SM(i)=SM(i)-alpha*a(1,i,1,p,U,V);
        SM(i)=SM(i)-beta*a(4,i,4,p,U,V);
    end
end
end

