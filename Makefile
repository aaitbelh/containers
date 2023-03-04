NAME=a.out
SRCS= main.cpp
OBJS=$(SRCS:.cpp=.o)
CXX=clang++ -g3
CXXFLAGS= -std=c++98 -Wall -Werror -Wextra -fsanitize=address
HEADER = vector.hpp

all: $(NAME)

$(NAME):$(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) && ./a.out
clean:
	rm -f ${OBJS}
fclean: clean
	rm -f $(NAME)
re : fclean clean all