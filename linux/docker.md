# Docker Information and Samples

* docker.io
* https://index.docker.io
* https://github.com/dotcloud/docker


docker

```
attach    Attach to a running container
build     Build a container from a Dockerfile
commit    Create a new image from a container's changes
diff      Inspect changes on a container's filesystem
export    Stream the contents of a container as a tar archive
history   Show the history of an image
images    List images
import    Create a new filesystem image from the contents of a tarball
info      Display system-wide information
insert    Insert a file in an image
inspect   Return low-level information on a container
kill      Kill a running container
login     Register or Login to the Docker registry server
logs      Fetch the logs of a container
port      Lookup the public-facing port which is NAT-ed to PRIVATE_PORT
ps        List containers
pull      Pull an image or a repository from the Docker registry server
push      Push an image or a repository to the Docker registry server
restart   Restart a running container
rm        Remove a container
rmi       Remove an image
run       Run a command in a new container
search    Search for an image in the Docker index
start     Start a stopped container
stop      Stop a running container
tag       Tag an image into a repository
version   Show the Docker version information
wait      Block until a container stops, then print its exit code
```

```shell
$ docker version
Docker Emulator version 0.1.3
 
Emulating:
Client version: 0.5.3
Server version: 0.5.3
Go version: go1.1

$ docker search debian

$ docker search ubuntu
Found 22 results matching your query ("ubuntu")
NAME                DESCRIPTION
shykes/ubuntu
base                Another general use Ubuntu base image. Tag...
ubuntu              General use Ubuntu base image. Tags availa...
boxcar/raring       Ubuntu Raring 13.04 suitable for testing v...
dhrp/ubuntu
creack/ubuntu       Tags:
12.04-ssh,
12.10-ssh,
12.10-ssh-l...
crohr/ubuntu              Ubuntu base images. Only lucid (10.04) for...
knewton/ubuntu
pallet/ubuntu2
erikh/ubuntu
samalba/wget              Test container inherited from ubuntu with ...
creack/ubuntu-12-10-ssh
knewton/ubuntu-12.04
tithonium/rvm-ubuntu      The base 'ubuntu' image, with rvm installe...
dekz/build                13.04 ubuntu with build
ooyala/test-ubuntu
ooyala/test-my-ubuntu
ooyala/test-ubuntu2
ooyala/test-ubuntu3
ooyala/test-ubuntu4
ooyala/test-ubuntu5
surma/go                  Simple augmentation of the standard Ubuntu...

 
$ docker pull
Usage: Docker pull NAME
 
Pull an image or a repository from the registry
 
-registry="": Registry to download from. Necessary if image is pulled by ID
-t="": Download tagged image in repository


$ docker pull learn/tutorial
Pulling repository learn/tutorial from https://index.docker.io/v1
Pulling image 8dbd9e392a964056420e5d58ca5cc376ef18e2de93b5cc90e868a1bbc8318c1c (precise) from ubuntu
Pulling image b750fe79269d2ec9a3c593ef05b4332b1d1a02a62b4accb2c21d589ff2f5f2dc (12.10) from ubuntu
Pulling image 27cf784147099545 () from tutorial


$ docker run learn/tutorial echo "hello world"
hello world 

$ docker run learn/tutorial apt-get install -y ping
Reading package lists...
Building dependency tree...
The following NEW packages will be installed:
  iputils-ping
0 upgraded, 1 newly installed, 0 to remove and 0 not upgraded.
Need to get 56.1 kB of archives.
After this operation, 143 kB of additional disk space will be used.
Get:1 http://archive.ubuntu.com/ubuntu/ precise/main iputils-ping amd64 3:20101006-1ubuntu1 [56.1 kB]
debconf: delaying package configuration, since apt-utils is not installed
Fetched 56.1 kB in 1s (50.3 kB/s)
Selecting previously unselected package iputils-ping.
(Reading database ... 7545 files and directories currently installed.)
Unpacking iputils-ping (from .../iputils-ping_3%3a20101006-1ubuntu1_amd64.deb) ...
Setting up iputils-ping (3:20101006-1ubuntu1) ...


$ docker ps -l
ID                  IMAGE               COMMAND                CREATED             STATUS              PORTS
6982a9948422        ubuntu:12.04        apt-get install ping   1 minute ago        Exit 0


$ docker commit
Usage: Docker commit [OPTIONS] CONTAINER [REPOSITORY [TAG]]
 
Create a new image from a container's changes
 
  -author="": Author (eg. "John Hannibal Smith <hannibal@a-team.com>"
  -m="": Commit message
  -run="": Config automatically applied when the image is run. (ex: {"Cmd": ["cat", "/world"], "PortSpecs": ["22"]}')


docker commit 6982a9948422 learn/ping
effb66b31edb

$ docker run learn/ping ping www.google.com
PING www.google.com (74.125.239.129) 56(84) bytes of data.
64 bytes from nuq05s02-in-f20.1e100.net (74.125.239.148): icmp_req=1 ttl=55 time=2.23 ms



$ docker ps
ID                  IMAGE               COMMAND               CREATED             STATUS              PORTS
efefdc74a1d5        learn/ping:latest   ping www.google.com   37 seconds ago      Up 36 seconds


$ docker inspect
 
Usage: Docker inspect CONTAINER|IMAGE [CONTAINER|IMAGE...]
 
Return low-level information on a container/image
 

$ docker inspect efe
[2013/07/30 01:52:26 GET /v1.3/containers/efef/json
{
  "ID": "efefdc74a1d5900d7d7a74740e5261c09f5f42b6dae58ded6a1fde1cde7f4ac5",
  "Created": "2013-07-30T00:54:12.417119736Z",
  "Path": "ping",
  "Args": [
      "www.google.com"
  ],
  "Config": {
      "Hostname": "efefdc74a1d5",
      "User": "",
      "Memory": 0,
      "MemorySwap": 0,
      "CpuShares": 0,
      "AttachStdin": false,
      "AttachStdout": true,
      "AttachStderr": true,
      "PortSpecs": null,
      "Tty": false,
      "OpenStdin": false,
      "StdinOnce": false,
      "Env": null,
      "Cmd": [
          "ping",
          "www.google.com"
      ],
      "Dns": null,
      "Image": "learn/ping",
      "Volumes": null,
      "VolumesFrom": "",
      "Entrypoint": null
  },
  "State": {
      "Running": true,
      "Pid": 22249,
      "ExitCode": 0,
      "StartedAt": "2013-07-30T00:54:12.424817715Z",
      "Ghost": false
  },
  "Image": "a1dbb48ce764c6651f5af98b46ed052a5f751233d731b645a6c57f91a4cb7158",
  "NetworkSettings": {
      "IPAddress": "172.16.42.6",
      "IPPrefixLen": 24,
      "Gateway": "172.16.42.1",
      "Bridge": "docker0",
      "PortMapping": {
          "Tcp": {},
          "Udp": {}
      }
  },
  "SysInitPath": "/usr/bin/docker",
  "ResolvConfPath": "/etc/resolv.conf",
  "Volumes": {},
  "VolumesRW": {}


$ docker images
ubuntu                latest              8dbd9e392a96        4 months ago        131.5 MB (virtual 131.5 MB)
learn/tutorial        latest              8dbd9e392a96        2 months ago        131.5 MB (virtual 131.5 MB)
learn/ping            latest              effb66b31edb        10 minutes ago      11.57 MB (virtual 143.1 MB)


$ docker push learn/ping
```

