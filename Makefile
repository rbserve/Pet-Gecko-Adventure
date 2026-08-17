NAME        = mygame
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++17

SRC_DIR       = src
OBJ_DIR       = obj
RAYLIB_DIR    = third_party/raylib/src
RAYLIB_LIB    = $(RAYLIB_DIR)/libraylib.a

SRCS        = $(wildcard $(SRC_DIR)/*.cpp)
OBJS        = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

CXXFLAGS   += -I$(RAYLIB_DIR)
LDFLAGS     = -L$(RAYLIB_DIR) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all: $(RAYLIB_LIB) $(NAME)

# Build raylib itself (only runs once, cached afterward)
$(RAYLIB_LIB):
	$(MAKE) -C $(RAYLIB_DIR) PLATFORM=PLATFORM_DESKTOP

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(RAYLIB_DIR) clean

re: fclean all

.PHONY: all clean fclean re