#!/bin/sh
echo "EFD Writer for Events starting"
echo "Process ID: $$"
sudo -u efduser bash <<EOF 
source /opt/CODE/ts_sal/setup.env
cd /home/efduser/sal/test/m1m3/cpp/src/
./sacpp_m1m3_event_efdwriter
EOF
echo "exiting"

#"$@"
#exec "$SHELL"

