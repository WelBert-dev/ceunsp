#!/bin/bash
# ----------------------------------------------------------------------------------------
# Script   :
# Descrição:
# Versão   : 0.1
# Autor    : Wellison Bertelli <wellison.bertelli@hotmail.com>
# Data     : 03/08/2021
# Licença  : GNU/GPL v3.0
# ----------------------------------------------------------------------------------------
# Uso:
# ----------------------------------------------------------------------------------------

clear

read -p "Nota da PRIMEIRA prova: " n1
read -p "Nota da PRIMEIRA prova: " n2
read -p "Nota da PRIMEIRA prova: " n3
read -p "Nota da PRIMEIRA prova: " n4

declare -i n1 n2 n3 n4

soma=$(($n1+$n2+$n3+$n4))

media=$(($soma/4))

echo "A Média do Aluno foi: $media"

[[ $media -le 5  ]] && echo "Nota bem COCO estuda mais!! animal"

[[ $media -gt 5 && $media -lt 7 ]] && echo "Nota abaixo da média! ;-;"

[[ $media -ge 7 ]] && echo "Nota ÓTIMA!! PARABÉNS!"


