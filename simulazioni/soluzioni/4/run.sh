#!/bin/bash
# Script: run.sh
# Compila, esegue e pulisce, mostrando solo l'output del programma

set -e  # Interrompe l'esecuzione se un comando fallisce

# Compila senza mostrare l'output
make &>/dev/null

# Pulisce lo schermo
clear

# Esegue il programma e mostra solo il suo output
./eseguibile "$@"

# Pulizia dei file temporanei senza output
make clean &>/dev/null
