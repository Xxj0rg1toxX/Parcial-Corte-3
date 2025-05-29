# Aclaracion
Hay 2 archivos de pokemon, v1 y v2, la v1 es la version inicial y completamente funcional, con 2 pokemon, 3 ataques, efectos de estado y combate por turnos mientras que la v2 es la version mas compleja y mas grande pero con algunos problemas en la implementacion del cambio de los pokemon cuando son debilitados y faltando los efectos de estado, queda a su criterio la calificacion de esta parte del proyecto ya que en la v2 quisimos ir mas alla de lo solicitado pero por falta de conocimiento se nos hizo complicado implementar estas funcionalidades.

# Cambios implementados archivo pokemonv1

Descripción General
Este proyecto implementa un sistema de combate Pokémon por turnos en C++, inspirado en los juegos originales de Game Freak. El programa simula una batalla entre dos Pokémon con diferentes ataques, efectos de estado y mecánicas de combate.

- Innovaciones Implementadas

1. Sistema de Efectos de Estado

¿Para qué se implementó?
Para añadir profundidad estratégica al combate, permitiendo que ciertos ataques tengan efectos persistentes más allá del daño inmediato.

¿Por qué se consideró necesario?
Los efectos de estado son una parte fundamental de los combates Pokémon reales, añadiendo capas de estrategia y variabilidad a las batallas.

¿Cómo se implementó?

Se creó un enum Estado con posibles condiciones (actualmente solo quemado)

Se añadió el método aplicarEfectoEstado() que se ejecuta cada turno

Los ataques pueden infligir estados con cierta probabilidad (ej: Ascuas tiene 15% de quemar)

2. Ataques con Efectos Secundarios

¿Para qué se implementó?
Para diversificar las opciones tácticas disponibles para cada Pokémon.

¿Por qué se consideró necesario?
En los juegos originales, muchos ataques tienen efectos adicionales que los hacen únicos, no solo varían en daño.

¿Cómo se implementó?

Se extendió la clase Ataque con propiedades para efectos especiales:

drenado: recupera vida igual al 50% del daño

quemar: probabilidad de infligir quemadura

retroceder: hace perder un turno al oponente

bprecision: reduce la precisión del rival

3. Modificadores de Precisión

¿Para qué se implementó?
Para simular cómo ciertos ataques pueden afectar estadísticas de combate durante la batalla.

¿Por qué se consideró necesario?
Esto añade otra capa estratégica donde los jugadores pueden priorizar debilitar al oponente en lugar de solo hacer daño directo.

¿Cómo se implementó?

Cada Pokémon tiene un modPrecision que afecta sus ataques

Ataques como "Bofetón Lodo" reducen este modificador

La precisión se verifica contra este modificador al atacar

4. Mecánica de Retroceso

¿Para qué se implementó?
Para añadir un efecto de control que puede hacer perder turnos al oponente.

¿Por qué se consideró necesario?
Proporciona una alternativa estratégica a los ataques puramente ofensivos o curativos.

¿Cómo se implementó?

Ataques como Mordisco tienen probabilidad de hacer retroceder

El flag retrocedido hace que el Pokémon afectado pierda su siguiente turno

5. Sistema de Críticos

¿Para qué se implementó?
Para añadir un elemento de aleatoriedad controlada que puede cambiar el curso de la batalla.

¿Por qué se consideró necesario?
Los golpes críticos son un elemento clásico de los juegos Pokémon que añaden emoción al combate.

¿Cómo se implementó?

Cada ataque tiene una probabilidad de crítico (critico)

Los golpes críticos hacen el doble de daño

Se muestra un mensaje especial cuando ocurre
