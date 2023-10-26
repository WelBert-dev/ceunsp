#!/bin/bash

# Data fornecida como argumento
data=$1

# Verifica se a data foi fornecida como argumento
if [ -z "$data" ]; then
    echo "Erro: Forneça a data como argumento (exemplo: $0 20231025)"
    exit 1
fi

# Cria o arquivo de log
echo "Criando arquivo de log..."
log="log.txt"
touch "$log"

# Loop para criar as pastas
for i in {1..10}; do
    nome_pasta="Pasta${i}_${data}"
    
    if [ -d "$nome_pasta" ]; then
        echo "Pasta $nome_pasta já existe" | tee -a "$log"
    else
        mkdir "$nome_pasta"
        echo "Criando pasta $nome_pasta" | tee -a "$log"
    fi
done

echo "Operação concluída. Verifique o arquivo de log $log para mais detalhes."

