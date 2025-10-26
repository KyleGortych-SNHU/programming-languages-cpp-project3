#       ::::::::: ::::::::: :::::::::::        :::::::: 
#      :+:    :+::+:    :+:    :+:           :+:    :+: 
#     +:+    +:++:+    +:+    +:+                  +:+  
#    +#++:++#+ +#++:++#:     +#+               +#++:    
#   +#+       +#+    +#+    +#+                  +#+    
#  #+#       #+#    #+##+# #+#           #+#    #+#     
# ###       ###    ### #####             ########       
#
#
# Author: Kyle Gortych
# Date: 2025-10-26

# Compiler
CXX = g++

# Directories
INCLUDE_DIR = include
SRC_DIR = src

# Source files
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/ProduceFrequency.cpp

# Output filename (OS-specific)
ifeq ($(OS),Windows_NT)
    OUT = producefrequencyExe.exe
    RM = del /Q
else
    OUT = producefrequencyExe
    RM = rm -f
endif

# Build
all:
	$(CXX) -I$(INCLUDE_DIR) $(SRC) -o $(OUT)

# Clean
clean:
	$(RM) $(OUT)
