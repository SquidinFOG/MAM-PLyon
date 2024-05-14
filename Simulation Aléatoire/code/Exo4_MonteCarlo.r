aprx <- function(n){
  cpt = 0
  
  for (i in 1:n){ 
    x=runif(1,0,1)
    y=runif(1,0,1)
    
    if( (x^2 + y^2) <= 1){
      cpt = cpt + 1
    }
  }
  
  aprx = cpt / n*4
  ecart = pi/aprx
  return (aprx)

}




aprx(1000000)
