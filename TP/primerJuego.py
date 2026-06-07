import pygame
import random

# ==========================================
# 1. CONFIGURACIÓN INICIAL Y VENTANA
# ==========================================
pygame.init()
pygame.mixer.init()
sonido_pop = pygame.mixer.Sound("pop.mp3")
sonido_cofre = pygame.mixer.Sound("chest_open.mp3")
sonido_derrota = pygame.mixer.Sound("perdiste.mp3")

ancho = 800
alto = 500
ventana = pygame.display.set_mode((ancho, alto))
pygame.display.set_caption("Cofre de la Cripta")

# Recursos y Fuentes
cripta = pygame.image.load("crypt.jpg")

# Forzamos tamaños idénticos para evitar saltos visuales molestos
ANCHO_COFRE = 250
ALTO_COFRE = 200

cofre_cerrado_original = pygame.image.load("cofreCerrado2.jpg").convert_alpha()
cofre_cerrado = pygame.transform.scale(cofre_cerrado_original, (ANCHO_COFRE, ALTO_COFRE))

cofre_original = pygame.image.load("cofreAbierto.png").convert_alpha()
cofre_abierto = pygame.transform.scale(cofre_original, (ANCHO_COFRE, ALTO_COFRE))

game_over_original = pygame.image.load("gameOver.jpg").convert_alpha()
game_over = pygame.transform.scale(game_over_original, (ANCHO_COFRE, ALTO_COFRE))

fuente = pygame.font.Font(None, 60)

# ==========================================
# 2. DEFINICIÓN DE COLORES
# ==========================================
ROJO = (200, 0, 0)
VERDE = (0, 200, 0)
AZUL = (0, 0, 200)
AMARILLO = (200, 200, 0)
VIOLETA = (95, 0, 200)
BLANCO = (200, 200, 200)
ROSA = (255, 105, 180)
NARANJA = (255, 140, 0)
CELESTE = (0, 191, 255)

# ==========================================
# 3. COMPONENTES DE LA INTERFAZ (BOTONES/RECTS)
# ==========================================
botonNuevaPartida = pygame.Rect(190, 220, 385, 60)
botonSalir = pygame.Rect(250, 320, 280, 60)

botonFacil = pygame.Rect(300, 170, 200, 50)
botonMedio = pygame.Rect(300, 250, 200, 50)
botonDificil = pygame.Rect(300, 330, 200, 50)

# Botones laterales reubicados en Y para no pisar la pelotita celeste
botonProbar = pygame.Rect(620, 320, 140, 40)
botonBorrar = pygame.Rect(620, 370, 140, 40)

# Áreas de colisión dinámicas para las Esferas de Colores
pelotaRoja = pygame.Rect(0, 425, 50, 50)
pelotaVerde = pygame.Rect(0, 425, 50, 50)
pelotaAzul = pygame.Rect(0, 425, 50, 50)
pelotaAmarilla = pygame.Rect(0, 425, 50, 50)
pelotaVioleta = pygame.Rect(0, 425, 50, 50)
pelotaBlanca = pygame.Rect(0, 425, 50, 50)
pelotaRosa = pygame.Rect(0, 425, 50, 50)
pelotaNaranja = pygame.Rect(0, 425, 50, 50)
pelotaCeleste = pygame.Rect(0, 425, 50, 50)

# ==========================================
# 4. VARIABLES DE ESTADO DEL JUEGO
# ==========================================
pantalla = "menu"
nivel = ""
clave = []
seleccion = []
historial = []

aciertos = 0
intentos = 0
mensaje = ""
juegoTerminado = False

# ==========================================
# 5. BUCLE PRINCIPAL DEL JUEGO (GAME LOOP)
# ==========================================
run = True
while run:

    # --------------------------------------
    # A. MANEJO DE EVENTOS (INPUTS)
    # --------------------------------------
    for event in pygame.event.get():

        if event.type == pygame.QUIT:
            run = False

        if event.type == pygame.MOUSEBUTTONDOWN:

            # Eventos: Menú Principal
            if pantalla == "menu":
                if botonNuevaPartida.collidepoint(event.pos):
                    pantalla = "dificultad"
                elif botonSalir.collidepoint(event.pos):
                    run = False

            # Eventos: Selección de Dificultad
            elif pantalla == "dificultad":
                if botonFacil.collidepoint(event.pos):
                    clave = [random.randint(1, 3), random.randint(1, 3), random.randint(1, 3)]
                    nivel = "facil"
                    pantalla = "juego"
                    
                    pelotaRoja.x, pelotaVerde.x, pelotaAzul.x = 295, 375, 455
                    pelotaAmarilla.x = pelotaVioleta.x = pelotaBlanca.x = -100
                    pelotaRosa.x = pelotaNaranja.x = pelotaCeleste.x = -100
                    
                    seleccion.clear()
                    historial.clear()
                    intentos = aciertos = 0
                    mensaje = ""
                    juegoTerminado = False
                    print("Clave Fácil creada:", clave)

                elif botonMedio.collidepoint(event.pos):
                    clave = [random.randint(1, 6), random.randint(1, 6), random.randint(1, 6)]
                    nivel = "medio"
                    pantalla = "juego"
                    
                    pelotaRoja.x, pelotaVerde.x, pelotaAzul.x = 195, 265, 335
                    pelotaAmarilla.x, pelotaVioleta.x, pelotaBlanca.x = 405, 475, 545
                    pelotaRosa.x = pelotaNaranja.x = pelotaCeleste.x = -100
                    
                    seleccion.clear()
                    historial.clear()
                    intentos = aciertos = 0
                    mensaje = ""
                    juegoTerminado = False
                    print("Clave Medio creada:", clave)

                elif botonDificil.collidepoint(event.pos):
                    clave = [random.randint(1, 9), random.randint(1, 9), random.randint(1, 9)]
                    nivel = "dificil"
                    pantalla = "juego"
                    
                    pelotaRoja.x, pelotaVerde.x, pelotaAzul.x = 130, 190, 250
                    pelotaAmarilla.x, pelotaVioleta.x, pelotaBlanca.x = 310, 370, 430
                    pelotaRosa.x, pelotaNaranja.x, pelotaCeleste.x = 490, 550, 610
                    
                    seleccion.clear()
                    historial.clear()
                    intentos = aciertos = 0
                    mensaje = ""
                    juegoTerminado = False
                    print("Clave Difícil creada:", clave)

            # Eventos: Dentro del Juego
            elif pantalla == "juego":
                if len(seleccion) < 3 and not juegoTerminado:
                    if pelotaRoja.collidepoint(event.pos):
                        seleccion.append(1)
                    elif pelotaVerde.collidepoint(event.pos):
                        seleccion.append(2)
                    elif pelotaAzul.collidepoint(event.pos):
                        seleccion.append(3)
                    elif pelotaAmarilla.collidepoint(event.pos) and nivel != "facil":
                        seleccion.append(4)
                    elif pelotaVioleta.collidepoint(event.pos) and nivel != "facil":
                        seleccion.append(5)
                    elif pelotaBlanca.collidepoint(event.pos) and nivel != "facil":
                        seleccion.append(6)
                    elif pelotaRosa.collidepoint(event.pos) and nivel == "dificil":
                        seleccion.append(7)
                    elif pelotaNaranja.collidepoint(event.pos) and nivel == "dificil":
                        seleccion.append(8)
                    elif pelotaCeleste.collidepoint(event.pos) and nivel == "dificil":
                        seleccion.append(9)
                    
                    sonido_pop.play()
                    print(seleccion)

                # Botón Confirmar Combinación
                if botonProbar.collidepoint(event.pos) and not juegoTerminado:
                    if len(seleccion) == 3 and len(clave) == 3:
                        intentos += 1
                        aciertos = 0

                        for i in range(3):
                            if seleccion[i] == clave[i]:
                                aciertos += 1

                        if aciertos == 3:
                            mensaje = "COFRE ABIERTO"
                            sonido_cofre.play()
                            juegoTerminado = True
                        elif intentos == 8:
                            mensaje = "FALLASTE"
                            sonido_derrota.play()
                            juegoTerminado = True

                        historial.append(seleccion.copy())
                        seleccion.clear()

                # Botón Borrar Selección
                if botonBorrar.collidepoint(event.pos):
                    seleccion.clear()

    # --------------------------------------
    # B. DIBUJO Y RENDERIZADO (GRAFICOS)
    # --------------------------------------
    ventana.blit(cripta, (0, 0))

    # Renderizado: Menú Principal
    if pantalla == "menu":
        pygame.draw.rect(ventana, (100, 100, 100), botonNuevaPartida)
        pygame.draw.rect(ventana, (100, 100, 100), botonSalir)

        txtNueva = fuente.render("NUEVA PARTIDA", True, (0, 0, 0))
        txtSalir = fuente.render("SALIR", True, (0, 0, 0))

        ventana.blit(txtNueva, (210, 230))
        ventana.blit(txtSalir, (330, 330))

    # Renderizado: Selección de Dificultad
    elif pantalla == "dificultad": 
        textoDificultad = fuente.render("ELIJA DIFICULTAD", True, (255, 255, 255))
        ventana.blit(textoDificultad, (180, 80))

        pygame.draw.rect(ventana, (0, 200, 0), botonFacil)
        pygame.draw.rect(ventana, (200, 200, 0), botonMedio)
        pygame.draw.rect(ventana, (200, 0, 0), botonDificil)

        textoFacil = fuente.render("FACIL", True, (0, 0, 0))
        textoMedio = fuente.render("MEDIO", True, (0, 0, 0))
        textoDificil = fuente.render("DIFICIL", True, (0, 0, 0))

        ventana.blit(textoFacil, (340, 175))
        ventana.blit(textoMedio, (335, 255))
        ventana.blit(textoDificil, (330, 335))
    
    # Renderizado: Interfaz del Juego activo
    elif pantalla == "juego":

        # Dibujar esferas inferiores dinámicamente según el nivel
        if nivel == "facil":
            pygame.draw.circle(ventana, ROJO, (320, 450), 25)
            pygame.draw.circle(ventana, VERDE, (400, 450), 25)
            pygame.draw.circle(ventana, AZUL, (480, 450), 25)
            
        elif nivel == "medio":
            pygame.draw.circle(ventana, ROJO, (220, 450), 25)
            pygame.draw.circle(ventana, VERDE, (290, 450), 25)
            pygame.draw.circle(ventana, AZUL, (360, 450), 25)
            pygame.draw.circle(ventana, AMARILLO, (430, 450), 25)
            pygame.draw.circle(ventana, VIOLETA, (500, 450), 25)
            pygame.draw.circle(ventana, BLANCO, (570, 450), 25)

        elif nivel == "dificil":
            pygame.draw.circle(ventana, ROJO, (155, 450), 25)
            pygame.draw.circle(ventana, VERDE, (215, 450), 25)
            pygame.draw.circle(ventana, AZUL, (275, 450), 25)
            pygame.draw.circle(ventana, AMARILLO, (335, 450), 25)
            pygame.draw.circle(ventana, VIOLETA, (395, 450), 25)
            pygame.draw.circle(ventana, BLANCO, (455, 450), 25)
            pygame.draw.circle(ventana, ROSA, (515, 450), 25)
            pygame.draw.circle(ventana, NARANJA, (575, 450), 25)
            pygame.draw.circle(ventana, CELESTE, (635, 450), 25)

        # Dibujar botones de acción lateral (Subidos y Ajustados)
        pygame.draw.rect(ventana, (180, 180, 180), botonBorrar)
        textoBorrar = pygame.font.Font(None, 30).render("BORRAR", True, (0, 0, 0))
        ventana.blit(textoBorrar, (645, 380))

        pygame.draw.rect(ventana, (180, 180, 180), botonProbar)
        # Cambiado a "CONFIRMAR" y centrado moviendo la X a 632
        textoConfirmar = pygame.font.Font(None, 30).render("CONFIRMAR", True, (0, 0, 0))
        ventana.blit(textoConfirmar, (632, 330))

        # Textos informativos de estado
        textoAciertos = pygame.font.Font(None, 40).render(f"Aciertos: {aciertos}", True, (255, 255, 255))
        ventana.blit(textoAciertos, (20, 20))

        textoIntentos = pygame.font.Font(None, 40).render(f"Intentos: {intentos}/8", True, (255, 255, 255))
        ventana.blit(textoIntentos, (20, 60))

        textoMensaje = pygame.font.Font(None, 10).render(mensaje, True, (255, 255, 255))
        ventana.blit(textoMensaje, (365, 250))

        # Dibujar combinación actual que el usuario está armando
        for i in range(len(seleccion)):
            x = 250 + (i * 70)
            color_actual = seleccion[i]
            if color_actual == 1: pygame.draw.circle(ventana, ROJO, (x, 100), 25)
            elif color_actual == 2: pygame.draw.circle(ventana, VERDE, (x, 100), 25)
            elif color_actual == 3: pygame.draw.circle(ventana, AZUL, (x, 100), 25)
            elif color_actual == 4: pygame.draw.circle(ventana, AMARILLO, (x, 100), 25)
            elif color_actual == 5: pygame.draw.circle(ventana, VIOLETA, (x, 100), 25)
            elif color_actual == 6: pygame.draw.circle(ventana, BLANCO, (x, 100), 25)
            elif color_actual == 7: pygame.draw.circle(ventana, ROSA, (x, 100), 25)
            elif color_actual == 8: pygame.draw.circle(ventana, NARANJA, (x, 100), 25)
            elif color_actual == 9: pygame.draw.circle(ventana, CELESTE, (x, 100), 25)

        # Dibujar el historial de intentos anteriores
        y = 100
        for i in range(len(historial)):
            x = 20
            texto_num = pygame.font.Font(None, 30).render(str(i+1) + ":", True, (255, 255, 255))
            ventana.blit(texto_num, (x, y))
            x += 30

            for color in historial[i]:
                if color == 1: pygame.draw.circle(ventana, ROJO, (x, y+10), 10)
                elif color == 2: pygame.draw.circle(ventana, VERDE, (x, y+10), 10)
                elif color == 3: pygame.draw.circle(ventana, AZUL, (x, y+10), 10)
                elif color == 4: pygame.draw.circle(ventana, AMARILLO, (x, y+10), 10)
                elif color == 5: pygame.draw.circle(ventana, VIOLETA, (x, y+10), 10)
                elif color == 6: pygame.draw.circle(ventana, BLANCO, (x, y+10), 10)
                elif color == 7: pygame.draw.circle(ventana, ROSA, (x, y+10), 10)
                elif color == 8: pygame.draw.circle(ventana, NARANJA, (x, y+10), 10)
                elif color == 9: pygame.draw.circle(ventana, CELESTE, (x, y+10), 10)
                x += 25
            y += 30

        # ==========================================
        # CONTROL VISUAL DE VICTORIA / DERROTA
        # ==========================================
        if juegoTerminado:
            if mensaje == "COFRE ABIERTO":
                # Victoria: Muestra el cofre abierto
                ventana.blit(cofre_abierto, (275, 170))
            
            elif mensaje == "FALLASTE":
                # Derrota: Mostramos tu imagen descargada centrada
                # (800 // 2 - 300 // 2) = 250 en X | En Y la ponemos a la misma altura que el cofre
                ventana.blit(game_over, (270, 160))
                
                # Dejamos la clave abajo en chiquito para que el jugador sepa cuál era
                fuente_revelar = pygame.font.Font(None, 30)
                txt_revelar = fuente_revelar.render(f"La clave era: {clave}", True, (200, 200, 200))
                ventana.blit(txt_revelar, (298, 340))
        else:
            # Si el juego sigue activo, el cofre se queda cerrado normal
            ventana.blit(cofre_cerrado, (275, 170))

    pygame.display.flip()

pygame.quit()
