function [u]=u_02(x)

 %Fonction u_02 , solution initiale de notre probleme
 
  for i = 1:length(x)
    if(x(i) <= 2/3) && (x(i) >= 1/3)
      u(i) = 1;
    else
      u(i) = 0;
  end
end