function [u]=U0(x)

 %Fonction u_01 , solution initiale de notre probleme
  for i = 1:length(x)
    if(x(i) < 1) 
        u(i) = 1;
    end
    if (x(i) >= 1) && (x(i) <= 2)
        u(i) = 2-x(i);
    end
    if (x(i) > 2)
        u(i) = 0;
    end
  end
end