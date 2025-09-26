#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution chatgpt.py

compile gen_rand.py

samplegroup
sample sample01

group group1 100
include_group sample
tc_manual secret01
tc_manual secret02
tc_manual secret03
tc_manual secret04
tc_manual secret05
for i in {1..30}; do
    tc g1-$i gen_rand
done;
