#!/usr/bin/env bash

PROG_PATH="../../app.exe"  # ./main.out
OUT="outfile.txt"

for test in *.tst; do
    ${PROG_PATH} < ${test} > ${OUT}
    if cmp -s ${OUT} ${test}".ou"; then
        echo "Test ${test} OK"
    else
        echo "Test ${test} FAILED"
    fi
    echo
done

echo "SUCCESS"