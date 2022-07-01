NAME = alcu

SHELL := /bin/bash
CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD -MP -I$(includes) -g

includes = ./includes
srcdir = srcs
objdir = objs
srcs = $(shell find $(srcdir) -name "*.c" -type f)
objs = $(srcs:$(srcdir)%.c=$(objdir)%.o)
deps = $(srcs:$(srcdir)%.c=$(objdir)%.d)

# ==== Align length to format compile message ==== #
align := $(shell tr ' ' '\n' <<<"$(srcs)" | while read line; do echo \
	$$((`echo $$line | wc -m`)); done | awk 'm<$$1{ m=$$1} END{print m}')

all: $(NAME)
-include $(deps)

$(NAME): $(objs)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo -e "flags  : $(ylw)$(CFLAGS)$(nc)\nbuild  : $(grn)$^$(nc)\n=> $(blu)$@$(nc)" 

$(objdir)/%.o: $(srcdir)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "compile: $(mgn)$<$(nc)\
	$$(yes ' ' | head -n $$(expr $(align) - $$((`echo $< | wc -m` - 1))) | tr -d '\n') -> \
	$(grn)$@$(nc)"

clean:
	$(RM) $(objs) $(deps)
	$(RM) -r $(objdir)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all test cav clean fclean re

# ==== Color define ==== #
ylw := \033[33m
grn := \033[32m
blu := \033[34m
mgn := \033[35m
cyn := \033[36m
nc := \033[m
