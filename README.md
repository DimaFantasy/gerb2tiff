# Gerb2TIFF

**Gerb2TIFF** is a tool for converting Gerber RS-274X files into raster images in TIFF format. This project was found online, based on the original code created by Adam Seychell, and has been modified to improve compatibility, eliminate compilation warnings, and add new features. The original project is no longer maintained.

## Key Features

- Conversion of Gerber files to monochrome TIFF images.
- Support for various parameters such as DPI, scaling, polarity inversion, and border addition.
- Export functions for use in other applications via a C++ interface (as a DLL).

## Exported Functions

1. **`int processGerber(const GerberOptions &options)`**  
   The main function for processing Gerber files using the `GerberOptions` structure. This function is exported from the library and allows flexible configuration of processing parameters.

2. **`int processGerberWrapper(int argc, char **argv)`**  
   A wrapper for processing command-line arguments.

3. **`int processGerberJSON(const char *jsonParams)`**  
   A function for processing parameters in JSON format.

### GerberOptions Structure

To use the `processGerber` function, you need to pass an object of the `GerberOptions` structure, which contains all processing parameters. Here is the structure description:

```cpp
struct GerberOptions {
    double imageDPI = 2400;                // Image DPI
    double optRotation = 0;               // Image rotation angle
    bool optGrowUnitsMillimeters = false; // Use millimeters for growth
    bool optBoarderUnitsMillimeters = false; // Use millimeters for borders
    double optBoarder = 0;                // Border size
    bool optInvertPolarity = false;       // Invert image polarity
    bool optTestOnly = false;             // Test only without saving
    int optVerbose = 0;                   // Verbosity level
    unsigned rowsPerStrip = 512;          // Rows per strip
    bool optShowArea = false;             // Show the area of darkened regions
    bool optQuiet = false;                // Suppress output messages
    double optGrowSize = 0;               // Growth size in pixels
    double optScaleX = 1;                 // Scaling along the X-axis
    double optScaleY = 1;                 // Scaling along the Y-axis
    std::string outputFilename;           // Output file name
    std::vector<std::string> inputFiles;  // List of input files
};
```

### `processGerber` Function

The `processGerber` function takes a `GerberOptions` object and processes Gerber files based on the specified parameters. It is exported from the library and available for use in other applications.

```cpp
extern "C" __declspec(dllexport) int processGerber(const GerberOptions &options);
```

**Parameters:**
- `options` — an object of the `GerberOptions` structure containing processing parameters.

**Return Value:**
- `0` — successful processing.
- Non-zero value — processing error.

Example usage of the `processGerber` function in C++:

```cpp
#include <iostream>

int main() {
    GerberOptions options;
    options.imageDPI = 2400;
    options.outputFilename = "output.tiff";
    options.inputFiles = {"input1.gbr", "input2.gbr"};

    int result = processGerber(options);
    if (result == 0) {
        std::cout << "Conversion successful!" << std::endl;
    } else {
        std::cerr << "Conversion failed!" << std::endl;
    }

    return result;
}
```

## Compilation Instructions

### Requirements

- **Compiler**: MinGW-w64 (GCC).
- **Environment**: MSYS2 for MinGW-w64.
- **Libraries**:
  - [libtiff](http://www.libtiff.org/) for working with TIFF files.
  - [nlohmann/json](https://github.com/nlohmann/json) for working with JSON.

### Compilation Steps with MSVC

1. Ensure all dependencies are installed.
2. Clone the repository:
   ```cmd
   git clone https://github.com/DimaFantasy/gerb2tiff/gerb2tiff.git
   cd gerb2tiff
   ```
3. Compile the project into a DLL:
   ```cmd
   cl /std:c++17 /W4 /EHsc /LD main.cpp /I"path_to_libtiff" /I"path_to_json" tiff.lib /Fe:gerb2tiff.dll
   ```

### Compilation Steps with MinGW-w64 (GCC)

1. Ensure MSYS2 is installed and added to `PATH`. Download MSYS2 from the [official website](https://www.msys2.org/).
2. Install the necessary packages:
   ```bash
   pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-libtiff mingw-w64-x86_64-nlohmann-json
   ```
3. Clone the repository:
   ```bash
   git clone https://github.com/DimaFantasy/gerb2tiff/gerb2tiff.git
   cd gerb2tiff
   ```
4. Compile the project into a DLL:
   ```bash
   g++ -std=c++17 -shared -o gerb2tiff.dll main.cpp -ltiff -I/mingw64/include -L/mingw64/lib
   ```

### Warning Resolution

The code has been modified to eliminate all compilation warnings. Use the flags `/W4` (MSVC) or `-Wall -Wextra` (GCC) for verification.

## Usage Examples

### Via JSON API

```cpp
#include <iostream>

int main() {
    const char *jsonParams = R"({
        "imageDPI": 2400,
        "outputFilename": "output.tiff",
        "inputFiles": ["input1.gbr", "input2.gbr"]
    })";

    int result = processGerberJSON(jsonParams);
    if (result == 0) {
        std::cout << "Conversion successful!" << std::endl;
    } else {
        std::cerr << "Conversion failed!" << std::endl;
    }

    return result;
}
```

### Via JSON API (Python)

```python
import ctypes
import json

# Load the compiled library
gerb2tiff = ctypes.CDLL('./gerb2tiff.dll')

# Define the processGerberJSON function
processGerberJSON = gerb2tiff.processGerberJSON
processGerberJSON.argtypes = [ctypes.c_char_p]
processGerberJSON.restype = ctypes.c_int

# Create a JSON structure
params = {
    "imageDPI": 2400,
    "optRotation": 0.0,
    "optGrowUnitsMillimeters": False,
    "optBoarderUnitsMillimeters": False,
    "optBoarder": 0.0,
    "optInvertPolarity": False,
    "optTestOnly": False,
    "optVerbose": 1,
    "rowsPerStrip": 512,
    "optShowArea": False,
    "optQuiet": False,
    "optGrowSize": 0.0,
    "optScaleX": 1.0,
    "optScaleY": 1.0,
    "outputFilename": "output.tiff",
    "inputFiles": ["input1.gbr", "input2.gbr"]
}

# Convert to JSON string
json_params = json.dumps(params)

# Call the function
result = processGerberJSON(json_params.encode('utf-8'))
if result == 0:
    print("Conversion successful!")
else:
    print("Conversion failed!")
```

### Via processGerberWrapper (Python)

```python
import ctypes

# Load the compiled library
gerb2tiff = ctypes.CDLL('./gerb2tiff.dll')

# Define the processGerberWrapper function
processGerberWrapper = gerb2tiff.processGerberWrapper
processGerberWrapper.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_char_p)]
processGerberWrapper.restype = ctypes.c_int

# Create command-line arguments
args = [
    b"gerb2tiff",  # Program name
    b"--dpi=2400",
    b"--output=output.tiff",
    b"input1.gbr",
    b"input2.gbr"
]

argc = len(args)
argv = (ctypes.c_char_p * argc)(*args)

# Call the function
result = processGerberWrapper(argc, argv)
if result == 0:
    print("Conversion successful!")
else:
    print("Conversion failed!")
```

## JSON Structure for processGerberJSON

```json
{
    "imageDPI": 2400,                     
    "optRotation": 0.0,                   
    "optGrowUnitsMillimeters": false,     
    "optBoarderUnitsMillimeters": false,  
    "optBoarder": 0.0,                    
    "optInvertPolarity": false,           
    "optTestOnly": false,                 
    "optVerbose": 1,                      
    "rowsPerStrip": 512,                  
    "optShowArea": false,                 
    "optQuiet": false,                    
    "optGrowSize": 0.0,                   
    "optScaleX": 1.0,                     
    "optScaleY": 1.0,                     
    "outputFilename": "output.tiff",      
    "inputFiles": ["input1.gbr", "input2.gbr"] 
}
```

## Change Log

- **Original Project**: Adam Seychell (2001). The project is no longer maintained.
- **Modifications**:
  - Added JSON API support.
  - Resolved compilation warnings.
  - Updated documentation.
  - The project now compiles into a DLL instead of an EXE.

## License

The project is distributed under the GNU General Public License v3.0 or later.

---

# Gerb2TIFF

**Gerb2TIFF** — это инструмент для преобразования файлов Gerber RS-274X в растровые изображения в формате TIFF. Этот проект был найден на просторах интернета, основан на оригинальном коде, созданном Adam Seychell, и был модифицирован для улучшения совместимости, устранения предупреждений компиляции и добавления новых функций. Оригинальный проект больше не поддерживается.

## Основные возможности

- Конвертация Gerber-файлов в монохромные TIFF-изображения.
- Поддержка различных параметров, таких как DPI, масштабирование, инверсия полярности и добавление границ.
- Экспорт функций для использования в других приложениях через интерфейс C++ (в виде DLL).

## Экспортируемые функции

1. **`int processGerber(const GerberOptions &options)`**  
   Основная функция для обработки Gerber-файлов с использованием структуры `GerberOptions`. Эта функция экспортируется из библиотеки и позволяет гибко настраивать параметры обработки.

2. **`int processGerberWrapper(int argc, char **argv)`**  
   Обертка для обработки аргументов командной строки.

3. **`int processGerberJSON(const char *jsonParams)`**  
   Функция для обработки параметров в формате JSON.

### Структура `GerberOptions`

Для использования функции `processGerber` необходимо передать объект структуры `GerberOptions`, которая содержит все параметры обработки. Вот описание структуры:

```cpp
struct GerberOptions {
    double imageDPI = 2400;                // DPI изображения
    double optRotation = 0;               // Угол поворота изображения
    bool optGrowUnitsMillimeters = false; // Использовать миллиметры для увеличения
    bool optBoarderUnitsMillimeters = false; // Использовать миллиметры для границ
    double optBoarder = 0;                // Размер границы
    bool optInvertPolarity = false;       // Инвертировать полярность изображения
    bool optTestOnly = false;             // Только тестирование без сохранения
    int optVerbose = 0;                   // Уровень детализации вывода
    unsigned rowsPerStrip = 512;          // Количество строк на полосу
    bool optShowArea = false;             // Показать площадь затемненных областей
    bool optQuiet = false;                // Подавить вывод сообщений
    double optGrowSize = 0;               // Размер увеличения в пикселях
    double optScaleX = 1;                 // Масштабирование по оси X
    double optScaleY = 1;                 // Масштабирование по оси Y
    std::string outputFilename;           // Имя выходного файла
    std::vector<std::string> inputFiles;  // Список входных файлов
};
```

### Функция `processGerber`

Функция `processGerber` принимает объект `GerberOptions` и выполняет обработку Gerber-файлов на основе указанных параметров. Она экспортируется из библиотеки и доступна для использования в других приложениях.

```cpp
extern "C" __declspec(dllexport) int processGerber(const GerberOptions &options);
```

**Параметры:**
- `options` — объект структуры `GerberOptions`, содержащий параметры обработки.

**Возвращаемое значение:**
- `0` — успешное завершение обработки.
- Ненулевое значение — ошибка обработки.

Пример использования функции `processGerber` в C++:

```cpp
#include <iostream>

int main() {
    GerberOptions options;
    options.imageDPI = 2400;
    options.outputFilename = "output.tiff";
    options.inputFiles = {"input1.gbr", "input2.gbr"};

    int result = processGerber(options);
    if (result == 0) {
        std::cout << "Conversion successful!" << std::endl;
    } else {
        std::cerr << "Conversion failed!" << std::endl;
    }

    return result;
}
```

## Инструкции по компиляции

### Требования

- **Компилятор**: MinGW-w64 (GCC).
- **Среда**: MSYS2 для MinGW-w64.
- **Библиотеки**:
  - [libtiff](http://www.libtiff.org/) для работы с TIFF-файлами.
  - [nlohmann/json](https://github.com/nlohmann/json) для работы с JSON.

### Шаги компиляции с MSVC

1. Убедитесь, что все зависимости установлены.
2. Склонируйте репозиторий:
   ```cmd
   git clone https://github.com/DimaFantasy/gerb2tiff/gerb2tiff.git
   cd gerb2tiff
   ```
3. Скомпилируйте проект в DLL:
   ```cmd
   cl /std:c++17 /W4 /EHsc /LD main.cpp /I"path_to_libtiff" /I"path_to_json" tiff.lib /Fe:gerb2tiff.dll
   ```

### Шаги компиляции с MinGW-w64 (GCC)

1. Убедитесь, что MSYS2 установлена и добавлена в `PATH`. Скачайте MSYS2 с [официального сайта](https://www.msys2.org/).
2. Установите необходимые пакеты:
   ```bash
   pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-libtiff mingw-w64-x86_64-nlohmann-json
   ```
3. Склонируйте репозиторий:
   ```bash
   git clone https://github.com/DimaFantasy/gerb2tiff/gerb2tiff.git
   cd gerb2tiff
   ```
4. Скомпилируйте проект в DLL:
   ```bash
   g++ -std=c++17 -shared -o gerb2tiff.dll main.cpp -ltiff -I/mingw64/include -L/mingw64/lib
   ```

### Устранение предупреждений

Код был модифицирован для устранения всех предупреждений компиляции. Используйте флаги `/W4` (MSVC) или `-Wall -Wextra` (GCC) для проверки.

## Пример использования

### Через JSON API

```cpp
#include <iostream>

int main() {
    const char *jsonParams = R"({
        "imageDPI": 2400,
        "outputFilename": "output.tiff",
        "inputFiles": ["input1.gbr", "input2.gbr"]
    })";

    int result = processGerberJSON(jsonParams);
    if (result == 0) {
        std::cout << "Conversion successful!" << std::endl;
    } else {
        std::cerr << "Conversion failed!" << std::endl;
    }

    return result;
}
```

### Через JSON API (Python)

```python
import ctypes
import json

# Загрузка скомпилированной библиотеки
gerb2tiff = ctypes.CDLL('./gerb2tiff.dll')

# Определение функции processGerberJSON
processGerberJSON = gerb2tiff.processGerberJSON
processGerberJSON.argtypes = [ctypes.c_char_p]
processGerberJSON.restype = ctypes.c_int

# Создание JSON-структуры
params = {
    "imageDPI": 2400,
    "optRotation": 0.0,
    "optGrowUnitsMillimeters": False,
    "optBoarderUnitsMillimeters": False,
    "optBoarder": 0.0,
    "optInvertPolarity": False,
    "optTestOnly": False,
    "optVerbose": 1,
    "rowsPerStrip": 512,
    "optShowArea": False,
    "optQuiet": False,
    "optGrowSize": 0.0,
    "optScaleX": 1.0,
    "optScaleY": 1.0,
    "outputFilename": "output.tiff",
    "inputFiles": ["input1.gbr", "input2.gbr"]
}

# Преобразование в JSON-строку
json_params = json.dumps(params)

# Вызов функции
result = processGerberJSON(json_params.encode('utf-8'))
if result == 0:
    print("Conversion successful!")
else:
    print("Conversion failed!")
```

### Через processGerberWrapper (Python)

```python
import ctypes

# Загрузка скомпилированной библиотеки
gerb2tiff = ctypes.CDLL('./gerb2tiff.dll')

# Определение функции processGerberWrapper
processGerberWrapper = gerb2tiff.processGerberWrapper
processGerberWrapper.argtypes = [ctypes.c_int, ctypes.POINTER(ctypes.c_char_p)]
processGerberWrapper.restype = ctypes.c_int

# Создание аргументов командной строки
args = [
    b"gerb2tiff",  # Имя программы
    b"--dpi=2400",
    b"--output=output.tiff",
    b"input1.gbr",
    b"input2.gbr"
]

argc = len(args)
argv = (ctypes.c_char_p * argc)(*args)

# Вызов функции
result = processGerberWrapper(argc, argv)
if result == 0:
    print("Conversion successful!")
else:
    print("Conversion failed!")
```

## Структура JSON для processGerberJSON

```json
{
    "imageDPI": 2400,                     
    "optRotation": 0.0,                   
    "optGrowUnitsMillimeters": false,     
    "optBoarderUnitsMillimeters": false,  
    "optBoarder": 0.0,                    
    "optInvertPolarity": false,           
    "optTestOnly": false,                 
    "optVerbose": 1,                      
    "rowsPerStrip": 512,                  
    "optShowArea": false,                 
    "optQuiet": false,                    
    "optGrowSize": 0.0,                   
    "optScaleX": 1.0,                     
    "optScaleY": 1.0,                     
    "outputFilename": "output.tiff",      
    "inputFiles": ["input1.gbr", "input2.gbr"] 
}
```

## История изменений

- **Оригинальный проект**: Adam Seychell (2001). Проект больше не поддерживается.
- **Модификации**:
  - Добавлена поддержка JSON API.
  - Устранены предупреждения компиляции.
  - Обновлена документация.
  - Проект теперь компилируется в DLL вместо EXE.

## Лицензия

Проект распространяется под лицензией GNU General Public License v3.0 или более поздней версии.
