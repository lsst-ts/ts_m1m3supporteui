#!/usr/bin/bash

cd /opt/CODE/builds/ts_M1M3SupportEUI
currentDirectory=$(pwd)

gnome-terminal --geometry 120x80+240+0 --window-with-profile=MONITOR -e "$currentDirectory"/scripts/startMonitor.sh

gnome-terminal --geometry 120x15+360+0 --window-with-profile=EFD -e "$currentDirectory"/scripts/efdWriterCommands.sh
gnome-terminal --geometry 120x15+360+20--window-with-profile=EFD -e "$currentDirectory"/scripts/efdWriterEvents.sh
gnome-terminal --geometry 120x15+360+40 --window-with-profile=EFD -e "$currentDirectory"/scripts/efdWriterTelemetry.sh

"$currentDirectory"/M1M3SupportEUI

