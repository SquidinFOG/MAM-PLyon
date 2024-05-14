function M = MatGlob(p,U,munique)
%Assemblage de la matrice globale
%Init de M
M=zeros(munique,munique);
for k=1:munique-1
    %calcul des Matrice local
    Ml=MatLoc(k,p,U);
    %assemblage
    M = M + Ml;
end
end

