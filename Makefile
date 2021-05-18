NOMBRE_PROYECTO = Chancla

PRODUCTO = producto
BINARIO = $(PRODUCTO)/binario
DIR_RECURSOS = recursos

CC = g++
LBANDERAS = -O
CBANDERAS = -c -Wall -Wextra -std=c++17
LIBS = -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image
RECURSOS = texturas/chanclas.png
DEBUG =

MODULOS = motor  objetos estadojuego
# Directorios donde estan todo el codigo fuente
DIRS_CODIGO = codigo $(addprefix codigo/, $(MODULOS))

# Directorios donde se guarda los archivos compilados
DIRS_PRODUCTO = $(PRODUCTO) $(BINARIO) $(addprefix $(PRODUCTO)/, $(MODULOS))

# Por cada directorio donde esta el codigo, obtenemos todos los .cpp
CODIGO = $(foreach cdir, $(DIRS_CODIGO), $(wildcard $(cdir)/*.cpp))
OBJETOS = $(patsubst codigo/%.cpp, $(PRODUCTO)/%.o, $(CODIGO))

vpath %.cpp $(DIRS_CODIGO)

all: imprimir $(DIRS_PRODUCTO) $(RECURSOS) compilar

imprimir:
	@echo
	@echo MODULOS: $(MODULOS)
	@echo DIRS_CODIGO: $(DIRS_CODIGO)
	@echo DIRS_PRODUCTO: $(DIRS_PRODUCTO)
	@echo CODIGO: $(CODIGO)
	@echo OBJETOS: $(OBJETOS)
	@echo	

$(DIRS_PRODUCTO):
	mkdir -p $@

compilar: $(OBJETOS)
	$(CC) $(DEBUG) $(OBJETOS) $(LIBS) $(LBANDERAS) -o  $(BINARIO)/$(NOMBRE_PROYECTO)

producto/%.o: codigo/%.cpp
	$(CC) $(CBANDERAS) $< -o $@

$(RECURSOS):
	cp -R $(DIR_RECURSOS)/$@ $(BINARIO)


limpiar:
	rm -rf $(PRODUCTO)


