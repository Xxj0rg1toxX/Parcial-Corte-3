Descripción del Proyecto
Este sistema de gestión de parqueaderos es una aplicación desarrollada en Python que simula las operaciones fundamentales de un estacionamiento vehicular, incluyendo el registro de entradas y salidas, cálculo de tarifas y visualización del estado actual del parqueadero.

Características Principales
1. Navegación Visual Interactiva
Propósito
Implementar una interfaz que permita al usuario seleccionar interactivamente el espacio de estacionamiento para cada vehículo.

Justificación

Simula el proceso real de estacionamiento mejorando la experiencia del usuario

Facilita la comprensión espacial del diseño del parqueadero

Garantiza que los vehículos solo ocupen espacios designados como válidos

Implementación

Matriz bidimensional que representa el plano del parqueadero

Sistema de coordenadas con controles direccionales (WASD)

Validación en tiempo real de las posiciones permitidas

2. Sistema de Zonificación Diferenciada
Propósito
Gestionar de manera separada los espacios para automóviles y motocicletas.

Justificación

Optimización del espacio disponible

Prevención de conflictos entre diferentes tipos de vehículos

Organización lógica del área de estacionamiento

Implementación

Identificación del tipo de vehículo mediante patrones de matrícula

Designación de áreas específicas para cada tipo de vehículo

Validación de ubicaciones permitidas durante el proceso de estacionamiento

3. Módulo de Facturación Automatizado
Propósito
Calcular automáticamente los cargos por tiempo de estacionamiento.

Justificación

Eliminación de errores en cálculos manuales

Transparencia en el proceso de cobro

Mantenimiento de registros históricos completos

Implementación

Registro preciso de marcas temporales (entrada/salida)

Cálculo de duración de estancia en segundos

Aplicación de tarifas diferenciadas por tipo de vehículo

4. Visualización en Tiempo Real
Propósito
Mostrar el estado actual de ocupación del parqueadero.

Justificación

Información inmediata sobre disponibilidad de espacios

Soporte para la toma de decisiones operativas

Retroalimentación visual de las acciones realizadas

Implementación

Representación matricial del plano del parqueadero

Actualización dinámica del estado de ocupación

Distinción clara entre espacios disponibles y ocupados
