# Information about apt-get and dpkg + deb

/etc/apt/sources.list
```
# deb cdrom:[Debian GNU/Linux 7.0 _Kali_ - Official Snapshot amd64 LIVE/INSTALL Binary 20130723-12:53]/ kali contrib main non-free
#deb cdrom:[Debian GNU/Linux 7.0 _Kali_ - Official Snapshot amd64 LIVE/INSTALL Binary 20130723-12:53]/ kali contrib main non-free
deb http://http.kali.org/kali kali main non-free contrib
deb-src http://http.kali.org/kali kali main non-free contrib
## Security updates
deb http://security.kali.org/kali-security kali/updates main contrib non-free
```

```shell
apt-get update
apt-get upgrade
apt-get dist-upgrade
```

hier liegen heruntergeladen deb files
```
/var/cache/apt/archives
```

* http://docs.kali.org/development/rebuilding-a-package-from-source
```shell
apt-get source libfreefare
nano examples/mifare-classic-format.c
dpkg-checkbuilddeps
dpkg-buildpackage
dpkg -i ../libfreefare*.deb
```

```
## Debian Wheezy
#deb http://http.us.debian.org/debian/ wheezy main contrib non-free
#deb http://security.debian.org/ wheezy/updates main contrib non-free
## Debian Testing
#deb http://http.us.debian.org/debian/ testing main contrib non-free
#deb http://security.debian.org/ testing/updates main contrib non-free
## Debian Sid
#deb http://http.us.debian.org/debian/ sid main contrib non-free
#deb http://security.debian.org/ sid/updates main contrib non-free
## Debian Squeeze
#deb http://http.us.debian.org/debian/ squeeze main contrib non-free
#deb http://security.debian.org/ squeeze/updates main contrib non-free
## Debian Stable
#deb http://http.us.debian.org/debian/ stable main contrib non-free
#deb http://security.debian.org/ stable/updates main contrib non-free
## Debian Unstable
#deb http://http.us.debian.org/debian/ unstable main contrib non-free
#deb http://security.debian.org/ unstable/updates main contrib non-free
## Debian Experimental
#deb http://http.us.debian.org/debian/ experimental main contrib non-free
#deb http://security.debian.org/ experimental/updates main contrib non-free 
```
