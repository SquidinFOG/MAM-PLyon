#simulation par la mthds d'inversion
#1)loi exponentielle

iter=10
iter1=1000
lambda=10



Finv<-function(u,lambda)
{
  return(-(1/lambda)*log(1-u))
}
U=c(Finv(runif(iter,0,1),lambda))
U=sort(U)
U1=c(Finv(runif(iter1,0,1),lambda))
U1=sort(U1)
par(mfrow=c(1,3))
curve ( pexp ( x , lambda ) , 0 , 1 , main='F : loi exp' )
plot(x=U,(y=1:iter),type="o")
plot(x=U1,(y=1:iter1),type="o")

#2)loi de Bernouilli
iter=10
iter1=1000
lambda=0.4

F2inv<-function(u,p)
{
  x=rep(0,length(u))
  for(i in 1:length(u))
  {
    if (u[i]<1-p)
    {
      x[i]=0
    }
    else
    {
      x[i]=1
    }
  }
  return (x)
}


U=c(F2inv(runif(iter,0,1),lambda))
U=sort(U)
U1=c(F2inv(runif(iter1,0,1),lambda))
U1=sort(U1)

par(mfrow=c(1,3))
curve ( pbinom(x,1, lambda ) , -0.01 , 1 , main='F : loi de Bernouilli théorique' )
plot(x=U,(y=1:iter),type="o")
plot(x=U1,(y=1:iter1),type="o")