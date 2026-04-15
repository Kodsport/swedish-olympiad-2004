#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../../testdata_tools/gen.sh

use_solution raunak.cpp

compile gen.py

samplegroup
sample 1
sample 2

group g1 30
limits mode="vowel"
tc vowel-01 gen N=3 mode="vowel"
tc vowel-02 gen N=10 mode="vowel"
tc vowel-03 gen N=20 mode="vowel"
tc vowel-04 gen mode="vowel"
tc vowel-05 gen mode="vowel"
tc vowel-06 gen mode="vowel"

group g2 70
include_group sample
tc small-01 gen N=3
tc small-02 gen N=5
tc small-03 gen N=10
tc small-04 gen N=10
tc small-05 gen N=15
tc small-06 gen N=20
tc small-07 gen 
tc small-08 gen 
tc small-09 gen 
tc small-10 gen 
tc_manual ../manual_testdata/skolkval1.in
tc_manual ../manual_testdata/skolkval2.in
tc_manual ../manual_testdata/skolkval3.in

