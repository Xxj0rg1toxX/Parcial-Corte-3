# Aclaracion
Hay 2 archivos de pokemon, v1 y v2, la v1 es la version inicial y completamente funcional, con 2 pokemon, 3 ataques, efectos de estado y combate por turnos mientras que la v2 es la version mas compleja y mas grande pero con algunos problemas en la implementacion de los efectos de estado y la separacion por headers y el combate por turnos esta dividido en etapas diferentes, en las que se elige un ataque y se ejecuta de una vez, queda a su criterio la calificacion de esta parte del proyecto ya que en la v2 quisimos ir mas alla de lo solicitado pero por falta de conocimiento se nos hizo complicado implementar estas funcionalidades.

# Cambios implementados pokemonv1

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

---


# Cambios implementados pokemonv2-AVANZADO

# Descripción General

Este proyecto implementa un sistema de combate Pokémon completo con todas las mecánicas principales de los juegos originales simulando la mitica batalla de los personajes principales "Red y Blue" usando sus pokemon caracterizticos. Incluye equipos de 6 Pokémon, sistema de tipos, estadísticas y un sistema de combate por turnos completo, con cambios de pokemon en combate y al momento de que son debilitados.

# 1. Sistema de Tipos Completo

Propósito

- Para recrear fielmente las relaciones de efectividad entre los 18 tipos Pokémon, añadiendo profundidad estratégica al combate.

Justificación

- El sistema de tipos es fundamental en Pokémon, donde las ventajas/desventajas pueden cambiar completamente el curso de una batalla.

Implementación

- Tabla de efectividad con mapas anidados (map<string, map<string, float>>)

- Función obtenerEfectividad() que calcula multiplicadores combinados

- Mensajes de "super efectivo" o "no muy efectivo" basados en el resultado

# 2. Sistema de Estadísticas Completo

Propósito

- Para simular con precisión cómo funcionan las estadísticas (Ataque, Defensa, etc.) en los juegos originales, incluyendo modificadores de etapa.

Justificación

- Las estadísticas y sus modificadores son cruciales para el balance del juego y las estrategias competitivas.

Implementación

- Sistema de etapas (-6 a +6) que modifican stats

- Tabla de multiplicadores para cada nivel de etapa

- Método getStat() que calcula el valor final considerando etapas

# 3. Equipos de 6 Pokémon

Propósito

- Para permitir combates más largos y estratégicos, similares a los juegos principales.

Justificación

- Los equipos completos son esenciales para la experiencia Pokémon auténtica.

Implementación

- Clase Jugador gestiona un equipo de 6 Pokémon

- Sistema de cambio de Pokémon durante el combate

- Forzar cambio cuando un Pokémon es debilitado

# 4. Sistema de Combate por Velocidad

Propósito

- Para determinar el orden de turnos basado en la velocidad de los Pokémon.

Justificación

- La velocidad es una mecánica clave que añade capas estratégicas al combate.

Implementación

- Comparación de stats de velocidad al inicio de cada ronda

- Movimientos con prioridad que ignoran la velocidad

- Turnos alternados basados en esta comparación


