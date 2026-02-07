MAX=$(($1-1))
ARG=$(shuf -i "0-$MAX" -n $1 | tr '\n' ' ')
echo $ARG
echo "$ARG\n" >> tests.txt
./push_swap $ARG