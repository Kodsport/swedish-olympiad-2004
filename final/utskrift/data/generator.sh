#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution gemini.py

compile gen_rand.py

samplegroup
sample sample01

group group1 100
include_group sample
tg_manual ../manual_data
for i in {1..15}; do
    tc g1-$i gen_rand mode=random
done

for i in {16..30}; do
    tc g1-$i gen_rand mode=max
done
