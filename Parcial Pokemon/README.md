# Aclaracion
Hay 2 archivos de pokemon, v1 y v2, la v1 es la version inicial y completamente funcional, con 2 pokemon, 3 ataques, efectos de estado y combate por turnos mientras que la v2 es la version mas compleja y mas grande pero con algunos problemas en la implementacion del cambio de los pokemon cuando son debilitados y faltando los efectos de estado, queda a su criterio la calificacion de esta parte del proyecto ya que en la v2 quisimos ir mas alla de lo solicitado pero por falta de conocimiento se nos hizo complicado implementar estas funcionalidades.

# Cambios implementados archivo pokemonv1

# Descripción General

Este proyecto implementa un sistema de combate Pokémon por turnos en C++, inspirado en los juegos originales de Game Freak. El programa simula una batalla entre dos Pokémon con diferentes ataques, efectos de estado y mecánicas de combate.

# 1. Sistema de Efectos de Estado

Propósito

- Para añadir profundidad estratégica al combate, permitiendo que ciertos ataques tengan efectos persistentes más allá del daño inmediato.

Propósito

- Los efectos de estado son una parte fundamental de los combates Pokémon reales, añadiendo capas de estrategia y variabilidad a las batallas.

Propósito

- Se creó un enum Estado con posibles condiciones (actualmente solo quemado)

- Se añadió el método aplicarEfectoEstado() que se ejecuta cada turno

- Los ataques pueden infligir estados con cierta probabilidad (ej: Ascuas tiene 15% de quemar)

# 2. Ataques con Efectos Secundarios

Propósito

- Para diversificar las opciones tácticas disponibles para cada Pokémon.

Justificación

- En los juegos originales, muchos ataques tienen efectos adicionales que los hacen únicos, no solo varían en daño.

Implementación

- Se extendió la clase Ataque con propiedades para efectos especiales:

- drenado: recupera vida igual al 50% del daño

- quemar: probabilidad de infligir quemadura

- retroceder: hace perder un turno al oponente

- bprecision: reduce la precisión del rival

# 3. Modificadores de Precisión

Propósito

- Para simular cómo ciertos ataques pueden afectar estadísticas de combate durante la batalla.

Justificación

- Esto añade otra capa estratégica donde los jugadores pueden priorizar debilitar al oponente en lugar de solo hacer daño directo.

Implementación

- Cada Pokémon tiene un modPrecision que afecta sus ataques

- Ataques como "Bofetón Lodo" reducen este modificador

- La precisión se verifica contra este modificador al atacar

# 4. Mecánica de Retroceso

Propósito

- Para añadir un efecto de control que puede hacer perder turnos al oponente.

Justificación

- Proporciona una alternativa estratégica a los ataques puramente ofensivos o curativos.

Implementación

- Ataques como Mordisco tienen probabilidad de hacer retroceder

- El flag retrocedido hace que el Pokémon afectado pierda su siguiente turno

# 5. Sistema de Críticos

Propósito

- Para añadir un elemento de aleatoriedad controlada que puede cambiar el curso de la batalla.

Justificación

- Los golpes críticos son un elemento clásico de los juegos Pokémon que añaden emoción al combate.


Implementación

- Cada ataque tiene una probabilidad de crítico (critico)

- Los golpes críticos hacen el doble de daño

- Se muestra un mensaje especial cuando ocurre
