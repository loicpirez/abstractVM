#!/usr/bin/env bash

print_red(){
    echo -e "\e[41m$@\e[49m"
}

print_blue(){
    echo -e "\e[44m$@\e[49m"
}

print_green(){
    echo -e "\e[44m$@\e[49m"
}

check_return(){
    if [ "$@" -eq "84" ]; then
        print_red "ERROR!"
    else
        print_green "OK"
    fi
}

separator(){
    echo -e "\n"
}

create_test(){
    print_blue $@
    bash -c "$@"
    check_return $?
    separator
}
