function Ml = MatLoc(k,p,U)
%Construction des Matrices locales

%Init
[V,munique,~] = Vunique(U);
Ml=zeros(munique,munique);
%extraction des indices des Nurbs non nul de IEN
I=IEN(p,munique);
I=I(k,:);
%calcul des coef de la matrices local
for i=1:length(I)
    for j=1:length(I)
        if (I(i)~=0) && (I(j)~=0)   
            Ml(I(i),I(j))=a(k,i,j,p,U,V);
        end
    end
end     
end

