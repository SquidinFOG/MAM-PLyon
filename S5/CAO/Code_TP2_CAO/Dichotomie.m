function [k] = Dichotomie(p,u,U)
n=length(U)- p - 1;

if u==U(n)
  k=n;
  return

else
  inf = p+1; 
  sup = n+1; 
  x=floor((sup+inf)/2);
while (u<U(x)) || (u>U(x+1))
    if (u<U(x))
        sup=x;
    else 
        inf=x;
    end
    x=floor((sup+inf)/2);
end
k=x;
end