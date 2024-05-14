N <- 100000

abs <- rep(0, N)
ord <- rep(0, N)

U <- runif(N, -1, 1)
V <- runif(N, 0, 1)

x<-U

y <- (2/pi) *sqrt(1-x^2)

for(i in 1:N){
  if(V[i]<y[i]){
    abs[i]<-x[i]
    ord[i]<-V[i]
  }
}

plot(abs, ord,cex=0.2)
curve((2/pi)*sqrt(1-x^2),from = -1, to =1,add=TRUE,col="red")

