function [sol] = schema_num(u0, m, c , tmax)
j = 1:m;
h=1/m;
V = feval(u0, (j-1)*h);

for n=1:tmax
   %U(1) = (1-c)*V(1) + c*V(m);
   U(1) = V(1) - c *(V(1) - V(m));
   for j=2:m
     %U(j) = (1-c)*V(j)+c*V(j-1);
     U(j) = V(j) - c * (V(j) - V(j-1));
   end
   V = U;
end
sol = U;
end
