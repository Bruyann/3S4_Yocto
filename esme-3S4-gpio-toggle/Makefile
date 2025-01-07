CFLAGS += $(shell pkg-config --cflags libgpiod)
LDLIBS += $(shell pkg-config --libs libgpiod)

INSTALL_DIR ?= ./.install
BIN = esme-gpio-toggle

# Cible par défaut pour construire l'exécutable
all: $(BIN)

# Compilation de l'exécutable
$(BIN): gpio-toggle.c
	gcc $(CFLAGS) -o $(BIN) gpio-toggle.c $(LDLIBS)

# Installation de l'exécutable
install: $(BIN)
	mkdir -p $(INSTALL_DIR)/usr/bin
	cp $(BIN) $(INSTALL_DIR)/usr/bin/

# Nettoyage des fichiers générés
clean:
	rm -f $(BIN) *.o
