#!/bin/sh
echo "EFD Writer for Telemetry starting"
echo "Process ID: $$"
sudo -u efduser bash <<EOF 
source /opt/CODE/ts_sal/setup.env
cd /home/efduser/sal/test/m1m3/cpp/src/
./sacpp_m1m3_telemetry_efdwriter
EOF
echo "exiting"

#"$@"
#exec "$SHELL"

