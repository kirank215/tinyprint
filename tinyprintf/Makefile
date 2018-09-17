CC = gcc
CFALGS = -Wextra -Wall -Werror -std=c99 -pedantic

LIB = libtinyprintf.a
SRC = tinyprintf.c
OBJ = $(SRC:.o=.c)

.PHONY: libtinyprintf
libtinyprintf:$(LIB)($(OBJ))
.PHONY: clean
clean:
	$(RM) $(LIB)
