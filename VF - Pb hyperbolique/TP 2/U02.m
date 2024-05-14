function [u] = U02(x)

  for i = 1:length(x)
    if (x(i)<=1)
      u(i)=1;
    else if (x(i)>1 && x(i)<3)
      u(i) = 3;
    else
      u(i) = 0;
    end
   end
end
end