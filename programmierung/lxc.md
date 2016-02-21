# LXC Linux Container Samples/Tutorials

Install
```shell
apt-get install lxc
```

Commandos
```shell
lxc-attach           lxc-checkpoint       lxc-create           lxc-freeze           lxc-monitor          lxc-stop             lxc-usernsexec
lxc-autostart        lxc-clone            lxc-destroy          lxcfs                lxc-snapshot         lxc-top              lxc-wait
lxc-cgroup           lxc-config           lxc-device           lxc-info             lxc-start            lxc-unfreeze
lxc-checkconfig      lxc-console          lxc-execute          lxc-ls               lxc-start-ephemeral  lxc-unshare 
```

namespaces - isolate containers
cgroups - limit ressources, controll priorities

* lxc-create - create a container
* -t debian - debian typ
* -n name  - name of container

* -r wheezy - wheezy debian

first create
```shell
# lxc-create -t debian -n debian_test1
debootstrap ist /usr/sbin/debootstrap
Checking cache download in /var/cache/lxc/debian/rootfs-jessie-amd64 ... 
Downloading debian minimal ...
W: Cannot check Release signature; keyring file not available /usr/share/keyrings/debian-archive-keyring.gpg
I: Retrieving Release 
I: Retrieving Packages
..........
Current default time zone: 'Europe/Berlin'
Local time is now:      Sat Feb 20 19:40:11 CET 2016.
Universal Time is now:  Sat Feb 20 18:40:11 UTC 2016.

Root password is 'root', please change !
Generating locales (this might take a while)...
  de_DE.UTF-8... done
  de_DE.UTF-8... done
Generation complete.
```

```shell
cd /var/lib/lxc/debian_test1
-rw-r--r--  1 root root  502 Feb 20 19:40 config
drwxr-xr-x 22 root root 4,0K Feb 20 19:40 rootfs
```

config
```
# Template used to create this container: /usr/share/lxc/templates/lxc-debian
# Parameters passed to the template:
# For additional config options, please look at lxc.container.conf(5)
lxc.network.type = veth
lxc.network.link = lxcbr0
lxc.network.flags = up
lxc.network.hwaddr = 00:16:3e:81:d0:b5
lxc.rootfs = /var/lib/lxc/debian_test1/rootfs

# Common configuration
lxc.include = /usr/share/lxc/config/debian.common.conf

# Container specific configuration
lxc.utsname = debian_test1
lxc.arch = amd64
```

```shell
# lxc-ls --fancy
NAME          STATE    IPV4  IPV6  GROUPS  AUTOSTART
----------------------------------------------------
debian_test1  STOPPED  -     -     -       NO 
```

start as daemon
```shell
# lxc-start -n debian_test1 -d

# lxc-info -n debian_test1
Name:           debian_test1
State:          RUNNING
PID:            23238
IP:             10.0.3.213
CPU use:        0.25 seconds
BlkIO use:      4.00 KiB
Memory use:     18.39 MiB
KMem use:       0 bytes
Link:           vethBR5S9B
 TX bytes:      1.34 KiB
 RX bytes:      4.98 KiB
 Total bytes:   6.32 KiB
```

lxc-console -n debian_test1
dont work for me, because i cant get login.

to stop
```shell
lxc-stop -n debian_test1
```


