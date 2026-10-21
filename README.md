# Aplicación: Sistema Inteligente de Pedidos de Cafetería

## Descripción del Problema
En una cafetería tradicional, calcular precios personalizados con múltiples ingredientes opcionales y notificar el estado del pedido a los clientes mediante `if-else` masivos genera código rígido, difícil de mantener y propenso a errores al añadir nuevas bebidas o estados.

------------------------------------------------------------------------------------------------------------------------------------------

## Patrones de Diseño Elegidos
1. **Creacional (Factory Method):** Encapsula la lógica de instanciación para la creación inicial de las bebidas base (Espresso o Té) desacoplando el código cliente.
2. **Estructural (Decorator):** Permite envolver dinámicamente el objeto bebida para añadir modificadores (leche, extra shot) modificando el costo y la descripción de forma limpia sin crear subclases infinitas.
3. **De comportamiento (Observer):** Notifica automáticamente al cliente cada vez que el estado del pedido cambia (*En preparación*, *Listo*), manteniendo la separación de responsabilidades.

------------------------------------------------------------------------------------------------------------------------------------------

Salida Esperada en Consola
=== SISTEMA DE GESTION DE CAFETERIA ===

[1] Creando bebida base...
[2] Agregando modificadores (Decorador)...
Detalle final: Cafe Espresso, con Leche Deslactosada, con Extra Shot de Cafe
Costo total: $8.5

[3] Iniciando proceso de preparacion (Observer)...
[Notificacion para Carlos]: Tu pedido ahora esta En preparacion
[Notificacion para Carlos]: Tu pedido now esta Listo para retirar en barra

------------------------------------------------------------------------------------------------------------------------------------------

## Instrucciones para Compilar y Ejecutar (C++)
Compilar usando g++:
```bash
g++ -std=c++17 cafeteria.cpp -o cafeteria
./cafetería
```


------------------------------------------------------------------------------------------------------------------------------------------





## integrantes de grupo:
#-JHOHAN ANDRES VASQUEZ MUÑOZ
#-JUAN FELIPE HERNANDEZ PINZON
#-VALERI CASTILLO GALLEGO
