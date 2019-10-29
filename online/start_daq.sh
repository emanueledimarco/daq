#!/bin/sh

. setup.sh

./kill_daq.sh

odbedit -c clean
#odbedit -c "rm /Analyzer/Trigger/Statistics"
#odbedit -c "rm /Analyzer/Scaler/Statistics"

mhttpd --http 8081 -D
sleep 2
xterm -e ./cygnus_fe &
xterm -e ../analyzer/cyganalyzer.exe -i ../analyzer/romeConfig.xml &
mlogger -D

echo Please point your web browser to http://localhost:8081
echo Or run: mozilla http://localhost:8081 &
echo To look at live histograms, run: roody -Hlocalhost

#end file
