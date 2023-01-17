NAME=a.out

SRCS= main.cpp #track/leak_checker.cpp track/memory_tracker.cpp
OBJS=$(SRCS:.cpp=.o)
CXX=clang++ -g
CXXFLAGS=  -std=c++98 -Wall -Werror -Wextra
HEADER=vector.hpp

all: $(NAME)

$(NAME):$(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) && ./a.out

# %.o:%.cpp $(HEADER)
# 	$(CXX) $(CXXFLAGS) $(SRC) -c $<

clean:
	rm -f ${OBJS}
fclean:
	rm -f $(NAME)
re : fclean clean all