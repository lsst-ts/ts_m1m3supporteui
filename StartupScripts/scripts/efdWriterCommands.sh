#!/bin/sh
# Need to add this to sudoers file:
# %groupname ALL=(efduser) NOPASSWD: /home/efduser/sal/test/m1m3/cpp/src
# Add all needed users to groupname

echo "EFD Writer for Commands starting"
echo "Process ID: $$"
sudo -u efduser bash <<EOF 
source /opt/CODE/ts_sal/setup.env
cd /home/efduser/sal/test/m1m3/cpp/src/ 
./sacpp_m1m3_command_efdwriter
EOF
echo "exiting"

#"$@"
#exec "$SHELL"

