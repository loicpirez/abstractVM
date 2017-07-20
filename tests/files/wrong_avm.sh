#!/usr/bin/env bash

. functions.sh
create_test "./abstractVM avm/overflow.avm"
create_test "./abstractVM avm/test_fail_exit.avm"
create_test "./abstractVM avm/assert_fail.avm"
