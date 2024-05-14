par(mfrow=c(1,1))
n = 10^4

V = rexp(n, 1)
U = runif(n, 0, 1)

X1 = sqrt(2*V)*cos(2*pi*U)
X2 = sqrt(2*V)*sin(2*pi*U)


par(mfrow=c(1,3))

hist(X1, col = "blue",freq = FALSE)
hist(X2, col = "red",freq = FALSE)

Y=(X1+X2)/2

hist(Y, col = "green", freq = FALSE)
  

