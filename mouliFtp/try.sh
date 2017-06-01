#!/bin/bash
## try.sh for azd in /home/debrau_c/cours/psu/PSU_2016_myftp/mouliFtp
## 
## Made by debrau_c
## Login   <carl.debrauwere@epitech.eu>
## 
## Started on  Fri May 19 16:03:33 2017 debrau_c
## Last update Fri May 19 16:37:20 2017 debrau_c
##

if [ "$#" != "2" ]; then
    echo "./$0 port file [-v]"
    exit;
fi

port=$1
file=$2
line1="/bin/nc localhost $port"
line2="/bin/nc ftp.epitech.eu 21"

while read -r line
do
    echo -ne "$line" | timeout 2s $line1 > trace1
    echo -ne "$line" | timeout 2s $line2 > trace2
    $(diff trace1 trace2 > /tmp/null)
    if [ "$?" != "0" ]; then
	echo "KO"
	diff trace1 trace2
    else
	echo "OK"
    fi
done < "$file"

rm trace1 trace2
