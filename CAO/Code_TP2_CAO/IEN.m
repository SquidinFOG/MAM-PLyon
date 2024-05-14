function [IEN] = IEN(p,munique)
%dans notre cas particulier, munique-1=p+1 on à donc une matrice carré
IEN=zeros(munique-1,p+1);
for k=1:munique-1
    if (k==1)
        
        for i=2:p+1
            IEN(k,i)=i-1;
        end
        
    elseif (k==munique-1)
            
        for i=1:p
            IEN(k,i)=p+i-1;
        end
    else
        for i=1:p+1
            IEN(k,i)=k-2+i;
        end
    end
end
end

