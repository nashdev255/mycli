CC = g++
CFLAGS = -std=c++17
OPT = -lboost_program_options
TARGET = src.exe

MAIN = src.cpp
SRCS = $(MAIN)

OBJS = $(SRCS:.cpp=.o)
INCDIR =
LIBDIR =

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS) $(OPT)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(INCDIR) -c $(SRCS)

clean:
	del -f $(OBJS)
