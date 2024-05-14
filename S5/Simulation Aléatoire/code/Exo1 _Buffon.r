buffon <- function(n, a, L) {
#génération des VA, teta pour langle, X pour la distance à la jointure la plus proche
  teta <- runif(n, -(pi/2), pi/2)
  x <- runif(n, 0, 0.5*L)
  #simulation
  lancer <- x<=(0.5 * a * cos(teta))
  
  return (2*a/(L*mean(lancer)))
}

test = buffon(10000000, 1, 4)
test

