import math
print("Calcule las coordenadas de un punto a partir del angulo y radio")
g = input('Ingrese los grados: ')
r = input('Ingrese el radio: ')
grad = float(g)
grados = math.radians(grad)
radio = float(r)
x = (math.cos(grados))*radio
y = (math.sin(grados))*radio
print ("Las coordenadas son (", x, ", ", y, ")")
