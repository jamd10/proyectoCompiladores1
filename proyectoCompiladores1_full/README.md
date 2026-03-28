# Proyecto Compiladores 1
## Lexer y Parser para un subconjunto de Rust en C++ con Flex y Bison

Este proyecto implementa:
- Analizador léxico (lexer) con Flex
- Analizador sintáctico (parser) con Bison
- Reconocimiento de tokens
- Árbol sintáctico abstracto (AST)
- Interfaz gráfica con Python Tkinter

## Estructura
- `src/lexer.l`: reglas del lexer
- `src/parser.y`: gramática del parser
- `src/main.cpp`: ejecución principal
- `src/ast.hpp`: estructura del árbol
- `src/analysis.*`: almacenamiento de tokens, errores y AST
- `tests/`: casos de prueba
- `gui/app.py`: interfaz gráfica

## Requisitos
- MSYS2 MINGW64
- g++
- flex
- bison
- make
- Python 3

## Compilación
```bash
make clean
make
```

## Uso por consola

### Parse normal
```bash
./rust_parser.exe < tests/ok1.rs
```

### Mostrar tokens
```bash
./rust_parser.exe --tokens tests/ok1.rs
```

### Mostrar AST
```bash
./rust_parser.exe --ast tests/ok1.rs
```

### Mostrar todo
```bash
./rust_parser.exe --all tests/ok1.rs
```

## Interfaz gráfica
Desde la raíz del proyecto:
```bash
python gui/app.py
```

## Cobertura del subconjunto
- Palabras reservadas: `fn`, `let`, `if`, `else`, `while`, `for`, `in`, `return`
- Tipos: `i32`, `f64`, `bool`, `char`, `str`
- Operadores: `+`, `-`, `*`, `/`, `&&`, `||`, `!`, `<`, `>`, `<=`, `>=`, `==`, `!=`
- Delimitadores: `{}`, `()`, `[]`, `,`, `;`
- Expresiones
- Funciones con parámetros limitados
- Control de flujo `if-else`, `while`, `for`

## Casos de prueba
- `tests/ok1.rs`
- `tests/ok2.rs`
- `tests/ok3.rs`
- `tests/err1.rs`
- `tests/err2.rs`
