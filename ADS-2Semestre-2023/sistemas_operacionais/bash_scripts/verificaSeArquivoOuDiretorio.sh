#!/bin/bash
# ----------------------------------------------------------------------------------------
# Script   :
# Descrição:
# Versão   : 0.1
# Autor    : Wellison Bertelli <wellison.bertelli@hotmail.com>
# Data     : 03/08/2021
# Licença  : GNU/GPL v3.0
# ----------------------------------------------------------------------------------------
# Uso: Ve se o nome passado no argumento é arquivo ou diretório
# ----------------------------------------------------------------------------------------

clear

if [ -f $1 ]: then 
	echo $1 é um arquivo
else  
	echo $1 é um diretório
fi


