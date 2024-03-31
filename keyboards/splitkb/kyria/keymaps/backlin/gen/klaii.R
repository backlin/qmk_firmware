library(dplyr)

total_mem <- 28*1024
free_kb <- total_mem - 24798 + 1610

tibble(char_width=3:12) %>%
  mutate(
    page_size = floor(128/char_width),
    alpha_kb = (230-(6*16) + 6*16+4) * char_width
  )
  

full_chars <- "åäöpyfgcrlaoeuidhtnsqjkxbmwvz#&@$<>%?1234567890"
half_chars <- ".{}[]|*+~\\/()^\"'`-_!="

nchar(full_chars) * 4 + nchar(half_chars) * 2 + (8 + 2 + 4 + 5 + 4) * 4
