#Funciones que seran usadas por otras, para comprobar datos o en el caso de limpiar(), para que no se llene la consola de texto
import os
import re

def limpiar():
    os.system('cls' if os.name == 'nt' else 'clear')

#Detecta si es un carro o una moto o si no existe esa matricula
def identificar_vehiculo(matricula):
    if re.fullmatch(r"[A-Z]{3}[0-9]{3}", matricula):
        return "Carro"
    elif re.fullmatch(r"[A-Z]{2}[0-9]{4}", matricula):
        return "Moto"

def vehiculo_registrado(matricula, registro):
    for i in registro:
        if i["matricula"] == matricula:
            return True
    return False