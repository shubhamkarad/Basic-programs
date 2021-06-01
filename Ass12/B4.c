/********************************
NAME :-
CLASS:-
ROll no:-
BATCH:-
ASSIGNMENT NO.:-4(group B)
*********************************/
/*Aim:C/C++ Program to assign nice values to processes and dynamically monitor them.*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>

int main()
{
int rc,nc;
int ch;
while(1)
{system("ps axl");
printf("\ncurrent nice value can be checked from above table");
printf("\ncurrent priority of process %d is %d",getpid(),getpriority(PRIO_PROCESS,0));
printf("\nEnter new nice value (bet -20 to 20)");
scanf("%d",&nc);
rc=setpriority(PRIO_PROCESS,0,nc);

if(0!=rc)
{
perror("setpriority"); 
}
sleep(2);

printf("\nModified nice value of the process %d is : %d ",getpid(),
getpriority(PRIO_PROCESS,0));
printf("\n Do you want to continue(press 1 to continue and 0 to stop):");

scanf("%d",&ch);

if(ch==0)
exit(0);
}
return 0;
}


/***OUTPUT*****


student@jit:~/OSAprogram$ cd Group-B
student@jit:~/OSAprogram/Group-B$ gcc B4.c
student@jit:~/OSAprogram/Group-B$ ./a.out
F   UID   PID  PPID PRI  NI    VSZ   RSS WCHAN  STAT TTY        TIME COMMAND
4     0     1     0  20   0   3672  2016 poll_s Ss   ?          0:00 /sbin/init
1     0     2     0  20   0      0     0 kthrea S    ?          0:00 [kthreadd]
1     0     3     2  20   0      0     0 run_ks S    ?          0:00 [ksoftirqd/0]
1     0     6     2 -100  -      0     0 cpu_st S    ?          0:00 [migration/0]
5     0     7     2 -100  -      0     0 watchd S    ?          0:00 [watchdog/0]
1     0     8     2 -100  -      0     0 cpu_st S    ?          0:00 [migration/1]
1     0    10     2  20   0      0     0 run_ks S    ?          0:00 [ksoftirqd/1]
5     0    12     2 -100  -      0     0 watchd S    ?          0:00 [watchdog/1]
1     0    13     2 -100  -      0     0 cpu_st S    ?          0:00 [migration/2]
1     0    15     2  20   0      0     0 run_ks S    ?          0:00 [ksoftirqd/2]
5     0    16     2 -100  -      0     0 watchd S    ?          0:00 [watchdog/2]
1     0    17     2 -100  -      0     0 cpu_st S    ?          0:00 [migration/3]
1     0    18     2  20   0      0     0 worker S    ?          0:00 [kworker/3:0]
1     0    19     2  20   0      0     0 run_ks S    ?          0:00 [ksoftirqd/3]
5     0    20     2 -100  -      0     0 watchd S    ?          0:00 [watchdog/3]
1     0    21     2   0 -20      0     0 rescue S<   ?          0:00 [cpuset]
1     0    22     2   0 -20      0     0 rescue S<   ?          0:00 [khelper]
5     0    23     2  20   0      0     0 devtmp S    ?          0:00 [kdevtmpfs]
1     0    24     2   0 -20      0     0 rescue S<   ?          0:00 [netns]
1     0    26     2  20   0      0     0 bdi_sy S    ?          0:00 [sync_supers]
1     0    27     2  20   0      0     0 bdi_fo S    ?          0:00 [bdi-default]
1     0    28     2   0 -20      0     0 rescue S<   ?          0:00 [kintegrityd]
1     0    29     2   0 -20      0     0 rescue S<   ?          0:00 [kblockd]
1     0    30     2   0 -20      0     0 rescue S<   ?          0:00 [ata_sff]
1     0    31     2  20   0      0     0 hub_th S    ?          0:00 [khubd]
1     0    32     2   0 -20      0     0 rescue S<   ?          0:00 [md]
1     0    34     2  20   0      0     0 watchd S    ?          0:00 [khungtaskd]
1     0    35     2  20   0      0     0 kswapd S    ?          0:00 [kswapd0]
1     0    36     2  25   5      0     0 ksm_sc SN   ?          0:00 [ksmd]
1     0    37     2  39  19      0     0 khugep SN   ?          0:00 [khugepaged]
1     0    38     2  20   0      0     0 fsnoti S    ?          0:00 [fsnotify_mark]
1     0    39     2  20   0      0     0 ecrypt S    ?          0:00 [ecryptfs-kthrea]
1     0    40     2   0 -20      0     0 rescue S<   ?          0:00 [crypto]
1     0    48     2   0 -20      0     0 rescue S<   ?          0:00 [kthrotld]
1     0    49     2  20   0      0     0 scsi_e S    ?          0:00 [scsi_eh_0]
1     0    50     2  20   0      0     0 scsi_e S    ?          0:00 [scsi_eh_1]
1     0    51     2  20   0      0     0 worker S    ?          0:00 [kworker/u:2]
1     0    52     2  20   0      0     0 scsi_e S    ?          0:00 [scsi_eh_2]
1     0    53     2  20   0      0     0 scsi_e S    ?          0:00 [scsi_eh_3]
1     0    54     2  20   0      0     0 worker S    ?          0:00 [kworker/u:3]
1     0    75     2   0 -20      0     0 rescue S<   ?          0:00 [devfreq_wq]
1     0    76     2  20   0      0     0 ?      R    ?          0:00 [kworker/1:1]
1     0    77     2  20   0      0     0 worker S    ?          0:00 [kworker/2:1]
1     0    87     2  20   0      0     0 worker S    ?          0:00 [kworker/3:1]
1     0   237     2  20   0      0     0 kjourn S    ?          0:00 [jbd2/sda5-8]
1     0   238     2   0 -20      0     0 rescue S<   ?          0:00 [ext4-dio-unwrit]
1     0   325     1  20   0   2836   608 poll_s S    ?          0:00 upstart-udev-bridge --daemon
5     0   327     1  20   0   3308  1516 ep_pol Ss   ?          0:00 /sbin/udevd --daemon
5     0   401   327  20   0   3252  1028 ep_pol S    ?          0:00 /sbin/udevd --daemon
5     0   402   327  20   0   3252  1032 ep_pol S    ?          0:00 /sbin/udevd --daemon
1     0   429     2   0 -20      0     0 rescue S<   ?          0:00 [kpsmoused]
1     0   660     1  20   0   2848   364 poll_s S    ?          0:00 upstart-socket-bridge --daemon
5     0   681     2 -51   -      0     0 irq_th S    ?          0:00 [irq/42-mei]
1     0   687     2   0 -20      0     0 rescue S<   ?          0:00 [hd-audio0]
1     0   698     2  20   0      0     0 worker S    ?          0:00 [kworker/2:2]
1     0   709     2  20   0      0     0 worker S    ?          0:00 [kworker/1:2]
1     0   730     2  20   0      0     0 kjourn S    ?          0:00 [jbd2/sda6-8]
1     0   731     2   0 -20      0     0 rescue S<   ?          0:00 [ext4-dio-unwrit]
1     0   739     2  20   0      0     0 kjourn S    ?          0:00 [jbd2/sda7-8]
1     0   740     2   0 -20      0     0 rescue S<   ?          0:00 [ext4-dio-unwrit]
4     0   770     1  20   0  21408  4876 poll_s Ss   ?          0:00 smbd -F
5   102   776     1  20   0   4116  1912 poll_s Ss   ?          0:00 dbus-daemon --system --fork --activation=upstart
1     0   779   770  20   0  21512  1364 poll_s S    ?          0:00 smbd -F
4     0   800     1  20   0   7224  2812 poll_s Ss   ?          0:00 /usr/sbin/modem-manager
5     0   802     1  20   0   4744  1404 poll_s Ss   ?          0:00 /usr/sbin/bluetoothd
5     0   807     1  20   0  30976  4788 poll_s Ssl  ?          0:00 NetworkManager
5     0   819     2  10 -10      0     0 rfcomm S<   ?          0:00 [krfcommd]
5   107   824     1  20   0   3580  1716 poll_s S    ?          0:00 avahi-daemon: running [jit-3.local]
5   101   825     1  20   0  31064  1508 poll_s Sl   ?          0:00 rsyslogd -c5
1   107   828   824  20   0   3456   432 unix_s S    ?          0:00 avahi-daemon: chroot helper
4     0   852     1  20   0  25228  3648 poll_s Sl   ?          0:00 /usr/lib/policykit-1/polkitd --no-debug
4     0   900     1  20   0   4632   864 n_tty_ Ss+  tty4       0:00 /sbin/getty -8 38400 tty4
4     0   904     1  20   0   4632   860 n_tty_ Ss+  tty5       0:00 /sbin/getty -8 38400 tty5
4     0   910     1  20   0   4632   856 n_tty_ Ss+  tty2       0:00 /sbin/getty -8 38400 tty2
4     0   915     1  20   0   4632   860 n_tty_ Ss+  tty3       0:00 /sbin/getty -8 38400 tty3
4     0   920     1  20   0   4632   860 n_tty_ Ss+  tty6       0:00 /sbin/getty -8 38400 tty6
1   105   937     1  20   0  25892  4412 poll_s Ssl  ?          0:00 whoopsie
1     0   939     1  20   0   2176   712 poll_s Ss   ?          0:00 acpid -c /etc/acpi/events -s /var/run/acpid.socket
5     0   940     1  20   0   3604   632 hrtime Ss   ?          0:00 /usr/sbin/irqbalance
1     0   941     1  20   0   2620   916 hrtime Ss   ?          0:00 cron
1     1   942     1  20   0   2472   352 hrtime Ss   ?          0:00 atd
4     0   949     1  20   0  34040  3088 poll_s Ssl  ?          0:00 lightdm
4     0   955     1  20   0  11076  3548 ep_pol Ss   ?          0:00 /usr/sbin/cupsd -F
1     0  1002     1  20   0   6236  2740 poll_s Ss   ?          0:00 /usr/sbin/apache2 -k start
5    33  1005  1002  20   0   6016  1932 wait_f S    ?          0:00 /usr/sbin/apache2 -k start
5    33  1007  1002  20   0 228680  2284 pipe_w Sl   ?          0:00 /usr/sbin/apache2 -k start
5    33  1008  1002  20   0 228680  2284 pipe_w Sl   ?          0:00 /usr/sbin/apache2 -k start
4     0  1092   949  20   0  26400 14376 poll_s Ss+  tty7       0:46 /usr/bin/X :0 -auth /var/run/lightdm/root/:0 -nolisten tcp vt7 -novtswitch
4     0  1202     1  20   0   4632   864 n_tty_ Ss+  tty1       0:00 /sbin/getty -8 38400 tty1
4     0  1207   949  20   0  16432  3180 wait   Sl   ?          0:00 lightdm --session-child 12 15
4     0  1210     1  20   0  15828  3400 poll_s Sl   ?          0:00 /usr/lib/accountsservice/accounts-daemon
4     0  1237     1  20   0  34232  3316 poll_s Sl   ?          0:00 /usr/sbin/console-kit-daemon --no-daemon
4  1001  1312  1207  20   0  49776  8504 poll_s Ssl  ?          0:00 gnome-session --session=ubuntu
1  1001  1348  1312  20   0   4080   208 poll_s Ss   ?          0:00 /usr/bin/ssh-agent /usr/bin/dbus-launch --exit-with-session gnome-session -
1  1001  1351     1  20   0   3940   480 poll_s S    ?          0:00 /usr/bin/dbus-launch --exit-with-session gnome-session --session=ubuntu
1  1001  1352     1  20   0   6472  3076 poll_s Ss   ?          0:05 //bin/dbus-daemon --fork --print-pid 5 --print-address 7 --session
5  1001  1360     1  20   0  64568  3168 poll_s Sl   ?          0:00 gnome-keyring-daemon --start --components=gpg
0  1001  1366  1312  20   0 138180 15416 poll_s Sl   ?          0:01 /usr/lib/gnome-settings-daemon/gnome-settings-daemon
4     0  1373     1  20   0  28420  3764 poll_s Sl   ?          0:00 /usr/lib/upower/upowerd
0  1001  1431     1  20   0   8408  2216 poll_s S    ?          0:00 /usr/lib/gvfs/gvfsd
0  1001  1441     1  20   0  34760  2564 futex_ Sl   ?          0:00 /usr/lib/gvfs//gvfs-fuse-daemon -f /home/student/.gvfs
0  1001  1489  1312  20   0 225780 77312 poll_s Sl   ?          0:41 compiz
4   103  1492     1  20   0  53340 10212 poll_s Sl   ?          0:00 /usr/lib/i386-linux-gnu/colord/colord
0  1001  1496     1  20   0   9272  2876 poll_s S    ?          0:00 /usr/lib/i386-linux-gnu/gconf/gconfd-2
1  1001  1505     1   9 -11  99908  5736 poll_s S<l  ?          0:00 /usr/bin/pulseaudio --start --log-target=syslog
4   111  1507     1  21   1  21332  1248 poll_s SNl  ?          0:00 /usr/lib/rtkit/rtkit-daemon
0  1001  1511     1  20   0   8432  2132 poll_s S    ?          0:00 /usr/lib/gvfs/gvfsd-metadata
0  1001  1513  1312  20   0 113308 13996 poll_s Sl   ?          0:00 nm-applet
0  1001  1515  1312  20   0  39468  7484 poll_s Sl   ?          0:00 /usr/lib/policykit-1-gnome/polkit-gnome-authentication-agent-1
0  1001  1516  1312  20   0 167424 35084 poll_s Sl   ?          0:47 nautilus -n
0  1001  1521  1312  20   0  57852  7536 poll_s Sl   ?          0:00 /usr/lib/gnome-settings-daemon/gnome-fallback-mount-helper
0  1001  1524  1312  20   0  88856 10572 poll_s Sl   ?          0:00 bluetooth-applet
0  1001  1525  1505  20   0  14104  2492 poll_s S    ?          0:00 /usr/lib/pulseaudio/pulse/gconf-helper
0  1001  1534     1  20   0   9864  3352 poll_s S    ?          0:00 /usr/lib/gvfs/gvfs-gdu-volume-monitor
4     0  1536     1  20   0  25304  3572 poll_s Sl   ?          0:00 /usr/lib/udisks/udisks-daemon
1     0  1537  1536  20   0   6556   728 poll_s S    ?          0:00 udisks-daemon: not polling any devices
0  1001  1544     1  20   0   9212  2136 poll_s S    ?          0:00 /usr/lib/gvfs/gvfs-gphoto2-volume-monitor
0  1001  1546     1  20   0  20488  2140 poll_s Sl   ?          0:00 /usr/lib/gvfs/gvfs-afc-volume-monitor
0  1001  1551     1  20   0   8840  2920 poll_s S    ?          0:00 /usr/lib/gvfs/gvfsd-trash --spawner :1.9 /org/gtk/gvfs/exec_spaw/0
4 65534  1554   807  20   0   5404  1156 poll_s S    ?          0:00 /usr/sbin/dnsmasq --no-resolv --keep-in-foreground --no-hosts --bind-interf
0  1001  1569     1  20   0  49616  8880 poll_s Sl   ?          0:03 /usr/lib/bamf/bamfdaemon
0  1001  1592  1489  20   0   2236   536 wait   Ss   ?          0:00 /bin/sh -c /usr/bin/compiz-decorator
0  1001  1593  1592  20   0  41388 10184 poll_s Sl   ?          0:01 /usr/bin/gtk-window-decorator
1     0  1600     2  20   0      0     0 bdi_wr S    ?          0:00 [flush-8:0]
0  1001  1614     1  20   0  95480 19336 poll_s Sl   ?          0:20 /usr/lib/unity/unity-panel-service
0  1001  1616     1  20   0  67964  5876 poll_s Sl   ?          0:16 /usr/lib/indicator-appmenu/hud-service
0  1001  1630     1  20   0   8440  2392 poll_s S    ?          0:00 /usr/lib/gvfs/gvfsd-burn --spawner :1.9 /org/gtk/gvfs/exec_spaw/1
0  1001  1633     1  20   0  82620  6148 poll_s Sl   ?          0:00 /usr/lib/indicator-datetime/indicator-datetime-service
0  1001  1634     1  20   0  63592  4412 poll_s Sl   ?          0:00 /usr/lib/indicator-application/indicator-application-service
0  1001  1642     1  20   0 127448  5936 poll_s Sl   ?          0:00 /usr/lib/indicator-sound/indicator-sound-service
0  1001  1643     1  20   0  69336  5644 poll_s Sl   ?          0:00 /usr/lib/indicator-messages/indicator-messages-service
0  1001  1647     1  20   0  78628  5440 poll_s Sl   ?          0:00 /usr/lib/indicator-session/indicator-session-service
0  1001  1656     1  20   0  61480  8796 poll_s Sl   ?          0:00 /usr/lib/indicator-printers/indicator-printers-service
0  1001  1665     1  20   0   7980  2368 poll_s S    ?          0:00 /usr/lib/geoclue/geoclue-master
0  1001  1677     1  20   0  21304  4584 poll_s S    ?          0:00 /usr/lib/ubuntu-geoip/ubuntu-geoip-provider
0  1001  1703     1  20   0  74720  9420 poll_s Sl   ?          0:00 /usr/lib/unity-lens-applications/unity-applications-daemon
0  1001  1705     1  20   0  89428  5868 poll_s Sl   ?          0:00 /usr/lib/unity-lens-files/unity-files-daemon
0  1001  1708     1  20   0  79752  7232 poll_s Sl   ?          0:00 /usr/lib/unity-lens-music/unity-music-daemon
0  1001  1709     1  20   0  70624 12064 poll_s Sl   ?          0:00 /usr/bin/python /usr/lib/unity-lens-video/unity-lens-video
0  1001  1741     1  20   0  45912  5632 poll_s Sl   ?          0:00 /usr/bin/zeitgeist-daemon
0  1001  1747     1  20   0  51972  8124 poll_s Sl   ?          0:00 /usr/lib/zeitgeist/zeitgeist-fts
0  1001  1749     1  20   0  54840  5672 poll_s Sl   ?          0:01 zeitgeist-datahub
0  1001  1755  1747  20   0   4228   284 unix_s S    ?          0:00 /bin/cat
0  1001  1771     1  20   0  33640  2464 poll_s Sl   ?          0:00 /usr/lib/dconf/dconf-service
0  1001  1778  1312  20   0  41148  8072 poll_s Sl   ?          0:00 /usr/lib/gnome-disk-utility/gdu-notification-daemon
0  1001  1780     1  20   0  79608  3776 poll_s Sl   ?          0:00 /usr/lib/unity-lens-music/unity-musicstore-daemon
0  1001  1815     1  20   0  91612 13488 poll_s Sl   ?          0:00 /usr/bin/python /usr/lib/unity-scope-video-remote/unity-scope-video-remote
5     0  1867     1  20   0  13332  1852 poll_s Ss   ?          0:00 nmbd -D
0  1001  1880  1312  20   0  74244  9504 poll_s Sl   ?          0:00 telepathy-indicator
0  1001  1887     1  20   0  41684  5596 poll_s Sl   ?          0:00 /usr/lib/telepathy/mission-control-5
0  1001  1892     1  20   0  91208  9196 poll_s Sl   ?          0:00 /usr/lib/gnome-online-accounts/goa-daemon
0  1001  1897  1312  20   0  39884  7820 poll_s Sl   ?          0:00 gnome-screensaver
0  1001  1920     1  20   0  83812 25332 poll_s Sl   ?          0:00 /usr/bin/python /usr/lib/ubuntuone-client/ubuntuone-syncdaemon
0  1001  1957  1312  20   0  51484 11204 poll_s Sl   ?          0:00 update-notifier
0  1001  1979  1312  20   0  35704  3460 poll_s Sl   ?          0:00 /usr/lib/deja-dup/deja-dup/deja-dup-monitor
0  1001  2013     1  20   0  93584 15512 -      Rl   ?          0:03 gnome-terminal
0  1001  2018  2013  20   0   2404   720 unix_s S    ?          0:00 gnome-pty-helper
0  1001  2019  2013  20   0   7448  3832 wait   Ss   pts/0      0:00 bash
0  1001  2171     1  20   0  35492  3100 pipe_w Sl   ?          0:00 /usr/lib/libreoffice/program/oosplash --writer /home/student/Downloads/grou
0  1001  2189  2171  20   0 262528 90840 poll_s Sl   ?          0:08 /usr/lib/libreoffice/program/soffice.bin --writer /home/student/Downloads/g
1     0  2408     2  20   0      0     0 worker S    ?          0:00 [kworker/0:1]
1     0  2676     2  20   0      0     0 worker S    ?          0:00 [kworker/0:2]
0  1001  2825     1  20   0 129164 30052 poll_s Sl   ?          0:03 gedit /home/student/OSAprogram/Group-B/B3.c
0  1001  2876  2019  20   0   2004   284 wait   S+   pts/0      0:00 ./a.out
0  1001  2877  2876  20   0   2236   540 wait   S+   pts/0      0:00 sh -c ps axl
0  1001  2878  2877  20   0   4708   708 -      R+   pts/0      0:00 ps axl

current nice value can be checked from above table
current priority of process 2876 is 0
Enter new nice value (bet -20 to 20)15

Modified nice value of the process 2876 is : 15 
 Do you want to continue(press 1 to continue and 0 to stop):1
F   UID   PID  PPID PRI  NI    VSZ   RSS WCHAN  STAT TTY        TIME COMMAND
4     0     1     0  20   0   3672  2016 poll_s Ss   ?          0:00 /sbin/init
1     0     2     0  20   0      0     0 kthrea S    ?          0:00 [kthreadd]
1     0     3     2  20   0      0     0 run_ks S    ?          0:00 [ksoftirqd/0]
1     0     6     2 -100  -      0     0 cpu_st S    ?          0:00 [migration/0]
5     0     7     2 -100  -      0     0 watchd S    ?          0:00 [watchdog/0]
1     0     8     2 -100  -      0     0 cpu_st S    ?          0:00 [migration/1]
1     0    10     2  20   0      0     0 run_ks S    ?          0:00 [ksoftirqd/1]
5     0    12     2 -100  -      0     0 watchd S    ?          0:00 [watchdog/1]
1     0    13     2 -100  -      0     0 cpu_st S    ?          0:00 [migration/2]
1     0    15     2  20   0      0     0 run_ks S    ?          0:00 [ksoftirqd/2]
5     0    16     2 -100  -      0     0 watchd S    ?          0:00 [watchdog/2]
1     0    17     2 -100  -      0     0 cpu_st S    ?          0:00 [migration/3]
1     0    18     2  20   0      0     0 worker S    ?          0:00 [kworker/3:0]
1     0    19     2  20   0      0     0 run_ks S    ?          0:00 [ksoftirqd/3]
5     0    20     2 -100  -      0     0 watchd S    ?          0:00 [watchdog/3]
1     0    21     2   0 -20      0     0 rescue S<   ?          0:00 [cpuset]
1     0    22     2   0 -20      0     0 rescue S<   ?          0:00 [khelper]
5     0    23     2  20   0      0     0 devtmp S    ?          0:00 [kdevtmpfs]
1     0    24     2   0 -20      0     0 rescue S<   ?          0:00 [netns]
1     0    26     2  20   0      0     0 bdi_sy S    ?          0:00 [sync_supers]
1     0    27     2  20   0      0     0 bdi_fo S    ?          0:00 [bdi-default]
1     0    28     2   0 -20      0     0 rescue S<   ?          0:00 [kintegrityd]
1     0    29     2   0 -20      0     0 rescue S<   ?          0:00 [kblockd]
1     0    30     2   0 -20      0     0 rescue S<   ?          0:00 [ata_sff]
1     0    31     2  20   0      0     0 hub_th S    ?          0:00 [khubd]
1     0    32     2   0 -20      0     0 rescue S<   ?          0:00 [md]
1     0    34     2  20   0      0     0 watchd S    ?          0:00 [khungtaskd]
1     0    35     2  20   0      0     0 kswapd S    ?          0:00 [kswapd0]
1     0    36     2  25   5      0     0 ksm_sc SN   ?          0:00 [ksmd]
1     0    37     2  39  19      0     0 khugep SN   ?          0:00 [khugepaged]
1     0    38     2  20   0      0     0 fsnoti S    ?          0:00 [fsnotify_mark]
1     0    39     2  20   0      0     0 ecrypt S    ?          0:00 [ecryptfs-kthrea]
1     0    40     2   0 -20      0     0 rescue S<   ?          0:00 [crypto]
1     0    48     2   0 -20      0     0 rescue S<   ?          0:00 [kthrotld]
1     0    49     2  20   0      0     0 scsi_e S    ?          0:00 [scsi_eh_0]
1     0    50     2  20   0      0     0 scsi_e S    ?          0:00 [scsi_eh_1]
1     0    51     2  20   0      0     0 worker S    ?          0:00 [kworker/u:2]
1     0    52     2  20   0      0     0 scsi_e S    ?          0:00 [scsi_eh_2]
1     0    53     2  20   0      0     0 scsi_e S    ?          0:00 [scsi_eh_3]
1     0    54     2  20   0      0     0 worker S    ?          0:00 [kworker/u:3]
1     0    75     2   0 -20      0     0 rescue S<   ?          0:00 [devfreq_wq]
1     0    76     2  20   0      0     0 worker S    ?          0:00 [kworker/1:1]
1     0    77     2  20   0      0     0 worker S    ?          0:00 [kworker/2:1]
1     0    87     2  20   0      0     0 worker S    ?          0:00 [kworker/3:1]
1     0   237     2  20   0      0     0 kjourn S    ?          0:00 [jbd2/sda5-8]
1     0   238     2   0 -20      0     0 rescue S<   ?          0:00 [ext4-dio-unwrit]
1     0   325     1  20   0   2836   608 poll_s S    ?          0:00 upstart-udev-bridge --daemon
5     0   327     1  20   0   3308  1516 ep_pol Ss   ?          0:00 /sbin/udevd --daemon
5     0   401   327  20   0   3252  1028 ep_pol S    ?          0:00 /sbin/udevd --daemon
5     0   402   327  20   0   3252  1032 ep_pol S    ?          0:00 /sbin/udevd --daemon
1     0   429     2   0 -20      0     0 rescue S<   ?          0:00 [kpsmoused]
1     0   660     1  20   0   2848   364 poll_s S    ?          0:00 upstart-socket-bridge --daemon
5     0   681     2 -51   -      0     0 irq_th S    ?          0:00 [irq/42-mei]
1     0   687     2   0 -20      0     0 rescue S<   ?          0:00 [hd-audio0]
1     0   698     2  20   0      0     0 worker S    ?          0:00 [kworker/2:2]
1     0   709     2  20   0      0     0 worker S    ?          0:00 [kworker/1:2]
1     0   730     2  20   0      0     0 kjourn S    ?          0:00 [jbd2/sda6-8]
1     0   731     2   0 -20      0     0 rescue S<   ?          0:00 [ext4-dio-unwrit]
1     0   739     2  20   0      0     0 kjourn S    ?          0:00 [jbd2/sda7-8]
1     0   740     2   0 -20      0     0 rescue S<   ?          0:00 [ext4-dio-unwrit]
4     0   770     1  20   0  21408  4876 poll_s Ss   ?          0:00 smbd -F
5   102   776     1  20   0   4116  1912 poll_s Ss   ?          0:00 dbus-daemon --system --fork --activation=upstart
1     0   779   770  20   0  21512  1364 poll_s S    ?          0:00 smbd -F
4     0   800     1  20   0   7224  2812 poll_s Ss   ?          0:00 /usr/sbin/modem-manager
5     0   802     1  20   0   4744  1404 poll_s Ss   ?          0:00 /usr/sbin/bluetoothd
5     0   807     1  20   0  30976  4788 poll_s Ssl  ?          0:00 NetworkManager
5     0   819     2  10 -10      0     0 rfcomm S<   ?          0:00 [krfcommd]
5   107   824     1  20   0   3580  1716 poll_s S    ?          0:00 avahi-daemon: running [jit-3.local]
5   101   825     1  20   0  31064  1508 poll_s Sl   ?          0:00 rsyslogd -c5
1   107   828   824  20   0   3456   432 unix_s S    ?          0:00 avahi-daemon: chroot helper
4     0   852     1  20   0  25228  3648 poll_s Sl   ?          0:00 /usr/lib/policykit-1/polkitd --no-debug
4     0   900     1  20   0   4632   864 n_tty_ Ss+  tty4       0:00 /sbin/getty -8 38400 tty4
4     0   904     1  20   0   4632   860 n_tty_ Ss+  tty5       0:00 /sbin/getty -8 38400 tty5
4     0   910     1  20   0   4632   856 n_tty_ Ss+  tty2       0:00 /sbin/getty -8 38400 tty2
4     0   915     1  20   0   4632   860 n_tty_ Ss+  tty3       0:00 /sbin/getty -8 38400 tty3
4     0   920     1  20   0   4632   860 n_tty_ Ss+  tty6       0:00 /sbin/getty -8 38400 tty6
1   105   937     1  20   0  25892  4412 poll_s Ssl  ?          0:00 whoopsie
1     0   939     1  20   0   2176   712 poll_s Ss   ?          0:00 acpid -c /etc/acpi/events -s /var/run/acpid.socket
5     0   940     1  20   0   3604   632 hrtime Ss   ?          0:00 /usr/sbin/irqbalance
1     0   941     1  20   0   2620   916 hrtime Ss   ?          0:00 cron
1     1   942     1  20   0   2472   352 hrtime Ss   ?          0:00 atd
4     0   949     1  20   0  34040  3088 poll_s Ssl  ?          0:00 lightdm
4     0   955     1  20   0  11076  3548 ep_pol Ss   ?          0:00 /usr/sbin/cupsd -F
1     0  1002     1  20   0   6236  2740 poll_s Ss   ?          0:00 /usr/sbin/apache2 -k start
5    33  1005  1002  20   0   6016  1932 wait_f S    ?          0:00 /usr/sbin/apache2 -k start
5    33  1007  1002  20   0 228680  2284 pipe_w Sl   ?          0:00 /usr/sbin/apache2 -k start
5    33  1008  1002  20   0 228680  2284 pipe_w Sl   ?          0:00 /usr/sbin/apache2 -k start
4     0  1092   949  20   0  26400 14376 poll_s Ss+  tty7       0:47 /usr/bin/X :0 -auth /var/run/lightdm/root/:0 -nolisten tcp vt7 -novtswitch
4     0  1202     1  20   0   4632   864 n_tty_ Ss+  tty1       0:00 /sbin/getty -8 38400 tty1
4     0  1207   949  20   0  16432  3180 wait   Sl   ?          0:00 lightdm --session-child 12 15
4     0  1210     1  20   0  15828  3400 poll_s Sl   ?          0:00 /usr/lib/accountsservice/accounts-daemon
4     0  1237     1  20   0  34232  3316 poll_s Sl   ?          0:00 /usr/sbin/console-kit-daemon --no-daemon
4  1001  1312  1207  20   0  49776  8504 poll_s Ssl  ?          0:00 gnome-session --session=ubuntu
1  1001  1348  1312  20   0   4080   208 poll_s Ss   ?          0:00 /usr/bin/ssh-agent /usr/bin/dbus-launch --exit-with-session gnome-session -
1  1001  1351     1  20   0   3940   480 poll_s S    ?          0:00 /usr/bin/dbus-launch --exit-with-session gnome-session --session=ubuntu
1  1001  1352     1  20   0   6472  3076 poll_s Ss   ?          0:05 //bin/dbus-daemon --fork --print-pid 5 --print-address 7 --session
5  1001  1360     1  20   0  64568  3168 poll_s Sl   ?          0:00 gnome-keyring-daemon --start --components=gpg
0  1001  1366  1312  20   0 138180 15416 poll_s Sl   ?          0:01 /usr/lib/gnome-settings-daemon/gnome-settings-daemon
4     0  1373     1  20   0  28420  3764 poll_s Sl   ?          0:00 /usr/lib/upower/upowerd
0  1001  1431     1  20   0   8408  2216 poll_s S    ?          0:00 /usr/lib/gvfs/gvfsd
0  1001  1441     1  20   0  34760  2564 futex_ Sl   ?          0:00 /usr/lib/gvfs//gvfs-fuse-daemon -f /home/student/.gvfs
0  1001  1489  1312  20   0 225780 77312 poll_s Sl   ?          0:41 compiz
4   103  1492     1  20   0  53340 10212 poll_s Sl   ?          0:00 /usr/lib/i386-linux-gnu/colord/colord
0  1001  1496     1  20   0   9272  2876 poll_s S    ?          0:00 /usr/lib/i386-linux-gnu/gconf/gconfd-2
1  1001  1505     1   9 -11  99908  5736 poll_s S<l  ?          0:00 /usr/bin/pulseaudio --start --log-target=syslog
4   111  1507     1  21   1  21332  1248 poll_s SNl  ?          0:00 /usr/lib/rtkit/rtkit-daemon
0  1001  1511     1  20   0   8432  2132 poll_s S    ?          0:00 /usr/lib/gvfs/gvfsd-metadata
0  1001  1513  1312  20   0 113308 13996 poll_s Sl   ?          0:00 nm-applet
0  1001  1515  1312  20   0  39468  7484 poll_s Sl   ?          0:00 /usr/lib/policykit-1-gnome/polkit-gnome-authentication-agent-1
0  1001  1516  1312  20   0 167424 35084 poll_s Sl   ?          0:47 nautilus -n
0  1001  1521  1312  20   0  57852  7536 poll_s Sl   ?          0:00 /usr/lib/gnome-settings-daemon/gnome-fallback-mount-helper
0  1001  1524  1312  20   0  88856 10572 poll_s Sl   ?          0:00 bluetooth-applet
0  1001  1525  1505  20   0  14104  2492 poll_s S    ?          0:00 /usr/lib/pulseaudio/pulse/gconf-helper
0  1001  1534     1  20   0   9864  3352 poll_s S    ?          0:00 /usr/lib/gvfs/gvfs-gdu-volume-monitor
4     0  1536     1  20   0  25304  3572 poll_s Sl   ?          0:00 /usr/lib/udisks/udisks-daemon
1     0  1537  1536  20   0   6556   728 poll_s S    ?          0:00 udisks-daemon: not polling any devices
0  1001  1544     1  20   0   9212  2136 poll_s S    ?          0:00 /usr/lib/gvfs/gvfs-gphoto2-volume-monitor
0  1001  1546     1  20   0  20488  2140 poll_s Sl   ?          0:00 /usr/lib/gvfs/gvfs-afc-volume-monitor
0  1001  1551     1  20   0   8840  2920 poll_s S    ?          0:00 /usr/lib/gvfs/gvfsd-trash --spawner :1.9 /org/gtk/gvfs/exec_spaw/0
4 65534  1554   807  20   0   5404  1156 poll_s S    ?          0:00 /usr/sbin/dnsmasq --no-resolv --keep-in-foreground --no-hosts --bind-interf
0  1001  1569     1  20   0  49616  8880 poll_s Sl   ?          0:03 /usr/lib/bamf/bamfdaemon
0  1001  1592  1489  20   0   2236   536 wait   Ss   ?          0:00 /bin/sh -c /usr/bin/compiz-decorator
0  1001  1593  1592  20   0  41388 10184 poll_s Sl   ?          0:01 /usr/bin/gtk-window-decorator
1     0  1600     2  20   0      0     0 bdi_wr S    ?          0:00 [flush-8:0]
0  1001  1614     1  20   0  95480 19336 poll_s Sl   ?          0:20 /usr/lib/unity/unity-panel-service
0  1001  1616     1  20   0  67964  5876 poll_s Sl   ?          0:16 /usr/lib/indicator-appmenu/hud-service
0  1001  1630     1  20   0   8440  2392 poll_s S    ?          0:00 /usr/lib/gvfs/gvfsd-burn --spawner :1.9 /org/gtk/gvfs/exec_spaw/1
0  1001  1633     1  20   0  82620  6148 poll_s Sl   ?          0:00 /usr/lib/indicator-datetime/indicator-datetime-service
0  1001  1634     1  20   0  63592  4412 poll_s Sl   ?          0:00 /usr/lib/indicator-application/indicator-application-service
0  1001  1642     1  20   0 127448  5936 poll_s Sl   ?          0:00 /usr/lib/indicator-sound/indicator-sound-service
0  1001  1643     1  20   0  69336  5644 poll_s Sl   ?          0:00 /usr/lib/indicator-messages/indicator-messages-service
0  1001  1647     1  20   0  78628  5440 poll_s Sl   ?          0:00 /usr/lib/indicator-session/indicator-session-service
0  1001  1656     1  20   0  61480  8796 poll_s Sl   ?          0:00 /usr/lib/indicator-printers/indicator-printers-service
0  1001  1665     1  20   0   7980  2368 poll_s S    ?          0:00 /usr/lib/geoclue/geoclue-master
0  1001  1677     1  20   0  21304  4584 poll_s S    ?          0:00 /usr/lib/ubuntu-geoip/ubuntu-geoip-provider
0  1001  1703     1  20   0  74720  9420 poll_s Sl   ?          0:00 /usr/lib/unity-lens-applications/unity-applications-daemon
0  1001  1705     1  20   0  89428  5868 poll_s Sl   ?          0:00 /usr/lib/unity-lens-files/unity-files-daemon
0  1001  1708     1  20   0  79752  7232 poll_s Sl   ?          0:00 /usr/lib/unity-lens-music/unity-music-daemon
0  1001  1709     1  20   0  70624 12064 poll_s Sl   ?          0:00 /usr/bin/python /usr/lib/unity-lens-video/unity-lens-video
0  1001  1741     1  20   0  45912  5632 poll_s Sl   ?          0:00 /usr/bin/zeitgeist-daemon
0  1001  1747     1  20   0  51972  8124 poll_s Sl   ?          0:00 /usr/lib/zeitgeist/zeitgeist-fts
0  1001  1749     1  20   0  54840  5672 poll_s Sl   ?          0:01 zeitgeist-datahub
0  1001  1755  1747  20   0   4228   284 unix_s S    ?          0:00 /bin/cat
0  1001  1771     1  20   0  33640  2464 poll_s Sl   ?          0:00 /usr/lib/dconf/dconf-service
0  1001  1778  1312  20   0  41148  8072 poll_s Sl   ?          0:00 /usr/lib/gnome-disk-utility/gdu-notification-daemon
0  1001  1780     1  20   0  79608  3776 poll_s Sl   ?          0:00 /usr/lib/unity-lens-music/unity-musicstore-daemon
0  1001  1815     1  20   0  91612 13488 poll_s Sl   ?          0:00 /usr/bin/python /usr/lib/unity-scope-video-remote/unity-scope-video-remote
5     0  1867     1  20   0  13332  1852 poll_s Ss   ?          0:00 nmbd -D
0  1001  1880  1312  20   0  74244  9504 poll_s Sl   ?          0:00 telepathy-indicator
0  1001  1887     1  20   0  41684  5596 poll_s Sl   ?          0:00 /usr/lib/telepathy/mission-control-5
0  1001  1892     1  20   0  91208  9196 poll_s Sl   ?          0:00 /usr/lib/gnome-online-accounts/goa-daemon
0  1001  1897  1312  20   0  39884  7820 poll_s Sl   ?          0:00 gnome-screensaver
0  1001  1920     1  20   0  83812 25332 poll_s Sl   ?          0:00 /usr/bin/python /usr/lib/ubuntuone-client/ubuntuone-syncdaemon
0  1001  1957  1312  20   0  51484 11204 poll_s Sl   ?          0:00 update-notifier
0  1001  1979  1312  20   0  35704  3460 poll_s Sl   ?          0:00 /usr/lib/deja-dup/deja-dup/deja-dup-monitor
0  1001  2013     1  20   0  93864 15680 sleep_ Dl   ?          0:03 gnome-terminal
0  1001  2018  2013  20   0   2404   720 unix_s S    ?          0:00 gnome-pty-helper
0  1001  2019  2013  20   0   7448  3832 wait   Ss   pts/0      0:00 bash
0  1001  2171     1  20   0  35492  3100 pipe_w Sl   ?          0:00 /usr/lib/libreoffice/program/oosplash --writer /home/student/Downloads/grou
0  1001  2189  2171  20   0 262528 90840 poll_s Sl   ?          0:08 /usr/lib/libreoffice/program/soffice.bin --writer /home/student/Downloads/g
1     0  2408     2  20   0      0     0 worker S    ?          0:00 [kworker/0:1]
1     0  2676     2  20   0      0     0 worker S    ?          0:00 [kworker/0:2]
0  1001  2825     1  20   0 129164 30052 poll_s Sl   ?          0:03 gedit /home/student/OSAprogram/Group-B/B3.c
0  1001  2876  2019  35  15   2012   284 wait   SN+  pts/0      0:00 ./a.out
0  1001  2879  2876  35  15   2236   540 wait   SN+  pts/0      0:00 sh -c ps axl
0  1001  2880  2879  35  15   4708   704 -      RN+  pts/0      0:00 ps axl

current nice value can be checked from above table
current priority of process 2876 is 15
Enter new nice value (bet -20 to 20)*/


