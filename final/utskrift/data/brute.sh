g++ ../submissions/accepted/js.cc -o js
while true; do
    python3 gen_rand.py > in.txt
    ./js < in.txt > out1.txt
    python3 ../submissions/accepted/joshua_weird_greedy.py < in.txt > out2.txt
    diff out1.txt out2.txt || break
done
