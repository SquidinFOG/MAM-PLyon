function [V,munique,S] = Vunique(U)
m=length(U)-1;
k=1;
V(1)=U(1);
S(1)=1;
for i=1:m
    if U(i+1)==U(i)
        S(k)=S(k)+1;
    else
        V(k)=U(i);
        k=k+1;
        S(k)=1;
    end
end

munique=length(V);
V(munique+1)=U(m);
munique=length(V);
S;

end

