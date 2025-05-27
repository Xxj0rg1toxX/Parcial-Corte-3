# desde aquí se llaman a otras funciones a partir de interfaces

from utilidades import limpiar
from parqueadero import mostrar_plano, registrar_vehiculo, mostrar_historial, factura

def menu_salida():
    limpiar()
    while True:
        print("---- Salida Vehículos ----")
        print("|1. Pagar                 |")
        print("|2. Regresar              |")
        print("--------------------------")
        opcion = input("Seleccione opción: ")
        if opcion == "1":
            placa = input("Ingrese la matrícula: ").upper().replace(" ", "")
            factura(placa)
        elif opcion == "2":
            return
        else:
            print("❌ Opción inválida")

def menu_principal():
    while True:
        limpiar()
        print("---------- Menú ----------")
        print("|1. Mostrar parqueadero  |")
        print("|2. Ingresar vehículo    |")
        print("|3. Salida de vehículo   |")
        print("|4. Registro             |")
        print("|5. Salir                |")
        print("--------------------------")
        opcion = input("Seleccione opción: ")
        if opcion == "1":
            mostrar_plano()
            input("Presione Enter para volver...")
        elif opcion == "2":
            registrar_vehiculo()
        elif opcion == "3":
            menu_salida()
        elif opcion == "4":
            mostrar_historial()
            input("Presione Enter para volver...")
        elif opcion == "5":
            break
        else:
            print("❌ Esa opción no se puede xd, lee bien")
