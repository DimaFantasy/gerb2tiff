import ctypes
from ctypes import *
from pathlib import Path
from typing import List
import json

class GerberOptions(Structure):
    _fields_ = [
        ("imageDPI", c_double),
        ("optRotation", c_double),
        ("optGrowUnitsMillimeters", c_bool),
        ("optBoarderUnitsMillimeters", c_bool),
        ("optBoarder", c_double),
        ("optInvertPolarity", c_bool),
        ("optTestOnly", c_bool),
        ("optVerbose", c_int),
        ("rowsPerStrip", c_uint),
        ("optShowArea", c_bool),
        ("optQuiet", c_bool),
        ("optGrowSize", c_double),
        ("optScaleX", c_double),
        ("optScaleY", c_double),
        ("outputFilename", c_char_p),
        ("inputFiles", POINTER(c_char_p)),
        ("inputFileCount", c_uint)
    ]

class GerberOptionsC(Structure):
    _fields_ = [
        ("imageDPI", c_double),
        ("optRotation", c_double),
        ("optGrowUnitsMillimeters", c_bool),
        ("optBoarderUnitsMillimeters", c_bool),
        ("optBoarder", c_double),
        ("optInvertPolarity", c_bool),
        ("optTestOnly", c_bool),
        ("optVerbose", c_int),
        ("rowsPerStrip", c_uint),
        ("optShowArea", c_bool),
        ("optQuiet", c_bool),
        ("optGrowSize", c_double),
        ("optScaleX", c_double),
        ("optScaleY", c_double),
        ("outputFilename", c_char * 256),
        ("inputFiles", (c_char * 256) * 10),
        ("inputFileCount", c_int)
    ]

def convert_gerber(input_files: List[str], output_file: str = None, options: dict = None):
    """
    Конвертирует Gerber-файлы в TIFF через DLL
    """
    if options is None:
        options = {}
    
    # Загрузка DLL
    dll_path = Path(__file__).parent / "gerb2tiff_x64.dll"
    print(f"Путь к DLL: {dll_path}")
    
    if not dll_path.exists():
        raise FileNotFoundError(f"Файл DLL не найден: {dll_path}")
    
    try:
        gerber_dll = cdll.LoadLibrary(str(dll_path))
        print("DLL успешно загружена")
    except OSError as e:
        raise RuntimeError(f"Не удалось загрузить DLL: {e}") from e

    if not hasattr(gerber_dll, "processGerberJSON"):
        raise RuntimeError("Функция 'processGerberJSON' не найдена в DLL")

    process_func = gerber_dll.processGerberJSON
    process_func.argtypes = [c_char_p]
    process_func.restype = c_int

    # Формирование JSON
    params = {
        "imageDPI": options.get("imageDPI", 1024),
        "optRotation": options.get("optRotation", 0),
        "optGrowUnitsMillimeters": options.get("optGrowUnitsMillimeters", False),
        "optBoarderUnitsMillimeters": options.get("optBoarderUnitsMillimeters", False),
        "optBoarder": options.get("optBoarder", 0),
        "optInvertPolarity": options.get("optInvertPolarity", False),
        "optTestOnly": options.get("optTestOnly", False),
        "optVerbose": options.get("optVerbose", 0),
        "rowsPerStrip": options.get("rowsPerStrip", 512),
        "optShowArea": options.get("optShowArea", False),
        "optQuiet": options.get("optQuiet", False),
        "optGrowSize": options.get("optGrowSize", 0),
        "optScaleX": options.get("optScaleX", 1),
        "optScaleY": options.get("optScaleY", 1),
        "outputFilename": output_file,
        "inputFiles": input_files
    }
    json_params = json.dumps(params)
    print(f"Передача JSON: {json_params}")

    # Вызов функции
    result = process_func(json_params.encode('utf-8'))
    print(f"Результат вызова processGerberJSON: {result}")

    if result != 0:
        raise RuntimeError(f"Ошибка конвертации (код: {result})")

    return True

if __name__ == "__main__":
    try:
        convert_gerber(
            input_files=[
                str(Path(__file__).parent / "SETKA.gbr")
            ],
            output_file=str(Path(__file__).parent / "OUTPUT.tiff"),
            options={
                "imageDPI": 1200,
                "optInvertPolarity": True,
                "optVerbose": 1
            }
        )
        print("Конвертация успешно завершена!")
    except Exception as e:
        print(f"Ошибка: {e}")
        import traceback
        traceback.print_exc()
