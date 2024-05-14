function [N] = BasisFuns(u,p,U)
k=Dichotomie(p,u,U);
left=zeros(p+1,1);
right=zeros(p+1,1);
N(1)=1;
for i=1:p
    left(i+1)=u-U(k+1-i);
    right(i+1)=U(k+i)-u;
    saved=0;
    for j=0:i-1
        temp=N(j+1)/(right(j+2)+left(i-j+1));
        N(j+1)=saved + right(j+2)*temp;
        saved=left(i-j+1)*temp;
    end
    N(i+1)=saved;
end
end

