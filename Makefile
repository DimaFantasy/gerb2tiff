# Автоматическое определение окружения
ifeq ($(MSYSTEM), MINGW32)
    BUILD_TARGET := x32
    INCLUDE_PATH := /mingw32/include
    LIB_PATH := /mingw32/lib
else ifeq ($(MSYSTEM), MINGW64)
    BUILD_TARGET := x64
    INCLUDE_PATH := /mingw64/include
    LIB_PATH := /mingw64/lib
else
    $(error Unknown build environment. Please use MSYS2 MINGW32 or MINGW64)
endif

# Компилятор
CXX := g++

# Флаги компиляции
CXXFLAGS := -Wall -Wextra -static -I$(INCLUDE_PATH) -L$(LIB_PATH)
CXXFLAGS += -I$(PROJECT_DIR)/include
LDFLAGS := -lm -lpthread -lstdc++

# Библиотеки
LIBS := \
    -ltiff -lzstd -ljpeg -lz -llzma -ljbig -lwebp -ldeflate \
    -llerc -lsharpyuv \
    -lgdi32 -luser32 -lcomdlg32 -lgdiplus -lshlwapi

# Исходные файлы
SRCS := \
    main.cpp \
    apertures.cpp \
    gerber.cpp \
    polygon.cpp \
    gerber_bison.cc \
    gerber_flex.cc 

# Основная цель
all: $(BUILD_TARGET)

# 64-bit сборка
x64:
	@echo "Building 64-bit DLL version..."
	@$(CXX) $(CXXFLAGS) -shared -o gerb2tiff_x64.dll $(SRCS) $(LIBS) $(LDFLAGS)
	@$(MAKE) strip_debug
	@echo "Done: gerb2tiff_x64.dll (64-bit)"

# 32-bit сборка
x32:
	@echo "Building 32-bit DLL version..."
	@$(CXX) $(CXXFLAGS) -shared -o gerb2tiff_x32.dll $(SRCS) $(LIBS) $(LDFLAGS)
	@$(MAKE) strip_debug
	@echo "Done: gerb2tiff_x32.dll (32-bit)"

# Очистка
clean:
	@rm -f gerb2tiff_x32.dll gerb2tiff_x64.dll
	@echo "Cleaned build artifacts."

# Удаление отладочной информации
strip_debug:
	@echo "Determining environment for stripping debug information..."
ifeq ($(BUILD_TARGET), x32)
	@echo "Stripping debug information from gerb2tiff_x32.dll..."
	@strip --strip-unneeded gerb2tiff_x32.dll
	@echo "Stripped: gerb2tiff_x32.dll"
else ifeq ($(BUILD_TARGET), x64)
	@echo "Stripping debug information from gerb2tiff_x64.dll..."
	@strip --strip-unneeded gerb2tiff_x64.dll
	@echo "Stripped: gerb2tiff_x64.dll"
else
	$(error Unknown BUILD_TARGET. Please use MSYS2 MINGW32 or MINGW64) 
endif

.PHONY: all x64 x32 clean strip_debug