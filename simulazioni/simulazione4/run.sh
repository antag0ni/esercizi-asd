#!/bin/bash
# Script: run.sh
# Compila, esegue e pulisce, mostrando solo l'output del programma

set -e  # Interrompe l'esecuzione se un comando fallisce

# Compila senza mostrare l'output
gcc array2.c array.c binary_tree.c dqueue.c dstack.c hashtable.c list.c main.c tinfo2.c tinfo.c -o eseguibile -lm &>/dev/null

# Pulisce lo schermo
clear

# Esegue il programma e mostra solo il suo output
./eseguibile "$@"

# Pulizia dei file temporanei senza output
rm -rf *.o eseguibile &>/dev/null
