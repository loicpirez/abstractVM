#!/usr/bin/env bash
echo "$(tput setaf 1)$(tput setab 7)Testing arguments$(tput sgr 0)"
cd files
./arguments.sh
echo "$(tput setaf 1)$(tput setab 7)Testing files access$(tput sgr 0)"
./files.sh
echo "$(tput setaf 1)$(tput setab 7)Testing parsing with correct AVM files$(tput sgr 0)"
./correct_avm.sh
echo "$(tput setaf 1)$(tput setab 7)Testing parsing with wrong AVM files$(tput sgr 0)"
./wrong_avm.sh
cd - &> /dev/null
