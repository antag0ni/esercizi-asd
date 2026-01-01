# Nome dell’eseguibile finale
TARGET = eseguibile

# Compilatore
CC = gcc

# Opzioni di compilazione
CFLAGS = -Wall -Wextra -O2

# Tutti i file .c nella cartella
SRC = $(wildcard *.c)

# Genera la lista dei file oggetto (.o)
OBJ = $(SRC:.c=.o)

# Regola di default: compila tutto
all: $(TARGET)

# Link finale
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

# Regola generica per compilare i .c in .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia
clean:
	rm -f $(OBJ) $(TARGET)

