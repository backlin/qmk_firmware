library(viridis)

n <- 64

hex2hsv <- function(x){
  hsv <- rgb2hsv(col2rgb(x))
  n <- ncol(hsv)
  hsv[1:2, n] <- hsv[1:2, n-1]
  return(hsv)
}

in_hsv <- hex2hsv(in_col)

in_n <- 41
in_col <- viridis::inferno(n)
in_hsv <- hex2hsv(in_col)

out_n <- TYPING_SPEED_MAX_VALUE + 1
apply(1, function(x) approx(
  seq(0, 1, length.out = ncol(in_col)),
  x,
  seq(0, 1, length.out = TYPING_SPEED_MAX_VALUE

matplot(, type="l")



image(t(0:n), col=inferno(n+1))
