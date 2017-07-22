#!/usr/bin/env bash

. functions.sh

create_test "./abstractVM files" #Dossier
create_test "./abstractVM files/fichier_non_existant"
create_test "./abstractVM files/fichier_vide"
create_test "./abstractVM files/fichier_sans_droits"
create_test "./abstractVM files/fichier_no_read"
