#!/bin/bash
#substitution:
printf '1:2:3:4\na:b:c:d\n' | perl -p -e 's/:/-/g'
