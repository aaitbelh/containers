NAME=a.out

SRCS=main.cpp
OBJS=$(SRCS:.cpp=.o)
CXX=clang++ -g
CXXFLAGS=
HEADER=vector.hpp

all: $(NAME)

$(NAME):$(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) && ./a.out

%.o:%.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) $(SRC) -c $<

clean:
	rm -f ${OBJS}