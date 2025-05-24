# Ejercicios con Punteros a Funciones y Métodos

## Índice
1. [Ejercicios con Punteros a Funciones](#ejercicios-con-punteros-a-funciones)
2. [Ejercicios con Punteros a Métodos](#ejercicios-con-punteros-a-metodos)

## Ejercicios con Punteros a Funciones

### 1. Calculadora con Punteros a Funciones
- Implementación de una calculadora básica con operaciones aritméticas
- Uso de punteros a funciones para modularizar las operaciones
- Menú interactivo para seleccionar operaciones
- Manejo de errores (división por cero)

### 2. Sistema de Procesamiento de Texto
- Transformaciones de texto usando punteros a funciones
- Operaciones disponibles:
  - Conversión a mayúsculas
  - Conversión a minúsculas
  - Capitalización de palabras
  - Inversión de texto

### 3. Filtrado de Arrays
- Sistema de filtrado dinámico de arrays
- Criterios de filtrado:
  - Números pares
  - Números impares
  - Números primos
  - Valores mayores que un umbral
- Diseño modular usando punteros a funciones

### 4. Ordenamiento con Diferentes Algoritmos
- Implementación de varios algoritmos de ordenamiento
- Algoritmos disponibles:
  - Bubble Sort
  - Insertion Sort
  - Selection Sort
- Selección dinámica del algoritmo mediante punteros a funciones

## Ejercicios con Punteros a Métodos

### 1. Gestión de Formas Geométricas
- Clase base `Forma` con métodos para área y perímetro
- Transformaciones geométricas usando punteros a métodos
- Transformaciones disponibles:
  - Escalado
  - Rotación
  - Traslación

### 2. Sistema de Filtros para Imágenes
- Clase `Imagen` con métodos de procesamiento
- Filtros disponibles:
  - Escala de grises
  - Negativo
  - Efecto sepia
  - Detección de bordes
- Aplicación dinámica de filtros usando punteros a métodos

### 3. Gestor de Tareas con Prioridades
- Clase `GestorTareas` para manejo de tareas
- Métodos de ordenación usando punteros a métodos
- Criterios de ordenación:
  - Por fecha
  - Por prioridad
  - Por categoría
  - Por estado

## Requisitos
- Compilador C++
- Estándar C++11 o superior
- Bibliotecas estándar de C++

## Estructura del Proyecto
```
puntero_funcion/
├── calculadora_funcion.cpp
├── texto_transform.cpp
├── array_filter.cpp
├── ordenamiento.cpp
├── formas_geometricas.cpp
├── imagen_filtro.cpp
└── gestor_tareas.cpp
```

## Compilación
```bash
g++ -std=c++11 -o calculadora calculadora_funcion.cpp
g++ -std=c++11 -o texto texto_transform.cpp
g++ -std=c++11 -o filtro array_filter.cpp
g++ -std=c++11 -o orden ordenamiento.cpp
g++ -std=c++11 -o formas formas_geometricas.cpp
g++ -std=c++11 -o imagen imagen_filtro.cpp
g++ -std=c++11 -o tareas gestor_tareas.cpp
```

## Ejecución
```bash
./calculadora
./texto
./filtro
./orden
./formas
./imagen
./tareas
```
