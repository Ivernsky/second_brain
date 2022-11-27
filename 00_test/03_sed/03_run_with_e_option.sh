#!/bin/bash
#1
sed -n -e '/^root/ p' -e '/^nobody/ p' /etc/passwd

#2
sed -n \
-e '/^root/ p' \
-e '/^nobody/ p' \
/etc/passwd

#3
sed -n '{
    /^root/ p
    /^nobody/ p
}' /etc/passwd
