read -p "Enter a line number: " lines
sed -e "s/{{LINES}}/$((lines * 64 + 64))/" template.cpp > auto.cpp
g++ -m32 -o busy auto.cpp
./run.sh
kitten transfer short_udat.txt Apps/Git/SMT/auto.dat
