#!/bin/bash
#filtering
printf 'gate\napple\nwhat\nkite\n' | perl -ne 'print if /at/'

#substitution:
printf '1:2:3:4\na:b:c:d\n' | perl -p -e 's/:/-/g'

# with backup
#perl -i.bkp -pe 's/bule/-green-/' colors.txt
# with prefix backup name
#perl -i'bkp.*' -pe 's/bule/-green-/' colors.txt
# backup in directory
#perl -i'backups/*' -pe 's/bule/-green-/' colors.txt
