# Aquí se encuentran las funciones esenciales del proyecto, movimiento del vehiculo, mostrar el plano, etc.

from datetime import datetime
from config import mapa, vehiculo_pos, filas, columnas, registro
from utilidades import limpiar, identificar_vehiculo, vehiculo_registrado

def mostrar_plano():
    limpiar()
    for fila in mapa:
        print("".join(fila))
    print()

def registrar_vehiculo():
    limpiar()
    matricula = input("¿Cuál es la matrícula?: \n").upper().replace(" ", "")

    if vehiculo_registrado(matricula, registro):
        print("🚫 Ese vehículo ya está registrado en el parqueadero.")
        return

    tipo = identificar_vehiculo(matricula)
    if tipo == "Carro":
        icono = "🚗"
        zona_valida = "✅"
    elif tipo == "Moto":
        icono = "🏍️ "
        zona_valida = "🅿️"
    else:
        print("❌ Tipo de vehículo no válido.")
        return

    while True:
        x, y = vehiculo_pos
        original = mapa[x][y]
        mapa[x][y] = icono
        mostrar_plano()
        mapa[x][y] = original

        print("Controles: W=Arriba A=Izquierda S=Abajo D=Derecha Q=Salir")
        mov = input("Mover: ").upper()

        if mov == "Q":
            break

        dx, dy = {"W": (-1, 0), "S": (1, 0), "A": (0, -1), "D": (0, 1)}.get(mov, (0, 0))
        nx, ny = x + dx, y + dy

        if 0 <= nx < filas and 0 <= ny < columnas:
            celda = mapa[nx][ny].strip()
            if celda in ["⬛", "✅", "🅿️", "ℹ️", "🔚"]:
                if celda == zona_valida:
                    print(f"✅ ¡Vehículo parqueado en {nx}, {ny}!")
                    mapa[nx][ny] = icono
                    vehiculo_pos[0], vehiculo_pos[1] = 0, 9
                    hora = datetime.now()
                    registro.append({
                        "matricula": matricula,
                        "tipo": tipo,
                        "estacionamiento": [nx, ny],
                        "hora": hora
                    })
                    break
                elif celda == "✅" and icono.strip() == "🏍️":
                    print("❌ Zona para carros. No puedes parquear moto ahí.")
                elif celda == "🅿️" and icono == "🚗":
                    print("❌ Zona para motos. No puedes parquear carro ahí.")
                elif celda == "🔚":
                    print("🚪 Saliste sin estacionar.")
                    vehiculo_pos[0], vehiculo_pos[1] = 0, 9
                    break
                else:
                    vehiculo_pos[0], vehiculo_pos[1] = nx, ny
        else:
            print("❌ No puedes ir por ahí.")

def mostrar_historial():
    limpiar()
    print("Registro:\n---------------------------")
    for r in registro:
        print(f"Matrícula        : {r['matricula']}")
        print(f"Tipo de Vehículo : {r['tipo']}")
        print(f"Estacionamiento  : {r['estacionamiento']}")
        print(f"Hora de Entrada  : {r['hora'].strftime('%H:%M:%S')}")
        print("---------------------------")

def factura(matricula):
    limpiar()
    for r in registro:
        if r["matricula"] == matricula:
            hora_entrada = r['hora']
            hora_salida = datetime.now()
            tiempo = hora_salida - hora_entrada
            segundos = int(tiempo.total_seconds())
            if r["tipo"] == "carro":
                valor = segundos * 15
            else:
                valor = segundos * 10

            print("----- FACTURA -----")
            print(f"Tipo: {r['tipo']}")
            print(f"Estacionamiento: {r['estacionamiento']}")
            print(f"Entrada: {hora_entrada.strftime('%H:%M:%S')}")
            print(f"Salida: {hora_salida.strftime('%H:%M:%S')}")
            print(f"Tiempo: {segundos} segundos")
            print(f"Valor a pagar: ${valor} COP")
            print("-------------------")

            registro.remove(r)
            input("Presione Enter para volver...")
            return
    print("🚫 Vehículo no encontrado.")
