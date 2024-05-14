function [N] = dBasisFuns(u,p,U)
k=Dichotomie(p,u,U);
left=zeros(p+1,1);
right=zeros(p+1,1);
N=zeros(1,p+1);
N(1)=1;
for j=1:p
    left(j+1)=u-U(k+1-j);
    right(j+1)=U(k+j)-u;
    saved=0;
    if j<p 
        for r=0:j-1
            temp=N(r+1)/(right(r+2)+left(j-r+1));
            N(r+1)=saved + right(r+2)*temp;
            saved=left(j-r+1)*temp;
        end
    else
        for r=0:j-1
            temp=N(r+1)/(right(r+2)+left(p-r+1));
            N(r+1)=saved - p*temp;
            saved=+p*temp;
        end
    end
    N(j+1)=saved;
end
N(p+1)=saved;
end

