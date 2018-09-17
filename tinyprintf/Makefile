CC = gcc
CFALGS = -Wextra -Wall -Werror -std=c99 -pedantic

LIB = libtinyprintf.a
OBJ = tinyprintf.o

all: $(LIB)$(OBJ)
.PHONY: libtinyprintf
library : $(LIB)($(OBJ))
.PHONY: clean
clean:
	$(RM) $(LIB)
