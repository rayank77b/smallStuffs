# Information aoub Linux und simple Commands

Exim - Frozen mails löschen
Alle löschen: 
```shell
# exiqgrep -zi | xargs exim -Mrm 
```

Alle löschen, die älter, als einen Tag sind: 
```bash
exiqgrep -zi -o 86400 | xargs exim -Mrm 
```

```bash
dd if=kali.iso of=/dev/sdb bs=512k
```

clone vmware vmdk to vbox vdi
```bash
VBoxManage clonehd --format vdi /path/to/original.vmdk /path/to/converted.vdi
```

```bash
find . -name .svn -exec rm -rf {} \;
find . -cmin +30 -exec rm -f {} \;
find . -user chayer -exec chown sfinn.tedradis {} \;
```

alle aelter als 90 tage löschen
```bash
find . -ctime +90  -exec rm -rf {} \;
```

start a google-chrome with proxy tor?
```bash
/usr/bin/google-chrome --user-data-dir=/tmp/abc --proxy-server=localhost:8118
```

```
mount -t cifs -o user=name,password=mypass,rw "//server/path" /mnt/point

sed -e 's/ AUTO_INCREMENT=[0-9]\+//'
```

* tripwire - a file integrity checker for UNIX systems
* twadmin - Tripwire administrative and utility tool
* twintro - introduction to Tripwire software


# tripwire
* http://www.thegeekstuff.com/2008/12/tripwire-tutorial-linux-host-based-intrusion-detection-system/
* http://netwizards.co.uk/installing-tripwire-on-ubuntu/
* http://www.linuxjournal.com/article/8758
* http://www.morpoint.com/setting-up-tripwire-in-ubuntu-11-10-intrusion-detection-system/
* http://www.ibm.com/developerworks/aix/library/au-usingtripwire/

```bash
tripwire --init             # For the first time use, you should initialize the tripwire database as shown below.
/etc/tripwire/twpol.tx      # Modify Tripwire Policy File
```

Update Tripwire Policy File
```bash
twadmin -m P /etc/tripwire/twpol.txt
```

Check for any changes to the files and update tripwire database.
```bash
tripwire --check --interactive
tripwire -m i
```

view the twr report file
```bash
twprint --print-report --twrfile /opt/tripwire/lib/tripwire/report/prod-db-srv-20081204-114336.twr  > /tmp/readable-output.txt
```

Monitor Linux System Integrity Regularly
```bash
00 4 * * * /opt/tripwire/sbin/tripwire  --check
```

Tripwire Configuration and Policy File Locations
```bash
twadmin --print-polfile
twadmin --print-cfgfile
```

```bash
$ tempfile -s .csv
/tmp/filesmEk3w.csv
```


* unhide — forensic tool to find hidden processes
* rkhunter - RootKit Hunter
* chrootkit - Determine whether the system is infected with a rootkit



remote wipe - Fernlöschung

tethering modus - wlan<->GSM/UMTS Gerät als Modem bzw AP.

datei ausdrucken
```bash
lpr -Plp Datei
```

```bash
fuser -k /dev/lp0 # alle dienste die den /dev/lp0 benutzen toeten
#/dev/usb/lp0

scsi-scanner /dev/sg0

set -o nochlobber

git-rev-tree --bisect ^good1 ^good2 bad > git/refs/headers/tryN
git checkout tryN
^goodx > v2.6.12 bad > master

suse:  yast -l    show modules

movw%bx, (%rsi) <-> recvfrom()

/usr/sbin/snort -b -m 027 -D -N -c /etc/snort/snort.conf -d -u snort -g snort -i eth1

iptables -A INPUT -ptcp -s PVT_IP_HERE -d 0/0

wget -p nur inhalt,
wget -r -np nur unterverzeichniss, nicht von root an

test -x $1 || exit 5

find /proc -type s

ls -Rr /proc/[0-9]* | fgrep ^s 

encrpyt:   gpg -c --cipher-algo blowfish filename.txt
decrypt:   gpg -d filename.txt.gpg > output.txt

firefox:  about:config

find . -type f -print0 | xargs -0 md5sum > /tmp/MD5SUM; mv /tmp/MD5SUM ./MD5SUM 

pdbedit -i tdbsam:/var/lib/samba/passdb.tdb -e smbpasswd:smbpasswd2


apt-get install mdadm
mit fdisk platte partitionieren und "fd" als typ fuer "raidautodetected" setzen
mdadm --create --verbose /dev/md0 --auto=yes --level=1 --raid-devices=2  /dev/sdb /dev/sdc
status: watch -n 3 cat /proc/mdstat
mkfs.ext4 /dev/md0
mdadm --detail /dev/md0
platte als defekt markeiren: 
mdadm /dev/md0 --fail /dev/sdX
aus raid entfernen:
mdadm /dev/md0 --remove /dev/sdX
Raid neue zusammenfügen:
zuerst mit --stop stopen
mdadm --stop /dev/md0
mdadm --assemble /dev/md0 /dev/sdbb
mdadm --detail --scan >> /etc/mdadm.conf
synchronisieren:
mdadm -A -U resync /dev/md0

.htaccess
AuthType Basic
AuthName "bla"
AuthUserFile .htpasswd
require valid_user

htpasswd -c .htpasswd username

Remove the 3rd line:
sed '3d' fileName.txt

Remove the line containing the string "awk":
sed '/awk/d' filename.txt

Remove the last line:
sed '$d' filename.txt

Remove the 3rd line:
sed '3d' fileName.txt

Remove all empty lines:
sed '/^$/d' filename.txt       
sed '/./!d' filename.txt

Remove the interval between lines 7 and 9:
sed '7,9d' filename.txt 

The same operation as above but replacing the address with parameters:
sed '/-Start/,/-End/d' filename.txt

The above examples are only changed at the display of the file (stdout1= screen).For permanent changes to the old versions (<4) use a temporary file for GNU sed using the "-i[suffix]":
sed -i".bak" '3d' filename.txt



/etc/apt/sources.list
# install jdk 1.7 on debian
deb http://ppa.launchpad.net/webupd8team/java/ubuntu precise main
deb-src http://ppa.launchpad.net/webupd8team/java/ubuntu precise main

apt-key adv --keyserver keyserver.ubuntu.com --recv-keys EEA14886
apt-get update
apt-get install oracle-java7-installer

rsync -avz -e ssh remoteuser@remotehost:/remote/dir /this/dir/ 
rsync -avz -e ssh /var/shares/videodata/ root@srv11:/backup/srv38/

VER=$(git describe --tags HEAD)

set -e
set - Manipulate shell variables and functions.
  -e   errexit
    Exit immediately if a simple command exits with a non-zero
    status, unless the command that fails is part of an until or
    while loop, part of an if statement, part of a && or || list,
    or if the command's return status is being inverted using !.
set -x			# activate debugging 
set +x			# stop debugging 
set -P is on (do not follow symbolic links)

munge() {
    printf %s "$1" | tr . _ | tr -d -c '[:alnum:]_'
}
printf %s "$1"  # druckt das erste parameter bei: munge blub
tr . _   # ersetzt . durch _
tr -d  # delete 
-c '[:alnum:]_'  complement von alnum_
entfernt alle nicht alnum_

quote() {
    sed 's/\\/\\\\/g' | sed 's/"/\\"/g' | sed 's/$/\\n/' | tr -d '\n'
}

Install Kernel on Debian
you need:
libncurses5-dev, kernel-package and maybe some other packages.
cd /usr/src/linux-3.X
make mrproper
cp /boot/config-xxx .config
make menuconfig
make-kpkg -j4 --append-to-version=-amd64 --initrd kernel_image kernel_headers


encrpyt:
gpg -c --cipher-algo blowfish filename.txt
decrypt:
gpg -d filename.txt.gpg > output.txt


lpr -Plp Datei # datei ausdrucken
fuser -k /dev/lp0 # alle dienste die den /dev/lp0 benutzen toeten
#/dev/usb/lp0
scsi-scanner /dev/sg0
set -o nochlobber
git-rev-tree --bisect ^good1 ^good2 bad > git/refs/headers/tryN
git checkout tryN
^goodx > v2.6.12 bad > master
movw%bx, (%rsi) <-> recvfrom()
/usr/sbin/snort -b -m 027 -D -N -c /etc/snort/snort.conf -d -u snort -g snort -i eth1

iptables -A INPUT -ptcp -s PVT_IP_HERE -d 0/0

wget -p nur inhalt,
wget -r -np nur unterverzeichniss, nicht von root an

test -x $1 || exit 5
find /proc -type s
ls -Rr /proc/[0-9]* | fgrep ^s

found free loop device:
losetup -f
encryption with losetup:
insmod loop.o
insmod des.o
insmod cryptoloop.o
dd if=/dev/urandom of=crypto.img bs=1M count=50
losetup -e blowfish /dev/loop0 crypto.img
mkfs -t ext2 /dev/loop0
losetup -d /dev/loop0 # delete
mount -o encryption=aes256 crypto.img crypto_home
encryption with bind drive:
losetup -e aes256 /dev/loop0 /dev/sda1
losetup -d /dev/loop0
mount -o encryption=aes256 /dev/sda1 crypto_home
resizing the image:
dd if=/dev/urandom bs=1M count=20 >> crypto.img
losetup -e aes256 /dev/loop0 crypto.img
ext2resize /dev/loop0
encrypt/decrypt with openssl:
openssl enc -aes-256-cbc -salt -in password.txt -out password.txt.enc
openssl enc -d -aes-256-cbc -in password.txt.enc -out password.txt
echo "put /bla/bl/das.log.gz /bls/bl2/dies.log.bz2" >> $TFTPSCRIPT
tftp $TFTPSRV < $TFTPSCRIPT
uuencode $FWLOG/old/$BLA.log.gz $BLA.log.gz | mail -s "FWEXPORT $EXPORTNAME.log.gz" $MAILRECPT

#!/bin/sh
#
[ $# -lt 1 ] && echo $0 server && exit 1

echo 'GET / HTTP/1.0\n' | nc $1 80 | egrep '^Server:'



some info about udev

see info:

man udev      - Linux dynamic device management
man udevd     - event managing daemon
man udevadm   - udev management tool

let see what habpen if we plug-in an usb-stick and monitoring it with udevadm monitor

$ udevadm monitor
monitor will print the received events for:
UDEV - the event which udev sends out after rule processing
KERNEL - the kernel uevent

### here we plug in
KERNEL[1310993660.681080] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9 (usb)
KERNEL[1310993660.682788] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0 (usb)
KERNEL[1310993660.683439] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7 (scsi)
KERNEL[1310993660.683480] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/scsi_host/host7 (scsi_host)
UDEV  [1310993660.717897] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9 (usb)
UDEV  [1310993660.722838] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0 (usb)
UDEV  [1310993660.726973] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7 (scsi)
UDEV  [1310993660.729599] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/scsi_host/host7 (scsi_host)
KERNEL[1310993661.679909] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0 (scsi)
UDEV  [1310993661.681299] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0 (scsi)
KERNEL[1310993661.681576] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0 (scsi)
KERNEL[1310993661.683434] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/scsi_disk/7:0:0:0 (scsi_disk)
KERNEL[1310993661.688669] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/scsi_device/7:0:0:0 (scsi_device)
KERNEL[1310993661.689288] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/scsi_generic/sg3 (scsi_generic)
KERNEL[1310993661.689399] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/bsg/7:0:0:0 (bsg)
UDEV  [1310993661.690794] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0 (scsi)
UDEV  [1310993661.695103] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/scsi_device/7:0:0:0 (scsi_device)
UDEV  [1310993661.697359] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/scsi_disk/7:0:0:0 (scsi_disk)
UDEV  [1310993661.700063] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/scsi_generic/sg3 (scsi_generic)
UDEV  [1310993661.711454] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/bsg/7:0:0:0 (bsg)
KERNEL[1310993663.768535] add      /devices/virtual/bdi/8:32 (bdi)
UDEV  [1310993663.769416] add      /devices/virtual/bdi/8:32 (bdi)
KERNEL[1310993663.772966] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/block/sdc (block)
KERNEL[1310993663.773037] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/block/sdc/sdc1 (block)
UDEV  [1310993664.231205] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/block/sdc (block)
UDEV  [1310993664.331853] add      /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/block/sdc/sdc1 (block)


### here we plug out
KERNEL[1310993703.170021] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/bsg/7:0:0:0 (bsg)
KERNEL[1310993703.170114] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/scsi_generic/sg3 (scsi_generic)
KERNEL[1310993703.170146] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/scsi_device/7:0:0:0 (scsi_device)
KERNEL[1310993703.170180] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/scsi_disk/7:0:0:0 (scsi_disk)
UDEV  [1310993703.172553] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/scsi_device/7:0:0:0 (scsi_device)
UDEV  [1310993703.173338] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/scsi_disk/7:0:0:0 (scsi_disk)
UDEV  [1310993703.174748] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/scsi_generic/sg3 (scsi_generic)
UDEV  [1310993703.174978] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/bsg/7:0:0:0 (bsg)
KERNEL[1310993703.178554] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/block/sdc/sdc1 (block)
UDEV  [1310993703.201812] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/block/sdc/sdc1 (block)
KERNEL[1310993703.248140] remove   /devices/virtual/bdi/8:32 (bdi)
KERNEL[1310993703.248304] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/block/sdc (block)
KERNEL[1310993703.248351] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0 (scsi)
KERNEL[1310993703.248448] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0 (scsi)
KERNEL[1310993703.248525] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/scsi_host/host7 (scsi_host)
KERNEL[1310993703.248560] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7 (scsi)
KERNEL[1310993703.251381] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0 (usb)
UDEV  [1310993703.251445] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/scsi_host/host7 (scsi_host)
KERNEL[1310993703.251501] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9 (usb)
UDEV  [1310993703.251595] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0/block/sdc (block)
UDEV  [1310993703.252799] remove   /devices/virtual/bdi/8:32 (bdi)
UDEV  [1310993703.254218] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0/7:0:0:0 (scsi)
UDEV  [1310993703.255623] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7/target7:0:0 (scsi)
UDEV  [1310993703.256904] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0/host7 (scsi)
UDEV  [1310993703.259197] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9/1-9:1.0 (usb)
UDEV  [1310993703.283898] remove   /devices/pci0000:00/0000:00:13.5
/usb1/1-9 (usb)

some configurationsfile are in

/lib/udev/rules.d

/etc/udev/rules.d

let see 10-vboxdrv.rules

KERNEL=="vboxdrv", NAME="vboxdrv", OWNER="root", GROUP="root", MODE="0600"
SUBSYSTEM=="usb_device", ACTION=="add", RUN+="/usr/share/virtualbox/
VBoxCreateUSBNode.sh $major $minor $attr{bDeviceClass} vboxusers"
SUBSYSTEM=="usb", ACTION=="add", ENV{DEVTYPE}=="usb_device", 
RUN+="/usr/share/virtualbox/VBoxCreateUSBNode.sh $major $minor 
$attr{bDeviceClass} vboxusers"
SUBSYSTEM=="usb_device", ACTION=="remove", RUN+="/usr/share/virtualbox
/VBoxCreateUSBNode.sh --remove $major $minor"
SUBSYSTEM=="usb", ACTION=="remove", ENV{DEVTYPE}=="usb_device", 
RUN+="/usr/share/virtualbox/VBoxCreateUSBNode.sh --remove $major $minor"

we see the name vboxdrv and run the VBoxCreateUSBNode.sh command.

let see VBoxCreateUSBNode.sh:

#! /bin/sh
# bla bla Oracle Copyright. see details the file itself.

do_remove=0
case "$1" in "--remove")
  do_remove=1; shift;;
esac
bus=`expr "$2" '/' 128 + 1`
device=`expr "$2" '%' 128 + 1`
class="$3"
group="$4"
if test "$class" -eq 9; then
  exit 0
fi
devdir="`printf "/dev/vboxusb/%.3d" $bus`"
devpath="`printf "/dev/vboxusb/%.3d/%.3d" $bus $device`"
if test "$do_remove" -eq 0; then
  if test -z "$group"; then
    group="vboxusers"
  fi
  mkdir /dev/vboxusb -m 0750 2>/dev/null
  chown root:$group /dev/vboxusb 2>/dev/null
  mkdir "$devdir" -m 0750 2>/dev/null
  chown root:$group "$devdir" 2>/dev/null
  mknod "$devpath" c $1 $2 -m 0660 2>/dev/null
  chown root:$group "$devpath" 2>/dev/null
else
  rm -f "$devpath"
fi

it create files in /dev/vboxusb/

crw-rw---- 1 root vboxusers 189, 385 2011-07-18 08:58 002
crw-rw---- 1 root vboxusers 189, 386 2011-07-18 08:58 003

at last there is a log file in

/var/log/udev



schnell ein Screenshot von einem Fenster erstellen.
> import bild.png
dann den Bereich mit Maus markieren, voila
```
