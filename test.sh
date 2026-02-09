#!/bin/bash



NUMBERS=$1
TESTS=$2

FAILED=0
TOTAL_OPS=0
MIN_OPS=-1
MAX_OPS=0

declare -A SEEN
COUNT=0

progress_bar() {
    local current=$1
    local total=$2
    local width=30

    local percent=$((100 * current / total))
    local filled=$((width * current / total))
    local empty=$((width - filled))

    printf "\r["
    printf "\e[0;32m%0.s█\e[0m" $(seq 1 $filled)
    printf "%0.s-" $(seq 1 $empty)
    printf "] %3d%% (%d/%d)" "$percent" "$current" "$total"
}


while [ $COUNT -lt $TESTS ]; do
    MAX=$(($NUMBERS - 1))
    ARG=$(shuf -i "0-$MAX" -n $NUMBERS | tr '\n' ' ')
	
    if [[ -n "${SEEN[$ARG]}" ]]; then
        continue
    fi

    SEEN[$ARG]=1
    COUNT=$((COUNT + 1))

	progress_bar $COUNT $TESTS
	#./push_swap $ARG
    RES=$( ./push_swap $ARG | wc -l)
    OPS=$(($RES - 4))

    TOTAL_OPS=$((TOTAL_OPS + OPS))

    if [ $MIN_OPS -eq -1 ] || [ $OPS -lt $MIN_OPS ]; then
        MIN_OPS=$OPS
    fi

    if [ $OPS -gt $MAX_OPS ]; then
        MAX_OPS=$OPS
    fi
done

PASSED=$((TESTS - FAILED))
PERCENT=$((100 * FAILED / TESTS))
echo "$TOTAL_OPS"
echo "$2"
if [ $PASSED -gt 0 ]; then
    AVG=$(($TOTAL_OPS / $2))
else
    AVG=0
fi

echo "Failed $FAILED/$TESTS ($PERCENT%) tests with an average of $AVG operations with values varying between $MIN_OPS-$MAX_OPS operations"
