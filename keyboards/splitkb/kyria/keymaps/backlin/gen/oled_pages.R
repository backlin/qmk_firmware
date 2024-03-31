# TODO:
# Underglow brightness -
# Del
# Shifted symbols
source("lib.R")

u <- utf8ToInt

a <- function(str, left=" ", right=""){
  as.vector(
    sapply(strsplit(str, NULL)[[1]], function(char){
      c(u(left), u(char), u(right))
    })
  )
}

p <- function(..., space=32) {
  as.vector(sapply(c(...), function(char) c(space, char)))
}

. <- 32 # space
aa <- c(32, 134)
ae <- c(32, 132)
oe <- c(32, 148)
none <- rep(32, 3)
tab <- 1:3
esc <- 4:6
bksp <- 7:9
del <- c(11,14:15) # Skipping 10 = \r, 12 = new page, 13 = \n
shift <- 16:17
ctrl <- 22
os <- 20:21
alt <- 18:19
f <- list(
  65:67,
  c(65, 68:69),
  c(65, 70:71),
  c(65, 72:73),
  c(65, 74:75),
  c(65, 76:77),
  c(65, 78:79),
  c(65, 80:81),
  c(65, 82:83),
  84:86,
  c(84, 87:88),
  c(84, 89:90)
)
qwe <- 23:25
rec1 <- 202:204
rec2 <- c(202, 208:209)
play1 <- c(205:206, 204)
play2 <- c(205, 210:209)
stop <- p(26)
ins <- 211:213
prtsc <- 214:216
capslk <- 220:222
numlk <- 223:225
scrlk <- 226:228
home <- p(27)
end <- p(28)
pgup <- p(29)
pgdown <- p(30)
mouse <- c(32, 127:128, p(130:131, 133, 135, space=129), 136:137, 32)
mouse_padd <- rep(c(32, 138:140, 32), c(1, 1, length(mouse)-4, 1, 1))
left <- p(128)
down <- p(129)
up <- p(130)
right <- p(131)
arrows <- c(left, down, up, right)

MAG_1_3 <- c(176, 179, 162)
MAG_2_3 <- c(160, 180, 162)
MAG_3_3 <- c(160, 181, 178)
MAG_123 <- c(176, 166, 162)
MAG_233 <- c(160, 182, 178)
MAG_LFT <- c(176, 163, 162)
MAG_RGT <- c(160, 164, 178)
MAG_CTR <- c(160, 165, 162)
MAG_FUL <- 176:178
MAG_TOP <- 183:185
MAG_BTM <- 167:169
MAG_T_L <- c(183, 187, 162)
MAG_T_R <- c(160, 186, 185)
MAG_B_L <- c(167, 171, 162)
MAG_B_R <- c(160, 170, 169)
MAG_S_L <- c(160, 128, 162)
MAG_S_R <- c(160, 131, 162)
DSK_LFT <- c()
DSK_RGT <- c()

thumb_padd1 <- function(...) c(u(" ,;"), rep(32, 12), ..., rep(32, 12), u("-_"))
thumb_padd2 <- function(...) c(rep(32, 5), none, none, none, 32, ..., 32, none)
thumb_main <- function(..., right=c(ctrl, os, alt)) c(rep(32, 5), alt, os, ctrl, 32, ..., 32, right)

validate <- function(maps) {
  sapply(maps, function(m){
    sapply(m, function(page){
      if(length(page) > 36){
        return("too many chars")
      }
      if(!is.null(page) && any(page > 255)) {
        return("out of range")
      }
      return("ok")
    })
  })
}

layers <- list(

  svorak = list(
    c(tab, ., aa, ae, oe, u(" p y        f g c r l  "), bksp),
    c(),
    c(esc, u("  a o e u i        d h t n s  "), del),
    c(),
    c(32, shift, ., p(138), u(" q j k x        b m w v z  "), shift),
    c(u(" ,;"), rep(none, 4), ., alt, alt, ., rep(none, 4), u("-_")),
    c(rep(none, 4), u("  \\s    \\n")),
    c(none, none, ., ., ctrl, u(" # 1   "), os, os, u("   1 # "), ctrl)
  ),

  qwerty = list(
    c(tab, u("  q w e r t        y u i o p "), aa),
    c(),
    c(esc, u("  a s d f g        h j k l"), oe, ., ae),
    c(),
    c(., shift, u("  z x c v b        n m"), p(138), bksp, del, shift),
    c(u(" ,;"), rep(none, 4), ., alt, alt, ., rep(none, 4), u("-_")),
    c(rep(none, 4), u("  \\s    \\n")),
    c(none, none, ., ., ctrl, u(" # 1   "), os, os, u("   1 # "), ctrl)
  ),

  symbols = list(
    c(tab, u("  / \\ [ ] |        # & $ ^ ~"), ., ., bksp),
    c(),
    c(esc, u("  { } ( ) @        * \" '"), up, right, ., ., del),
    c(),
    c(., shift, u("  ="), p(150), u(" < > %        ! ?"), left, down, u(" +  "), shift),
    c(u(" ,;"), rep(none, 4), ., alt, alt, ., rep(none, 4), u("-_")),
    c(rep(none, 4), u("  \\s    \\n")),
    c(none, none, ., ., ctrl, u(" # 1   "), os, os, u("   1 # "), ctrl)
  ),

  numeric = list(
    c(tab, u("                  "), p(149), u(" 7 8 9"), p(133), ., ., bksp),
    c(),
    c(esc, u("    h y p e r      * 4 5 6"), p(96), ., ., del),
    c(),
    c(., shift, u("                  "), p(31), u(" 1 2 3 +"), ., ., shift),
    c(u(" ,;"), rep(none, 4), ., alt, alt, ., rep(none, 4), u("-_")),
    c(rep(none, 4), u("  \\s    \\n")),
    c(none, none, ., ., ctrl, u(" # 1   "), os, os, u("   0 . :"))
  ),

  func = list(
    c(MAG_TOP, MAG_123, none, MAG_233, MAG_T_L, MAG_T_R,    135:136,u("+"), f[[7]], f[[8]], f[[9]], 144,144, 151:152,u("+")),
    c(),
    c(MAG_BTM, MAG_1_3, MAG_2_3, MAG_3_3, MAG_LFT, MAG_RGT, u("  -"),       f[[4]], f[[5]], f[[6]], 145,145, u("  -")),
    c(),
    c(., shift, prtsc, prtsc, none, MAG_B_L, MAG_B_R,       .,.,137,        f[[1]], f[[2]], f[[3]], 144,146, .,shift),
    c(u(" ,;"), rep(none, 4), ., alt, alt, ., rep(none, 4), u("-_")),
    c(rep(none, 4), ., ., MAG_CTR, ., ., MAG_FUL),
    c(none, none, ., ., ctrl, left, right, none, os, os, f[[10]], f[[11]], f[[12]])
  ),

  rgb = list(
    c(tab,     u("  speed 3  hue  "), none, none, none, u("  m2")),
    c(),
    c(esc,     u("  mode 42  sat  "),  none, none, u("m1"), up, right),
    c(),
    c(.,shift, u("  toggle   val  "),  none, none, left, down),
    c(u(" ,;"), rep(none, 4), ., alt, alt, ., rep(none, 4), u("-_")),
    c(rep(none, 4), u("  \\s    \\n")),
    c(none, none, ., ., ctrl, u(" # 1   "), os, os, u("   1 # "), ctrl)
  )

)

(validate(layers))

par(mar=c(0,0,0,0), mfrow=c(6,1))
for(layer in layers){
  render(layer)
}

#write(layers)
